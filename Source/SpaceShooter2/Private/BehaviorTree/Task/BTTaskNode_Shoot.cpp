// Copyright by Hungne


#include "BehaviorTree/Task/BTTaskNode_Shoot.h"

#include "AI/EnemyAIController.h"
#include "Enemy/EnemyCharacter.h"

EBTNodeResult::Type UBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	AEnemyAIController* OwnerAIController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	
	if (OwnerAIController)
	{
		AShooterCharacter* ShooterCharacter = OwnerAIController->ShooterCharacter;
		AEnemyCharacter* EnemyCharacter = OwnerAIController->EnemyCharacter;
		
		if (ShooterCharacter && EnemyCharacter)
		{
			EnemyCharacter->Shoot();
			return EBTNodeResult::Succeeded;
		}
	}
	
	return EBTNodeResult::Failed;
}
