#include "stdafx.h"
#include "AI.h"
#include <string>
#include "../PlayGround/Bullet.h"

AI::AI()
	: _gauge(0.f)
{
	Init();
}

AI::~AI()
{
}

void AI::Init()
{
	_name = L"AI";
	_position = Vector2(WINSIZEX / 2 + 500, WINSIZEY / 2 + 280);
	_size = Vector2(100, 100);
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// 히트박스
	_active = true;
	_direction = Vector2(-1, 0);
	// 커스텀 변수들

	_angle = atan2(_direction.y, _direction.x); //* 180 / 3.141592;
	_direction = Vector2((float)cos(_angle), sin(_angle));
	_gaugeRect = RectMakePivot(_position + Vector2(0, 60), Vector2(40.f, 10.f), Pivot::Center);

	_HP = RectMakePivot(Vector2(1420, 80), Vector2(800.f, 80.f), Pivot::Center);
	_HPBar = 1.f;

	_moveTime = 0;
	_player = OBJECTMANAGER->FindObject(ObjectType::Player, L"Player");

	isDead = false;
}

void AI::Release()
{
}

void AI::Update()
{
	srand((unsigned int)time(NULL));

	auto vBullet = OBJECTMANAGER->FindObjects(ObjectType::Bullet, L"Bullet");
	auto vAIBullet = OBJECTMANAGER->FindObjects(ObjectType::AIBullet, L"Bullet");
	auto vReinforcedBullet = OBJECTMANAGER->FindObjects(ObjectType::ReinforcedBullet, L"ReinforcedBullet");



	for (auto pObj : vAIBullet) {
		if (pObj->GetActive())
			continue;

		
		auto pBulletObj = dynamic_cast<Bullet*>(pObj);
		pBulletObj->Init("AI");
		pBulletObj->SetActive(true);
		pBulletObj->_isFire = true;

		break;
	}

	_gaugeRect = RectMakePivot(_position + Vector2(0, 60), Vector2(40.f, 10.f), Pivot::Center);
	if(_position.x > 1350 || _position.x < 1920)
		Move(Vector2((rand() % 21 - 10), 0), 10);	//랜덤 움직임 -10 ~ 10

	for (auto pObj : vBullet) {	
		if (pObj->GetPosition().x < _position.x + _size.x / 2 && pObj->GetPosition().x > _position.x - _size.x / 2
			&& pObj->GetPosition().y < _position.y + _size.y / 2 && pObj->GetPosition().y > _position.y - _size.y / 2
			&& pObj->GetActive() == true)

		{
			
			isCollide = true;

			if (_HPBar <= 0)
			{
				isDead = true;
				break;
			}
			else
			{
				_HPBar -= 5.0f * TIMEMANAGER->GetElapsedTime();
			}
			pObj->SetActive(false);
		}
	}
	for (auto pObj : vReinforcedBullet) {
		if (pObj->GetPosition().x < _position.x + _size.x / 2 && pObj->GetPosition().x > _position.x - _size.x / 2
			&& pObj->GetPosition().y < _position.y + _size.y / 2 && pObj->GetPosition().y > _position.y - _size.y / 2
			&& pObj->GetActive() == true)
		{
			
			isCollide = true;

			if (_HPBar < 0)
			{

				isDead = true;
				break;
			}
			else
			{
				if (_HPBar >= 0.1f)
					_HPBar -= 10.0f * TIMEMANAGER->GetElapsedTime();
				else
					_HPBar = 0.0f;
			}
			pObj->SetActive(false);
		}
	}

	//if (_position.x - _player->GetPosition().x < 400 && _position.x - _player->GetPosition().x > 0)	//거리가 0~400 사이면
	//{
	//	_direction = Vector2(-1, -0.5);
	//}
	if (abs(_position.x - _player->GetPosition().x) > 1000) //거리가 600보다 멀면
	{
		_direction = Vector2(-1, -1);
	}
	else if (abs(_position.x - _player->GetPosition().x) <= 600 && abs(_position.x - _player->GetPosition().x) > 400)	//거리가 300~600 사이면
	{
		_direction = Vector2(-1, 0);
	}
}

void AI::Render()
{
	_D2DRenderer->FillRectangle(_rect, D2DRenderer::DefaultBrush::White);			// 채우기
	_D2DRenderer->DrawRectangle(_rect, D2DRenderer::DefaultBrush::Black, 1.0f);		// 라인

	_D2DRenderer->DrawLine(_position, _position + _direction * 100);

	FloatRect greenRect{ _gaugeRect.left, _gaugeRect.top, _gaugeRect.left + _gaugeRect.GetWidth() * _gauge, _gaugeRect.bottom };

	_D2DRenderer->FillRectangle(greenRect, D2DRenderer::DefaultBrush::Green);
	_D2DRenderer->DrawRectangle(_gaugeRect);

	FloatRect HPRect{ _HP.left, _HP.top, _HP.left + _HP.GetWidth() * _HPBar, _HP.bottom };

	_D2DRenderer->DrawRectangle(_HP);

	if (_HPBar > 0.7f)
		_D2DRenderer->FillRectangle(HPRect, D2DRenderer::DefaultBrush::Green);
	else if (_HPBar <= 0.7 && _HPBar > 0.2)
		_D2DRenderer->FillRectangle(HPRect, D2DRenderer::DefaultBrush::Yellow);
	else
		_D2DRenderer->FillRectangle(HPRect, D2DRenderer::DefaultBrush::Red);

	if (_HPBar <= 0)
		_D2DRenderer->RenderText(WINSIZEX / 2, WINSIZEY / 2, L"승리", 50);
	
}

void AI::Move(Vector2 moveDirection, float speed)
{
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();	// == deltaTime
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}

#pragma region 7주차 과제_MoveAngle 함수 구현
void AI::MoveAngle(float angle, float speed)
{
	_angle += angle * TIMEMANAGER->GetElapsedTime();	
}
#pragma endregion