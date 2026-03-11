// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "PaperCharacter.h"
#include "TS_BaseCharacter.generated.h"

UCLASS(Abstract)
class THESLIDERS_API ATS_BaseCharacter : public APaperCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATS_BaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};