#pragma once
#include <SFML/Graphics.hpp>
class Button :
	public sf::Drawable
{
public:

	Button(sf::Font* font, std::string str, sf::Vector2f pos, unsigned int charSize = 35);
	~Button();

	void setPosition(float x, float y);
	void markBox();
	void unmarkBox();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Text text;
	sf::RectangleShape box;
	float boxOffset;
	float outlineThickness;

	// Inherited via Drawable
	
};

