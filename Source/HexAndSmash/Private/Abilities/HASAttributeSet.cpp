// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/HASAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "HexAndSmash/HASCharacterBase.h"

void UHASAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	float DeltaValue = 0;
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
	{
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	AActor* TargetActor = nullptr;
	AHASCharacterBase* TargetCharacter = nullptr;

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetCharacter = Cast<AHASCharacterBase>(TargetActor);
	}
	// Clamp Health based on Max Health and 0;
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
		if (TargetCharacter)
		{
			TargetCharacter->HandleHealthChanged(-DeltaValue);
		}
	}
}
