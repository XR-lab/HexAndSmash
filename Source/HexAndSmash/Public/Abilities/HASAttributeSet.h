// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemComponent.h"

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "HASAttributeSet.generated.h"



/**
 * 
 */
UCLASS()
class HEXANDSMASH_API UHASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	// Characters Health Attribute
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character")
	FGameplayAttributeData Health;

	// Getters and setters for the Health Attribute
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Health);
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UHASAttributeSet, Health);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character")
	FGameplayAttributeData MaxHealth;
	
	GAMEPLAYATTRIBUTE_VALUE_GETTER(MaxHealth);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(MaxHealth);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(MaxHealth);
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UHASAttributeSet, MaxHealth);
};
