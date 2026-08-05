// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

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
	
	void StartBehaviorTree();
};
