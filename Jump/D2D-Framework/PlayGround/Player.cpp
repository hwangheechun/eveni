#include "stdafx.h"
#include "Player.h"

Player::Player()
	: _gauge(0.f)
{
	Init();
}

Player::~Player()
{
}

void Player::Init()
{
	_name = L"Player";
	_position = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	_size = Vector2(100, 100);
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// 히트박스
	_active = true;

	// 커스텀 변수들
	_direction = Vector2(1, 0);
}

void Player::Release()
{
}

void Player::Update()
{
	const float rotationSpeed = 0.1f; // 회전 속도 (라디안)

	if (KEYMANAGER->IsStayKeyDown(VK_LEFT))
	{
		Move(Vector2(-10, 0), 10);
	}
	if (KEYMANAGER->IsStayKeyDown(VK_RIGHT))
	{
		Move(Vector2(10, 0), 10);
	}
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
	{
		auto vTest = OBJECTMANAGER->FindObjects(ObjectType::Bullet, L"Bullet");
		for (auto pObj : vTest) {
			if (pObj->GetActive())
				continue;
			pObj->Init();
			pObj->SetActive(true);
			break;
		}
	}
	if (KEYMANAGER->IsStayKeyDown(VK_SPACE))
	{
		
	}
	if (KEYMANAGER->IsOnceKeyUp(VK_SPACE))
	{
		
	}
}

void Player::Render()
{
	_D2DRenderer->FillRectangle(_rect, D2DRenderer::DefaultBrush::White);			// 채우기
	_D2DRenderer->DrawRectangle(_rect, D2DRenderer::DefaultBrush::Black, 1.0f);		// 라인

	_D2DRenderer->DrawLine(_position, _position + _direction * 100);
}

void Player::Move(Vector2 moveDirection, float speed)
{
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();	// == deltaTime
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}