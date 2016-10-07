// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyProject2Character.generated.h"

UCLASS()
class MYPROJECT2_API AMyProject2Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyProject2Character();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void SetColetavelLife(int NewColetavelLife);
	int GetColetavelLife();

	//FORCEINLINE int GetNewLife() const { return Life; }
	//FORCEINLINE void AMyProject2Character::SetNewLife(int NewLife) { Life = NewLife; }
	FORCEINLINE TArray<class AItem*> GetInventory() const { return Inventory; }

	void OnDeath();


private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere)
		UArrowComponent* ArrowComp;
	UPROPERTY(EditAnywhere)
		int ColetavelLife = 100;

	USphereComponent* CollectCollisionComp;
	TArray<class AItem*> Inventory;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartRun();
	void StopRun();
	void DropProjectile();
	void Turn(float Value);
	void OnCollect();


};
	

