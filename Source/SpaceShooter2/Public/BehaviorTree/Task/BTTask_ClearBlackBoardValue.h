// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ClearBlackBoardValue.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER2_API UBTTask_ClearBlackBoardValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_ClearBlackBoardValue();
	
	virtual EBTNodeResult::Type ExecuteTask ( UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
