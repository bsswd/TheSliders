// The Sliders Game. Made by Alex Sinkin (C)


#include "TheSliders/Public/Characters/TS_BaseCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"
#include "Core/CharacterStats.h"
#include "GameFramework/CharacterMovementComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseCharacter, Log, All);

ATS_BaseCharacter::ATS_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	HitBox = CreateDefaultSubobject<UBoxComponent>("HitBox");
	HitBox->SetupAttachment(RootComponent);	
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
	
	if(GetSprite()->GetPlaybackPositionInFrames() == 4 && GetSprite()->GetFlipbook() == AttackFlipbook)
	{
		GetSprite()->SetFlipbook(IdleFlipbook);
	}
	
	if (!FMath::IsNearlyEqual(Speed, LastSpeed, 0.1f))
	{
		const TObjectPtr<UPaperFlipbook>  DesiredFlipbook = (Speed > RunSpeedThreshold) ? RunFlipbook : IdleFlipbook;
		
		if (DesiredFlipbook && DesiredFlipbook != CurrentFlipbook)
		{
			GetSprite()->SetFlipbook(DesiredFlipbook);
			CurrentFlipbook = DesiredFlipbook;
		}
		
		if (GetCharacterMovement()->IsFalling())
		{
			GetSprite()->SetFlipbook(JumpFlipbook);
			
		}
		else
		{
			GetSprite()->SetFlipbook(DesiredFlipbook);
		}
 
		LastSpeed = Speed;
	}
	
	if (GetVelocity().X > KINDA_SMALL_NUMBER && !bIsFacingRight)
	{
		GetSprite()->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
		HitBox->SetRelativeLocation(FVector(130.f, 0.f, 0.f));
		bIsFacingRight = true;
	}
	else if (GetVelocity().X < -KINDA_SMALL_NUMBER && bIsFacingRight)
	{
		GetSprite()->SetRelativeRotation(FRotator(0.f, -180.f, 0.f));
		HitBox->SetRelativeLocation(FVector(-130.f, 0.f, 0.f));
		bIsFacingRight = false;
	}
}

/** Attack animation **/

void ATS_BaseCharacter::PlayAttackAnimation()
{
	if (GetVelocity().X == 0.f && GetVelocity().Z == 0.f)
	{
		GetSprite()->SetFlipbook(AttackFlipbook);		
	}
}

void ATS_BaseCharacter::ApplyStats(const FName RowName) const
{

	if (!StatsTable)
	{
		UE_LOG(LogBaseCharacter, Error, TEXT("DataTable not found!"));
		return;
	}
   
    FCharacterStats* FoundStats = StatsTable->FindRow<FCharacterStats>(RowName, TEXT("StatsLookup"));
     
    if (!FoundStats)
    {
    	UE_LOG(LogBaseCharacter, Error, TEXT("Stats not found!"));
    	return;
    }
    	
	UE_LOG(LogBaseCharacter, Log, TEXT("Stats for %s applied successfully!"), *RowName.ToString());
}