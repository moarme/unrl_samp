// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorOpener.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UDoorOpener::UDoorOpener()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorOpener::BeginPlay()
{
	Super::BeginPlay();
	keyActor = GetWorld()->GetFirstPlayerController()->GetPawn();
	//OpenDoor();
	// ...
	
}

void UDoorOpener::OpenDoor()
{
	AActor *p_owner = GetOwner();
	FRotator ang_opened = FRotator(0.0f, OpenAngle, 0.0f);
	//float z_rotate = p_owner->GetActorRotation().GetComponentForAxis(EAxis::Type::Z);
	p_owner->SetActorRotation(ang_opened);
}


// Called every frame
void UDoorOpener::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (pressurePlate->IsOverlappingActor(keyActor))
		OpenDoor();
	// ...
}

