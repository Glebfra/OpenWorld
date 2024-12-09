#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class OPENWORLD_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* LookAction;
	
	virtual void BeginPlay() override;
	
	void Move(const FInputActionValue& Value);
	
	void Look(const FInputActionValue& Value);

public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
