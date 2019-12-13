// Fill out your copyright notice in the Description page of Project Settings.


#include "UnTrap.h"
#include "Components/BoxComponent.h"/////
#include "G1213ANTOCharacter.h"////
#include "Components/StaticMeshComponent.h"//////


// Sets default values
AUnTrap::AUnTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//ITEM2
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("trapTrigger"));/////
	RootComponent = BoxTrigger;///	

	BoxTrigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);/////
	BoxTrigger->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);/////
	BoxTrigger->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);//////
	BoxTrigger->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);//////

	TrapShape = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("trapShape"));/////
	TrapShape->SetupAttachment(GetRootComponent());///
	TrapShape->SetSimulatePhysics(true); ////
	//FIM ITEM2

}

// Called when the game starts or when spawned
void AUnTrap::BeginPlay()
{
	Super::BeginPlay();

	//ITEM2
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &AUnTrap::OnOverlapBegin); ///
	BoxTrigger->OnComponentEndOverlap.AddDynamic(this, &AUnTrap::OnOverlapEnd);///
	//FIM //ITEM2
	
}

// Called every frame
void AUnTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//ITEM2
void AUnTrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)/////
{
	//ITEM2
	if (OtherActor != nullptr)///
	{////
		UE_LOG(LogTemp, Warning, TEXT("Coisou"));////
		Cast<AG1213ANTOCharacter>(OtherActor)->FunctionUnluck();////
		UE_LOG(LogTemp, Warning, TEXT("Overlap begin"));////
		/*Destroy(this);*/

	}/////


}////

void AUnTrap::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)////
{////
	UE_LOG(LogTemp, Warning, TEXT("Overlap end"));////
	this->Destroy(true);
}////

//FIM //ITEM2

