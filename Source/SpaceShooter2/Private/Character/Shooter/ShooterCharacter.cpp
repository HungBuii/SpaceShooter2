// Copyright by Hungne


#include "Character/Shooter/ShooterCharacter.h"

#include "EnhancedInputComponent.h"

AShooterCharacter::AShooterCharacter()
{
	
}

void AShooterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AShooterCharacter::Move);
	}
}

void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AShooterCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	
	// UE_LOG(LogTemp, Display, TEXT("MovementVector: %s"), *MovementVector.ToString());
	
	// route the input
	DoMove(MovementVector.X, MovementVector.Y);
}

void AShooterCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}
