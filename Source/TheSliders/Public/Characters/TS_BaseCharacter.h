// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "PaperCharacter.h"
#include "TS_BaseCharacter.generated.h"

class UGameplayAbility;
class UPaperFlipbook;

UCLASS(Abstract)
class THESLIDERS_API ATS_BaseCharacter : public APaperCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	ATS_BaseCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	virtual void PlayAttackAnimation();
	
protected:
	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/** Flipbooks **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TS|Flipbooks")
	TObjectPtr<UPaperFlipbook> IdleFlipbook;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TS|Flipbooks")
	TObjectPtr<UPaperFlipbook> RunFlipbook;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TS|Flipbooks")
	TObjectPtr<UPaperFlipbook> JumpFlipbook;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TS|Flipbooks")
	TObjectPtr<UPaperFlipbook> AttackFlipbook;
	
	/** Animation setup **/
	UPROPERTY(EditAnywhere, Category="TS|Animation")
	float AnimationCheckInterval = 0.1f;
 
	UPROPERTY(EditAnywhere, Category="TS|Animation")
	float RunSpeedThreshold = 1.0f;
	
	/** Ability system **/
	void GiveStartupAbilities();
	
private:

	UPROPERTY(EditDefaultsOnly, Category = "TS|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
	
	UPROPERTY()
	TObjectPtr<UPaperFlipbook>  CurrentFlipbook = nullptr;
	
	FTimerHandle AnimationTimerHandle;
	float LastSpeed = 0.f;
	
	bool bIsFacingRight = true;
	bool bIsAttacking = false;
	
	
	UFUNCTION()
	void OnAttackAnimationFinished();	
	
	void CheckAndUpdateMovementAnimation();	
};