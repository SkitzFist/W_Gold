#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "SoundManager.h"
#include "DeltaTime.h"
#include "Animator.h"

class GameObject : public sf::Drawable
{
public:
	GameObject(sf::Texture* texture, ResourceManager* rm, int spriteColumns = NULL, int spriteRows = NULL);
	~GameObject();
	virtual void update(DeltaTime delta) = 0;
	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const;
	sf::FloatRect getBounds() const;
	//easier to code with
	float getLeft()const;
	float getRight()const;
	float getBot()const;
	float getTop()const;
	float getWidth();
	float getHeight();
	float getRotation();
	void setSpriteScale(float scale);
	void setSpriteScalePx(float sizeX, float sizeY);
	sf::Vector2f getCenterOfSprite()const;
	void moveSprite(float velX, float velY);
	void moveSprite(sf::Vector2f dir, float speed);

	void setanimation(float timeBetween, int nrofCol, int nrOfRows, int whatRow);
	void changeTimeBetween(float time);
	void changeNrOfCol(int col);
	void changeWhatRow(int row);

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	
	void setRotatioSprite(float angle);
	void rotateSprite(float angle);
	void addRotationSprite(float angle);
	//centerOrigin private
	Sound sound;
	Animator animator;

	ResourceManager* getRm();
private:
	void centerOrigin();
	ResourceManager* rm;

	sf::Sprite* sprite;
	int spriteColumns;
	int spriteRows;
};