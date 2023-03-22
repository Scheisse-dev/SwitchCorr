#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DataObject.h"
#include "GameModeSpawn.generated.h"


UCLASS()
class SWITCHCORR_API AGameModeSpawn : public AGameModeBase
{
	GENERATED_BODY()


		//TSoftObjectPtr<AItem> refLevel = nullptr;
		//TSubClassOF<AItem> refToCopy = nullptr;
		// 
		//FORCEINLINE GetItem() 
		// { 
		//		AItem* _item = nullptr;
		//		if(refLevel.IsValid())
		//		{
		//			return refLevel.Get()
		//		}
		//		else
		//		{
		//			refLevel = GetWorld->SpawnActor(refToCopy);
		//			return refLevel.Get();
		//		}
		//}


	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> timerManagerRef = nullptr;
	UPROPERTY()
		TObjectPtr<UDataObject> data = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> timerManager = nullptr;


public:
	FORCEINLINE TObjectPtr<AActor>  GetTimerManager() const {
		return timerManager;
	}
		FORCEINLINE TObjectPtr<UDataObject> GetData() const { return data; }
private:
		virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
};
