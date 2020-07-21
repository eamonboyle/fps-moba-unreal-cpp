// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMinionCharacter.h"

// Sets default values
AAIMinionCharacter::AAIMinionCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAIMinionCharacter::BeginPlay()
{
    Super::BeginPlay();

    // stats
    Health = MaxHealth;
}

// Called every frame
void AAIMinionCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

bool AAIMinionCharacter::IsDead() const
{
    return Health <= 0;
}

float AAIMinionCharacter::GetHealthPercent() const
{
    return Health / MaxHealth;
}
