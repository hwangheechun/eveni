#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"
#include <string>

Bullet::Bullet()
	: _player(nullptr), _isInit(false)
{
	Init();
}

Bullet::~Bullet()
{
	//소멸자 구현 내용
}

void Bullet::Init()
{
	_name = L"Bullet";
	_position = Vector2(WINSIZEX / 2 - 100, WINSIZEY / 2 - 100);
	_size = Vector2(10, 10);
	_rect = RectMakePivot(_position, _size, Pivot::Center);
	_active = false;	// 미리 생성 후 가져다 쓸 용도로 이렇게 설정함, 생성해서 쓰려면 true로 놓는 것이 맞음

	_direction = Vector2(1, 0);
	_isInit = false;

	_player = dynamic_cast<Player*>(OBJECTMANAGER->FindObject(ObjectType::Player, L"Player"));
	if (_player)
	{
		_position = _player->GetPosition();
		_direction = _player->GetDirection();	//추가한 문구
		
		//_size.x = max(_size.x * _player->_gauge, 10);	//10보다 작으면 10, 10보다 크면 해당 값
	}

	
}

void Bullet::Release()
{
	Bullet::~Bullet();
}

void Bullet::Update()
{
	Move(_direction ,200.0f);

	if (_position.x >= WINSIZEX || _position.x <= 0 || _position.y >= WINSIZEY || _position.y <= 0)
	{
		this->Release();
	}
}

void Bullet::Render()
{
	D2DRenderer::GetInstance()->DrawEllipse(_position, _size.x, D2DRenderer::DefaultBrush::Black, 1.0f);
	
	
	_D2DRenderer->RenderText(10, 10, L"일반 탄환 x:" + to_wstring(_position.x) + L"  y:" + to_wstring(_position.y), 20);
}

void Bullet::Move(Vector2 moveDirection, float speed)
{
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}

void Bullet::MoveAngle(float speed)
{
	_position += _direction * speed * TIMEMANAGER->GetElapsedTime();
	_rect.Update(_position, _size, Pivot::Center);
}

#pragma region 7주차 과제_강화 탄환
ReinforcedBullet::ReinforcedBullet()
	: _player(nullptr), _isInit(false)
{
	Init();
}

ReinforcedBullet::~ReinforcedBullet()
{
	
}

void ReinforcedBullet::Init()
{
	_name = L"ReinforcedBullet";
	_position = Vector2(WINSIZEX / 2 - 100, WINSIZEY / 2 - 100);
	_size = Vector2(20, 20);
	_rect = RectMakePivot(_position, _size, Pivot::Center);
	_active = false;	

	_direction = Vector2(1, 0);
	_isInit = false;

	_player = dynamic_cast<Player*>(OBJECTMANAGER->FindObject(ObjectType::Player, L"Player"));
	if (_player)
	{
		_position = _player->GetPosition();
		_direction = _player->GetDirection();
	}

	countCollide = 4;
}

void ReinforcedBullet::Release()
{
	ReinforcedBullet::~ReinforcedBullet();
}

void ReinforcedBullet::Update()
{
	Move(_direction, 450.0f);

	if (countCollide > 0)
	{
		if (_position.x >= WINSIZEX || _position.x <= 0)
		{
			_direction.x = -_direction.x;
			countCollide--;
		}
		if (_position.y >= WINSIZEY || _position.y <= 0)
		{
			_direction.y = -_direction.y;
			countCollide--;
		}
	}
}

void ReinforcedBullet::Render()
{
	D2DRenderer::GetInstance()->DrawEllipse(_position, _size.x, D2DRenderer::DefaultBrush::Red, 3.0f);

	_D2DRenderer->RenderText(10, 50, L"강화 탄환 x:" + to_wstring(_position.x) + L"  y:" + to_wstring(_position.y), 20);
}

void ReinforcedBullet::Move(Vector2 moveDirection, float speed)
{
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}

void ReinforcedBullet::MoveAngle(float speed)
{
	_position += _direction * speed * TIMEMANAGER->GetElapsedTime();
	_rect.Update(_position, _size, Pivot::Center);
}
#pragma endregion

#pragma region 7주차 과제_산탄
Shot::Shot()
	: _player(nullptr), _isInit(false)
{
	Init();
}

Shot::~Shot()
{
	
}

void Shot::Init()
{
	_name = L"Shot";
	_position = Vector2(WINSIZEX / 2 - 100, WINSIZEY / 2 - 100);
	_size = Vector2(10, 10);
	_rect = RectMakePivot(_position, _size, Pivot::Center);
	_active = false;	

	_direction = Vector2(1, 0);
	_isInit = false;

	_player = dynamic_cast<Player*>(OBJECTMANAGER->FindObject(ObjectType::Player, L"Player"));
	if (_player)
	{
		_position = _player->GetPosition();
		_direction = _player->GetDirection();	
	}
}

void Shot::Release()
{
	Shot::~Shot();
}

void Shot::Update()
{
	Move(_direction, 200.0f);
}

void Shot::Render()
{
	D2DRenderer::GetInstance()->DrawEllipse(_position, _size.x, D2DRenderer::DefaultBrush::Blue, 3.0f);

	_D2DRenderer->RenderText(10, 70, L"산탄 x:" + to_wstring(_position.x) + L"  y:" + to_wstring(_position.y), 20);
}

void Shot::Move(Vector2 moveDirection, float speed)
{
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}

void Shot::MoveAngle(float speed)
{
	_position += _direction * speed * TIMEMANAGER->GetElapsedTime();
	_rect.Update(_position, _size, Pivot::Center);
}
#pragma endregion 

void Shot::SetType(float a)
{
	//_direction.y = _player->GetDirection().y + a; 단순히 벡터의 가감으로는 원뿔 모양의 산탄이 형성되지 않음
	
	_direction.x = cos(_player->_angle + a);
	_direction.y = sin(_player->_angle + a);
}
