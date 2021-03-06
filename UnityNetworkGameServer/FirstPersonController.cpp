﻿#include "FirstPersonController.h"
#include <MinNetPool.h>
#include <MinNet.h>

FirstPersonController::~FirstPersonController()
{

}

void FirstPersonController::InitRPC()
{
	DefRPC("SyncPosition", std::bind(&FirstPersonController::SyncPosition, this, std::placeholders::_1));
}

void FirstPersonController::SyncPosition(MinNetPacket * rpcPacket)
{
	auto position = rpcPacket->pop_vector3();
	auto euler = rpcPacket->pop_vector3();
	auto cameraEuler = rpcPacket->pop_vector3();

	gameObject->position = position;
}