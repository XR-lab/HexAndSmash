// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MeleeHitboxData.generated.h"

USTRUCT(BlueprintType)
struct FMeleeHitSphereDefinition
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName Name;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FVector PositionOffset;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float Radius;
};

/**
 *  A data class storing an array of hitboxes which we can use during melee attacks
 */
UCLASS(BlueprintType)
class HEXANDSMASH_API UMeleeHitboxData : public UDataAsset
{
	GENERATED_BODY()

	public:
		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		TArray<FMeleeHitSphereDefinition> MeleeHitSpheres;	
};
