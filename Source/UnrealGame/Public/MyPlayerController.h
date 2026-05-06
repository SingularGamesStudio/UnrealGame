// MyPlayerController.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "MyPlayerController.generated.h"

UCLASS()
class UNREALGAME_API AMyPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Team")
	uint8 TeamId = 1; // player/friendly team

	virtual FGenericTeamId GetGenericTeamId() const override
	{
		return FGenericTeamId(TeamId);
	}
};