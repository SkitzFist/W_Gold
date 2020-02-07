#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "SoundManager.h"
#include "DeltaTime.h"
class GameObject : public sf::Drawable
{
public:
	GameObject(sf::Texture* texture, ResourceManager *rm, int spriteColumns = NULL, int spriteRows = NULL);
	~GameObject();
	virtual void update(DeltaTime delta) = 0;
	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const;
	sf::FloatRect getBounds() const;
	void setSpriteScale(float scale);
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	//why protected?
	void moveSprite(sf::Vector2f dir, float speed);
	void moveSprite(float velX, float velY);
	void rotateSprite(float angle);
	//void setSpriteScale(float scale);
	void centerOrigin();
	ResourceManager* getRm();
private:
	ResourceManager* rm;
	sf::Sprite* sprite;
	int spriteColumns;
	int spriteRows;
};

