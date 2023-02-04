// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RaizDelCrimenHUD.generated.h"

/**
 * 
 */
UCLASS()
class CORDOBAGAMEJAM_API ARaizDelCrimenHUD : public AHUD
{
	GENERATED_BODY()
	
	public:
	UFUNCTION(BlueprintImplementableEvent)
	void DisplayItem_Event(const FText &Description);
};
