// The Sliders Game. Made by Alex Sinkin (C)


#include "Characters/TS_BaseEnemyCharacter.h"


// Sets default values
ATS_BaseEnemyCharacter::ATS_BaseEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATS_BaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}