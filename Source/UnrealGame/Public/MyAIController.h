// MyAIController.h
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GenericTeamAgentInterface.h"
#include "MyAIController.generated.h"

UCLASS()
class UNREALGAME_API AMyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AMyAIController();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI|Team")
	uint8 TeamId = 2; // default enemy team

public:
	UFUNCTION(BlueprintCallable, Category="AI|Team")
	void SetTeamId(uint8 NewTeamId);

	UFUNCTION(BlueprintPure, Category="AI|Team")
	uint8 GetTeamIdValue() const { return TeamId; }

	virtual FGenericTeamId GetGenericTeamId() const override;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
};