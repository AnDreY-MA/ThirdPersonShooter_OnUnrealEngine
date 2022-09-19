// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AShooterPlayerController();

protected:

	virtual void BeginPlay() override;

private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta=(AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> HUDOverlayClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI", meta=(AllowPrivateAccess = "true"))
	UUserWidget* HUDOverlay;
	
};
