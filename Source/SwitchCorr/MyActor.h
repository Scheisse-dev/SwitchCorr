#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataObject.h"

#include "MyActor.generated.h"

UCLASS()
class SWITCHCORR_API AMyActor : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<UDataObject> obj = nullptr;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASwitchCharacter> originalCopy = nullptr;
		TObjectPtr<class ASwitchCharacter> copy;
public:	
	AMyActor();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
