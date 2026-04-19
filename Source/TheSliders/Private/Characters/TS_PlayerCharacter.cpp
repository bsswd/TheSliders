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
	
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
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
}