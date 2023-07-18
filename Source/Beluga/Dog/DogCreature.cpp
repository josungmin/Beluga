#include "Dog/DogCreature.h"

void UDogCreature::Init()
{
	CurrentHP = MaxHP;

	GEngine->AddOnScreenDebugMessage(1, 3, FColor::Yellow, FString::Printf(TEXT("Create % s"), *Name.ToString()));
}

FString UDogCreature::CPP_Hello()
{
	return HelloMsg;
}

FName UDogCreature::CPP_GetName()
{
	return Name;
}

void UDogCreature::BOTH_Update_Implementation()
{
	HelloMsg = HelloMsg.ToUpper();
}