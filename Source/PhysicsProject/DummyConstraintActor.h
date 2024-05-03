// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "DummyConstraintActor.generated.h"

UCLASS()
class PHYSICSPROJECT_API ADummyConstraintActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADummyConstraintActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Component1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Component2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Component3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere)
	UPhysicsConstraintComponent* Constraint;

	UPROPERTY(VisibleAnywhere)
	UPhysicsConstraintComponent* Constraint2;

};
