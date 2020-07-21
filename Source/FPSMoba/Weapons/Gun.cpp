// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGun::AGun()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(Root);

    Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
    Super::BeginPlay();

    CurrentAmmo = MaxAmmo;
    CurrentAmmoMagazine = MaxMagazineAmmo;
}

AController* AGun::GetOwnerController() const
{
    APawn* OwnerPawn = Cast<APawn>(GetOwner());

    if (OwnerPawn == nullptr) return nullptr;

    return OwnerPawn->GetController();
}

bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection) const
{
    // get the player controller
    AController* OwnerController = GetOwnerController();
    if (OwnerController == nullptr) return false;

    // initialise return vars
    FVector Location;
    FRotator Rotation;

    // get the location, rotation from viewpoint
    OwnerController->GetPlayerViewPoint(Location, Rotation);

    // work out shot direction
    ShotDirection = -Rotation.Vector();
    
    // calculate the line tracing with the max range
    const FVector LineTraceEnd = Location + Rotation.Vector() * MaxRange;

    // test line tracing
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);
    Params.AddIgnoredActor(GetOwner());

    // debug
    // DrawDebugLine(
    //     GetWorld(),
    //     Location,
    //     LineTraceEnd,
    //     FColor::Red,
    //     false,
    //     -1,
    //     0,
    //     12.333
    // );
    //
    // const FName TraceTag("MyTraceTag");
    // GetWorld()->DebugDrawTraceTag = TraceTag;
    // FCollisionQueryParams CollisionParameters;
    // CollisionParameters.TraceTag = TraceTag;
    // CollisionParameters.AddIgnoredActor(this);
    // CollisionParameters.AddIgnoredActor(GetOwner());

    // return the result
    return GetWorld()->LineTraceSingleByChannel(
        Hit,
        Location,
        LineTraceEnd,
        ECollisionChannel::ECC_GameTraceChannel1,
        Params
    );
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGun::PullTrigger()
{
    UE_LOG(LogTemp, Warning, TEXT("SHOOT"));

    // spawn muzzle and sound

    // ray trace
    FHitResult Hit;
    FVector ShotDirection;
    bool bSuccess = GunTrace(Hit, ShotDirection);

    if (bSuccess)
    {
        UE_LOG(LogTemp, Warning, TEXT("TRACE SUCCESS"));

        // hit effects
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
        
        // apply damage
        // check ammo etc
    }
}
