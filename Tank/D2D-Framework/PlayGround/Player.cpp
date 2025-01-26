#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
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
	_position = Vector2(WINSIZEX / 2 - 500, WINSIZEY / 2 + 280);
	_size = Vector2(100, 100);
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// 히트박스
	_active = true;

	// 커스텀 변수들
	
	_angle = atan2(_direction.y, _direction.x); //* 180 / 3.141592;
	_direction = Vector2((float)cos(_angle), sin(_angle));
	_gaugeRect = RectMakePivot(_position + Vector2(0, 60), Vector2(40.f, 10.f), Pivot::Center);

	_HP = RectMakePivot(Vector2(500, 80), Vector2(800.f, 80.f), Pivot::Center);
	_HPBar = 1.f;
}

void Player::Release()
{
}

void Player::Update()
{
	const float rotationSpeed = 0.1f; // 회전 속도 (라디안)	
	_gaugeRect = RectMakePivot(_position + Vector2(0, 60), Vector2(40.f, 10.f), Pivot::Center);
	auto vBullet = OBJECTMANAGER->FindObjects(ObjectType::Bullet, L"Bullet");
	auto vReinforcedBullet = OBJECTMANAGER->FindObjects(ObjectType::ReinforcedBullet, L"ReinforcedBullet");
	auto vShot = OBJECTMANAGER->FindObjects(ObjectType::Shot, L"Shot");

	for (auto pObj : vReinforcedBullet) {
		if (pObj->GetActive())
			continue;

		auto pReinforcedBulletObj = dynamic_cast<ReinforcedBullet*>(pObj);

		pReinforcedBulletObj->Init();
		break;
	}


	if (KEYMANAGER->IsStayKeyDown(0x57))	//W키
	{
#pragma region 7주차 과제_왼쪽 회전 처리
		MoveAngle(-4, 0);
		_direction.x = cos(_angle);
		_direction.y = sin(_angle);
#pragma endregion
	}
	if (KEYMANAGER->IsStayKeyDown(0x53))	//S키
	{
#pragma region 7주차 과제_오른쪽 회전 처리
		MoveAngle(4, 0);
		_direction.x = cos(_angle);
		_direction.y = sin(_angle);
#pragma endregion
	}
	
	if (KEYMANAGER->IsStayKeyDown(0x41))
	{
		Move(Vector2(-10, 0), 10);
	}
	if (KEYMANAGER->IsStayKeyDown(0x44))
	{
		Move(Vector2(10, 0), 10);
	}
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
	{
		
	}
	if (KEYMANAGER->IsStayKeyDown(VK_SPACE))
	{
		_gauge = min(_gauge + 0.05f, 1.0f);
		for (auto pObj : vReinforcedBullet) {
			if (pObj->GetActive())
				continue;

			auto pReinforcedBulletObj = dynamic_cast<ReinforcedBullet*>(pObj);

			pReinforcedBulletObj->_isReady = true;
			break;
		}
	}
	if (KEYMANAGER->IsOnceKeyUp(VK_SPACE))
	{
#pragma region 7주차 과제_게이지에 따른 탄환 변환
		if (_gauge < 0.5f)
		{
			// 바로바로 생성하셔도 무방
			// 저는 미리 생성해 놓고 꺼내 쓰는 방식을 선택함 (PlayGround::Init 참고)
			for (auto pObj : vBullet) {	//벡터 반복문
				if (pObj->GetActive())
					continue;
				pObj->Init();
				pObj->SetActive(true);
				
				auto pBulletObj = dynamic_cast<Bullet*>(pObj);

				pBulletObj->_isFire = true;

				break;
			}
			_gauge = 0;
		}
		else
		{
			for (auto pObj : vReinforcedBullet) {
				if (pObj->GetActive())
					continue;

				auto pReinforcedBulletObj = dynamic_cast<ReinforcedBullet*>(pObj);

				pReinforcedBulletObj->SetActive(true);
				pReinforcedBulletObj->_isFire = true;
				pReinforcedBulletObj->_isReady = false;
				break;
			}
			_gauge = 0;
#pragma endregion
		}
	}
#pragma region 7주차 과제_산탄
	if (KEYMANAGER->IsOnceKeyDown(0x5A))
	{
		
		for (auto pObj : vShot) {
			if (pObj->GetActive())
				continue;

			pObj->Init();
			pObj->SetActive(true);
			break;
		}
		for (auto pObj : vShot) {
			if (pObj->GetActive())
				continue;

			auto pShotObj = dynamic_cast<Shot*>(pObj);

			pShotObj->Init();
			pShotObj->SetType(0.1);
			pShotObj->SetActive(true);

			break;
		}
		for (auto pObj : vShot) {
			if (pObj->GetActive())
				continue;

			auto pShotObj = dynamic_cast<Shot*>(pObj);

			pShotObj->Init();
			pShotObj->SetType(-0.1);
			pShotObj->SetActive(true);

			break;
		}
		//3개의 Init 방법 고민_ 벡터를 돌면서 active의 값을 true인지 false인지 구별하며 3번 Init
	}
#pragma endregion
	
		//충돌 처리
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

void Player::Render()
{
	auto vReinforcedBullet = OBJECTMANAGER->FindObjects(ObjectType::ReinforcedBullet, L"ReinforcedBullet");


	_D2DRenderer->FillRectangle(_rect, D2DRenderer::DefaultBrush::White);			// 채우기
	_D2DRenderer->DrawRectangle(_rect, D2DRenderer::DefaultBrush::Black, 1.0f);		// 라인

	_D2DRenderer->DrawLine(_position, _position + _direction * 100);

	FloatRect greenRect{ _gaugeRect.left, _gaugeRect.top, _gaugeRect.left + _gaugeRect.GetWidth() * _gauge, _gaugeRect.bottom };

	_D2DRenderer->FillRectangle(greenRect, D2DRenderer::DefaultBrush::Green);
	_D2DRenderer->DrawRectangle(_gaugeRect);

	FloatRect HPRect{ _HP.left, _HP.top, _HP.left + _HP.GetWidth() * _HPBar, _HP.bottom};
	_D2DRenderer->FillRectangle(HPRect, D2DRenderer::DefaultBrush::Green);
	_D2DRenderer->DrawRectangle(_HP);

	if (KEYMANAGER->IsStayKeyDown(VK_SPACE))
	{
		for (auto pObj : vReinforcedBullet) {
			if (pObj->GetActive())
				continue;

			auto pReinforcedBulletObj = dynamic_cast<ReinforcedBullet*>(pObj);

			pReinforcedBulletObj->Trajectory();
			break;
		}
		
	}
}

void Player::Move(Vector2 moveDirection, float speed)
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
void Player::MoveAngle(float angle, float speed)
{
	_angle += angle * TIMEMANAGER->GetElapsedTime();	//60프레임 기준 한 프레임 당, angle 값과 한 프레임 그리는 데 걸리는 시간을 곱한 값을 더해준다(개념적 이해) -> 설정한 angle만큼 커지는 순간 순간이 1초에 60번 보인다	
														//만약 deltaTime을 곱해주지 않는다면 60프레임 기준 의도한 바의 60배만큼 움직여 빠르게 보인다
}
#pragma endregion