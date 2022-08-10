// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

ATank::ATank()
{
    springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    if(springArm)
    {
        springArm->SetupAttachment(RootComponent);
        
        camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
        if(camera)
        {
            camera->SetupAttachment(springArm);
        }
    }
    dLocation = {0.0f,0.0f,0.0f};

}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    //APawn::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::MoveForward );
}

void ATank::MoveForward(float axisValue)
{
    if(axisValue){
        dLocation.X = axisValue;
        AddActorLocalOffset(dLocation);
    }
}