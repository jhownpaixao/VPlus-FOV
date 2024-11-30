class CfgPatches
{
    class VPlus_FOV
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
};

class CfgMods
{
    class VPlus_FOV
    {
        dir = "vplus_fov";
        name = "Vanilla Plus FOV";
        author = "iTzChronuZ [DayZ Blackout]";
        authorID = "76561199441861559";
        version = "1.0";
        type = "mod";
        dependencies[] = {"World", "Game"};
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"vplus_fov\scripts\4_World"};
            };
            class gameScriptModule
            {
                value = "";
                files[] = {"vplus_fov\scripts\3_Game"};
            };
        };
    };
};