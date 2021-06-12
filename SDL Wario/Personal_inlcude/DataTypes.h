#pragma once
namespace WarioPrimark {


	class Vector2D {
	public:
		float X, Y;

		Vector2D(float x = 0, float y = 0) : X(x), Y(y) {};

		inline void Ones() {
			X = 1.0f;
			Y = 1.0f;
		}

		inline void Zero() {
			X = 0.0f;
			Y = 0.0f;
		}
	};
}
