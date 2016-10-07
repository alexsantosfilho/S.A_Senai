// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "MyProject2Character.h"
#include "ProjectActor.h"
#include "Item.h"
#include "ColetavelLife.h"

// Sets default values
AMyProject2Character::AMyProject2Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->bGenerateOverlapEvents = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(GetCapsuleComponent());

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	PlayerCamera->AttachTo(CameraBoom);

	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComp"));
	ArrowComp->SetHiddenInGame(false);
	ArrowComp->ArrowSize = 2.0f;
	ArrowComp->AttachTo(MeshComp);

	CollectCollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollectCollision"));
	CollectCollisionComp->InitSphereRadius(200.0f);
	CollectCollisionComp->AttachTo(RootComponent);

	GetCharacterMovement()->MaxWalkSpeed = 400;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMyProject2Character::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Exemplo!"));

	
}

// Called every frame
void AMyProject2Character::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyProject2Character::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &AMyProject2Character::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyProject2Character::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMyProject2Character::Turn);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyProject2Character::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyProject2Character::StopJumping);
	InputComponent->BindAction("Run", IE_Pressed, this, &AMyProject2Character::StartRun);
	InputComponent->BindAction("Run", IE_Released, this, &AMyProject2Character::StopRun);

	InputComponent->BindAction("Drop", IE_Pressed, this, &AMyProject2Character::DropProjectile);
	InputComponent->BindAction("Collect", IE_Pressed, this, &AMyProject2Character::OnCollect);
}

void AMyProject2Character::MoveForward(float Value) {
	if (false) {
		UE_LOG(LogTemp, Warning, TEXT("Vai conflitar!"));
	}
	FVector Forward(0, 1, 0);
	AddMovementInput(Forward, Value);
}

void AMyProject2Character::MoveRight(float Value) {
	FVector Right(1, 0, 0);
	AddMovementInput(Right, Value);
}

void AMyProject2Character::StartRun() {
	GetCharacterMovement()->MaxWalkSpeed = 800;
}

void AMyProject2Character::StopRun() {
	GetCharacterMovement()->MaxWalkSpeed = 400;
}

void AMyProject2Character::SetColetavelLife(int NewColetavelLife) {
	ColetavelLife = NewColetavelLife;

}
int AMyProject2Character::GetColetavelLife() {
	return ColetavelLife;
}

void AMyProject2Character::OnDeath() {
	if (ColetavelLife <= 0) {
		FVector InitialLocation(-7414.0f, 137.002579f, 226.001587f);
		ColetavelLife = 3;
		SetActorLocation(InitialLocation);
		UE_LOG(LogTemp, Warning, TEXT("Voce morreu!3"));
	}

}


void AMyProject2Character::OnCollect() {
	TArray<AActor*> AtoresColetados;
	CollectCollisionComp->GetOverlappingActors(AtoresColetados);

	for (int i = 0; i < AtoresColetados.Num(); i++) {
		if (AtoresColetados[i]->IsA(AItem::StaticClass())) {
			AItem* ItemColetado = Cast<AItem>(AtoresColetados[i]);
			Inventory.Add(ItemColetado);
			ItemColetado->Destroy();
			UE_LOG(LogTemp, Warning, TEXT("%d"), Inventory.Num());
		}
//		else if (AtoresColetados[i]->IsA(AAlavanca::StaticClass())) {
		//	AAlavanca* Alavanca = Cast<AAlavanca>(AtoresColetados[i]);
		//	Alavanca->OnPressed();
		//}
	}
}