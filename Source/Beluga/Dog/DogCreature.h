#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DogCreature.generated.h"

UCLASS(Abstract)
class BELUGA_API UDogCreature : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Creature")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category = "Creature")
	int32 MaxHP;

	UPROPERTY(EditDefaultsOnly, Category = "Creature")
	int32 CurrentHP;

	UFUNCTION()
	virtual void Init();
};