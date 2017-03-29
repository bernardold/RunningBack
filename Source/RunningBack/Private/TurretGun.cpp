// Fill out your copyright notice in the Description page of Project Settings.

#include "RunningBack.h"
#include "TurretGun.h"


void ATurretGun::DelayedShoot()
{
	Super::Shoot();
}

void ATurretGun::Shoot()
{
	GetWorldTimerManager().SetTimer(FireDelayHandle, this, &ATurretGun::DelayedShoot, 0.1f, true, 0.1f);
	if (ProjectileParticle)
	{
		ProjectileParticle->Activate();
	}
	else
	{
		
		ProjectileParticle = UGameplayStatics::SpawnEmitterAttached(
			ProjectileTemp, GetRootComponent(), TEXT("Barrel"), FVector(0, 0, 0), FRotator(0, 0, 0 /*Owner->GetActorRotation().Yaw * -1*/) , EAttachLocation::SnapToTargetIncludingScale, false);
//		ProjectileParticle = UGameplayStatics::SpawnEmitterAtLocation(this, ProjectileTemp, GetActorLocation());
//		ProjectileParticle->AttachTo(GetRootComponent(), TEXT("Barrel"));
	}
}

void ATurretGun::ShootStop()
{
	GetWorld()->GetTimerManager().ClearTimer(FireDelayHandle);
	ProjectileParticle->Deactivate();
}
