class EarPlugsWidget extends Managed
{
    autoptr ImageWidget			m_icon;
    float						m_iconalpha = 0;

    void EarPlugsWidget()
    {
        m_icon 	= ImageWidget.Cast(GetGame().GetWorkspace().CreateWidgets( "Essentials/data/earplugs.layout" ));
        m_icon.Show(false);
    }

    void ~EarPlugsWidget()
	{
        m_icon.Show(false);
        if (m_iconalpha != 0)
        {
	 		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.HideIcon);
		}
        delete m_icon;
    }

    void SetIcon(string imagePath)
    {
        m_icon.LoadImageFile( 0, imagePath );
        m_icon.Show(true);
        m_iconalpha = 1;
        m_icon.SetAlpha(m_iconalpha);
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.HideIcon, 20, true);
    }

    void HideIcon()
    {
        if (m_iconalpha > 0.90)
        {
            m_iconalpha = m_iconalpha - 0.0035;
        }
        else
        {
            m_iconalpha = m_iconalpha - 0.022;
        }

        if (m_iconalpha <= 0)
        {
            m_icon.Show(false);
            m_iconalpha = 0;
            GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.HideIcon);
        }

        m_icon.SetAlpha(m_iconalpha);
    }
}