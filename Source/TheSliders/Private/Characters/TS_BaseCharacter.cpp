// The Sliders Game. Made by Alex Sinkin (C)


#include "TheSliders/Public/Characters/TS_BaseCharacter.h"


// Sets default values
ATS_BaseCharacter::ATS_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* ATS_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}