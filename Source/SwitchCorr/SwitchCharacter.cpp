#include "SwitchCharacter.h"
#include <Kismet/KismetMathLibrary.h>

ASwitchCharacter::ASwitchCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	arm = CreateDefaultSubobject<USpringArmComponent>("arm");
	camera = CreateDefaultSubobject<UCameraComponent>("component");

	arm->SetupAttachment(RootComponent);
	camera->SetupAttachment(arm);
	bUseControllerRotationYaw = true;
}
void ASwitchCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
void ASwitchCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FollowBehaviour();

}
void ASwitchCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &ASwitchCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Horizontal", this, &ASwitchCharacter::Rotate);

}

void ASwitchCharacter::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector() * _axis);
	onMoveForward.Broadcast(_axis);
}

void ASwitchCharacter::Rotate(float _axis)
{
	AddControllerYawInput(_axis);
}

void ASwitchCharacter::FollowBehaviour()
{
	if (isControlled || !GetWorld()->GetFirstPlayerController() || !GetWorld()->GetFirstPlayerController()->GetPawn())
		return;
	const FVector _this = GetActorLocation(),
				  _other = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	const bool _isAtRange = settings.IsAtRange(_this, _other);
	onMoveForward.Broadcast(_isAtRange ? 0 : 1);
	if (_isAtRange)
		return;
	const FVector _location = FMath::VInterpConstantTo(_this, _other, GetWorld()->DeltaTimeSeconds, settings.speed);
	SetActorLocation(_location);
	FRotator _target = UKismetMathLibrary::FindLookAtRotation(_this, _other);
	SetActorRotation(_target);
}



