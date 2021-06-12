#pragma once
#include <entt.hpp>
#include <Components.h>

struct Button 
{
public:
	void create(entt::registry& Registry);
};

struct Label
{
public:
	void create(entt::registry& Registry);
};

struct Player
{
public:
	void create(entt::registry& Registry);
};

struct Tilemap
{
public:
	void create(entt::registry& Registry);
};

struct Enemy
{
	void create(entt::registry& Registry);
};

struct QuestionBlocks
{
	void create(entt::registry& Registry);
};
 
//regular blocks part of tile map???

struct Powerup
{
	void create(entt::registry& Registry);
};

//pipe part of tilemap??

struct flagpole
{
	void create(entt::registry& Registry);
};

inline void Button::create(entt::registry& Registry) {
	auto ButtonEntity = Registry.create();
	Registry.emplace<TransformComponent2D, UIrenderer, Interactable, Matireal >(); // the UIrenderer... and others will be created later
}
inline void Label::create(entt::registry& Registry) {
	auto LabelEntity = Registry.create();
	Registry.emplace<TransformComponent2D, UIrenderer, Matireal >();// the UIrenderer... and others will be created later
}
inline void Player::create(entt::registry& Registry) {
	auto PlayerEntity = Registry.create();
	Registry.emplace<TransformComponent2D, Renderer2d, Matireal, RigidBody, collider2D >();// the UIrenderer... and others will be created later
}
inline void Tilemap::create(entt::registry& Registry) {
	auto TilemapEntity = Registry.create();
	Registry.emplace<TransformComponent2D, TilemapComponent, TilemapRenderer, TileMapCollider2D >();// the UIrenderer... and others will be created later
}
inline void Enemy::create(entt::registry& Registry) {
	auto EnemyEntity = Registry.create();
	Registry.emplace<TransformComponent2D, Renderer2d, Matireal, RigidBody, collider2D, BasicEnemyAI  >();// the UIrenderer... and others will be created later
}
inline void QuestionBlocks::create(entt::registry& Registry) {
	auto QuestionEntity = Registry.create();
	Registry.emplace<TransformComponent2D, Renderer2d, Matireal, collider2D, Interactable  >();// the UIrenderer... and others will be created later
}
inline void Powerup::create(entt::registry& Registry) {
	auto powerEntity = Registry.create();
	Registry.emplace<TransformComponent2D, Renderer2d, Matireal, collider2D, Interactable  >();// the UIrenderer... and others will be created later
}
inline void flagpole::create(entt::registry& Registry) {
	auto QuestionEntity = Registry.create();
	Registry.emplace<TransformComponent2D, Renderer2d, Matireal, collider2D, Interactable  >();// the UIrenderer... and others will be created later
}