// The Sliders Game. Made by Alex Sinkin (C)


#include "TheSliders/Public/Characters/TS_BaseCharacter.h"
#include "GameplayAbilitySpec.h"
#include "PaperFlipbookComponent.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


ATS_BaseCharacter::ATS_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;	
}

/** BeginPlay and EndPlay **/

void ATS_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(
		AnimationTimerHandle,
		this,
		&ATS_BaseCharacter::CheckAndUpdateMovementAnimation,
		AnimationCheckInterval,
		true
	);
}

void ATS_BaseCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorldTimerManager().ClearTimer(AnimationTimerHandle);
}

/** Movement animation **/ 

void ATS_BaseCharacter::CheckAndUpdateMovementAnimation()
{
	float Speed = GetVelocity().Size();
	
	if (!FMath::IsNearlyEqual(Speed, LastSpeed, 0.1f))
	{
		TObjectPtr<UPaperFlipbook>  DesiredFlipbook = (Speed > RunSpeedThreshold) ? RunFlipbook : IdleFlipbook;
 
		if (DesiredFlipbook && DesiredFlipbook != CurrentFlipbook)
		{
			GetSprite()->SetFlipbook(DesiredFlipbook);
			CurrentFlipbook = DesiredFlipbook;
		}
		
		if (GetCharacterMovement()->IsFalling())
		{
			bCanAttack = false;
			GetSprite()->SetFlipbook(JumpFlipbook);
		}
		else
		{
			bCanAttack = true;
			GetSprite()->SetFlipbook(DesiredFlipbook);
		}
 
		LastSpeed = Speed;
	}
	
	if (GetVelocity().X > KINDA_SMALL_NUMBER && !bIsFacingRight)
	{
		GetSprite()->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
		bIsFacingRight = true;
	}
	else if (GetVelocity().X < -KINDA_SMALL_NUMBER && bIsFacingRight)
	{
		GetSprite()->SetRelativeRotation(FRotator(0.f, -180.f, 0.f));
		bIsFacingRight = false;
	}
}

/** Attack animation **/

void ATS_BaseCharacter::PlayAttackAnimation()
{
	if (AttackFlipbook && bCanAttack)
	{
		SetFlipbookIfDifferent(AttackFlipbook);		
	}
}

void ATS_BaseCharacter::SetFlipbookIfDifferent(TObjectPtr<UPaperFlipbook> NewFlipbook) const
{
	UPaperFlipbookComponent* CurrentSprite = GetSprite();
	if (CurrentSprite && NewFlipbook && CurrentSprite->GetFlipbook() != NewFlipbook)
	{
		CurrentSprite->SetFlipbook(NewFlipbook);
		CurrentSprite->PlayFromStart();
		
		
	}
}

/** Ability system **/

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