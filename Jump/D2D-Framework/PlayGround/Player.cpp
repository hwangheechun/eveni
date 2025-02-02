#include "stdafx.h"
#include "Player.h"
#include <string>

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
	_position = Vector2(WINSIZEX / 2, WINSIZEY / 2 - 300);
	_size = Vector2(50, 50);
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// 히트박스
	_active = true;

	// 커스텀 변수들
	_direction = Vector2(1, 0);

	_gravity = 10.0f;
	_onGround = false;
}

void Player::Release()
{
}

void Player::Update()
{
	_gravity += 2.0f;

	if(!_onGround)
	Move(Vector2(0.0f, _gravity), 10);

	const float rotationSpeed = 0.1f;

	if (KEYMANAGER->IsStayKeyDown(VK_LEFT))
	{
		Move(Vector2(-10, 0), 10);
	}
	if (KEYMANAGER->IsStayKeyDown(VK_RIGHT))
	{
		Move(Vector2(10, 0), 10);
	}
	
	if (KEYMANAGER->IsStayKeyDown(VK_SPACE))
	{
		
	}
	if (KEYMANAGER->IsOnceKeyUp(VK_SPACE))
	{
		
	}

	_ground = (OBJECTMANAGER->FindObject(ObjectType::Ground, L"Ground"));

	if (_position.y + _size.y / 2 >= _ground->GetPosition().y - _ground->GetSize().y / 2)
	{
		_onGround = true;
		
		if (KEYMANAGER->IsOnceKeyDown(VK_UP))
		{
			_onGround = false;
			_gravity = -60.0f;
		}
	}
}

void Player::Render()
{
	_D2DRenderer->FillRectangle(_rect, D2DRenderer::DefaultBrush::White);			// 채우기
	_D2DRenderer->DrawRectangle(_rect, D2DRenderer::DefaultBrush::Black, 1.0f);		// 라인

	_D2DRenderer->DrawLine(_position, _position + _direction * 100);

	_D2DRenderer->RenderText(0, 0, L"땅에 착지하면 true" + to_wstring(_onGround), 50);
}

void Player::Move(Vector2 moveDirection, float speed)
{
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();	// == deltaTime
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}