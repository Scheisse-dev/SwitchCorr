#include "MyActor.h"
#include "SwitchCharacter.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	//NewObject<T>(owner); owner -> clear 
	obj = NewObject<UDataObject>(this);


	copy = GetWorld()->SpawnActor<ASwitchCharacter>(originalCopy, GetActorLocation(), FRotator(0));
}
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(obj)
	obj->UpdateTime();

}

