// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreeActor.generated.h"

class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FTrees {
	GENERATED_BODY()

public:
	// Values are in standard Unreal Engine coordinates (centimeters)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeVar")
	float positionX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeVar")
	float positionY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeVar")
	float positionZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeVar")
	float height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeVar")
	float canopyRadius;
};

UCLASS()
class MYPROJECT2_API ATreeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATreeActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTrees TreeStruct;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UHierarchicalInstancedStaticMeshComponent* HISMC;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
