// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/HASAttributeSet.h"

#include "GameplayEffectExtension.h"

void UHASAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// Clamp Health based on Max Health and 0;
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
}
