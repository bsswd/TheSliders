// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "TS_BaseWidget.h"
#include "Data/TS_ButtonData.h"
#include "TS_ButtonsContainer.generated.h"

class UTS_BaseButton;
class UPanelWidget;
	
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMenuActionSelected, EButtonAction, Action);

UCLASS(Abstract, Blueprintable)
class THESLIDERS_API UTS_ButtonsContainer : public UTS_BaseWidget
{
	GENERATED_BODY()
	
public:
	
    /** PROPERTIES **/
    	
    UPROPERTY(BlueprintAssignable, Category = "TS|Settings")
	FOnMenuActionSelected OnActionSelected;
    	
	UPROPERTY(EditAnywhere, Category = "TS|Settings")
	TArray<FMenuButtonConfig> ButtonConfigs;
    
	
	/** FUNCTIONS **/
    	
	UFUNCTION(BlueprintCallable, Category = "TS|Settings")
	void InitializeButtons(TArray<FMenuButtonConfig> InConfigs);
    			
	UFUNCTION(BlueprintCallable, Category = "TS|Settings")
	UWidget* GetFirstButton() const;
    	
    	
protected:
	
	/** PROPERTIES **/
    	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPanelWidget> ButtonsContainer;
    	
	UPROPERTY(EditAnywhere, Category = "TS|Settings")
	FMargin SlotPadding = FMargin(0.f, 0.f);
    	
	UPROPERTY(EditAnywhere, Category = "TS|Settings")
	TSubclassOf<UTS_BaseButton> ButtonClass;
    
	
	/** FUNCTIONS **/
    	
	UFUNCTION()
	void OnButtonClicked(EButtonAction Action);
     
	UFUNCTION(BlueprintImplementableEvent, Category = "TS|MenuEvents")
	void OnMenuActionSelected(EButtonAction Action);
    	
    	
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
};

