// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinionTargetLocation.generated.h"

UCLASS()
class FPSMOBA_API AMinionTargetLocation : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AMinionTargetLocation();

    uint32 GetLane();
    uint32 GetWaypointNumber();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere)
    uint32 Lane;

    UPROPERTY(EditAnywhere)
    uint32 WaypointNumber;
};
