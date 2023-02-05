// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "SanityMananger.h"
#include "LightClass.generated.h"

UCLASS()
class CORDOBAGAMEJAM_API ALightClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightClass();
	ASanityMananger* Mananger;
	UPROPERTY(EditAnywhere, category = "SphereCollider")
	float RadioColider;

	void ReceiveActorBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void ReceiveActorEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(EditAnywhere, Category = "Changeables")
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, category = "SphereCollider")
		USphereComponent* Sphere;

	UFUNCTION(BlueprintCallable)
		void Goober();

	UFUNCTION(BlueprintCallable)
		void NotGoober();

	ASanityMananger* GetMananger();

		protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
