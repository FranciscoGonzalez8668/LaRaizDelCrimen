// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PickItemUI.generated.h"

/**
 * 
 */
UCLASS()
class CORDOBAGAMEJAM_API UPickItemUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* Description = nullptr;
};
