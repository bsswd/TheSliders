// The Sliders Game. Made by Alex Sinkin (C)


#include "AbilitySystem/TS_AbilitySystemComponent.h"
#include "GameplayTags/TSTags.h"


void UTS_AbilitySystemComponent::OnGiveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnGiveAbility(AbilitySpec);	
	HandleAutoActivatedAbility(AbilitySpec);
}

void UTS_AbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();
	
	FScopedAbilityListLock AbilityScopeLock(*this);
	
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		HandleAutoActivatedAbility(AbilitySpec);
	}
}

void UTS_AbilitySystemComponent::HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec)
{
	if (!IsValid(AbilitySpec.Ability)) return;

	for (const FGameplayTag& Tag: AbilitySpec.Ability->GetAssetTags())
	{
		if (Tag.MatchesTagExact(TSTags::Abilities::ActivateOnGiven))
		{
			TryActivateAbility(AbilitySpec.Handle);
			return;
		}
	}
}
