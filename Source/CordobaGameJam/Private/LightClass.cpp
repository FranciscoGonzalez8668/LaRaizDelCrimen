// Fill out your copyright notice in the Description page of Project Settings.


#include "LightClass.h"
#include "Kismet/GameplayStatics.h"
#include "CBJGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../CordobaGameJamCharacter.h"
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
	Sphere->bHiddenInGame = false;
}

// Called when the game starts or when spawned
void ALightClass::BeginPlay()
{
	Super::BeginPlay();

}

	void ALightClass::Goober() {    //A Goober le gusta apager y prender la luz, PERO NO LE GUSTAN LOS NULL POINTERS
		ACordobaGameJamCharacter* player = Cast<ACordobaGameJamCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());
		if (player == nullptr) {
			return;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("ENTERING"))
				player->SetObscure(false);
			player->SanityReduce();

		}
		/*Mananger = GetMananger();
		if (Mananger == nullptr)
		{
			UE_LOG(LogTemp,Warning,TEXT("Mimos Son Mimos"))
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("Goober"));
		Mananger->set_obscure(false);
		Mananger->LifeReducer();*/
	}
	void ALightClass::NotGoober() {  //Goober Dice "Time to play" y apaga la loz
	//	ACordobaGameJamCharacter* player = Cast<ACordobaGameJamCharacter>(UGameplayStatics::GetPlayerController(GetWorld(),0). Acontroller::GetPawn());
		ACordobaGameJamCharacter* player = Cast<ACordobaGameJamCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());
		if (player == nullptr) {
			UE_LOG(LogTemp, Warning, TEXT("NULLED"))
			return;
		}else
		{
			UE_LOG(LogTemp, Warning, TEXT("FINALIZINGGGINGIGN"))
			player->SetObscure(true);
			player->SanityReduce();
		}
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

