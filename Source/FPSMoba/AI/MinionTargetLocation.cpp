// Fill out your copyright notice in the Description page of Project Settings.


#include "MinionTargetLocation.h"

// Sets default values
AMinionTargetLocation::AMinionTargetLocation()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
}

uint32 AMinionTargetLocation::GetLane()
{
    return Lane;
}

uint32 AMinionTargetLocation::GetWaypointNumber()
{
    return WaypointNumber;
}

// Called when the game starts or when spawned
void AMinionTargetLocation::BeginPlay()
{
    Super::BeginPlay();
}
