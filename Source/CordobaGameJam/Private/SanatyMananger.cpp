// Fill out your copyright notice in the Description page of Project Settings.


#include "SanatyMananger.h"

// Sets default values
ASanatyMananger::ASanatyMananger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASanatyMananger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASanatyMananger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ASanatyMananger::LifeReducer() {
	//UE_LOG(LogTemp, Warning, TEXT("Help"));
	GetWorld()->GetTimerManager().SetTimer(myTimer, this, &ASanatyMananger::Reducer, timeDamage, obscure);
}

void ASanatyMananger::Reducer() {
	//UE_LOG(LogTemp, Warning, TEXT("%f"), sanity);
	sanity -= damageAmount;
}

void ASanatyMananger::ChangeIcon() {

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


