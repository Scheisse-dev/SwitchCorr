// Fill out your copyright notice in the Description page of Project Settings.

#include "SwitchCharaAnimation.h"
#include "SwitchCharacter.h"

void USwitchCharaAnimation::NativeBeginPlay()
{
	Bind();
}

void USwitchCharaAnimation::Bind()
{
	ASwitchCharacter* _char = Cast<ASwitchCharacter>(TryGetPawnOwner());
	if (!_char)
		return;
	_char->OnMoveForward().AddDynamic(this, &USwitchCharaAnimation::SetForwardSpeed);
}

void USwitchCharaAnimation::SetForwardSpeed(float _speed)
{
	forwardSpeed = _speed;
}
