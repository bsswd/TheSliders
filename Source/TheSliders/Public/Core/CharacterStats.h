// The Sliders Game. Made by Alex Sinkin (C)

#pragma once
 
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharacterStats.generated.h"
 

UENUM(BlueprintType)
enum class EWeight : uint8
{
	Light  UMETA(DisplayName = "Light"),
	Middle UMETA(DisplayName = "Middle"),
	Heavy  UMETA(DisplayName = "Heavy")
};


UENUM(BlueprintType)
enum class EJump : uint8
{
	None   UMETA(DisplayName = "None"),
	Middle UMETA(DisplayName = "Middle"),
	High   UMETA(DisplayName = "High")
};
 

UENUM(BlueprintType)
enum class ESpeed : uint8
{
	Slow   UMETA(DisplayName = "Slow"),
	Middle UMETA(DisplayName = "Middle"),
	Fast   UMETA(DisplayName = "Fast")
};
 

UENUM(BlueprintType)
enum class ERange : uint8
{
	Close  UMETA(DisplayName = "Close"),
	Middle UMETA(DisplayName = "Middle"),
	Far    UMETA(DisplayName = "Far")
};

UENUM(BlueprintType)
enum class EDamage : uint8
{
	Light  UMETA(DisplayName = "Light"),
	Middle UMETA(DisplayName = "Middle"),
	Strong    UMETA(DisplayName = "Strong")
};
 

USTRUCT(BlueprintType)
struct FCharacterStats : public FTableRowBase
{
	GENERATED_BODY()
 
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats")
	float Health = 100.0f;
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats")
	ESpeed Speed = ESpeed::Middle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats")
	EJump Jump = EJump::Middle;
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats")
	EWeight Weight = EWeight::Middle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats")
	ERange Range = ERange::Middle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats")
	EDamage Damage = EDamage::Middle;
};