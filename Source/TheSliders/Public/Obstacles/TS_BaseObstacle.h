// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TS_BaseObstacle.generated.h"

class UBoxComponent;
class TS_PlayerCharacter;

UCLASS()
class THESLIDERS_API ATS_BaseObstacle : public AActor
{
	GENERATED_BODY()

public:

	ATS_BaseObstacle();

protected:
	
	/** PROPERTIES **/
	
	// UPROPERTY(EditAnywhere)
	// TObjectPtr<TS_PlayerCharacter> PlayerCharacter;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> TriggerBox;
	
	
	/** FUNCTIONS **/
	

	virtual void TriggerAction();
	
	
	virtual void BeginPlay() override;
};