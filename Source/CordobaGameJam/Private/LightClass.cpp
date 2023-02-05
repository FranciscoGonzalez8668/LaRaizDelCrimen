// Fill out your copyright notice in the Description page of Project Settings.


#include "LightClass.h"
#include "SanityMananger.h"
#include "Kismet/GameplayStatics.h"
#include "CBJGameInstance.h"
#include "Components/SphereComponent.h"

// Sets default values
ALightClass::ALightClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	Sphere = CreateDefaultSubobject<USphereComponent>(FName("Sphere"));
	Sphere->InitSphereRadius(RadioColider);
	Sphere->SetGenerateOverlapEvents(true);
	Sphere->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Sphere->SetupAttachment(RootComponent);
	Sphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ALightClass::ReceiveActorBeginOverlap);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ALightClass::ReceiveActorEndOverlap);
	Sphere->bHiddenInGame = false;
}

// Called when the game starts or when spawned
void ALightClass::BeginPlay()
{
	Super::BeginPlay();

}
void ALightClass::ReceiveActorBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
	
	}
	void ALightClass::ReceiveActorEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
		Mananger = GetMananger();
		if (Mananger == nullptr)
		{
			return;
		}
		Mananger->set_obscure(true);
		Mananger->LifeReducer();
	}
	void ALightClass::Goober() {    //A Goober le gusta apager y prender la luz, PERO NO LE GUSTAN LOS NULL POINTERS
		Mananger = GetMananger();
		if (Mananger == nullptr)
		{
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("Goober"));
		Mananger->set_obscure(false);
		Mananger->LifeReducer();
	}
	void ALightClass::NotGoober() {  //Goober Dice "Time to play" y apaga la loz
		Mananger = GetMananger();
		if (Mananger == nullptr)
		{
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("NotGoober"));
		Mananger->set_obscure(true);
		Mananger->LifeReducer();

	}

	ASanityMananger* ALightClass::GetMananger() {
		if (Mananger == nullptr)
		{
			UCBJGameInstance* gameInstance = Cast<UCBJGameInstance>(GetGameInstance());
			Mananger = gameInstance->GetMananger();
		}

		return Mananger;
	}
// Called every frame
void ALightClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

