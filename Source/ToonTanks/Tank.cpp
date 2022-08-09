// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

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

}