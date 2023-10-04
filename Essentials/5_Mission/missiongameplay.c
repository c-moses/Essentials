modded class MissionGameplay
{
	int m_EarPlugsState = 0; 
	autoptr EarPlugsWidget m_earplugswidget = new EarPlugsWidget;

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice); 
		if ( GetGame().GetInput().LocalPress("UAEarPlugsToggle") && GetGame().GetUIManager().GetMenu() == NULL ) 
		{
			if (m_EarPlugsState == 0)
			{
				m_EarPlugsState++;
				GetGame().GetSoundScene().SetSoundVolume(0.20,1);
				m_earplugswidget.SetIcon("Essentials\\data\\volume_low.edds");
			}
			else if (m_EarPlugsState == 1)
			{
				m_EarPlugsState = 0;
				GetGame().GetSoundScene().SetSoundVolume(1,1);
				m_earplugswidget.SetIcon("Essentials\\data\\volume_full.edds");
			}
		}
	}
	override void AddActiveInputRestriction(int restrictor)
	{
		if (restrictor > -1)
		{
			switch (restrictor)
			{
				case EInputRestrictors.INVENTORY:
				{
					GetUApi().GetInputByID(UAWalkRunForced).ForceEnable(false);
					PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
					if ( player )
					{
						ItemBase item = player.GetItemInHands();
						if (item && item.IsWeapon())
							player.RequestResetADSSync();
					}
					break;
				}
				case EInputRestrictors.MAP:
				{
					GetUApi().GetInputByID(UAWalkRunForced).ForceEnable(false);
					break;
				}
			}
			
			if (!m_ActiveInputRestrictions)
			{
				m_ActiveInputRestrictions = new array<int>;
			}
			if (m_ActiveInputRestrictions.Find(restrictor) == -1)
			{
				m_ActiveInputRestrictions.Insert(restrictor);
			}
		}
	}
}