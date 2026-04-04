// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TS_AbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THESLIDERS_API UTS_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	
	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	virtual void OnRep_ActivateAbilities() override;
	
	
private:

	void HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec);
};