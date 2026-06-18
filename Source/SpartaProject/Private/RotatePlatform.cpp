// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatePlatform.h"

ARotatePlatform::ARotatePlatform()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
		
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f; 
}


void ARotatePlatform::BeginPlay()
{
	Super::BeginPlay();
	
	OnItemPickedUp();
}
		
void ARotatePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{		
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

void ARotatePlatform::ResetActorPosition()
{
	// (0, 0, 0) 위치로 되돌립니다.
	SetActorLocation(FVector::ZeroVector);
}

float ARotatePlatform::GetRotationSpeed() const
{
	return RotationSpeed;
}