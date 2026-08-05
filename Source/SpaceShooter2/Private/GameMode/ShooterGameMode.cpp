// Copyright by Hungne


#include "GameMode/ShooterGameMode.h"

#include "AI/EnemyAIController.h"
#include "Character/Shooter/ShooterCharacter.h"
#include "Kismet/GameplayStatics.h"

AShooterGameMode::AShooterGameMode()
{
}

void AShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	AShooterCharacter* Player = Cast<AShooterCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	TArray<AActor*> EnemyAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyAIController::StaticClass(), EnemyAIActors);

	for (AActor* EnemyAIActor : EnemyAIActors)
	{
		if (AEnemyAIController* EnemyAI = Cast<AEnemyAIController>(EnemyAIActor))
		{
			EnemyAI->StartBehaviorTree(Player);
		}
	}
}
