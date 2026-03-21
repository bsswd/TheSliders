// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TS_GameplayAbility.generated.h"


UCLASS()
class THESLIDERS_API UTS_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TS|Debug")
	bool bIsDrawDebug = false;
};
