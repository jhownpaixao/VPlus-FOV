modded class DayZPlayerImplement extends DayZPlayer
{
    override int 	CameraHandler(int pCameraMode)
	{
		//! ironsights
		if (!m_LiftWeapon_player)
		{
			ItemOptics optics = null;
			EntityAI entityInHands = GetHumanInventory().GetEntityInHands();
			Weapon weapon = Weapon.Cast(entityInHands);
			if (weapon)
				optics = weapon.GetAttachedOptics();
			else if (entityInHands)
				Class.CastTo(optics,entityInHands);
			
			if (m_CameraOptics && optics)
			{
				return DayZPlayerCameras.DAYZCAMERA_OPTICS;
			}
			else if (m_CameraIronsight && weapon)
			{
				return DayZPlayerCameras.DAYZCAMERA_IRONSIGHTS;
			}
		}	
		
		// If the logic above doesn't reach optics nor ironsights camera,
		// yet weapon is still raised and ads is wanted, enforce 1pv camera
		// as this will reduce erratic behaviour of camera switching in 3pv
		HumanInputController hic = GetInputController();
		if (m_Camera3rdPerson && m_IsWeapon && m_IsRaised && hic && hic.WeaponADS())
		{
			return DayZPlayerCameras.DAYZCAMERA_1ST;
		}
		
		//uncon
		if ( GetCurrentCommandID() == DayZPlayerConstants.COMMANDID_UNCONSCIOUS )
		{
			return DayZPlayerCameras.DAYZCAMERA_1ST_UNCONSCIOUS;
		}
		
		HumanCommandVehicle vehicleCommand = GetCommand_Vehicle();
		
		if (!m_Camera3rdPerson)
		{
			if (vehicleCommand)
			{
				return DayZPlayerCameras.DAYZCAMERA_1ST_VEHICLE;
			}
			
			return DayZPlayerCameras.DAYZCAMERA_1ST;
		}
		else
		{
			if (vehicleCommand)
			{
				Transport transport = vehicleCommand.GetTransport();
				if (transport && GetParent())
				{
					return transport.Get3rdPersonCameraType();
				}
			}
			
			//! get movement state 
			GetMovementState(m_MovementState);
			
			//! VKOSTIK: v ostatnich commandech mimo COMMANDID_MOVE je 
			//! m_MovementState.m_iStanceIdx - DayZPlayerConstants.STANCEIDX_ERECT
			//! m_MovementState.m_iMovement = 0 (idle)

			//! COMMANDID_ACTION returns stance right - ERECT/CROUCH

			//! melee camera - not melee - stays in stance camera

			if (m_MovementState.m_CommandTypeId == DayZPlayerConstants.COMMANDID_CLIMB)
			{
				return DayZPlayerCameras.DAYZCAMERA_3RD_CLIMB;
			}

			if (m_JumpClimb.m_bIsJumpInProgress)
			{
				return DayZPlayerCameras.DAYZCAMERA_3RD_JUMP;
			}
			
			int targetStanceIndex = m_MovementState.m_iStanceIdx;
			
			//! special handling to allow the camera to fully blend before transitioning to the raised one
			HumanCommandMove commandMove = GetCommand_Move();
			if (commandMove && commandMove.IsChangingStance() && m_MovementState.IsRaised())
			{
				targetStanceIndex = m_MovementState.m_iStanceIdx - DayZPlayerConstants.STANCEIDX_RAISED;
			}
			
			//		
			// normal movement cameras			
			if (targetStanceIndex == DayZPlayerConstants.STANCEIDX_CROUCH)
			{
				return DayZPlayerCameras.DAYZCAMERA_3RD_CRO;
			}
			else if (targetStanceIndex == DayZPlayerConstants.STANCEIDX_RAISEDCROUCH)
			{
				return DayZPlayerCameras.DAYZCAMERA_3RD_CRO_RAISED;
			}
			else if (targetStanceIndex == DayZPlayerConstants.STANCEIDX_PRONE)
			{
				return DayZPlayerCameras.DAYZCAMERA_3RD_PRO;
			}
			else if (targetStanceIndex == DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
			{
				return DayZPlayerCameras.DAYZCAMERA_3RD_PRO_RAISED;
			}

			if (targetStanceIndex == DayZPlayerConstants.STANCEIDX_RAISEDERECT)
			{
				if (m_IsWeapon) 
				{
					return DayZPlayerCameras.DAYZCAMERA_3RD_ERC_RAISED;
				}
				else
				{
					return DayZPlayerCameras.DAYZCAMERA_3RD_ERC_RAISED_MELEE;
				}
			}
            else if (CfgGameplayHandler.GetHeadBobOnSprint() && m_MovementState.m_iMovement == 3)
            {
                return DayZPlayerCameras.DAYZCAMERA_3RD_ERC_SPR;
            }
			else if (targetStanceIndex == DayZPlayerConstants.MOVEMENTIDX_SPRINT)
			{
				return DayZPlayerCameras.DAYZCAMERA_3RD_ERC_SPR;
			}

			// DayZPlayerConstants.STANCEIDX_ERECT
			return DayZPlayerCameras.DAYZCAMERA_3RD_ERC;
		}
		
		return DayZPlayerCameras.DAYZCAMERA_1ST;
	}
}