#include "stdafx.h"
#include "AI.h"
#include <string>

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

	// 커스텀 변수들

	_angle = atan2(_direction.y, _direction.x); //* 180 / 3.141592;
	_direction = Vector2((float)cos(_angle), sin(_angle));
	_gaugeRect = RectMakePivot(_position + Vector2(0, 60), Vector2(40.f, 10.f), Pivot::Center);

	_HP = RectMakePivot(Vector2(1420, 80), Vector2(800.f, 80.f), Pivot::Center);
	_HPBar = 1.f;
}

void AI::Release()
{
}

void AI::Update()
{
	auto vBullet = OBJECTMANAGER->FindObjects(ObjectType::Bullet, L"Bullet");
	auto vReinforcedBullet = OBJECTMANAGER->FindObjects(ObjectType::ReinforcedBullet, L"ReinforcedBullet");


	for (auto pObj : vBullet) {	//벡터 반복문
		if (pObj->GetPosition().x < _position.x + _size.x / 2 && pObj->GetPosition().x > _position.x - _size.x / 2
			&& pObj->GetPosition().y < _position.y + _size.y / 2 && pObj->GetPosition().y > _position.y - _size.y / 2
			&& pObj->GetActive() == true)

		{
			//포탄 충돌 처리
			isCollide = true;

			_HPBar -= 5.0f * TIMEMANAGER->GetElapsedTime();
			pObj->SetActive(false);
		}
	}
	for (auto pObj : vReinforcedBullet) {	//벡터 반복문
		if (pObj->GetPosition().x < _position.x + _size.x / 2 && pObj->GetPosition().x > _position.x - _size.x / 2
			&& pObj->GetPosition().y < _position.y + _size.y / 2 && pObj->GetPosition().y > _position.y - _size.y / 2
			&& pObj->GetActive() == true)
		{
			//포탄 충돌 처리
			isCollide = true;

			_HPBar -= 5.0f * TIMEMANAGER->GetElapsedTime();
			pObj->SetActive(false);
		}
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
	_D2DRenderer->FillRectangle(HPRect, D2DRenderer::DefaultBrush::Green);
	_D2DRenderer->DrawRectangle(_HP);
}

void AI::Move(Vector2 moveDirection, float speed)
{
	// 예시 1
	/*
	_position.x += moveDirection.x * speed * TIMEMANAGER->GetElapsedTime();
	_position.y += moveDirection.y * speed * TIMEMANAGER->GetElapsedTime();
	_rect = RectMakePivot(_position, _size, Pivot::Center);
	*/

	// 예시 2
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();	// == deltaTime
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}

#pragma region 7주차 과제_MoveAngle 함수 구현
void AI::MoveAngle(float angle, float speed)
{
	_angle += angle * TIMEMANAGER->GetElapsedTime();	//60프레임 기준 한 프레임 당, angle 값과 한 프레임 그리는 데 걸리는 시간을 곱한 값을 더해준다(개념적 이해) -> 설정한 angle만큼 커지는 순간 순간이 1초에 60번 보인다	
	//만약 deltaTime을 곱해주지 않는다면 60프레임 기준 의도한 바의 60배만큼 움직여 빠르게 보인다
}
#pragma endregion