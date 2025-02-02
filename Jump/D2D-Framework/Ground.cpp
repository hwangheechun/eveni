#include "stdafx.h"
#include "Ground.h"

Ground::Ground()
	: _gauge(0.f)
{
	Init();
}

Ground::~Ground()
{
}

void Ground::Init()
{
	_name = L"Ground";
	_position = Vector2(WINSIZEX / 2, WINSIZEY - 50);
	_size = Vector2(WINSIZEX, 45);
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// 히트박스
}

void Ground::Release()
{
}

void Ground::Update()
{

}

void Ground::Render()
{
	_D2DRenderer->FillRectangle(_rect, D2DRenderer::DefaultBrush::White);			// 채우기
	_D2DRenderer->DrawRectangle(_rect, D2DRenderer::DefaultBrush::Black, 1.0f);		// 라인
}
