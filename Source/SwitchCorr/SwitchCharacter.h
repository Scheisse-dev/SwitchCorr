#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include "SwitchCharacter.generated.h"

USTRUCT()
struct FFollowerSettings
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		float speed = 100;
	UPROPERTY(EditAnywhere)
		float minimalRange = 200;

public:
	FORCEINLINE bool IsAtRange(const FVector& _from, const FVector& _to) const {
		return FVector::Distance(_from, _to) < minimalRange;
	}
};

UCLASS()
class SWITCHCORR_API ASwitchCharacter : public ACharacter
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveForward, float, _axis);

		UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> arm = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FOnMoveForward onMoveForward;
	FFollowerSettings settings;

	bool isControlled = false;
public:
	ASwitchCharacter();
	FORCEINLINE FOnMoveForward& OnMoveForward() {
		return onMoveForward;
	}
	FORCEINLINE void SetControl(const bool& _value) { isControlled = _value; }
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void Rotate(float _axis);
	void FollowBehaviour();
};
