#include "Switcher.h"

ASwitcher::ASwitcher()
{
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
}



void ASwitcher::BeginPlay()
{
	Super::BeginPlay();
	Init();
	
}

void ASwitcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASwitcher::Switch()
{
	if (!fpc || switchTeam.Num() == 0)
		return;
	ASwitchCharacter* _next = switchTeam[currentSwitchIndex];
	if (!_next)
		return;
	if (currentChar)
		currentChar->SetControl(false);
	fpc->Possess(_next);
	currentChar = _next;
	currentChar->SetControl(true);
}

void ASwitcher::IncrementSwitch()
{
	currentSwitchIndex++;
	currentSwitchIndex = FMath::Fmod(currentSwitchIndex, switchTeam.Num());
	onIncrementSwitch.Broadcast();
}
void ASwitcher::Init()
{
	onIncrementSwitch.AddDynamic(this, &ASwitcher::Switch);
	fpc = GetWorld()->GetFirstPlayerController();
	if (!fpc)
		return;

	fpc->InputComponent->BindAction("Switch", IE_Pressed, this, &ASwitcher::IncrementSwitch);
	Switch();
}

