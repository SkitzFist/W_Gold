#include "Button.h"

Button::Button(sf::Font* font, std::string str, sf::Vector2f pos)
{
	//config
	boxOffset = 10.f;
	outlineThickness = 2.0f;
	text.setFillColor(sf::Color::White);

	box.setFillColor(sf::Color::Black);
	box.setOutlineColor(sf::Color::Green);
	box.setOutlineThickness(0);

	//setup
	text.setFont(*font);
	text.setCharacterSize(35);
	text.setString(str);
	float width = text.getGlobalBounds().width;
	float height = text.getGlobalBounds().height;
	box.setSize(sf::Vector2f(width + boxOffset, height + (boxOffset)));
	box.setOrigin(box.getSize().x / 2, box.getSize().y / 2);

	setPosition(pos.x, pos.y);
}

Button::~Button()
{
}

void Button::setPosition(float x, float y)
{
	box.setPosition(x, y);
	text.setPosition(
		(box.getPosition().x - (box.getSize().x / 2)) + (boxOffset / 2),
		(box.getPosition().y - (box.getSize().y / 2)) - (boxOffset / 2)
	);
}

void Button::markBox()
{
	box.setOutlineThickness(outlineThickness);
}

void Button::unmarkBox()
{
	box.setOutlineThickness(0.f);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box);
	target.draw(text);
}
