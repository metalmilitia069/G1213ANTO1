// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "G1213ANTOHUD.generated.h"

UCLASS()
class AG1213ANTOHUD : public AHUD
{
	GENERATED_BODY()

public:
	AG1213ANTOHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

