// Fill out your copyright notice in the Description page of Project Settings.


#include "LeosPlayerController.h"
#include "LeosUserWidget.h"////
#include "G1213ANTOCharacter.h"///
#include "Kismet/GameplayStatics.h"///
#include "Blueprint/UserWidget.h" //////


//ITEM1
void ALeosPlayerController::BeginPlay()
{
	//PlayRef = (UGameplayStatics::GetPlayerController(this, 0));
	//PlayRef = UGameplayStatics::GetPlayerCharacter(this, 0);
	//PlayRef = 

	//ITEM1

	Super::BeginPlay();

	if (HUDAsset)///
	{

		HUDOverlay = CreateWidget<ULeosUserWidget>(this, HUDAsset);
		HUDOverlay->AddToViewport();
		HUDOverlay->SetVisibility(ESlateVisibility::Visible);

		PlayRef = UGameplayStatics::GetPlayerPawn(this, 0);
		HUDOverlay->player = Cast<AG1213ANTOCharacter>(PlayRef);
	}
}

	//FIM ITEM 1


