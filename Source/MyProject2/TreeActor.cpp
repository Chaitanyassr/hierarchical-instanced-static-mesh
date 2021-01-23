// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeActor.h"
#include "trees-10.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"

// Sets default values
ATreeActor::ATreeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TArray<Tree> arr;
	arr.SetNumUninitialized(trees.size());

	for (int i = 0; i < trees.size(); i++) {
		arr[i] = trees[i];
	}

	this->HISMC = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("HierarchicalInstancedStaticMesh"));

	SetRootComponent(this->HISMC);



}

// Called when the game starts or when spawned
void ATreeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATreeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

