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
	_position = Vector2(WINSIZEX / 2 + 100, WINSIZEY / 2);
	_size = Vector2(100, 100);
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// 히트박스
	_active = true;

	// 커스텀 변수들
	_direction = Vector2(1, 0);

	_gravity = 30.0f;
	_onGround = false;
}

void Player::Release()
{
}

void Player::Update()
{
	if(!_onGround)
		Move(Vector2(0.0f, _gravity), 10);

	//_position.y += _gravity;

	const float rotationSpeed = 0.1f; // 회전 속도 (라디안)

	if (KEYMANAGER->IsStayKeyDown(VK_LEFT))
	{
		Move(Vector2(-10, 0), 10);
	}
	if (KEYMANAGER->IsStayKeyDown(VK_RIGHT))
	{
		Move(Vector2(10, 0), 10);
	}
	if (KEYMANAGER->IsOnceKeyDown(VK_UP))
	{
		Move(Vector2(0, -1000), 10);
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
		_gravity = 0;
		_onGround = true;
		//Move(Vector2(0.0f, -_gravity), 10);
	}
	else
	{
		_gravity = 30.0f;
		_onGround = false;
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