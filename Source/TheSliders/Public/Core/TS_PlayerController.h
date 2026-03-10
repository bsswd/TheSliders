// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TS_PlayerController.generated.h"

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
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "TS|Input")
	TObjectPtr<UInputAction> JumpAction;
	
	
	void Move(const FInputActionValue& Value);
	void Jump();
	void StopJumping();
};
