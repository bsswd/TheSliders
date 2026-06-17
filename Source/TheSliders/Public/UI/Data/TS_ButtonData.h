// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "TS_ButtonData.generated.h"

UENUM(BlueprintType)
enum class EButtonAction : uint8
{
	NewGame,
	Continue,
	Quit
};

USTRUCT(BlueprintType)
struct FMenuButtonConfig
{
	GENERATED_BODY()
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EButtonAction Action = EButtonAction::NewGame;
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Label;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UCommonTextStyle> TextStyle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> Icon;
};