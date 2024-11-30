// *************************************************************************************
// ! DayZPlayerCamera3rdPersonErc - 3rd person erected
// *************************************************************************************
modded class DayZPlayerCamera3rdPersonErc extends DayZPlayerCamera3rdPerson
{
	void DayZPlayerCamera3rdPersonErc(DayZPlayer pPlayer, HumanInputController pInput)
	{
		//Print("new camera: DayZPlayerCamera3rdPersonErc");
		
		/* m_fDistance 		= 1.6;
		m_CameraOffsetMS	= "0.0 1.4 0.0";
		m_CameraOffsetLS	= "0.0 0.3 0.0";
		m_fShoulderWidth	= 0.3;
		m_fPredictCollisionRadius = 1.2; */

		m_fDistance 		= 2.0;
		m_CameraOffsetMS    = "0.0 1.3 0.0";
		m_CameraOffsetLS	= "0.0 0.3 0.0";
		m_fShoulderWidth	= 0.4;
		m_fPredictCollisionRadius = 0.2;
	}
}

// *************************************************************************************
// ! DayZPlayerCamera3rdPersonErcRaised - 3rd person erected raised
// *************************************************************************************
modded class DayZPlayerCamera3rdPersonErcRaised extends DayZPlayerCamera3rdPersonErc
{
	void DayZPlayerCamera3rdPersonErcRaised(DayZPlayer pPlayer, HumanInputController pInput)
	{
		//Print("new camera: DayZPlayerCamera3rdPersonErcRaised");
		m_fPredictCollisionRadius = 0.2;

		if ( pPlayer.GetCurrentPerItemCameraUD () == DayZPlayerCameras.PERITEMUD_EMPTYHANDED )
		{
			// no item in hands 
			m_fDistance 		= 1.8;
			m_fShoulderWidth	= 0.4;
			m_CameraOffsetMS    = "0.0 1.3 0.2";
			m_CameraOffsetLS	= "0.0 0.3 0.0";
			
		}		
		else if ( pPlayer.GetCurrentPerItemCameraUD () == DayZPlayerCameras.PERITEMUD_TWOHANDED )
		{
			// two handed
			m_fDistance 		= 1.8;
			m_fShoulderWidth	= 0.4;
			m_CameraOffsetMS    = "0.0 1.3 0.2";
			m_CameraOffsetLS	= "0.0 0.3 0.0";
		}
		else if ( pPlayer.GetCurrentPerItemCameraUD () == DayZPlayerCameras.PERITEMUD_ONEHANDED )
		{
			// one handed
			m_fDistance 		= 1.8;
			m_fShoulderWidth	= 0.4;
			m_CameraOffsetMS    = "0.0 1.3 0.2";
			m_CameraOffsetLS	= "0.0 0.3 0.0";
		}
		else
		{
			// weapons in hands			
			m_fDistance 		= 1.4;
			m_CameraOffsetMS    = "0.0 1.3 0.2";
			m_CameraOffsetLS	= "0.0 0.3 0.0";
			m_fShoulderWidth	= 0.5;
		}		
	}
	
	override bool IsCamera3rdRaised()
	{
		return true;
	}
}

// *************************************************************************************
// ! DayZPlayerCamera3rdPersonCrouch - 3rd person crouch
// *************************************************************************************
modded class DayZPlayerCamera3rdPersonCrouch extends DayZPlayerCamera3rdPerson
{
	static const float 	CONST_CAMERAMOVEMENTHEIGH = 0.4;	// 0 idle, 0.15 walk 0.3 run/sprint 

	void DayZPlayerCamera3rdPersonCrouch (DayZPlayer pPlayer, HumanInputController pInput)
	{
		//Print("new camera: DayZPlayerCamera3rdPersonCrouch");
		
		m_fDistance 		= 2.0;
		m_CameraOffsetMS	= "0.0 1.2 0.1";
		m_CameraOffsetLS	= "0.0 0.3 0.0";
		m_fShoulderWidth	= 0.4;
		m_fPredictCollisionRadius = 0.3;

	}

	//	
	override void 		OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{				
		m_pPlayer.GetMovementState(m_MovementState);

		//! movement height 
		float 	movement 	= (Limit(m_MovementState.m_iMovement, 1, 3) - 1.0) * 0.5;
		movement 			*= CONST_CAMERAMOVEMENTHEIGH;
		m_fCameraHeight		= Math.SmoothCD(m_fCameraHeight, movement, m_fCameraHeightVel, 0.2, 1000, pDt);
		m_CameraOffsetMS[1] = 0.9 + m_fCameraHeight;		
		
		//! prev update 
		super.OnUpdate(pDt, pOutResult);
	}

	protected float 	m_fCameraHeight;			// -1..1 shoulderness :)
	protected float 	m_fCameraHeightVel[1];		// 0
}

// *************************************************************************************
// ! DayZPlayerCamera3rdPersonCrouchRaised- 3rd person crouch raised
// *************************************************************************************
modded class DayZPlayerCamera3rdPersonCrouchRaised extends DayZPlayerCamera3rdPersonCrouch
{
	void DayZPlayerCamera3rdPersonCrouchRaised(DayZPlayer pPlayer, HumanInputController pInput)
	{
		//Print("new camera: DayZPlayerCamera3rdPersonCrouchRaised");
		
		m_fDistance 		= 1.4;
		m_CameraOffsetMS    = "0.0 1.3 0.1"; // being overwritten by m_CameraOffsetMS[1] from DayZPlayerCamera3rdPersonCrouch 
		m_CameraOffsetLS	= "0.0 0.3 0.0";
		m_fShoulderWidth	= 0.5;
	}
	
}