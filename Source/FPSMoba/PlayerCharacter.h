// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UENUM()
enum PlayStyle
{
    ThirdPerson,
    BirdsEye
};

class AGun;

UCLASS()
class FPSMOBA_API APlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    APlayerCharacter();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    void MoveForward(float AxisValue);
    void MoveRight(float AxisValue);
    void ChangePlayStyle();
    void Shoot();

    UPROPERTY(VisibleAnywhere)
    TEnumAsByte<PlayStyle> CurrentPlayStyle = PlayStyle::ThirdPerson;

    // stats
    UPROPERTY(EditDefaultsOnly)
    float MaxHealth = 100.f;
    UPROPERTY(VisibleAnywhere)
    float Health;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AGun> GunClass;

    UPROPERTY()
    AGun* Gun;
};
