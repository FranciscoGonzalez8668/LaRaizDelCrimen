#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "PickObject.generated.h"

UCLASS(BlueprintType)
class CORDOBAGAMEJAM_API APickObject : public AActor
{
	GENERATED_BODY()

	void Spawn();

	float realDamageMade = 1;			//da;o real hecho, Puede ser negativo o positivo segun el tipo de enemigo que sea
	
public:
	APickObject();

	UPROPERTY(EditAnyWhere, Category = CollisionComp)
	UBoxComponent* Box_Trigger_Component = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Assets")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, category = "ItemPickUp")
	float damageMade = 1;	//El valor publico de da;oo es siempre positivo ya que marca la cantidad a hacer

	UPROPERTY(EditAnywhere, category = "ItemPickUp")
	float healingMade = 1;	//no puede ser negativo

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ItemPickUp")
	class USoundBase* NiceSound;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ItemPickUp")
	class USoundBase* EvilSound;
		
	UPROPERTY(EditAnywhere, category = "ItemPickUp")
	bool isBad = false;

	UPROPERTY(EditAnywhere, category = "ItemPickUp")
	FString pickMessage = "Default";

	int GetDamage() {
		return realDamageMade;
	}

	FString GetPickMessage() {
		return pickMessage;
	}

	void PlaySound();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
