// The Sliders Game. Made by Alex Sinkin (C)

#include "Characters/TS_BaseEnemyCharacter.h"

#include "Components/AttackComponent.h"
#include "Components/CapsuleComponent.h"

ATS_BaseEnemyCharacter::ATS_BaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;	
}

void ATS_BaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();	
	
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_ENEMY, ECollisionResponse::ECR_Block);
}
