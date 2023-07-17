#pragma once

#include "CoreMinimal.h"
#include "Dog/DogCreature.h"
#include "DogPlayer.generated.h"


UCLASS()
class BELUGA_API UDogPlayer : public UDogCreature
{
public:
	GENERATED_BODY()

	UDogPlayer();

	UFUNCTION()
	void Attack(class UDogMonster* Target);

	UPROPERTY(EditDefaultsOnly, Category = "Default")
	int32 AttackPower;
};