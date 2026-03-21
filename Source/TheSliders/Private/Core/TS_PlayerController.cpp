// The Sliders Game. Made by Alex Sinkin (C)


#include "Core/TS_PlayerController.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "GameplayTags/TSTags.h"

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
	EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &ThisClass::Attack);
	EnhancedInputComponent->BindAction(SelectDocAction, ETriggerEvent::Started, this, &ThisClass::SelectDoc);
	EnhancedInputComponent->BindAction(SelectBaldAction, ETriggerEvent::Started, this, &ThisClass::SelectBald);
	EnhancedInputComponent->BindAction(SelectLawAction, ETriggerEvent::Started, this, &ThisClass::SelectLaw);
	EnhancedInputComponent->BindAction(SelectSazzAction, ETriggerEvent::Started, this, &ThisClass::SelectSazz);
	EnhancedInputComponent->BindAction(SelectJokaAction, ETriggerEvent::Started, this, &ThisClass::SelectJoka);
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

void ATS_PlayerController::ActivateAbility(const FGameplayTag& AbilityTag) const
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn());
	if (!IsValid(ASC)) return;
	
	ASC->TryActivateAbilitiesByTag(AbilityTag.GetSingleTagContainer());	
}

void ATS_PlayerController::Attack()
{
	// Need to check what character is active, because different types of attacks
	
	ActivateAbility(TSTags::TSAbilities::Player::MeleeAttack);
}

void ATS_PlayerController::SelectDoc()
{
	UE_LOG(LogTemp, Warning, TEXT("Doc selected"))
}

void ATS_PlayerController::SelectBald()
{
	UE_LOG(LogTemp, Warning, TEXT("Bald selected"))
}

void ATS_PlayerController::SelectLaw()
{
	UE_LOG(LogTemp, Warning, TEXT("Law selected"))
}

void ATS_PlayerController::SelectSazz()
{
	UE_LOG(LogTemp, Warning, TEXT("Sazz selected"))
}

void ATS_PlayerController::SelectJoka()
{
	UE_LOG(LogTemp, Warning, TEXT("Joka selected"))
}
