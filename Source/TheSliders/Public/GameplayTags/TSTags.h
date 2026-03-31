// The Sliders Game. Made by Alex Sinkin (C)


#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"


namespace TSTags
{
	namespace TSAbilities
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(ActivateOnGiven);		
		
		namespace Player
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(MeleeAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(RangeAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(DocSelect);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(BaldSelect);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(LawSelect);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(SazzSelect);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(JokaSelect);
		}
		
		namespace Enemy
        {
        	UE_DECLARE_GAMEPLAY_TAG_EXTERN(MeleeAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(RangeAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Jump);
        }
	}
}