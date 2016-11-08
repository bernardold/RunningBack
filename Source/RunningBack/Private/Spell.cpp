// Fill out your copyright notice in the Description page of Project Settings.

#include "RunningBack.h"
#include "Spell.h"


// Sets default values
ASpell::ASpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpell::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(LifetimeHandle, this, &ASpell::Kill, 5.0f, false, 5.0f);
}

// Called every frame
void ASpell::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASpell::Kill()
{
	Destroy();
}

