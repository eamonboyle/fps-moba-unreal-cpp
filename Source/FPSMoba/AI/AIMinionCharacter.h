// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIMinionCharacter.generated.h"

UCLASS()
class FPSMOBA_API AAIMinionCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AAIMinionCharacter();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintPure)
    bool IsDead() const;

    UFUNCTION(BlueprintPure)
    float GetHealthPercent() const;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:

    // stats
    UPROPERTY(EditDefaultsOnly)
    float MaxHealth = 100.f;
    UPROPERTY(VisibleAnywhere)
    float Health;
};
