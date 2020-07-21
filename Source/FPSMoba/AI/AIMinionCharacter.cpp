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
	
}

// Called every frame
void AAIMinionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIMinionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

