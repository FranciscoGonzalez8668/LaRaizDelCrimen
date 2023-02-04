// Fill out your copyright notice in the Description page of Project Settings.


#include "PickyObject.h"

// Sets default values
APickyObject::APickyObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (isBad) {
		realDamageMade = damageMade;
	}
	else {
		realDamageMade = (-1) * healingMade;
	}
}

// Called when the game starts or when spawned
void APickyObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickyObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


