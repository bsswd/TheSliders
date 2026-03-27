// The Sliders Game. Made by Alex Sinkin (C)


#include "Core/TS_PlayerController.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PaperFlipbookComponent.h"
#include "Characters/TS_PlayerCharacter.h"
#include "GameFramework/Character.h"
#include "GameplayTags/TSTags.h"

ATS_BaseCharacter* ATS_PlayerController::GetBaseCharacter() const
{
	APawn* CharacterPawn = GetPawn();	
	return Cast<ATS_BaseCharacter>(CharacterPawn);	
}

ATS_PlayerCharacter* ATS_PlayerController::GetPlayerCharacter() const
{
	APawn* CharacterPawn = GetPawn();
	return Cast<ATS_PlayerCharacter>(CharacterPawn);
}

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
	GetBaseCharacter()->PlayAttackAnimation();
	
	
	
	
	
}

void ATS_PlayerController::SelectDoc()
{
	ActivateAbility(TSTags::TSAbilities::Player::DocSelect);
}

void ATS_PlayerController::SelectBald()
{
	ActivateAbility(TSTags::TSAbilities::Player::BaldSelect);
}

void ATS_PlayerController::SelectLaw()
{
	ActivateAbility(TSTags::TSAbilities::Player::LawSelect);
}

void ATS_PlayerController::SelectSazz()
{
	ActivateAbility(TSTags::TSAbilities::Player::SazzSelect);
}

void ATS_PlayerController::SelectJoka()
{
	ActivateAbility(TSTags::TSAbilities::Player::JokaSelect);
}