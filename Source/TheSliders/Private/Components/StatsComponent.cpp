// The Sliders Game. Made by Alex Sinkin (C)

#include "Components/StatsComponent.h"
#include "Characters/TS_BaseCharacter.h"
#include "Components/AttackComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogStatsComponent, Log, All)

UStatsComponent::UStatsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;	
}

void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ATS_BaseCharacter>(GetOwner());	
}

void UStatsComponent::ApplyStats(FName RowName)
{
	if (!StatsTable)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("DataTable not found!"));
		return;
	}
   
	FCharacterStats* FoundStats = StatsTable->FindRow<FCharacterStats>(RowName, TEXT("StatsLookup"));
     
	if (!FoundStats)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("Stats not found!"));
		return;
	}
	
	if (!OwnerCharacter)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("OwnerCharacter not found!"));
		return;
	}
    
	CharacterStats.Health = FoundStats->Health;
	
	CharacterStats.Weight = FoundStats->Weight;
	CharacterStats.JumpHeight = FoundStats->JumpHeight;
	CharacterStats.MovementSpeed = FoundStats->MovementSpeed;
	
	CharacterStats.AttackRange = FoundStats->AttackRange;
	CharacterStats.AttackDamage = FoundStats->AttackDamage;
	CharacterStats.AttackFrameIndex = FoundStats->AttackFrameIndex;
	
	CharacterStats.IdleFlipbook = FoundStats->IdleFlipbook;
	CharacterStats.WalkFlipbook = FoundStats->WalkFlipbook;
	CharacterStats.JumpFlipbook = FoundStats->JumpFlipbook;
	CharacterStats.AttackFlipbook = FoundStats->AttackFlipbook;
	
	/** Set Movement **/
	
	UCharacterMovementComponent* MoveComponent = OwnerCharacter->FindComponentByClass<UCharacterMovementComponent>();
	
	if (!MoveComponent)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("Character MovementComponent not found!"));
		return;
	}
	
	MoveComponent->MaxWalkSpeed = CharacterStats.MovementSpeed;
	MoveComponent->JumpZVelocity = CharacterStats.JumpHeight;
	
	/** Set Attack **/
	
	UAttackComponent* AttackComponent = OwnerCharacter->FindComponentByClass<UAttackComponent>();
	
	if (!AttackComponent)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("Character AttackComponent not found!"));
		return;
	}
	
	AttackComponent->Range = CharacterStats.AttackRange;
	AttackComponent->Damage = CharacterStats.AttackDamage;
	AttackComponent->TargetAttackFrameIndex = CharacterStats.AttackFrameIndex;
	
	/** Set flipbooks **/
	
	if(!CharacterStats.IdleFlipbook)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("IdleFlipbook is null"))
		return;
	}
	
	OwnerCharacter->SetIdleFlipbook(CharacterStats.IdleFlipbook);
	
	if(!CharacterStats.WalkFlipbook)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("WalkFlipbook is null"))
		return;
	}
	
	OwnerCharacter->SetWalkFlipbook(CharacterStats.WalkFlipbook);
	
	if(!CharacterStats.JumpFlipbook)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("JumpFlipbook is null"))
		return;
	}
	
	OwnerCharacter->SetJumpFlipbook(CharacterStats.JumpFlipbook);
	
	if(!CharacterStats.AttackFlipbook)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("AttackFlipbook is null"))
		return;
	}
	
	OwnerCharacter->SetAttackFlipbook(CharacterStats.AttackFlipbook);
	
	PrintDebugStats(RowName, CharacterStats, bPrintStatsDebug);
    	
	UE_LOG(LogStatsComponent, Log, TEXT("Stats for %s applied successfully!"), *RowName.ToString());
}

void UStatsComponent::PrintDebugStats(FName CharacterName, FCharacterStats Stats, const bool bPrint)
{
	if (!bPrint || !GEngine)
	{
		UE_LOG(LogStatsComponent, Error, TEXT("Disable logging or error of GEngine"));
		return;
	}
	
	const UEnum* WeightEnum = StaticEnum<EWeight>();		
	const FString CharacterNameString = CharacterName.ToString();
	const FString WeightString = WeightEnum ? WeightEnum->GetNameStringByValue(static_cast<int64>(Stats.Weight)) : TEXT("Unknown");
	
	const FString DebugString = FString::Printf(
		TEXT("NAME: %s\nHEALTH: %.2f\nWEIGHT: %s\nJUMP HEIGHT: %.2f\nSPEED: %.2f\nRANGE: %.2f\nDAMAGE: %.2f\nATTACK INDEX: %d"),
		*CharacterNameString,
		Stats.Health,
		*WeightString,
		Stats.JumpHeight,
		Stats.MovementSpeed,
		Stats.AttackRange,
		Stats.AttackDamage,
		Stats.AttackFrameIndex
	);
 
	GEngine->AddOnScreenDebugMessage(
		-1,                  
		5.f,                
		FColor::Green,       
		DebugString          
	);
}