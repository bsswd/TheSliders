// The Sliders Game. Made by Alex Sinkin (C)


#include "Characters/TS_BaseEnemyCharacter.h"
#include "AbilitySystem/TS_AbilitySystemComponent.h"


ATS_BaseEnemyCharacter::ATS_BaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	AbilitySystemComponent = CreateDefaultSubobject<UTS_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* ATS_BaseEnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ATS_BaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	
	if (!HasAuthority()) return;
	
	GiveStartupAbilities();
	
	
	
}
