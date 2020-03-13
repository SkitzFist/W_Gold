#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Text:
	public sf::Drawable
{
public:
	Text(sf::Font* font,const std::string& str, sf::Vector2f pos, unsigned int charSize = 54);
	~Text();
	void setText(std::string string);
	void setText(double value);
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
private:
	sf::Text* text;
	void centerOrigin();
};

