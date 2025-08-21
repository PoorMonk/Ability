// Fill out your copyright notice in the Description page of Project Settings.


#include "ShinbiCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AShinbiCharacter::AShinbiCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->TargetArmLength = 300;
	SpringArmComponent->SocketOffset = FVector(0, 0, 60);	// 
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AShinbiCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShinbiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShinbiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	if (Controller != nullptr)
	{
		
	}
}

UAbilitySystemComponent* AShinbiCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AShinbiCharacter::Attack()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance != nullptr)
	{
		AnimInstance->Montage_Play(AttackAnimMontage);
	}
}

