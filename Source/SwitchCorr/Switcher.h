#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwitchCharacter.h"
#include "Switcher.generated.h"

UCLASS()
class SWITCHCORR_API ASwitcher : public AActor
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIncrementSwitch);
		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;

	UPROPERTY(EditAnywhere)
		TArray<ASwitchCharacter*> switchTeam;

	UPROPERTY(EditAnywhere)
		TObjectPtr<ASwitchCharacter> currentChar = nullptr;

	UPROPERTY(EditAnywhere)
		TObjectPtr<AController> fpc = nullptr;

	int currentSwitchIndex = 0;

	FOnIncrementSwitch onIncrementSwitch;
public:	
	ASwitcher();
private:
	UFUNCTION() void Switch();
	void IncrementSwitch();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Init();
};
