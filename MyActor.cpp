// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "CoreMinimal.h"

float distance(FVector first, FVector second);
void TriggerEventWithProbability(float Probability);



// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::move() 
{
	FVector TargetLocation = start + FVector(step(), step(), 0); 
	float dist = distance(start, TargetLocation);
	SetActorLocation(TargetLocation); 
	UE_LOG(LogTemp, Log, TEXT("Vector X = %f, Y = %f"), TargetLocation.X, TargetLocation.Y); 
	UE_LOG(LogTemp, Log, TEXT("Distance = %f"), dist);
	TriggerEventWithProbability(50);
	start = TargetLocation; 
}

int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

float distance(FVector first, FVector second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

void TriggerEventWithProbability(float Probability)
{
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	if (RandomValue <= Probability)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
	}
}



// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	start = GetActorLocation();
	move_cnt = 0;
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (move_cnt < 10) {
		move();
		move_cnt++;
	}
}

