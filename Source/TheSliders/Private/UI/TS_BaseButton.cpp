// The Sliders Game. Made by Alex Sinkin (C)

#include "UI/TS_BaseButton.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseButton, Log, All);


void UTS_BaseButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	ButtonIcon->SetVisibility(ESlateVisibility::Collapsed);
}

void UTS_BaseButton::NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnAddedToFocusPath(InFocusEvent);
	ButtonIcon->SetVisibility(ESlateVisibility::Visible);
}

void UTS_BaseButton::NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnRemovedFromFocusPath(InFocusEvent);
	ButtonIcon->SetVisibility(ESlateVisibility::Collapsed);
}
