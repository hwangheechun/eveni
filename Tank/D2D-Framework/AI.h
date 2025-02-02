#pragma once
#include "GameObject.h"

class AI : public GameObject
{
public:
	AI();
	virtual ~AI();

	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	void Move(Vector2 moveDirection, float speed);
	void MoveAngle(float angle, float speed);

	Vector2 _direction;
	Vector2 GetDirection() { return _direction; };

	float _angle;

	float _gauge;
	FloatRect _gaugeRect;

	FloatRect _HP;
	float _HPBar;
	bool isCollide;

	float _moveTime;

	class GameObject* _player;

	bool isDead;
};

