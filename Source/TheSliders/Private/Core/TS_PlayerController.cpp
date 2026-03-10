// The Sliders Game. Made by Alex Sinkin (C)


#include "Core/TS_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

void ATS_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());	
	if (!IsValid(InputSubsystem)) return;
	
	for (UInputMappingContext* Context : InputMappingContexts)
	{
		InputSubsystem->AddMappingContext(Context, 0);
	}
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent)) return;
	
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered,this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started,this, &ThisClass::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed,this, &ThisClass::StopJumping);
	
}

void ATS_PlayerController::Move(const FInputActionValue& Value)
{
	const float MoveValue = Value.Get<float>();
 
	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(FVector(1.f, 0.f, 0.f), MoveValue);
	}
}

void ATS_PlayerController::Jump()
{
	if (ACharacter* ControlledCharacter = Cast<ACharacter>(GetPawn()))
	{
		ControlledCharacter->Jump();
	}
}

void ATS_PlayerController::StopJumping()
{
	if (ACharacter* ControlledCharacter = Cast<ACharacter>(GetPawn()))
	{
		ControlledCharacter->StopJumping();
	}
}