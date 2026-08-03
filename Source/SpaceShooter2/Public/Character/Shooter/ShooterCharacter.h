// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "ShooterCharacter.generated.h"

class AGun;
struct FInputActionValue;
class UInputAction;
/**
 * 
 */
UCLASS()
class SPACESHOOTER2_API AShooterCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:

	/** Constructor */
	AShooterCharacter();	
	
protected:

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* ShootAction;
	
	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);
	
	/** Called for looking input */
	void Look(const FInputActionValue& Value);
	
	/** Called for shoot input */
	void Shoot(const FInputActionValue& Value);
	
public:
	
	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);
	
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);
	
	/** Weapon */
	UPROPERTY(EditAnywhere, Category="Gun")
	TSubclassOf<AGun> GunClass;
	TObjectPtr<AGun> Gun; 
	
};
