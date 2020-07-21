// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSMoba/FPSMobaGameModeBase.h"
#include "FPSMobaClassicGameMode.generated.h"

class AMinionTargetLocation;

/**
 * 
 */
UCLASS()
class FPSMOBA_API AFPSMobaClassicGameMode : public AFPSMobaGameModeBase
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

private:
    TArray<AActor*> MinionTargetLocations;
    TArray<AMinionTargetLocation*> TeamAWaypoints;
    TArray<AMinionTargetLocation*> TeamBWaypoints;

    int MaxLanes;
    TArray<int> Lanes;
    TArray<int> WaypointCounts;
};
