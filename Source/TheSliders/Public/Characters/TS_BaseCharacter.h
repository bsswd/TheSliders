// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Engine/DataTable.h"
#include "TS_BaseCharacter.generated.h"

class UBoxComponent;
class UPaperFlipbook;


UCLASS(Abstract)
class THESLIDERS_API ATS_BaseCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	
	ATS_BaseCharacter();
	
	/** FUNCTIONS **/
	
	virtual void PlayAttackAnimation();
	void ApplyStats(const FName RowName) const;
	
protected:

	/** PROPERTIES **/

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
	
	UPROPERTY(EditAnywhere, Category="TS|Character|Attack")
	int AttackFrameIndex;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TS|Character|Attack")
	TObjectPtr<UBoxComponent> HitBox;
	
	/** Stats **/
	
	UPROPERTY(EditAnywhere, Category = "TS|Data")
    UDataTable* StatsTable;
	
	
	/** FUNCTIONS **/	
	
	/** Basic **/
	
	virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
private:

	/** PROPERTIES **/
	
	UPROPERTY()
	TObjectPtr<UPaperFlipbook>  CurrentFlipbook = nullptr;
	
	FTimerHandle AnimationTimerHandle;
	float LastSpeed = 0.f;
	
	bool bIsFacingRight = true;
	bool bIsAttacking = false;
		
	/** FUNCTIONS **/
	
	void CheckAndUpdateMovementAnimation();	
};