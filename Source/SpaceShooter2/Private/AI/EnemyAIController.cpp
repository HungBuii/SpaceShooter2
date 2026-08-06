// Copyright by Hungne


#include "AI/EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy/EnemyCharacter.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

void AEnemyAIController::StartBehaviorTree(AShooterCharacter* Player)
{
	if (EnemyAIBehaviorTree)
	{
		EnemyCharacter = Cast<AEnemyCharacter>(GetPawn());
		
		if (Player)
		{
			ShooterCharacter = Player;
		}
		
		RunBehaviorTree(EnemyAIBehaviorTree);
		
		GetBlackboardComponent()->SetValueAsVector("StartLocation", EnemyCharacter->GetActorLocation());
		
	}
	
}
