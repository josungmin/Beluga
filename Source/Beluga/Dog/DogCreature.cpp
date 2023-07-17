#include "Dog/DogCreature.h"

void UDogCreature::Init()
{
	CurrentHP = MaxHP;

	GEngine->AddOnScreenDebugMessage(1, 3, FColor::Yellow, FString::Printf(TEXT("Create % s"), *Name.ToString()));
}
