// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Engine/World.h"
#include "Weapons/Gun.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    // stats
    Health = MaxHealth;

    // spawn gun
    if(!ensure(GunClass != nullptr)) return;
    Gun = GetWorld()->SpawnActor<AGun>(GunClass);
    Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
    Gun->SetOwner(this);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(+TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
    PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);

    PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction(TEXT("ChangePlayStyle"), IE_Pressed, this, &APlayerCharacter::ChangePlayStyle);
    PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &APlayerCharacter::Shoot);
}


void APlayerCharacter::MoveForward(float AxisValue)
{
    AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayerCharacter::MoveRight(float AxisValue)
{
    AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayerCharacter::ChangePlayStyle()
{
    UE_LOG(LogTemp, Warning, TEXT("Change Play Style"));

    if (CurrentPlayStyle == PlayStyle::ThirdPerson)
    {
        CurrentPlayStyle = PlayStyle::BirdsEye;
    }
    else if (CurrentPlayStyle == PlayStyle::BirdsEye)
    {
        CurrentPlayStyle = PlayStyle::ThirdPerson;
    }
}

void APlayerCharacter::Shoot()
{
    if (Gun != nullptr)
    {
        Gun->PullTrigger();
    }
}
