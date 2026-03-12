// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "PaperCharacter.h"
#include "TS_BaseCharacter.generated.h"

class UPaperFlipbook;

UCLASS(Abstract)
class THESLIDERS_API ATS_BaseCharacter : public APaperCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATS_BaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TS|Flipbooks")
	TObjectPtr<UPaperFlipbook> IdleFlipbook;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TS|Flipbooks")
	TObjectPtr<UPaperFlipbook> RunFlipbook;
	
	UPROPERTY(EditAnywhere, Category="TS|Animation")
	float AnimationCheckInterval = 0.1f;
 
	UPROPERTY(EditAnywhere, Category="TS|Animation")
	float RunSpeedThreshold = 1.0f;
	
private:

	UPROPERTY()
	UPaperFlipbook* CurrentFlipbook;
	
	FTimerHandle AnimationTimerHandle;
 
	float LastSpeed = 0.f;
	
	void CheckAndUpdateAnimation();	
};