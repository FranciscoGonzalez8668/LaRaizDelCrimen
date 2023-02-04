// Fill out your copyright notice in the Description page of Project Settings.
//Bendi UI
#include "SanityBar.h"


// Sets default values for this component's properties
USanityBar::USanityBar()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void USanityBar::BeginPlay()
{
	Super::BeginPlay();
	LowSanityEvent.AddDynamic(this,&USanityBar::ChangeIcon);

	// ...
	
}


// Called every frame
void USanityBar::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USanityBar::ChangeIcon() {

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
