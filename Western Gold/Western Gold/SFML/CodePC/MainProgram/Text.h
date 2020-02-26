#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Text:
	public sf::Drawable
{
public:
	Text(sf::Font* font,const std::string& str, sf::Vector2f pos, unsigned int charSize = 54);
	~Text();

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Text* text;

	void centerOrigin();

	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
};

