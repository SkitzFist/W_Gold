#include "UI.h"



UI::UI(ResourceManager *rm):
	gold(rm,0,0)

{
	this->rm = rm;
	nrOfShots = 6;
	cylinder.setTexture(*rm->getCylinder());
	cylinder.setScale(1.5f, 1.5f);
	cylinderPos.x = 370;
	cylinderPos.y = 270;
	this->shots = new sf::Sprite[nrOfShots];
	for (int i = 0; i < nrOfShots; i++) {
		shots[i].setTexture(*rm->getUIBullet());
		shots[i].setScale(1.7f, 1.7f);
	}
	time.setFont(*rm->getBasicFont());
	
	time.setCharacterSize(40);
	time.setFillColor(sf::Color::White);
	text.setFont(*rm->getBasicFont());
	text.setPosition(10, 10);
	text.setCharacterSize(40);
	text.setString("00");
	text.setFillColor(sf::Color::White);

	nrOfGold.setCharacterSize(40);
	nrOfGold.setFillColor(sf::Color::White);
	nrOfGold.setFont(*rm->getBasicFont());
	nrOfGold.setCharacterSize(40);
	
}

UI::~UI()
{
	delete[] shots;	
}

void UI::updateUI(Player *player, DeltaTime dt)
{
	cylinder.setPosition(player->getPosition() + cylinderPos);
	time.setPosition(player->getPosition().x + -470, player->getPosition().y - 390);
	gold.setPosition(player->getPosition().x + -470, player->getPosition().y - 460);
	gold.update(dt);
	nrOfGold.setString(std::to_string(player->getNrOfGold()) + "/12");
	nrOfGold.setPosition(player->getPosition().x + -430, player->getPosition().y - 480);

	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << dt.getTotalTime();
	std::string s = stream.str();
	time.setString(s);

	shots[5].setPosition(player->getPosition().x + 398, player->getPosition().y + 270);
	shots[4].setPosition(player->getPosition().x + 423, player->getPosition().y + 284);
	shots[3].setPosition(player->getPosition().x + 423, player->getPosition().y + 312);
	shots[2].setPosition(player->getPosition().x + 398, player->getPosition().y + 327);
	shots[1].setPosition(player->getPosition().x + 373, player->getPosition().y + 312);
	shots[0].setPosition(player->getPosition().x + 373, player->getPosition().y + 284);

	this->nrOfShots = player->nrOfShotsLeft();
	sf::Vector2f textPos = {
		player->getPosition().x + 280.f,
		player->getPosition().y  - 500.f
	};
	text.setPosition(textPos);
	text.setString(std::to_string(1/dt.getRawTime()));
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < nrOfShots; i++) {
		target.draw(shots[i]);
	}
	target.draw(time);
	target.draw(cylinder);
	target.draw(text);
	target.draw(gold);
	target.draw(nrOfGold);
}
