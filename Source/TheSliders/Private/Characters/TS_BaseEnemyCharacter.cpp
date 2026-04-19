// The Sliders Game. Made by Alex Sinkin (C)

#include "Characters/TS_BaseEnemyCharacter.h"

ATS_BaseEnemyCharacter::ATS_BaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;	
}

void ATS_BaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();	
}
