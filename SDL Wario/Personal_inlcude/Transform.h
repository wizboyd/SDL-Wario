#pragma once
#include <Componenet.h>
#include <Vec2D.h>
class Transform: public Component
{
public:
	Transform() = default;

	Transform(float x, float y) {
		position.x = x;
		position.y = y;
		scale.ones();
		rotation = 0;
	}
	Transform(float x, float y, float scalex, float scaley) {
		position.x = x;
		position.y = y;
		scale.x = scalex;
		scale.y = scaley;
	}
	Transform(float x, float y, float scalex, float scaley , float rotation) {
		position.x = x;
		position.y = y;
		scale.x = scalex;
		scale.y = scaley;
		rotation = rotation;
	}
	virtual	~Transform() = default;

	Vec2DF position = Vec2DF();
	Vec2DF scale = Vec2DF(1,1);
	float rotation = 0.0f;


private:

};