// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseAttributeSet.h"
#include "AbilitySystemComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	UAbilitySystemComponent* MyAbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();
	if (MyAbilitySystemComponent)
	{
		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetHPAttribute()).AddUObject(this,&ABaseCharacter::OnHealthAttributeChange);
		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetMPAttribute()).AddUObject(this,&ABaseCharacter::OnMPAttributeChange);
		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetStrengthAttribute()).AddUObject(this,&ABaseCharacter::OnStrengthAttributeChange);

	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::OnHealthAttributeChange(const FOnAttributeChangeData& Data)
{
	HPChangeEvent.Broadcast(Data.NewValue);
}

void ABaseCharacter::OnMPAttributeChange(const FOnAttributeChangeData& Data)
{
	MPChangeEvent.Broadcast(Data.NewValue);
}

void ABaseCharacter::OnStrengthAttributeChange(const FOnAttributeChangeData& Data)
{
	StrengthChangeEvent.Broadcast(Data.NewValue);
}

FGameplayAbilityInfo ABaseCharacter::GetAbilityInfo(TSubclassOf<UBaseGameplayAbility> AbilityClass, int level)
{
	if (!AbilityClass)
    {
        return FGameplayAbilityInfo();
    }
	
	UAbilitySystemComponent* MyAbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();
	
	UBaseGameplayAbility* AbilityInstance = AbilityClass->GetDefaultObject<UBaseGameplayAbility>();
	if (MyAbilitySystemComponent && AbilityInstance )
	{
		return AbilityInstance->GetAbilityInfo(level);
	}
	return FGameplayAbilityInfo();
}

