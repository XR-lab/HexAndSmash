// Fill out your copyright notice in the Description page of Project Settings.


#include "HASCharacterBase.h"

#include "AbilitySystemComponent.h"

// Sets default values
AHASCharacterBase::AHASCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Ability System Component"));

}

// Called when the game starts or when spawned
void AHASCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHASCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHASCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AHASCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

