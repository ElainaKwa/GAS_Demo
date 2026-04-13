// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

/**
 * 
 */

UCLASS()
class GAS_TEST_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	
	//生命值
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData HP;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, HP)
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")	
	FGameplayAttributeData MaxHP;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, MaxHP)

	//法力值
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData MP;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, MP)
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData MaxMP;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, MaxMP)

	//
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, Strength)
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")	
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, MaxStrength)

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;
};
