// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "Fogo.h"


// Sets default values
AFogo::AFogo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFogo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFogo::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

