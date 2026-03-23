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
	// Sets default values for this character's properties
	ATS_BaseEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
