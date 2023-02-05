
#include "PickObject.h"
#include "Kismet/GameplayStatics.h"
#include "../CordobaGameJamCharacter.h"


APickObject::APickObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box_Trigger_Component = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = Box_Trigger_Component;
	Box_Trigger_Component->SetBoxExtent(FVector(50.0f, 50.0f, 20.0f));
	Box_Trigger_Component->SetCollisionProfileName(TEXT("OverlapAll"));
	Box_Trigger_Component->SetGenerateOverlapEvents(true);
	Box_Trigger_Component->bMultiBodyOverlap = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual"));
	MeshComp->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> NewMesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	if (NewMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(NewMesh.Object);
		MeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		MeshComp->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		MeshComp->SetWorldScale3D(FVector(1.0f));
		MeshComp->SetCollisionProfileName(TEXT("OverlapAll"));
	}
}

void APickObject::BeginPlay()
{
	Super::BeginPlay();

	if (isBad) {
		realDamageMade = damageMade;
	}
	else {
		realDamageMade = (-1) * healingMade;
	}
}

void APickObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APickObject::PlaySound() 
{
	if (isBad) {
		UGameplayStatics::PlaySoundAtLocation(this, EvilSound, GetOwner()->GetActorLocation());
	}
	else {
		UGameplayStatics::PlaySoundAtLocation(this, NiceSound, GetOwner()->GetActorLocation());
	}
}
