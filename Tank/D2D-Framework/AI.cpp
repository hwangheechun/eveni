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
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// ��Ʈ�ڽ�
	_active = true;
	_direction = Vector2(-1, 0);
	// Ŀ���� ������

	_angle = atan2(_direction.y, _direction.x); //* 180 / 3.141592;
	_direction = Vector2((float)cos(_angle), sin(_angle));
	_gaugeRect = RectMakePivot(_position + Vector2(0, 60), Vector2(40.f, 10.f), Pivot::Center);

	_HP = RectMakePivot(Vector2(1420, 80), Vector2(800.f, 80.f), Pivot::Center);
	_HPBar = 1.f;

	_moveTime = 0;
}

void AI::Release()
{
}

void AI::Update()
{
	srand((unsigned int)time(NULL));

	auto vBullet = OBJECTMANAGER->FindObjects(ObjectType::Bullet, L"Bullet");
	auto AIvBullet = OBJECTMANAGER->FindObjects(ObjectType::AIBullet, L"Bullet");
	auto vReinforcedBullet = OBJECTMANAGER->FindObjects(ObjectType::ReinforcedBullet, L"ReinforcedBullet");

	for (auto pObj : AIvBullet) {
		if (pObj->GetActive())
			continue;

		auto pBulletObj = dynamic_cast<Bullet*>(pObj);

		pBulletObj->_isAI = true;
		break;
	}

	_gaugeRect = RectMakePivot(_position + Vector2(0, 60), Vector2(40.f, 10.f), Pivot::Center);
	if(_position.x > 1350 || _position.x < 1920)
		Move(Vector2((rand() % 21 - 10), 0), 10);	//���� ������ -10 ~ 10

	for (auto pObj : vBullet) {	//���� �ݺ���
		if (pObj->GetPosition().x < _position.x + _size.x / 2 && pObj->GetPosition().x > _position.x - _size.x / 2
			&& pObj->GetPosition().y < _position.y + _size.y / 2 && pObj->GetPosition().y > _position.y - _size.y / 2
			&& pObj->GetActive() == true)

		{
			//��ź �浹 ó��
			isCollide = true;

			_HPBar -= 2.0f * TIMEMANAGER->GetElapsedTime();
			pObj->SetActive(false);
		}
	}
	for (auto pObj : vReinforcedBullet) {	//���� �ݺ���
		if (pObj->GetPosition().x < _position.x + _size.x / 2 && pObj->GetPosition().x > _position.x - _size.x / 2
			&& pObj->GetPosition().y < _position.y + _size.y / 2 && pObj->GetPosition().y > _position.y - _size.y / 2
			&& pObj->GetActive() == true)
		{
			//��ź �浹 ó��
			isCollide = true;

			_HPBar -= 5.0f * TIMEMANAGER->GetElapsedTime();
			pObj->SetActive(false);
		}
	}

	for (auto pObj : AIvBullet) {	
		if (pObj->GetActive())
			continue;
		pObj->Init();
		pObj->SetActive(true);

		auto pBulletObj = dynamic_cast<Bullet*>(pObj);

		pBulletObj->_isAI = true;
		pBulletObj->_isFire = true;
		break;
	} // �� �κ� �ٲ�� �� �� ���� 
}

void AI::Render()
{
	_D2DRenderer->FillRectangle(_rect, D2DRenderer::DefaultBrush::White);			// ä���
	_D2DRenderer->DrawRectangle(_rect, D2DRenderer::DefaultBrush::Black, 1.0f);		// ����

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
	// ���� 1
	/*
	_position.x += moveDirection.x * speed * TIMEMANAGER->GetElapsedTime();
	_position.y += moveDirection.y * speed * TIMEMANAGER->GetElapsedTime();
	_rect = RectMakePivot(_position, _size, Pivot::Center);
	*/

	// ���� 2
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();	// == deltaTime
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}

#pragma region 7���� ����_MoveAngle �Լ� ����
void AI::MoveAngle(float angle, float speed)
{
	_angle += angle * TIMEMANAGER->GetElapsedTime();	//60������ ���� �� ������ ��, angle ���� �� ������ �׸��� �� �ɸ��� �ð��� ���� ���� �����ش�(������ ����) -> ������ angle��ŭ Ŀ���� ���� ������ 1�ʿ� 60�� ���δ�	
	//���� deltaTime�� �������� �ʴ´ٸ� 60������ ���� �ǵ��� ���� 60�踸ŭ ������ ������ ���δ�
}
#pragma endregion