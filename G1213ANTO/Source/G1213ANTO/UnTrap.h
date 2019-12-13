// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnTrap.generated.h"

UCLASS()
class G1213ANTO_API AUnTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnTrap();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Boom")/////
		class UBoxComponent* BoxTrigger;////

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Boom")////
		class UStaticMeshComponent* TrapShape;///

		//List<UObject> list;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//ITEM2
	UFUNCTION() ////
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); ////

	UFUNCTION()////
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);//////
		///FIM DO ITEM2

};
