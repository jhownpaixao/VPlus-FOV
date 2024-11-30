//!contents of this class will be transfered to client upon connecting, with the variables in either initial state as set through the 'InitServer..()' call, or replaced with contents of the json configuration file if such file is both present and reading is enabled in server.cfg

modded class ITEM_PlayerData
{
	ref ITEM_CameraData CameraData 				= new ITEM_CameraData;
};

class ITEM_CameraData : ITEM_DataBase
{
	override void InitServer()
	{
	}
	
	override bool ValidateServer()
	{
		return true;
	}
	
	//-------------------------------------------------------------------------------------------------
	//!!! all member variables must correspond with the cfggameplay.json file contents !!!!
	float fovMultiplier = 1.0;
	bool headBobOnSprint = true;
}