// Copyright by Hungne


#include "GameMode/ShooterGameMode.h"

#include "AI/EnemyAIController.h"
#include "Kismet/GameplayStatics.h"

AShooterGameMode::AShooterGameMode()
{
}

void AShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> EnemyAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyAIController::StaticClass(), EnemyAIActors);

	for (AActor* EnemyAIActor : EnemyAIActors)
	{
		if (AEnemyAIController* EnemyAI = Cast<AEnemyAIController>(EnemyAIActor))
		{
			EnemyAI->StartBehaviorTree();
		}
	}
}
