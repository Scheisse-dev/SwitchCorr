// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataObject.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SWITCHCORR_API UDataObject : public UObject
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		float dayTime = 0;

public:
	FORCEINLINE void UpdateTime()
	{
		dayTime++;
	}
};
