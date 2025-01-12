#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet();
	virtual ~Bullet();

	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	void Move(Vector2 moveDirection, float speed);
	void MoveAngle(float speed);

	class Player* _player;
	bool _isInit;
	Vector2 _direction;

	int countCollide;
};

class ReinforcedBullet : public GameObject
{
public:
	ReinforcedBullet();
	virtual ~ReinforcedBullet();

	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	void Move(Vector2 moveDirection, float speed);
	void MoveAngle(float speed);

	class Player* _player;
	bool _isInit;
	Vector2 _direction;

	int countCollide;
};

class Shot : public GameObject
{
public:
	Shot();
	virtual ~Shot();

	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	void Move(Vector2 moveDirection, float speed);
	void MoveAngle(float speed);

	class Player* _player;
	bool _isInit;
	Vector2 _direction;

	int countCollide;

	void SetType(float a);
};

