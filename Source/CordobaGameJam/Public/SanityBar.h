// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SanityBar.generated.h"
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_Threeparams(FLowSanity);
	//UPROPERTY(BlueprintAssignable, BlueprintCallable)
	//	FLowSanity LowSanityEvent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLowSanity);
UCLASS(Blueprintable )
class CORDOBAGAMEJAM_API USanityBar : public UActorComponent
{
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this component's properties
	USanityBar();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
