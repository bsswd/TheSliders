// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CommonLazyImage.h"
#include "CommonTextBlock.h"
#include "Data/TS_ButtonData.h"
#include "UObject/Object.h"
#include "TS_BaseButton.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnButtonPressed, EButtonAction);

UCLASS(Abstract, Blueprintable)
class THESLIDERS_API UTS_BaseButton : public UCommonButtonBase
{
	GENERATED_BODY()
	
public:
	
	/** FUNCTIONS **/
	
	UFUNCTION(BlueprintCallable, Category = "TS|UI")
	void SetButtonText(const FText InText) { if (ButtonText) ButtonText->SetText(InText); }
	
	UFUNCTION(BlueprintCallable, Category = "TS|UI")
	void SetButtonTextStyle(const TSubclassOf<UCommonTextStyle> InStyle) { if (ButtonText) ButtonText->SetStyle(InStyle); }
	
	UFUNCTION(BlueprintCallable, Category = "TS|UI")
	void SetButtonIcon(const TSoftObjectPtr<UTexture2D> InIcon) { if (ButtonIcon) ButtonIcon->SetBrushFromLazyDisplayAsset(InIcon); };

	UFUNCTION(BlueprintImplementableEvent, Category = "TS|UI")
	void OnButtonPressed();
	
	void SetButtonAction(EButtonAction InAction) { MenuAction = InAction; }
	
	FOnButtonPressed OnButtonPressedDelegate;
	
	
protected:
	
	/** PROPERTIES **/
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> ButtonText;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCommonLazyImage> ButtonIcon;
	
	EButtonAction MenuAction;
	
	
	virtual FReply NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent) override;
	virtual void NativeOnFocusLost(const FFocusEvent& InFocusEvent) override;
};
