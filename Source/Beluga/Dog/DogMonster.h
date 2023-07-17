#pragma once

#include "CoreMinimal.h"
#include "Dog/DogCreature.h"
#include "DogMonster.generated.h"


UCLASS(Abstract)
class BELUGA_API UDogMonster : public UDogCreature
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	bool TakeDamage(int32 Damage);

};