#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ReplicatedActorComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEJAM1_API UReplicatedActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UReplicatedActorComponent();

protected:

	virtual void BeginPlay() override;

public:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Category="")
	class ABaseCharacter* GetCharacterOwner() const;

private:

	UPROPERTY(Replicated)
	ABaseCharacter* CharacterOwner;
	
};