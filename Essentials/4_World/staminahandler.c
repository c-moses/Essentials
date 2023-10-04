modded class StaminaHandler

{
	override protected void RegisterStaminaConsumers()
	{
		m_StaminaConsumers = new StaminaConsumers();
		m_StaminaConsumers.RegisterConsumer(EStaminaConsumers.HOLD_BREATH, GameConstants.STAMINA_HOLD_BREATH_THRESHOLD_ACTIVATE,GameConstants.STAMINA_HOLD_BREATH_THRESHOLD_DRAIN);
		m_StaminaConsumers.RegisterConsumer(EStaminaConsumers.SPRINT, CfgGameplayHandler.GetStaminaMinCap());
		m_StaminaConsumers.RegisterConsumer(EStaminaConsumers.JUMP, GameConstants.STAMINA_JUMP_THRESHOLD);
		m_StaminaConsumers.RegisterConsumer(EStaminaConsumers.VAULT, GameConstants.STAMINA_VAULT_THRESHOLD);
		m_StaminaConsumers.RegisterConsumer(EStaminaConsumers.CLIMB, GameConstants.STAMINA_CLIMB_THRESHOLD);
		m_StaminaConsumers.RegisterConsumer(EStaminaConsumers.MELEE_HEAVY, GameConstants.STAMINA_MELEE_HEAVY_THRESHOLD);
		m_StaminaConsumers.RegisterConsumer(EStaminaConsumers.MELEE_EVADE, GameConstants.STAMINA_MELEE_EVADE_THRESHOLD);
		m_StaminaConsumers.RegisterConsumer(EStaminaConsumers.ROLL, GameConstants.STAMINA_ROLL_THRESHOLD);
		m_StaminaConsumers.RegisterConsumer(EStaminaConsumers.DROWN,0);
	}

	override protected void CheckStaminaState()
	{
		if (m_Stamina <= 0)
		{
			m_StaminaDepleted = true;
			if (!m_IsInCooldown)
			{
				SetCooldown(GameConstants.STAMINA_REGEN_COOLDOWN_EXHAUSTION); 
			}
		}
		else
		{
			m_StaminaDepleted = false;
		}
	}

	override protected void SetCooldown(float time, int modifier = -1)
	{
		if ( m_StaminaDepleted || m_Stamina <= 0.0 )
		{
			ResetCooldown(modifier);
			return;
		}

		m_IsInCooldown = true;
		
		Timer timer;
		if (m_TimerMap.Find(modifier, timer) && timer.IsRunning())
		{
			timer.Stop();
		}
		else
		{
			timer = new ref Timer;
			m_TimerMap.Set(modifier,timer);
		}
		timer.Run(time, this, "ResetCooldown",  new Param1<int>( modifier ));
	}
	
	override protected void ResetCooldown(int modifier = -1)
	{
		StaminaModifier sm = m_StaminaModifiers.GetModifierData(modifier);
		if (sm)
		{
			sm.SetStartTime(-1);
			sm.ResetRunTime();
			sm.SetInUse(false);
		}
		m_IsInCooldown = false;
	}
	
	override Timer GetCooldownTimer(int modifier)
	{
		
	}

}