// The Sliders Game. Made by Alex Sinkin (C)

#include "UI/TS_BaseButton.h"

FReply UTS_BaseButton::NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent)
{
	ButtonIcon->SetVisibility(ESlateVisibility::Visible);
	return Super::NativeOnFocusReceived(InGeometry, InFocusEvent);
}

void UTS_BaseButton::NativeOnFocusLost(const FFocusEvent& InFocusEvent)
{
	ButtonIcon->SetVisibility(ESlateVisibility::Collapsed);
	Super::NativeOnFocusLost(InFocusEvent);
}
