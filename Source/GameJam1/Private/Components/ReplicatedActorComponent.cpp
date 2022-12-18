#include "Components/ReplicatedActorComponent.h"
#include "Net/UnrealNetwork.h"
#include "Characters/BaseCharacter.h"

UReplicatedActorComponent::UReplicatedActorComponent()
{
	SetIsReplicated(true);
}

void UReplicatedActorComponent::BeginPlay()
{
	Super::BeginPlay();

	CharacterOwner = Cast<ABaseCharacter>(GetOwner());
}

void UReplicatedActorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UReplicatedActorComponent, CharacterOwner);
}

ABaseCharacter* UReplicatedActorComponent::GetCharacterOwner() const
{
	return CharacterOwner;
}
