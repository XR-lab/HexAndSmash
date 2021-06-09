// Fill out your copyright notice in the Description page of Project Settings.


#include "HASCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "Abilities/HASAttributeSet.h"

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

	if (IsValid(AbilitySystemComponent))
	{
		AttributeSet = AbilitySystemComponent->GetSet<UHASAttributeSet>();
	}
	
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

void AHASCharacterBase::GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputCode)
{
	if (!IsValid(AbilitySystemComponent) || !IsValid(AbilityClass)) return;

	UGameplayAbility* Ability = AbilityClass->GetDefaultObject<UGameplayAbility>();

	if (!IsValid(Ability)) return;
	
	FGameplayAbilitySpec AbilitySpec(Ability, Level, InputCode);
	AbilitySystemComponent->GiveAbility(AbilitySpec);
}

void AHASCharacterBase::ActivateAbility(int32 index)
{
	if (!IsValid(AbilitySystemComponent)) return;

	AbilitySystemComponent->AbilityLocalInputPressed(index);
}

