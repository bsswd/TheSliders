// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "TS_PlayerState.generated.h"

class UAbilitySystemComponent;

UCLASS()
class THESLIDERS_API ATS_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:

	ATS_PlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
private:
	
	UPROPERTY(VisibleAnywhere, Category = "TS|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};