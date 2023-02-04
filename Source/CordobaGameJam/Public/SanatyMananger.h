// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SanatyMananger.generated.h"

UCLASS()
class CORDOBAGAMEJAM_API ASanatyMananger : public AActor
{
	GENERATED_BODY()
	void LifeReducer();
	void Reducer();
	UPROPERTY()
		FTimerHandle myTimer;
	UPROPERTY(EditAnywhere, Category = "sanity")
		float damageAmount = 1;

	UPROPERTY(EditAnywhere, Category = "sanity")
		float timeDamage = 1;

	UPROPERTY(EditDefaultsOnly, Category = "sanity")
		float sanity = 100;

	UFUNCTION()
		void ChangeIcon();
	
public:	
	// Sets default values for this actor's properties
	ASanatyMananger();
	void set_obscure(bool isObscure) { //Set si character en luz
		obscure = isObscure;
	}
	UPROPERTY(EditDefaultsOnly, Category = "Obscurity")
		bool obscure = true;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
