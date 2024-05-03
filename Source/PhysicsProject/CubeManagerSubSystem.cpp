// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeManagerSubSystem.h"
#include "Components/StaticMeshComponent.h"


void UCubeManagerSubSystem::SpawnCube(FVector SpawnLocation, FRotator SpawnRotation)
{
	FString AssetPath = "/Game/Blueprints/EnvironmentObjs/BP_Cube.BPCube";
	UWorld* World = GetWorld();
	UObject* Obj = LoadObject <UObject>(nullptr, *AssetPath);
	AActor* NewActor = World->SpawnActor<AActor>(Obj->GetClass(), SpawnLocation, SpawnRotation);
	UStaticMeshComponent* Mesh = NewActor->GetComponentByClass <UStaticMeshComponent>();

	if (Mesh) 
	{
		Mesh->SetSimulatePhysics(true);
		Mesh->SetMassOverrideInKg(NAME_None, 10);
		Mesh->SetLinearDamping(0.01);
		Mesh->SetAngularDamping(0.01);
		SpawnedActors.Add(NewActor);
	}
}

