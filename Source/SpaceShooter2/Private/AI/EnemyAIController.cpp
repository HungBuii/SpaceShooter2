// Copyright by Hungne


#include "AI/EnemyAIController.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

void AEnemyAIController::StartBehaviorTree()
{
	RunBehaviorTree(EnemyAIBehaviorTree);
}
