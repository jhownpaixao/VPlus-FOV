modded class ModItemRegisterCallbacks
{

    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);
		
		pType.AddItemInHandsProfileIK("Naloxona",         "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", pBehavior,"dz/anims/anm/player/ik/gear/morphine.anm");
		pType.AddItemInHandsProfileIK("VitaminBottleBase","dz/anims/workspaces/player/player_main/props/player_main_1h_pills.asi",    pBehavior,"dz/anims/anm/player/ik/gear/VitaminBottle.anm");
		pType.AddItemInHandsProfileIK("TabletsBase1",     "dz/anims/workspaces/player/player_main/props/player_main_1h_tablets.asi",  pBehavior,"dz/anims/anm/player/ik/gear/tetracycline_tablets.anm");
		pType.AddItemInHandsProfileIK("TabletsBase2",     "dz/anims/workspaces/player/player_main/props/player_main_1h_tablets.asi",  pBehavior,"dz/anims/anm/player/ik/gear/painkillers2.anm");
		pType.AddItemInHandsProfileIK("SurgicalKit",	  "dz/anims/workspaces/player/player_main/player_main_1h.asi",				  pBehavior,"dz/anims/anm/player/ik/gear/sewing_kit.anm");
		pType.AddItemInHandsProfileIK("SalveTube",		  "dz/anims/workspaces/player/player_main/props/player_main_1h_pills.asi",	  pBehavior,"dz/anims/anm/player/ik/gear/VitaminBottle.anm");
        
    }
};
