// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "AIMinionController.generated.h"

/**
 * 
 */
UCLASS()
class FPSMOBA_API AAIMinionController : public AAIController
{
    GENERATED_BODY()

public:
    virtual void Tick(float DeltaSeconds) override;
    bool IsDead() const;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere)
    bool Ranged;
    
    UPROPERTY(EditAnywhere)
    class UBehaviorTree* AIBehavior;

    UBlackboardComponent* BlackboardComponent;
};
