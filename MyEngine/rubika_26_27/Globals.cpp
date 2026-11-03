#include "Globals.h"

#include <DebugMgr.h>
#include <Logger.h>

Globals gData;

Globals::Globals() : FrameCount(0)
{
	DebugMgr = new ::DebugMgr();
	Logger = new ::Logger();
	TextureMgr  =  new ::TextureMgr();
	InputMgr    =  new ::InputMgr();
}

Globals::~Globals()
{
	Destroy();
}

void Globals::Init()
{
	Logger->Init();
	TextureMgr->Init();
	InputMgr->Init();
}

void Globals::Update(float deltaTime)
{
	InputMgr->Update(deltaTime);
}

void Globals::Shut()
{
	Logger->Shut();
}

void Globals::Destroy()
{
	delete DebugMgr;
	DebugMgr = nullptr;

	delete Logger;
	Logger = nullptr;
}

void Globals::IncrementFrameCount()
{
	++FrameCount;
}
