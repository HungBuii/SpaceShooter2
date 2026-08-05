// Copyright by Hungne


#include "BehaviorTree/Service/BTService_ShooterLocationIfSeen.h"

#include "AI/EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Character/Shooter/ShooterCharacter.h"

UBTService_ShooterLocationIfSeen::UBTService_ShooterLocationIfSeen()
{
	NodeName = TEXT("Update Shooter Location If Seen");
}

void UBTService_ShooterLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
                                                float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	AEnemyAIController* OwnerAIController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	AShooterCharacter* ShooterCharacter = OwnerAIController->ShooterCharacter;
	UBlackboardComponent* Blackboard = OwnerAIController->GetBlackboardComponent();

	if (OwnerAIController && ShooterCharacter && Blackboard)
	{
		if (OwnerAIController->LineOfSightTo(ShooterCharacter))
		{
			Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), ShooterCharacter->GetActorLocation());
			OwnerAIController->SetFocus(ShooterCharacter);
		}
	}
}
