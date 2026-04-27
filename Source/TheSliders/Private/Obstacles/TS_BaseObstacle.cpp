// The Sliders Game. Made by Alex Sinkin (C)

#include "Obstacles/TS_BaseObstacle.h"

ATS_BaseObstacle::ATS_BaseObstacle()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATS_BaseObstacle::TriggerAction()
{
	
}

void ATS_BaseObstacle::BeginPlay()
{
	Super::BeginPlay();
}
