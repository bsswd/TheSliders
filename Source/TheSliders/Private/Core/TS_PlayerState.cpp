// The Sliders Game. Made by Alex Sinkin (C)


#include "Core/TS_PlayerState.h"
#include "AbilitySystem/TS_AbilitySystemComponent.h"


ATS_PlayerState::ATS_PlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystemComponent = CreateDefaultSubobject<UTS_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent -> SetIsReplicated(true);
	AbilitySystemComponent -> SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* ATS_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}