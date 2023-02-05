// Copyright Epic Games, Inc. All Rights Reserved.

#include "CordobaGameJamCharacter.h"
#include "CordobaGameJamProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SanityMananger.h"
#include "RaizDelCrimenHUD.h"
#include "PickObject.h"
#include "Kismet/GameplayStatics.h"

#include "Engine/World.h"


//////////////////////////////////////////////////////////////////////////
// ACordobaGameJamCharacter

ACordobaGameJamCharacter::ACordobaGameJamCharacter()
{
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

void ACordobaGameJamCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	TSubclassOf<ASanityMananger> sanity;
	AActor* sanityActorManager = UGameplayStatics::GetActorOfClass(this, sanity);
	SanityMananger = Cast<ASanityMananger>(sanityActorManager);

	//a->set_obscure(false);
	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ACordobaGameJamCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACordobaGameJamCharacter::Move);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACordobaGameJamCharacter::Look);
	}
}


void ACordobaGameJamCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ACordobaGameJamCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ACordobaGameJamCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

bool ACordobaGameJamCharacter::GetHasRifle()
{
	return bHasRifle;
}

void ACordobaGameJamCharacter::die(AActor* Other)
{
	if (Other == nullptr)
	{
		return;
	}
	
	if (APickObject* pickObject = Cast<APickObject>(Other))
	{
		if (ARaizDelCrimenHUD* hud = Cast<ARaizDelCrimenHUD>(GetWorld()->GetFirstPlayerController()->GetHUD()))
		{
			hud->DisplayItem_Event(FText::FromString(pickObject->GetPickMessage()));
		}

		if (SanityMananger != nullptr)
		{
			SanityMananger->ItemPickedUp(pickObject->GetDamage());
		}

		class USoundBase* Sound = pickObject->isBad ? pickObject->EvilSound : pickObject->NiceSound;

		if (Sound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, Sound, GetOwner()->GetActorLocation());
		}
	}

	Other->Destroy();
}
