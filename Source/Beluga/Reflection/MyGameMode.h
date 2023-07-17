// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BELUGA_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AMyGameMode();

	UPROPERTY()
	int32 Number;

	UFUNCTION()
	void HongikUniver();
};
