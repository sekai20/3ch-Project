#include "MovePlatform.h"

AMovePlatform::AMovePlatform()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    PrimaryActorTick.bCanEverTick = true;
}

void AMovePlatform::BeginPlay()
{
    Super::BeginPlay();

  
    StartLocation = GetActorLocation();
}

void AMovePlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector CurrentLocation = GetActorLocation();

    float DeltaMove = MoveSpeed * DeltaTime * Direction;

    CurrentLocation.X += DeltaMove;

    float Distance = CurrentLocation.X - StartLocation.X;

    if (FMath::Abs(Distance) >= MaxRange)
    {
        Direction *= -1;
    }

    SetActorLocation(CurrentLocation);
}