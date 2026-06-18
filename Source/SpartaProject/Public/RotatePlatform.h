#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatePlatform.generated.h"



UCLASS()
class SPARTAPROJECT_API ARotatePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ARotatePlatform();

protected:
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatePlatform|Components")
	

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;
	
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "RotatePlatform|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category = "RotatePlatform|Properties")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "RotatePlatform|Event")
	void OnItemPickedUp();
};
