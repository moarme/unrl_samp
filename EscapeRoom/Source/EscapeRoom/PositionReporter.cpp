// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReporter.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();
	FString obj_name= GetOwner()->GetName();
	FString obj_pos = *FString::Printf(TEXT("X=%d, Y=%d, Rotation=%d, Location: %s"),	GetOwner()->GetTransform().GetLocation().X, 
																	GetOwner()->GetActorLocation().Y,
																	GetOwner()->GetActorRotation().GetComponentForAxis(EAxis::Z),
																	*GetOwner()->GetActorLocation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Coordinates of %s: %s"), *obj_name,*obj_pos);
	// ...
	
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

