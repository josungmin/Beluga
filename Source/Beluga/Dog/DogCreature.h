#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DogCreature.generated.h"

UCLASS(Blueprintable, BlueprintType)//, Abstract)
class BELUGA_API UDogCreature : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	FName Name;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	int32 MaxHP;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default", Transient)
	int32 CurrentHP;

public:
	UFUNCTION(BlueprintCallable)
	virtual void Init();

	UFUNCTION(BlueprintCallable)
		FString CPP_Hello();

	UFUNCTION(BlueprintPure)
		FName CPP_GetName();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void BP_SetHelloMessage();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void BOTH_Update();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString HelloMsg;
};