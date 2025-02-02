#include "stdafx.h"
#include "PlayGround.h"
#include "IEvent.h"
#include "Bullet.h"

HRESULT PlayGround::Init()
{
	GameNode::Init(true);

	Player* player = new Player();

	OBJECTMANAGER->AddObject(ObjectType::Player, player);

	AI* ai = new AI();

	OBJECTMANAGER->AddObject(ObjectType::AI, ai);

	for (int i = 0; i < 20; ++i) {
		Bullet* bullet = new Bullet();

		OBJECTMANAGER->AddObject(ObjectType::Bullet, bullet);
	}

	for (int i = 0; i < 1; ++i) {
		Bullet* bullet2 = new Bullet();

		OBJECTMANAGER->AddObject(ObjectType::AIBullet, bullet2);
	}

	for (int i = 0; i < 1; ++i) {
		ReinforcedBullet* reinforcedBullet = new ReinforcedBullet();

		OBJECTMANAGER->AddObject(ObjectType::ReinforcedBullet, reinforcedBullet);
	}

	for (int i = 0; i < 3; ++i) {
		Shot* shot = new Shot();

		OBJECTMANAGER->AddObject(ObjectType::Shot, shot);
	}

	return S_OK;
}

void PlayGround::Release()
{
	OBJECTMANAGER->Release();
}

void PlayGround::Update()
{
	GameNode::Update();

	OBJECTMANAGER->Update();

	EventManager::GetInstance()->Update();	
}

void PlayGround::Render()
{	
	// 백버퍼 초기화
	D2DRenderer::GetInstance()->BeginRender(D2D1::ColorF::White);
	{
		OBJECTMANAGER->Render();
	}
	D2DRenderer::GetInstance()->EndRender();
}
