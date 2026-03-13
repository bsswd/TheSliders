// The Sliders Game. Made by Alex Sinkin (C)


#include "Characters/TS_PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Core/TS_PlayerState.h"
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
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = false;
	
	SideCamera = CreateDefaultSubobject<UCameraComponent>("SideCamera");
	SideCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideCamera->bUsePawnControlRotation = false;
	SideCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	SideCamera->SetOrthoWidth(1200.f);
	
}

UAbilitySystemComponent* ATS_PlayerCharacter::GetAbilitySystemComponent() const
{
	ATS_PlayerState* TSPlayerState = Cast<ATS_PlayerState>(GetPlayerState());
	if (!IsValid(TSPlayerState)) return nullptr;
	
	return TSPlayerState->GetAbilitySystemComponent();
}

void ATS_PlayerCharacter::PossessedBy(AController* EventController)
{
	Super::PossessedBy(EventController);
	
	if (!IsValid(GetAbilitySystemComponent()) || !HasAuthority()) return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	GiveStartupAbilities();
}

void ATS_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
}