#pragma once
#include <DataTypes.h>
#include <SDL.h>
#include <vector>
namespace WarioPrimark {

	struct TransformComponent2D
	{
		Vector2D Transform;
		Vector2D Scale;
		Vector2D Rotation;

		TransformComponent2D() {
			Scale.Ones(); // sets the scale to 1 on construction
		}

		void Reset() {
			Transform.Zero();
			Scale.Ones();
			Rotation.Zero();
		}

	};

	struct UIrenderer
	{
		UIrenderer() = default;
	};

	struct Interactable
	{
		Interactable() = default;
	};

	struct Matireal
	{
		Matireal() = default;
	};

	struct Renderer2d
	{
		Renderer2d() = default;
	};

	struct sprite
	{
	public:
		sprite() = default;
		virtual ~sprite() = default;
		//sprite(SDL_Renderer* target, int TextureID) :Rtarget(target), int(TextureID) {};

	private:
		int width = 0;
		int height = 0;
		SDL_Rect srcrect = { 0,0,0,0 };
		SDL_Rect destrect = { 0,0,0,0 };

		TransformComponent2D* transform = nullptr;
		//TextureTypes type = NONE;
		SDL_Texture* texture = nullptr;

		SDL_Renderer* Rtarget = nullptr;
		SDL_RendererFlip flip = SDL_FLIP_NONE;
	};

	struct RigidBody
	{
		RigidBody() = default;
	};

	struct collider2D
	{
		collider2D() = default;
	};

	struct TilemapComponent
	{
		TilemapComponent() = default;

		map Map;

	};

	struct TilemapRenderer
	{
		TilemapRenderer(SDL_Renderer* render)
			:mapRenderer(render) {};
		
		SDL_Renderer* mapRenderer;

		void DrawTileMap(map Map);

	};

	struct TileMapCollider2D
	{
		TileMapCollider2D() = default;
	};

	struct BasicEnemyAI
	{
		BasicEnemyAI() = default;
	};

	struct Grid2d
	{
		Grid2d(Vector2D cellsize) {
			sizecell = cellsize;
		}
		Grid2d() {
			sizecell.Ones();
		}

		Vector2D sizecell;
		Vector2D cellgap;
	};


}