// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/CharacterStats.h"
#include "StatsComponent.generated.h"

class ATS_BaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THESLIDERS_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UStatsComponent();
	
	/** PROPERTIES **/

	UPROPERTY(VisibleAnywhere, Category = "TS|Data")
	TObjectPtr<ATS_BaseCharacter> OwnerCharacter;
	
	UPROPERTY(EditAnywhere, Category = "TS|Data")
	UDataTable* StatsTable;
    
	UPROPERTY(VisibleAnywhere, Category = "TS|Data")
	FCharacterStats CharacterStats;
	
	UPROPERTY(EditAnywhere, Category = "TS|Data")
	bool bPrintStatsDebug = false;

	
	/** FUNCTIONS **/
	
	void ApplyStats(FName RowName);
	
	
protected:

	virtual void BeginPlay() override;
	
	
private:
	
	static void PrintDebugStats(FName CharacterName, FCharacterStats Stats, const bool bPrint);
};