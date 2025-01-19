//#pragma once 여러 번 include를 피하기(9주차 변경)
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
	bool _isFire;

	FloatRect trajectory;	//궤적
	Vector2 _gravity;			//중력
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
	bool _isFire;
	bool _isReady;

	FloatRect _trajectory;	//궤적
	Vector2 _gravity;			//중력
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
	bool _isFire;

	void SetType(float a);
};

