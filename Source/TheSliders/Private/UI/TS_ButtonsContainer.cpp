// The Sliders Game. Made by Alex Sinkin (C)

#include "UI/TS_ButtonsContainer.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/VerticalBoxSlot.h"
#include "UI/TS_BaseButton.h"

DEFINE_LOG_CATEGORY_STATIC(LogButtonsContainer, Log, All);

void UTS_ButtonsContainer::NativePreConstruct()
{
	Super::NativePreConstruct();
	InitializeButtons(ButtonConfigs);
}

void UTS_ButtonsContainer::NativeConstruct()
{
	Super::NativeConstruct();
}

void UTS_ButtonsContainer::InitializeButtons(TArray<FMenuButtonConfig> InConfigs)
{
	if (!ButtonsContainer || !ButtonClass)
	{
		UE_LOG(LogButtonsContainer, Warning, TEXT("InitializeButtons --- !MenuContainer || !ButtonClass"))
		return;
	}
 
	ButtonsContainer->ClearChildren();
 
	for (const FMenuButtonConfig& Config : InConfigs)
	{
		UTS_BaseButton* NewButton = CreateWidget<UTS_BaseButton>(this, ButtonClass);
		if (!NewButton)
		{
			UE_LOG(LogButtonsContainer, Warning, TEXT("InitializeMenu --- !NewButton"))
			return;
		}
		
		NewButton->SetButtonText(Config.Label);
		NewButton->SetButtonTextStyle(Config.TextStyle);
		NewButton->SetButtonAction(Config.Action);
		NewButton->SetButtonIcon(Config.Icon);
		
		NewButton->OnClicked().AddUObject(this, &UTS_ButtonsContainer::OnButtonClicked, Config.Action);
		
		UPanelSlot* NewSlot = ButtonsContainer->AddChild(NewButton);
		
		if (UVerticalBoxSlot* VertSlot = Cast<UVerticalBoxSlot>(NewSlot))
		{
			VertSlot->SetHorizontalAlignment(HAlign_Fill);
			VertSlot->SetPadding(SlotPadding);
		}
		else if (UHorizontalBoxSlot* HorizSlot = Cast<UHorizontalBoxSlot>(NewSlot))
		{
			HorizSlot->SetVerticalAlignment(VAlign_Fill);
			HorizSlot->SetPadding(SlotPadding);
		}
	}
}

UWidget* UTS_ButtonsContainer::GetFirstButton() const
{
	UE_LOG(LogButtonsContainer, Log, TEXT("First button retrieved: Name='%s', Class='%s'"), 
			   *ButtonsContainer->GetChildAt(0)->GetName(), 
			   *ButtonsContainer->GetChildAt(0)->GetClass()->GetName());
	return (ButtonsContainer && ButtonsContainer->GetChildrenCount() > 0) ? ButtonsContainer->GetChildAt(0) : nullptr;
}

void UTS_ButtonsContainer::OnButtonClicked(EButtonAction Action)
{
	UE_LOG(LogButtonsContainer, Log, TEXT("OnButtonClicked"))
	OnActionSelected.Broadcast(Action);
}