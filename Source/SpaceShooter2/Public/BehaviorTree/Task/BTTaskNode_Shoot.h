// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER2_API UBTTaskNode_Shoot : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask ( UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
