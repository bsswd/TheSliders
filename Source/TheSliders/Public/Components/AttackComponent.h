// The Sliders Game. Made by Alex Sinkin (C)

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"

#define COLLISION_ENEMY ECC_GameTraceChannel1

DEFINE_LOG_CATEGORY_STATIC(LogAttackComponent, Log, All)


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THESLIDERS_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UAttackComponent();
	
	/** PROPERTIES **/
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Attack|Settings")
	float Range = 150.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Attack|Settings")
	FVector2D TraceOffset = FVector2D(0.0f, 0.0f);
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Attack|Settings")
	FVector2D AttackDirection = FVector2D(1.0f, 0.0f);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TS|Attack|Debug")
	bool bDrawDebug = true;
	
	FTimerHandle CheckAttackFrameTimerHandle;
	
	
	/** FUNCTIONS **/
	
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void PerformAttack();
 
	
protected:
	
	/** PROPERTIES **/
	
	FVector GetCalculatedDirection() const;	
	
	
	/** FUNCTIONS **/
	
	virtual void BeginPlay() override;
	
	
private:
	
	void CheckAttackFrameIndex();
};