#include "MyActor.h"
#include "SwitchCharacter.h"
#include "GameModeSpawn.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	AGameModeSpawn* _gm = GetWorld()->GetAuthGameMode<AGameModeSpawn>();
	_gm->GetData()->UpdateTime();
	//NewObject<T>(owner); owner -> clear 
	obj = NewObject<UDataObject>(this);


	copy = GetWorld()->SpawnActor<ASwitchCharacter>(originalCopy, GetActorLocation(), FRotator(0));
	//copy->Destroy();
	copy->SetLifeSpan(2);
	//copy->InvokeDestroy();
}
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(obj)
	obj->UpdateTime();

}

void AMyActor::EndPlay(const EEndPlayReason::Type)
{
	UE_LOG(LogTemp, Warning, TEXT("Death"));
}

