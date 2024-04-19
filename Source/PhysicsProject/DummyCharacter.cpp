// Fill out your copyright notice in the Description page of Project Settings.


#include "DummyCharacter.h"

// Sets default values
ADummyCharacter::ADummyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADummyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADummyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADummyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ADummyCharacter::Shoot(const float ShootDist, const float ImpulseIntensity)
{
	UWorld* World = GetWorld();
	FVector StartPoint = GetActorLocation();
	FVector EndPoint = StartPoint + GetActorForwardVector() * ShootDist;
	FHitResult HitResult;
	bool bHitted = World->LineTraceSingleByChannel(HitResult, StartPoint, EndPoint, ECollisionChannel::ECC_Visibility);

	if (bHitted)
	{
		UPrimitiveComponent* HitComponent = HitResult.GetComponent();
		if (HitComponent)
		{
			if (HitComponent->IsSimulatingPhysics())
			{
				FVector Impulse = EndPoint - StartPoint;
				Impulse.Normalize();
				Impulse *= ImpulseIntensity;
				HitComponent->AddImpulseAtLocation(Impulse, HitResult.ImpactPoint);
				return true;
			}
		}
	}
	return false;
}

