#include "Text.h"

Text::Text(sf::Font* font,const std::string& str, sf::Vector2f pos, unsigned int charSize)
{
	//config

	//setup
	text = new sf::Text();
	text->setFont(*font);
	text->setCharacterSize(charSize);
	text->setString(str);
	centerOrigin();
	setPosition(pos);
	//debug
}

Text::~Text()
{
	delete text;
}

void Text::setText(std::string string)
{
	text->setString(string);
}

void Text::setText(double value)
{
	text->setString(std::to_string(value));
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*text);
}

void Text::centerOrigin()
{
	text->setOrigin(
		text->getGlobalBounds().width / 2.f,
		text->getGlobalBounds().height / 2.f);
}

void Text::setPosition(sf::Vector2f pos)
{
	text->setPosition(pos);
}

void Text::setPosition(float x, float y)
{
	text->setPosition(x, y);
}
