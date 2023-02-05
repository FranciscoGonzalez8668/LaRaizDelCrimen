// Fill out your copyright notice in the Description page of Project Settings.

#pragma 
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CBJGameInstance.generated.h"

class ASanityMananger;
UCLASS()
class CORDOBAGAMEJAM_API UCBJGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:
	ASanityMananger* Mananger;
	ASanityMananger* GetMananger();
	
};
