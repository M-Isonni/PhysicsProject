// Fill out your copyright notice in the Description page of Project Settings.


#include "DummyConstraintActor.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

// Sets default values
ADummyConstraintActor::ADummyConstraintActor()
{
    // Set up root component
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    // Create two static mesh components
    UStaticMesh* StaticMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/EngineMeshes/Sphere.Sphere"));
    //UPhysicalMaterial* PhysMaterial = nullptr;
    FString MaterialPath = "/Engine/EngineMaterials/PhysMat_Rubber.PhysMat_Rubber";
    UPhysicalMaterial* PhysMaterial = LoadObject<UPhysicalMaterial>(nullptr, *MaterialPath);

    Component1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Component1"));
    Component1->SetupAttachment(RootComponent);
    Component1->SetRelativeLocation(FVector(0.f, 0.f, 0.f)); // Adjust location if needed    
    Component1->SetStaticMesh(StaticMesh);
    Component1->SetSimulatePhysics(true);
    Component1->SetMassOverrideInKg(NAME_None, 100);
    Component1->SetPhysMaterialOverride(PhysMaterial);

    Component2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Component2"));
    Component2->SetupAttachment(RootComponent);
    Component2->SetRelativeLocation(FVector(350.0f, 0.f, 0.f)); // Adjust location if needed
    Component2->SetStaticMesh(StaticMesh);
    Component2->SetSimulatePhysics(true);
    Component2->SetMassOverrideInKg(NAME_None, 1000);
    Component2->SetPhysMaterialOverride(PhysMaterial);

    //Third static mesh init
    Component3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Component3"));
    Component3->SetupAttachment(RootComponent);
    Component3->SetRelativeLocation(FVector(700.0f, 0.f, 0.f)); // Adjust location if needed
    Component3->SetStaticMesh(StaticMesh);
    Component3->SetSimulatePhysics(true);
    Component3->SetMassOverrideInKg(NAME_None, 10);
    Component3->SetPhysMaterialOverride(PhysMaterial);


    // Create physics constraint component
    Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("Constraint"));
    Constraint->SetupAttachment(RootComponent);
    Constraint->SetConstrainedComponents(Component1, NAME_None, Component2, NAME_None);

    Constraint2 = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("Constraint2"));
    Constraint2->SetupAttachment(RootComponent);
    Constraint2->SetConstrainedComponents(Component2, NAME_None, Component3, NAME_None);

    //Constraint Settings
    //Constraint->SetDisableCollision(false);
    //Constraint->bUseAttachParentBound = true;
    //Constraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Limited, 50);
    //Constraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Limited, 100);
    //Constraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Limited,500);
    //Constraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Free, 0.0);
    //Constraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0.0);
    //Constraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Limited,100.0);

}

// Called when the game starts or when spawned
void ADummyConstraintActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADummyConstraintActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

