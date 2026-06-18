#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePlatform.generated.h"

UCLASS()
class SPARTAPROJECT_API AMovePlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovePlatform();

protected:
    virtual void BeginPlay() override;
    USceneComponent* SceneRoot;
    UStaticMeshComponent* StaticMeshComp;

public:
    virtual void Tick(float DeltaTime) override;

private:
   
    FVector StartLocation;

   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    float MoveSpeed = 100.f;

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    float MaxRange = 300.f;

    
    int32 Direction = 1;
};