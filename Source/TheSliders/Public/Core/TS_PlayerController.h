// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TS_PlayerController.generated.h"

struct FGameplayTag;
struct FInputActionValue;
class UInputMappingContext;
class UInputAction;

UCLASS()
class THESLIDERS_API ATS_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input|Movement")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input|Movement")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input|Movement")
	TObjectPtr<UInputAction> AttackAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input|Selectors")
	TObjectPtr<UInputAction> SelectDocAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input|Selectors")
	TObjectPtr<UInputAction> SelectBaldAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input|Selectors")
	TObjectPtr<UInputAction> SelectLawAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input|Selectors")
	TObjectPtr<UInputAction> SelectSazzAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input|Selectors")
	TObjectPtr<UInputAction> SelectJokaAction;
	
	void Move(const FInputActionValue& Value);
	
	void Jump();
	void StopJumping();
	
	void ActivateAbility(const FGameplayTag& AbilityTag) const;
	
	void Attack();
	
	void SelectDoc();
	void SelectBald();
	void SelectLaw();
	void SelectSazz();
	void SelectJoka();
};
