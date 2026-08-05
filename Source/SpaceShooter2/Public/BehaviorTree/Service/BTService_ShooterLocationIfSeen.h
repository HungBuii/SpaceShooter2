// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_ShooterLocationIfSeen.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER2_API UBTService_ShooterLocationIfSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_ShooterLocationIfSeen();
	
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
