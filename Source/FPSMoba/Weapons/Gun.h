// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UENUM()
enum WEAPON_TYPE
{
    RIFLE,
    HANDGUN,
    ROCKET_LAUNCHER,
    SNIPER,
    BOLT_ACTION,
    BOW,
    SLING_SHOT,
    CROSSBOW,
    THROWING_KNIFE,
    LASER,
    HOMING_MISSILE
};
UENUM()
enum BULLET_TYPE
{
    NORMAL,
    EXPLOSIVE,
    HOMING,
    ARROW,
    KNIFE,
    ENERGY
};

UCLASS()
class FPSMOBA_API AGun : public AActor
{
    GENERATED_BODY()

public:
    
    // Sets default values for this actor's properties
    AGun();
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    void PullTrigger();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    // mesh
    UPROPERTY(VisibleAnywhere)
    USceneComponent* Root;

    UPROPERTY(VisibleAnywhere)
    USkeletalMeshComponent* Mesh;

    // stats
    UPROPERTY(EditAnywhere)
    float FireRate = 1.f;
    UPROPERTY(EditAnywhere)
    float Damage = 10.f;
    UPROPERTY(EditAnywhere)
    float MaxRange = 1000.f;
    UPROPERTY(EditAnywhere)
    float ReloadTime = 2.5f;
    UPROPERTY(EditAnywhere)
    float Recoil = 5.f;
    UPROPERTY(EditAnywhere)
    int32 MaxMagazineAmmo = 30;
    UPROPERTY(EditAnywhere)
    int32 MaxAmmo = 250;
    UPROPERTY(VisibleAnywhere)
    int32 CurrentAmmo;
    UPROPERTY(VisibleAnywhere)
    int32 CurrentAmmoMagazine;
    UPROPERTY(EditAnywhere)
    bool HasScope = false;
    UPROPERTY(EditAnywhere)
    TEnumAsByte<WEAPON_TYPE> WeaponType;
    UPROPERTY(EditAnywhere)
    TEnumAsByte<BULLET_TYPE> BulletType;
    UPROPERTY(EditAnywhere)
    float Weight = 100.f;
    UPROPERTY(EditAnywhere)
    float Cost = 1200.f;
    

    // effects
    UPROPERTY(EditAnywhere)
    UParticleSystem* MuzzleFlash;

    UPROPERTY(EditAnywhere)
    USoundBase* MuzzleSound;

    UPROPERTY(EditAnywhere)
    UParticleSystem* ImpactEffect;

    UPROPERTY(EditAnywhere)
    USoundBase* ImpactSound;

    
    // functions
    AController* GetOwnerController() const;
    bool GunTrace(FHitResult& Hit, FVector& ShotDirection) const;
};
