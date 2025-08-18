// Fill out your copyright notice in the Description page of Project Settings.


#include "ShinbiPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "ShinbiCharacter.h"

AShinbiPlayerController::AShinbiPlayerController()
{
	
}

void AShinbiPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AShinbiPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// 获取增强输入组件
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// 绑定移动
		if (MoveAction)
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AShinbiPlayerController::Move);
		}
        
		// 绑定视角控制
		if (LookAction)
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AShinbiPlayerController::Look);
		}
        
		// 绑定跳跃
		if (JumpAction)
		{
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AShinbiPlayerController::Jump);
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AShinbiPlayerController::StopJumping);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AShinbiPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ShinbiCharacter = Cast<AShinbiCharacter>(InPawn);
}

void AShinbiPlayerController::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (ShinbiCharacter)
	{
		// find out which way is forward
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		ShinbiCharacter->AddMovementInput(ForwardDirection, MovementVector.Y);
		ShinbiCharacter->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AShinbiPlayerController::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (ShinbiCharacter)
	{
		// add yaw and pitch input to controller
		ShinbiCharacter->AddControllerYawInput(LookAxisVector.X);
		ShinbiCharacter->AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AShinbiPlayerController::Jump()
{
	if (ShinbiCharacter)
	{
		ShinbiCharacter->Jump();
	}
}

void AShinbiPlayerController::StopJumping()
{
	if (ShinbiCharacter)
	{
		ShinbiCharacter->StopJumping();
	}
}



