// Fill out your copyright notice in the Description page of Project Settings.


#include "Reset.h"
#include "Components/BoxComponent.h"/////
#include "G1213ANTOCharacter.h"/////
#include "Kismet/GameplayStatics.h"/////
#include "Components/StaticMeshComponent.h"//////

// Sets default values
AReset::AReset()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	////ITEM3
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("trapTrigger"));/////
	RootComponent = BoxTrigger;///	

	BoxTrigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);/////
	BoxTrigger->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);/////
	BoxTrigger->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);//////
	BoxTrigger->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);//////

	HealShape = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("trapShape"));/////
	HealShape->SetupAttachment(GetRootComponent());///
	HealShape->SetSimulatePhysics(false); ////

	HealingTimer = 10.f;
	//FIM //ITEM3

}

// Called when the game starts or when spawned
void AReset::BeginPlay()
{
	Super::BeginPlay();

	//ITEM3
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &AReset::OnOverlapBegin); ///
	BoxTrigger->OnComponentEndOverlap.AddDynamic(this, &AReset::OnOverlapEnd);///
	//FIM //ITEM3
	
}

// Called every frame
void AReset::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//ITEM3
void AReset::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)/////
{
	//ITEM 3
	if (OtherActor != nullptr)///
	{////
		UE_LOG(LogTemp, Warning, TEXT("Coisou"));////
		//Cast<AFinalCharacter>(OtherActor)->HealingStop = HealingTimer;
		Cast<AG1213ANTOCharacter>(OtherActor)->IsHealing = true;////
		UE_LOG(LogTemp, Warning, TEXT("Overlap begin"));////
		/*Destroy(this);*/

		//if (HealSound != NULL)/////
		//{//////
		//	UGameplayStatics::PlaySoundAtLocation(this, HealSound, GetActorLocation());/////
		//}////

	}/////


}////

void AReset::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)////
{////
	UE_LOG(LogTemp, Warning, TEXT("Overlap end"));////
	//this->Destroy(true);
}////

//FIM //ITEM3

