// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CubeManagerSubSystem.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSPROJECT_API UCubeManagerSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public: 

	UFUNCTION(BlueprintCallable)
	void SpawnCube(FVector SpawnLocation, FRotator SpawnRotation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	TArray < AActor* > SpawnedActors;
	
};
