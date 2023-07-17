#include "Dog/DogPlayer.h"
#include "Dog/DogMonster.h"

UDogPlayer::UDogPlayer()
{
	Name = TEXT("Player");
	MaxHP = 100;
	AttackPower = 30;
}

void UDogPlayer::Attack(UDogMonster* Target)
{
	GEngine->AddOnScreenDebugMessage(1, 3, FColor::White, FString::Printf(TEXT("Attack %s"), *Name.ToString()));
	Target->TakeDamage(AttackPower);
}