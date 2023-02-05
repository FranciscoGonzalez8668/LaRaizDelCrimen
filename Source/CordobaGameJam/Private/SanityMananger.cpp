// Fill out your copyright notice in the Description page of Project Settings.


#include "SanityMananger.h"

// Sets default values
ASanityMananger::ASanityMananger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ASanityMananger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASanityMananger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASanityMananger::LifeReducer() {
	GetWorld()->GetTimerManager().SetTimer(myTimer, this, &ASanityMananger::Reducer, timeDamage, obscure);
}

void ASanityMananger::Reducer() {
	sanity -= damageAmount;
}

void ASanityMananger::ChangeIcon() {

	/*if (getPawn(sanity) <= 20) {
		//Pick Critical
	}
	else {
		if (getPawn(sanity) <= 60) {
			//pick Low
		}
		else
		{
			//Pick Full
		}
	}*/
}