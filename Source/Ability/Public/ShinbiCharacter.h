// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ShinbiCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;

UCLASS()
class ABILITY_API AShinbiCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShinbiCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	void Attack();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category = Attack)
	UAnimMontage* AttackAnimMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;
};
