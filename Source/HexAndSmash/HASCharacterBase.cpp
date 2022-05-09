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

void AHASCharacterBase::CancelAbilityWithTags(const FGameplayTagContainer CancelWithTags)
{
	if (!IsValid(AbilitySystemComponent)) return;

	AbilitySystemComponent->CancelAbilities(&CancelWithTags);
}

bool AHASCharacterBase::GetCooldownRemainingForTag(FGameplayTagContainer CooldownTags, float& TimeRemaining,
	float& CooldownDuration)
{
	if (AbilitySystemComponent && CooldownTags.Num() > 0)
	{
		TimeRemaining = 0.0f;
		CooldownDuration = 0.0f;

		FGameplayEffectQuery const Query = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(CooldownTags);
		TArray<TPair<float,float>> DurationAndTimeRemaining = AbilitySystemComponent->GetActiveEffectsTimeRemainingAndDuration(Query);

		if (DurationAndTimeRemaining.Num() > 0)
		{
			int32 BestIdx = 0;
			float LongestTime = DurationAndTimeRemaining[0].Key;
			for (int32 Idx = 1; Idx <DurationAndTimeRemaining.Num(); ++Idx)
			{
				if (DurationAndTimeRemaining[Idx].Key > LongestTime)
				{
					LongestTime = DurationAndTimeRemaining[Idx].Key;
					BestIdx = Idx;
				}
			}

			TimeRemaining = DurationAndTimeRemaining[BestIdx].Key;
			CooldownDuration = DurationAndTimeRemaining[BestIdx].Value;

			return true;
		}
	}
	return false;
}

float AHASCharacterBase::GetHealth() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetHealth();
	}

	return -1.0;
}

float AHASCharacterBase::GetMaxHealth() const
{
	if (IsValid(AttributeSet))
	{
		return AttributeSet->GetMaxHealth();
	}

	return -1.0;
}

void AHASCharacterBase::HandleHealthChanged(float Delta)
{
	OnHealthChanged(Delta);
}

