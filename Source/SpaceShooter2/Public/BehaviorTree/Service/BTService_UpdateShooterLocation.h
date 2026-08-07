// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_UpdateShooterLocation.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER2_API UBTService_UpdateShooterLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_UpdateShooterLocation();
	
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
