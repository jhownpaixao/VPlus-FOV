modded class CfgGameplayHandler
{

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!! =====================================================================================
	//!!! the naming convention for static functions in this file is Get+MemberVariableName !!
	//!! =====================================================================================
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//========================
	// !!! ONLY GETTERS BELLOW
	//========================

	//----------------------------------------------------------------------------------
	static bool GetFOVMultiplier()
	{
		return m_Data.PlayerData.CameraData.fovMultiplier;
	}
	//----------------------------------------------------------------------------------
	static bool GetHeadBobOnSprint()
	{
		return m_Data.PlayerData.CameraData.headBobOnSprint;
	}
	//----------------------------------------------------------------------------------

}