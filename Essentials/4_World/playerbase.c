modded class PlayerBase
{
	override void OnCommandSwimStart()
	{
		super.OnCommandSwimStart();
		
		if ( GetInventory() ) { GetInventory().UnlockInventory(LOCK_FROM_SCRIPT); }
	}
	
	override void OnCommandSwimFinish()
	{
		if ( GetInventory() ) { GetInventory().LockInventory(LOCK_FROM_SCRIPT); }
		
		super.OnCommandSwimFinish();
	}

	override void OnCommandVehicleStart()
	{
		super.OnCommandVehicleStart();
		
		if ( GetInventory() ) { GetInventory().UnlockInventory(LOCK_FROM_SCRIPT); }
	}
	
	override void OnCommandVehicleFinish()
	{
		if ( GetInventory() ) { GetInventory().LockInventory(LOCK_FROM_SCRIPT); }
		
		super.OnCommandVehicleFinish();
	}

	override bool CanReceiveItemIntoHands (EntityAI item_to_hands)
	{
		if ( IsInVehicle() )
		{
			EntityAI root = item_to_hands.GetHierarchyRoot();
			if ( !root.IsTransport() && !root.IsPlayer() )
				return false;
		}

		if ( !CanPickupHeavyItem(item_to_hands) )
			return false;

		return true;
	}
}