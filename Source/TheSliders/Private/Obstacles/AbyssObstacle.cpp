// The Sliders Game. Made by Alex Sinkin (C)

#include "Obstacles/AbyssObstacle.h"

AAbyssObstacle::AAbyssObstacle()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAbyssObstacle::BeginPlay()
{
	Super::BeginPlay();
}

void AAbyssObstacle::TriggerAction()
{
	Super::TriggerAction();
	
	// After fall in abyss Player loses one attemp and respawning on the edge 
}






