// The Sliders Game. Made by Alex Sinkin (C)


#include "TheSliders/Public/Characters/TS_BaseCharacter.h"
#include "GameplayAbilitySpec.h"
#include "PaperFlipbookComponent.h"
#include "AbilitySystemComponent.h"


ATS_BaseCharacter::ATS_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;	
	CurrentFlipbook = nullptr;
}

void ATS_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(
		AnimationTimerHandle,
		this,
		&ATS_BaseCharacter::CheckAndUpdateAnimation,
		AnimationCheckInterval,
		true
	);
}

void ATS_BaseCharacter::CheckAndUpdateAnimation()
{
	float Speed = GetVelocity().Size();
	
	if (!FMath::IsNearlyEqual(Speed, LastSpeed, 0.1f))
	{
		UPaperFlipbook* DesiredFlipbook = (Speed > RunSpeedThreshold) ? RunFlipbook : IdleFlipbook;
 
		if (DesiredFlipbook && DesiredFlipbook != CurrentFlipbook)
		{
			GetSprite()->SetFlipbook(DesiredFlipbook);
			CurrentFlipbook = DesiredFlipbook;
		}
 
		LastSpeed = Speed;
	}
	
	if (GetVelocity().X < 0.f)
	{
		GetSprite()->SetRelativeRotation(FRotator(0.f, -180.f, 0.f));
	}
	else
	{
		GetSprite()->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
	}
}

UAbilitySystemComponent* ATS_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ATS_BaseCharacter::GiveStartupAbilities()
{
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	for (const auto& Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}

void ATS_BaseCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorldTimerManager().ClearTimer(AnimationTimerHandle);
}