class CfgPatches
{
	class Essentials
	{
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Medical",
			"DZ_Scripts",
			"JM_CF_Scripts"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgMods
{
	class Essentials
	{
		dir="Essentials";
		name="Essentials";
        author="Moses";
		inputs="Essentials/Inputs.xml";
		type="mod";
		dependencies[]=
		{
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				files[]=
				{
					"Essentials/3_Game"
				};
			};
			class worldScriptModule
			{
				files[]=
				{
					"Essentials/4_World"
				};
			};
			class missionScriptModule
			{
				files[]=
				{
					"Essentials/5_Mission"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Epinephrine: Inventory_Base
	{
		scope=2;
		descriptionShort="A shot of adrenaline. Injection gives three minutes of boosted stamina. Side effects include dehydration.";
	};
	class Morphine: Inventory_Base
	{
		scope=2;
		descriptionShort="A shot of morphine. Injection gives five minutes of pain relief and will speed up recovery of broken bones.";
	};
};