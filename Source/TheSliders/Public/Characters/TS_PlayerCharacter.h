// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "Characters/TS_BaseCharacter.h"
#include "TS_PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class THESLIDERS_API ATS_PlayerCharacter : public ATS_BaseCharacter
{
	GENERATED_BODY()

public:

	ATS_PlayerCharacter();
	
	/** PROPERTIES **/
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TS|Movement")
    TMap<ESpeed, float> SpeedMap;
        
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TS|Movement")
    TMap<EJump, float> JumpMap;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TS|Movement")
	TMap<ERange, float> AttackRangeMap;
	
	
	/** FUNCTIONS **/
	
	FORCEINLINE int32 GetLivesCount() {return LivesCount;}

	virtual void ApplyStats(FName RowName) override;
	
private:

	/** PROPERTIES **/
	
	UPROPERTY(VisibleAnywhere, Category = "TS|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, Category = "TS|Camera")
	TObjectPtr<UCameraComponent> SideCamera;

	UPROPERTY(VisibleAnywhere)
	int32 LivesCount = 3;
};