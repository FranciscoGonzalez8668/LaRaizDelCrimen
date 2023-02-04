// Fill out your copyright notice in the Description page of Project Settings.

#include "../CordobaGameJamCharacter.h"
#include "PickObject.h"

// Sets default values
APickObject::APickObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (isBad) {
		realDamageMade = damageMade;
	}
	else {
		realDamageMade = (-1) * healingMade;
	}

	Box_Trigger_Component = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = Box_Trigger_Component;
	Box_Trigger_Component->SetBoxExtent(FVector(70.0f, 20.0f, 20.0f));
	Box_Trigger_Component->SetCollisionProfileName(TEXT("OverlapAll"));
	Box_Trigger_Component->SetGenerateOverlapEvents(true);
	Box_Trigger_Component->bMultiBodyOverlap = true;

	//Rep Visual
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual"));
	MeshComp->SetupAttachment(RootComponent);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> NewMesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	if (NewMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(NewMesh.Object);
		MeshComp->SetRelativeLocation(FVector(-20.0f, 0.0f, 0.0f));
		MeshComp->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		MeshComp->SetWorldScale3D(FVector(1.0f));
		MeshComp->SetCollisionProfileName(TEXT("OverlapAll"));
	}
	
	Box_Trigger_Component->OnComponentBeginOverlap.AddDynamic(this, &APickObject::PickUp);
}

// Called when the game starts or when spawned
void APickObject::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APickObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickObject::PickUp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACordobaGameJamCharacter* PlayerInteracting = Cast<ACordobaGameJamCharacter>(OtherActor);
	if (PlayerInteracting != nullptr)
	{
		this->Destroy();
	}

	this->Destroy();

	/*UGameplayStatics::SpawnEmitterAtLocation(
		GetWorld(),
		EmitterTemplate,
		GetActorLocation(),
		FRotator(0.0f, 0.0f, 0.0f),
		true);*/
}

