// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "TS_BaseObstacle.h"
#include "AbyssObstacle.generated.h"

UCLASS()
class THESLIDERS_API AAbyssObstacle : public ATS_BaseObstacle
{
	GENERATED_BODY()

public:
	
	AAbyssObstacle();

protected:

	virtual void TriggerAction() override;
	
	virtual void BeginPlay() override;


};
