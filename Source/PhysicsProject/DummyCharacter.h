// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DummyCharacter.generated.h"

UCLASS()
class PHYSICSPROJECT_API ADummyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADummyCharacter();

	//Impulse
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ShootDistance = 1000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ImpulseIntensity = 10000;

	//Force
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ForceIntensity = 1000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void Shoot();

	UFUNCTION(BlueprintCallable)
	void ShootForce();

};
