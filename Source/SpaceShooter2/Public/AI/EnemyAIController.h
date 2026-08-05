// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class AShooterCharacter;
class AEnemyCharacter;
/**
 * 
 */
UCLASS()
class SPACESHOOTER2_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyAIBehaviorTree;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AEnemyCharacter> EnemyCharacter;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AShooterCharacter> ShooterCharacter;
	
	void StartBehaviorTree(AShooterCharacter* Player);
};
