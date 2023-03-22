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


	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1, UIMax = 10, ClampMax = 10))
		int maxSpawn = 5;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASwitchCharacter> memberTeam;


public:	
	ASwitcher();
private:
	UFUNCTION() void Switch();
	void IncrementSwitch();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Init();


	void SpawnTeamMember(); 
};
