#include "stdafx.h"
#include "PlayGround.h"
#include "IEvent.h"
#include "Bullet.h"
#include "Ground.h"

HRESULT PlayGround::Init()
{
	GameNode::Init(true);

	Player* player = new Player();

	OBJECTMANAGER->AddObject(ObjectType::Player, player);

	/*for (int i = 0; i < 50; ++i) {
		Bullet* bullet = new Bullet();

		OBJECTMANAGER->AddObject(ObjectType::Bullet, bullet);
	}*/

	Ground* ground = new Ground();
	OBJECTMANAGER->AddObject(ObjectType::Ground, ground);

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
