// The Sliders Game. Made by Alex Sinkin (C)

#pragma once
 
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharacterStats.generated.h"

class UPaperFlipbook;

UENUM(BlueprintType)
enum class EWeight : uint8 
{
	Light  UMETA(DisplayName = "Light"), // Платформа поднимается, струна выстрелиивает (если была натянута)
	Middle UMETA(DisplayName = "Middle"), // Платформа и струна не реагируют
	Heavy  UMETA(DisplayName = "Heavy") // Платформа опускается, струна натягивается
};
 

USTRUCT(BlueprintType)
struct FCharacterStats : public FTableRowBase
{
	GENERATED_BODY()
 
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats")
	float Health = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Movement")
	EWeight Weight = EWeight::Middle;
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Movement")
	float MovementSpeed = 300.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Movement")
	float JumpHeight = 300.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Attack")
	float AttackRange = 300.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Attack")
	float AttackDamage = 10.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Attack")
	int32 AttackFrameIndex = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Flipbooks")
	TObjectPtr<UPaperFlipbook> IdleFlipbook = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Flipbooks")
    TObjectPtr<UPaperFlipbook> WalkFlipbook = nullptr;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Flipbooks")	
	TObjectPtr<UPaperFlipbook> JumpFlipbook = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Stats|Flipbooks")
	TObjectPtr<UPaperFlipbook> AttackFlipbook = nullptr;
};