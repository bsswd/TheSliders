// The Sliders Game. Made by Alex Sinkin (C)


#include "AbilitySystem/TS_AbilitySystemComponent.h"
#include "GameplayTags/TSTags.h"


void UTS_AbilitySystemComponent::OnGiveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnGiveAbility(AbilitySpec);
	
	if (!IsValid(AbilitySpec.Ability)) return;

	for (const FGameplayTag& Tag: AbilitySpec.Ability->GetAssetTags())
	{
		if (Tag.MatchesTagExact(TSTags::TSAbilities::ActivateOnGiven))
		{
			return;
		}
	}
}
