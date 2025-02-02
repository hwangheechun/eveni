#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"
#include "AI.h"
#include <string>

Bullet::Bullet()
	: _player(nullptr), _ai(nullptr), _isInit(false)
{
	Init();
}

Bullet::~Bullet()
{

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
	_ai = dynamic_cast<AI*>(OBJECTMANAGER->FindObject(ObjectType::AI, L"AI"));

	if (_player)
	{
		_position = _player->GetPosition() + _player->GetDirection() * 100;
		_direction = _player->GetDirection();	//추가한 문구
	}

	_isFire = false;
	_gravity.x = 0;
	_gravity.y = 1.5;
}

void Bullet::Init(string a)
{
	_name = L"Bullet";
	_position = Vector2(WINSIZEX / 2 - 100, WINSIZEY / 2 - 100);
	_size = Vector2(10, 10);
	_rect = RectMakePivot(_position, _size, Pivot::Center);
	_active = false;	// 미리 생성 후 가져다 쓸 용도로 이렇게 설정함, 생성해서 쓰려면 true로 놓는 것이 맞음

	_direction = Vector2(1, 0);
	_isInit = false;

	_player = dynamic_cast<Player*>(OBJECTMANAGER->FindObject(ObjectType::Player, L"Player"));
	_ai = dynamic_cast<AI*>(OBJECTMANAGER->FindObject(ObjectType::AI, L"AI"));

	if (a == "AI")
	{
		_position = _ai->GetPosition() + _ai->GetDirection() * 100;
		_direction = _ai->GetDirection();	//추가한 문구
	}

	_isFire = false;
	_gravity.x = 0;
	_gravity.y = 1.5;
}

void Bullet::Release()
{

}

void Bullet::Update()
{
	if (_isFire)
	{
		Move(_direction, 650.0f);
		_direction += _gravity * TIMEMANAGER->GetElapsedTime();
	}

	if (_position.x >= WINSIZEX || _position.x <= 0 || _position.y >= WINSIZEY || _position.y <= 0)
	{
		//this->Release();	객체가 없어지지 않는 오브젝트 풀링 방식이라 사용할 필요가 없다. 릴리즈 함수는 오브젝트 소멸 시 설정할 내용이 있다면 내부에 작성하여 사용하는 함수
		//OBJECTMANAGER->RemoveObject(ObjectType::Bullet, this);	객체가 없어지지 않는다
		Init();
		//SetActive(false);	//액티브 값을 false로 바꿔 
	}
}

void Bullet::Render()
{
	D2DRenderer::GetInstance()->DrawEllipse(_position, _size.x, D2DRenderer::DefaultBrush::Black, 1.0f);
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
	_position = Vector2(0, 0);
	Init();
}

ReinforcedBullet::~ReinforcedBullet()
{
	
}

void ReinforcedBullet::Init()
{
	_name = L"ReinforcedBullet";
	_position = Vector2(0, 0);
	_size = Vector2(20, 20);
	_rect = RectMakePivot(_position, _size, Pivot::Center);
	_active = false;	

	_direction = Vector2(1, 0);
	_isInit = false;

	_player = dynamic_cast<Player*>(OBJECTMANAGER->FindObject(ObjectType::Player, L"Player"));
	if (_player)
	{
		_position = _player->GetPosition() + _player->GetDirection() * 100;
		_direction = _player->GetDirection();
	}

	countCollide = 4;
	_isFire = false;
	_gravity.x = 0;
	_gravity.y = 1.5;
}

void ReinforcedBullet::Release()
{

}

void ReinforcedBullet::Update()
{
	if (_isFire)
	{
		Move(_direction, 650.0f);
		_direction += _gravity * TIMEMANAGER->GetElapsedTime();
	}
#pragma region 7주차 튕기기
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
	else     //강화 탄환이 4번 튕겼다면
	{
		if (_position.x >= WINSIZEX || _position.x <= 0 || _position.y >= WINSIZEY || _position.y <= 0)
		{
			//this->Release();	객체가 없어지지 않는 오브젝트 풀링 방식이라 사용할 필요가 없다. 릴리즈 함수는 오브젝트 소멸 시 설정할 내용이 있다면 내부에 작성하여 사용하는 함수
			//OBJECTMANAGER->RemoveObject(ObjectType::Bullet, this);	객체가 없어지지 않는다
			Init();
			//SetActive(false);	//액티브 값을 false로 바꿔 
		}
	}
#pragma endregion

	if (_position.x >= WINSIZEX || _position.x <= 0 || _position.y >= WINSIZEY || _position.y <= 0)
	{
		Init();
	}
}

void ReinforcedBullet::Render()
{
	//Trajectory();
	D2DRenderer::GetInstance()->DrawEllipse(_position, _size.x, D2DRenderer::DefaultBrush::Red, 3.0f);
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

void ReinforcedBullet::Trajectory()
{
	_D2DRenderer->DrawLine(_position, _position + _direction * 10);
	for (int i = 0; i < 10000; i++)
	{
		Move(_direction, 650.0f);
		_direction += _gravity * TIMEMANAGER->GetElapsedTime();
		_D2DRenderer->DrawLine(_position, _position + _direction * 10);
	}
	
}

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
		_position = _player->GetPosition() + _player->GetDirection() * 100;
		_direction = _player->GetDirection();	
	}
}

void Shot::Release()
{

}

void Shot::Update()
{
	Move(_direction, 350.0f);

	if (_position.x >= WINSIZEX || _position.x <= 0 || _position.y >= WINSIZEY || _position.y <= 0)
	{
		//this->Release();	객체가 없어지지 않는 오브젝트 풀링 방식이라 사용할 필요가 없다. 릴리즈 함수는 오브젝트 소멸 시 설정할 내용이 있다면 내부에 작성하여 사용하는 함수
		//OBJECTMANAGER->RemoveObject(ObjectType::Bullet, this);	객체가 없어지지 않는다
		Init();
		//SetActive(false);	//액티브 값을 false로 바꿔 
	}
}

void Shot::Render()
{
	D2DRenderer::GetInstance()->DrawEllipse(_position, _size.x, D2DRenderer::DefaultBrush::Blue, 3.0f);

	//_D2DRenderer->RenderText(10, 70, L"산탄 x:" + to_wstring(_position.x) + L"  y:" + to_wstring(_position.y), 20);
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

AIBullet::AIBullet()
	: _ai(nullptr), _isInit(false)
{
	Init();
}

AIBullet::~AIBullet()
{

}

void AIBullet::Init()
{
	_name = L"AIBullet";
	_position = Vector2(WINSIZEX / 2 - 100, WINSIZEY / 2 - 100);
	_size = Vector2(10, 10);
	_rect = RectMakePivot(_position, _size, Pivot::Center);
	_active = false;	// 미리 생성 후 가져다 쓸 용도로 이렇게 설정함, 생성해서 쓰려면 true로 놓는 것이 맞음

	_direction = Vector2(1, 0);
	_isInit = false;

	_ai = dynamic_cast<AI*>(OBJECTMANAGER->FindObject(ObjectType::AI, L"AI"));
	if (_ai)
	{
		_position = _ai->GetPosition() + _ai->GetDirection() * 100;
		_direction = _ai->GetDirection();	
	}

	_isFire = false;
	_gravity.x = 0;
	_gravity.y = 1.5;
}

void AIBullet::Release()
{

}

void AIBullet::Update()
{
	if (_isFire)
	{
		Move(_direction, 750.0f);
		_direction += _gravity * TIMEMANAGER->GetElapsedTime();
	}

	if (_position.x >= WINSIZEX || _position.x <= 0 || _position.y >= WINSIZEY || _position.y <= 0)
	{
		//this->Release();	객체가 없어지지 않는 오브젝트 풀링 방식이라 사용할 필요가 없다. 릴리즈 함수는 오브젝트 소멸 시 설정할 내용이 있다면 내부에 작성하여 사용하는 함수
		//OBJECTMANAGER->RemoveObject(ObjectType::Bullet, this);	객체가 없어지지 않는다
		Init();
		//SetActive(false);	//액티브 값을 false로 바꿔 
	}
}

void AIBullet::Render()
{
	D2DRenderer::GetInstance()->DrawEllipse(_position, _size.x, D2DRenderer::DefaultBrush::Black, 1.0f);
	//_D2DRenderer->RenderText(110, 110, L"_position", 0);
	
}

void AIBullet::Move(Vector2 moveDirection, float speed)
{
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}

void AIBullet::MoveAngle(float speed)
{
	_position += _direction * speed * TIMEMANAGER->GetElapsedTime();
	_rect.Update(_position, _size, Pivot::Center);
}