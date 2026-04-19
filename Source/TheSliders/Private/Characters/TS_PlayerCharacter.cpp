// The Sliders Game. Made by Alex Sinkin (C)


#include "Characters/TS_PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


ATS_PlayerCharacter::ATS_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 8000.f;
	CameraBoom->SetRelativeLocation(FVector(0.f, 0.f, 200.f));
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bInheritYaw = false;
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->CameraLagSpeed = 4.f;
	CameraBoom->CameraLagMaxDistance = 0.f;
	
	SideCamera = CreateDefaultSubobject<UCameraComponent>("SideCamera");
	SideCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideCamera->bUsePawnControlRotation = false;
	SideCamera->SetProjectionMode(ECameraProjectionMode::Perspective);
	SideCamera->FieldOfView = 10.f;
	
	AttackFrameIndex = 3;
	
	SpeedMap.Add(ESpeed::Slow, 200.0f);
	SpeedMap.Add(ESpeed::Middle, 600.0f);
    SpeedMap.Add(ESpeed::Fast, 1000.0f);
     
	JumpMap.Add(EJump::None, 0.0f);
	JumpMap.Add(EJump::Middle, 600.0f);
	JumpMap.Add(EJump::High, 1200.0f);
}

void ATS_PlayerCharacter::ApplyStats(FName RowName)
{
	Super::ApplyStats(RowName);
	
	if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
	{
		if (const float* SpeedValue = SpeedMap.Find(CharacterStats.Speed))
		{
			MoveComp->MaxWalkSpeed = *SpeedValue;
		}
		
		if (const float* JumpValue = JumpMap.Find(CharacterStats.Jump))
		{
			MoveComp->JumpZVelocity = *JumpValue;
		}
	}
}