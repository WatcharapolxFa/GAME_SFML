#include "HitboxComponent.h"

HitboxComponent::HitboxComponent(float offset_x, float offset_y, sf::Vector2f size, sf::Vector2f playerPosition)
{
	hitbox.setPosition(playerPosition.x + offset_x, playerPosition.y + offset_y);
	hitbox.setSize(size);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOutlineColor(sf::Color::Blue);
}

HitboxComponent::~HitboxComponent()
{
}

void HitboxComponent::Update(sf::Vector2f playerPosition, float offset_x, float offset_y)
{
	hitbox.setPosition(playerPosition.x + offset_x, playerPosition.y + offset_y);
}

void HitboxComponent::Draw(sf::RenderWindow& window)
{
	window.draw(hitbox);
}