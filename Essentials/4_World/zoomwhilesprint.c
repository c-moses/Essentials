modded class DayZPlayerImplement
{
	override void HandleView()
	{
		
		super.HandleView();
		
		HumanInputController hic = GetInputController();
	
		//bool camChange = hic.CameraViewChanged();
		
		if ( !m_MovementState.IsRaised() && hic.IsZoomToggle() )        
		{
			m_CameraEyeZoomLevel = ECameraZoomType.NORMAL;
		}
	}
}