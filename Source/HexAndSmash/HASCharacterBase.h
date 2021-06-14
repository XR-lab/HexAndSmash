// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemInterface.h"

#include "CoreMinimal.h"

#include "Abilities/HASAttributeSet.h"
#include "GameFramework/Character.h"
#include "HASCharacterBase.generated.h"

class UAbilitySystemComponent;

UCLASS()
class HEXANDSMASH_API AHASCharacterBase : public ACharacter, public IAbilitySystemInterface
{
private:
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHASCharacterBase();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

protected:
	UPROPERTY()
	const class UHASAttributeSet* AttributeSet;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category="Abilities")
	void GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputCode);

	// for now use the index of ability array, might want to change this later to try activate ability by class
	UFUNCTION(BlueprintCallable, Category="Abilities")
	void ActivateAbility(int32 index);

	UFUNCTION(BlueprintCallable, Category="Abilities")
	void CancelAbilityWithTags(const FGameplayTagContainer CancelWithTags);

	UFUNCTION(BlueprintPure, Category="Abilities|Attributes")
	float GetHealth() const;

	UFUNCTION(BlueprintPure, Category="Abilities|Attributes")
	float GetMaxHealth() const;
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnHealthChanged(float delta);

	virtual void HandleHealthChanged(float Delta);
};
