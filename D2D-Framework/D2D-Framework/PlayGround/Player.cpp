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
	
	_angle = atan2(_direction.y, _direction.x); //* 180 / 3.141592;
	//_direction = Vector2(1, 0);
	_direction = Vector2((float)cos(_angle), sin(_angle));
	_gaugeRect = RectMakePivot(_position + Vector2(0, 60), Vector2(40.f, 10.f), Pivot::Center);

}

void Player::Release()
{
}

void Player::Update()
{
	const float rotationSpeed = 0.1f; // 회전 속도 (라디안)	
	
	if (KEYMANAGER->IsStayKeyDown(VK_LEFT))
	{

		// TODO : 회전 처리
#pragma region 7주차 과제_왼쪽 회전 처리
		MoveAngle(-4, 0);
		_direction.x = cos(_angle);
		_direction.y = sin(_angle);
#pragma endregion
	}
	if (KEYMANAGER->IsStayKeyDown(VK_RIGHT))
	{
#pragma region 7주차 과제_오른쪽 회전 처리
		MoveAngle(4, 0);
		_direction.x = cos(_angle);
		_direction.y = sin(_angle);
#pragma endregion
	}
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
	{
		
	}
	if (KEYMANAGER->IsStayKeyDown(VK_SPACE))
	{
		_gauge = min(_gauge + 0.05f, 1.0f);
	}
	if (KEYMANAGER->IsOnceKeyUp(VK_SPACE))
	{
#pragma region 7주차 과제_게이지에 따른 탄환 변환
		if (_gauge < 0.5f)
		{
			// 바로바로 생성하셔도 무방
			// 저는 미리 생성해 놓고 꺼내 쓰는 방식을 선택함 (PlayGround::Init 참고)
			auto vTest = OBJECTMANAGER->FindObjects(ObjectType::Bullet, L"Bullet");
			for (auto pObj : vTest) {	//벡터 반복문
				if (pObj->GetActive())
					continue;
				pObj->Init();
				pObj->SetActive(true);
				break;
			}
			_gauge = 0;
		}
		else
		{
			auto vTest = OBJECTMANAGER->FindObjects(ObjectType::ReinforcedBullet, L"ReinforcedBullet");
			for (auto pObj : vTest) {
				if (pObj->GetActive())
					continue;
				pObj->Init();
				pObj->SetActive(true);
				break;
			}
			_gauge = 0;
#pragma endregion
		}
	}
#pragma region 7주차 과제_산탄
	if (KEYMANAGER->IsOnceKeyDown(0x5A))
	{
		auto vTest = OBJECTMANAGER->FindObjects(ObjectType::Shot, L"Shot");
		for (auto pObj : vTest) {
			if (pObj->GetActive())
				continue;
			pObj->Init();
			pObj->SetActive(true);
			break;
		}
		//_gauge = 0; 필요 없는 듯
	}
#pragma endregion
}

void Player::Render()
{
	_D2DRenderer->FillRectangle(_rect, D2DRenderer::DefaultBrush::White);			// 채우기
	_D2DRenderer->DrawRectangle(_rect, D2DRenderer::DefaultBrush::Black, 1.0f);		// 라인

	_D2DRenderer->DrawLine(_position, _position + _direction * 100);

	FloatRect greenRect{ _gaugeRect.left, _gaugeRect.top, _gaugeRect.left + _gaugeRect.GetWidth() * _gauge, _gaugeRect.bottom };
	_D2DRenderer->FillRectangle(greenRect, D2DRenderer::DefaultBrush::Green);
	_D2DRenderer->DrawRectangle(_gaugeRect);

	
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