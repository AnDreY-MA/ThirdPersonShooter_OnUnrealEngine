// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "CharacterController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCharacterAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	CharacterController = Cast<ACharacterController>(TryGetPawnOwner());
	if(CharacterController != nullptr)
	{
		FVector Velocity = CharacterController->GetVelocity();
		Velocity.Z = 0;
		Speed = Velocity.Size();

		bIsInAir = CharacterController->GetCharacterMovement()->IsFalling();

		if(CharacterController->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.0f)
		{
			bIsAccelerating = true;
		}
		else
		{
			bIsAccelerating = false;
		}

		FRotator AimRotation = CharacterController->GetBaseAimRotation();
		FString RotationMessage = FString::Printf(TEXT("Aim rotation: %f"), AimRotation.Yaw);
		
		FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(CharacterController->GetVelocity());

		OffsetAxis = UKismetMathLibrary::NormalizedDeltaRotator(CharacterController->GetControlRotation(), CharacterController->GetActorRotation());

		MovementOffsetYaw = UKismetMathLibrary::NormalizedDeltaRotator(
			MovementRotation, AimRotation).Yaw;
		
		if(CharacterController->GetVelocity().Size() > 0.f)
		{
			LastMovementOffsetYaw = MovementOffsetYaw;
		}

		bAiming = CharacterController->GetAiming();
	}
}

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	CharacterController = Cast<ACharacterController>(TryGetPawnOwner());

}

FRotator UCharacterAnimInstance::GetOffsetAxis()
{
	return OffsetAxis;
}
