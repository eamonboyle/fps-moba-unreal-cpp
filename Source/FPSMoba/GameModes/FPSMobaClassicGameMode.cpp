// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSMobaClassicGameMode.h"

#include "FPSMoba/AI/MinionTargetLocation.h"

#include "Kismet/GameplayStatics.h"

void AFPSMobaClassicGameMode::BeginPlay()
{
    Super::BeginPlay();

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMinionTargetLocation::StaticClass(), MinionTargetLocations);

    UE_LOG(LogTemp, Warning, TEXT("Classic Game Mode Loaded"));

    for (AActor* MinionTargetLocation : MinionTargetLocations)
    {
        AMinionTargetLocation* Waypoint = Cast<AMinionTargetLocation>(MinionTargetLocation);

        UE_LOG(LogTemp, Warning, TEXT("Lane: %d, Waypoint: %d"), Waypoint->GetLane(), Waypoint->GetWaypointNumber());

        if (Waypoint->GetLane() != LastLane)
        {
            
        }
    }
}
