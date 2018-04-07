

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	AActor *Owner = GetOwner();
	FString Rotation = Owner->GetActorRotation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("current rotation for door is %s"), *Rotation);
	FRotator Rotator = FRotator(0.f, 60.0f, 0.f);
	Owner->SetActorRotation(Rotator);
	Rotation = Owner->GetActorRotation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("new rotation for door is %s"), *Rotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

