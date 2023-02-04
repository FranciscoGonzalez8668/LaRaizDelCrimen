// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PickObject.generated.h"


UCLASS(BlueprintType)
class CORDOBAGAMEJAM_API APickObject : public AActor
{
	GENERATED_BODY()
	void Spawn();
	int realDamageMade = 1;			//da;o real hecho, Puede ser negativo o positivo segun el tipo de enemigo que sea
	


public:
	APickObject();

	UPROPERTY(EditAnyWhere, Category = CollisionComp)
	UBoxComponent* Box_Trigger_Component = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Assets")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, category = "Hostile")
		unsigned int damageMade = 1;	//El valor publico de da;oo es siempre positivo ya que marca la cantidad a hacer
	UPROPERTY(EditAnywhere, category = "Hostile")
		unsigned int healingMade = 1;	//no puede ser negativo 
	UPROPERTY(EditAnywhere, category = "Hostile")
		bool isBad = false;
	UPROPERTY(EditAnywhere, category = "Messages")
		FString pickMessage = "Default";

	int GetDamage() {
		return realDamageMade;
	}
	FString GetPickMessage() {
		return pickMessage;
	}
	
	UFUNCTION()
	void PickUp(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
