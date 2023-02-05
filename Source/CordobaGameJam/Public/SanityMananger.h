// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SanityMananger.generated.h"

UCLASS()
class CORDOBAGAMEJAM_API ASanityMananger : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	FTimerHandle myTimer;

	UPROPERTY(EditAnywhere, Category = "sanity")
	float damageAmount = 1;

	UPROPERTY(EditAnywhere, Category = "sanity")
	float timeDamage = 1;

	
public:	
	// Sets default values for this actor's properties
	ASanityMananger();
	void ChangeIcon();
	UPROPERTY(EditDefaultsOnly, Category = "sanity")
	float sanity = 100;
	bool obscure = false;
	void LifeReducer();
	void Reducer();
	void set_obscure(bool isObscure) { //Set si character en luz
		obscure = isObscure;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
