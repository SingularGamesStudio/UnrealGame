// MyAIController.cpp
#include "MyAIController.h"
#include "GameFramework/Pawn.h"
#include "GenericTeamAgentInterface.h"

AMyAIController::AMyAIController()
{
}

void AMyAIController::SetTeamId(uint8 NewTeamId)
{
	TeamId = NewTeamId;
}

FGenericTeamId AMyAIController::GetGenericTeamId() const
{
	return FGenericTeamId(TeamId);
}

ETeamAttitude::Type AMyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const IGenericTeamAgentInterface* TeamAgent = Cast<const IGenericTeamAgentInterface>(&Other);
	if (!TeamAgent)
	{
		if (const APawn* OtherPawn = Cast<APawn>(&Other))
		{
			TeamAgent = Cast<const IGenericTeamAgentInterface>(OtherPawn->GetController());
		}
	}

	if (!TeamAgent)
	{
		return ETeamAttitude::Neutral;
	}

	const FGenericTeamId OtherTeam = TeamAgent->GetGenericTeamId();
	const FGenericTeamId MyTeam = GetGenericTeamId();

	if (OtherTeam == FGenericTeamId::NoTeam)
	{
		return ETeamAttitude::Neutral;
	}

	if (OtherTeam == MyTeam)
	{
		return ETeamAttitude::Friendly;
	}

	return ETeamAttitude::Hostile;
}