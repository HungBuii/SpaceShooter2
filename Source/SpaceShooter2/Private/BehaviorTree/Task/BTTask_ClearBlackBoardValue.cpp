// Copyright by Hungne


#include "BehaviorTree/Task/BTTask_ClearBlackBoardValue.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackBoardValue::UBTTask_ClearBlackBoardValue()
{
	NodeName = TEXT("Clear BlackBoard Value");
}

EBTNodeResult::Type UBTTask_ClearBlackBoardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard)
	{
		Blackboard->ClearValue(GetSelectedBlackboardKey());
	}
	
	return EBTNodeResult::Succeeded;
}
