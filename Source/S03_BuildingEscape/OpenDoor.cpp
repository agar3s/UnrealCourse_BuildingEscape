

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"

#define OUT


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

	Owner = GetOwner();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	float CurrentTime = GetWorld()->GetTimeSeconds();
	// poll the trigger volume if the ActorThatOpens is in the volume, we open the door
	if (GetTotalMassOfActorsOnPlate() > TriggerMass)
	{
		OnOpenRequest.Broadcast();
	}
	else
	{
		//OnCloseRequest.Broadcast();
	}
	
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	// find all overlapping actors
	TArray<AActor *> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	// iterate through them adding their masses
	for (const auto* Actor: OverlappingActors)
	{
		TotalMass+=Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		
		UE_LOG(LogTemp, Error, TEXT("%s component"), *(Actor->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("totalMass: %f kgs"), TotalMass );

	return TotalMass;
}

