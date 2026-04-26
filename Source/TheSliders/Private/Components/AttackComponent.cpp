// The Sliders Game. Made by Alex Sinkin (C)


#include "Components/AttackComponent.h"
#include "Engine/Engine.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "GameFramework/Actor.h"
#include "Characters/TS_BaseCharacter.h"
#include "Engine/World.h"
#include "TimerManager.h"


UAttackComponent::UAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(
		CheckAttackFrameTimerHandle,
		this,
		&ThisClass::CheckAttackFrameIndex,
		0.1f,
		true
	);
}

void UAttackComponent::PerformAttack()
{
	AActor* Owner = GetOwner();
	if (!Owner) return;
 
	UWorld* World = GetWorld();
	if (!World) return;
	
	FVector ActorLocation = Owner->GetActorLocation();
	FVector Direction = GetCalculatedDirection();
	
	float Facing = Owner->GetActorScale3D().X > 0 ? 1.0f : -1.0f;
	FVector Start = ActorLocation + FVector(TraceOffset.X * Facing, 0.0f, TraceOffset.Y);
	FVector End = Start + (Direction * Range);
	
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Owner);
	
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		COLLISION_ENEMY, 
		Params
	);
	
	if (bDrawDebug)
	{
		DrawDebugLine(GetWorld(), Start, End, bHit ? FColor::Red : FColor::Red, false, 3.0f, 0, 3.0f);
	}
	
	if (bHit && HitResult.GetActor())
	{
		AActor* HitActor = HitResult.GetActor();
        
		UE_LOG(LogTemp, Log, TEXT("Attack hit: %s"), *HitActor->GetName());
	}
}

FVector UAttackComponent::GetCalculatedDirection() const
{
	const ATS_BaseCharacter* Character = Cast<ATS_BaseCharacter>(GetOwner());
	
	if (!Character) return FVector::ZeroVector;
	
	if (Character->GetFacingRight())
	{
		return FVector(1.0f, 0.0f, 0.0f);
	}
	
	return FVector(-1.0f, 0.0f, 0.0f);
}

void UAttackComponent::CheckAttackFrameIndex()
{
	AActor* Owner = GetOwner();
	if (!Owner)
	{
		UE_LOG(LogAttackComponent, Error, TEXT("Owner not valid!"))
		return;
	}
 
	UPaperFlipbookComponent* Sprite = Owner->FindComponentByClass<UPaperFlipbookComponent>();
	
	if (!Sprite && !Sprite->GetFlipbook())
	{
		UE_LOG(LogAttackComponent, Error, TEXT("Sprite and Flipbook not valid!"))
		return;
	}
	
	const int32 FrameIndex = Sprite->GetPlaybackPositionInFrames();
	const FString FlipbookName = Sprite->GetFlipbook()->GetName();
		
	if (!FlipbookName.Contains(TEXT("Attack")))
	{
		return;
	}
 
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
				1, 1.1f, FColor::Cyan, 
				FString::Printf(TEXT("Flipbook: %s | Frame: %d"), *FlipbookName, FrameIndex)
			);
	}
}