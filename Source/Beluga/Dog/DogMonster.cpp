#include "Dog/DogMonster.h"
#include "Kismet/KismetMathLibrary.h"

bool UDogMonster::TakeDamage(int32 Damage)
{
	CurrentHP = FMath::Max(CurrentHP - Damage, 0);

	bool dead = false;
	if (CurrentHP == 0)
	{
		dead = true;

		GEngine->AddOnScreenDebugMessage(1, 3, FColor::Red, FString::Printf(TEXT("Damaged %d"), Damage));
	}

	return dead;
}
