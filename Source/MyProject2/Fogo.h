// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Fogo.generated.h"

UCLASS()
class MYPROJECT2_API AFogo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFogo();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
