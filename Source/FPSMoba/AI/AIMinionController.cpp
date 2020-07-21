// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMinionController.h"


#include "AIMinionCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


void AAIMinionController::BeginPlay()
{
    Super::BeginPlay();

    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);

        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        APawn* ThisPawn = GetPawn();
        BlackboardComponent = GetBlackboardComponent();
        BlackboardComponent->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
    }
}

void AAIMinionController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

bool AAIMinionController::IsDead() const
{
    AAIMinionCharacter* ControlledCharacter = Cast<AAIMinionCharacter>(GetPawn());

    if (ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }

    return true;
}
