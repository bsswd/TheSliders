// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "TS_BaseCharacter.h"
#include "TS_BaseEnemyCharacter.generated.h"

UCLASS()
class THESLIDERS_API ATS_BaseEnemyCharacter : public ATS_BaseCharacter
{
	GENERATED_BODY()

public:
	
	ATS_BaseEnemyCharacter();

protected:
	
	virtual void BeginPlay() override;
};
