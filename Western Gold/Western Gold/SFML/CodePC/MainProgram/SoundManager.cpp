#include "SoundManager.h"
#include <iostream>


Sound::Sound()
{
	this->volume = 10;
	sound.setVolume(volume);
	music.setVolume(volume);

}
Sound::~Sound()
{
}

void Sound::PlaySounds(sf::SoundBuffer *File, float volume)
{
	if (volume != -1.0f) {
		sound.setVolume(volume * this->volume);
	}
	this->sound.setBuffer(*File);
	this->sound.play();
			
			
}

void Sound::PlayMusic(std::string FileName, float volume)
{
	if (volume != -1.0f) {
		music.setVolume(volume * this->volume);
	}
	if (this->music.openFromFile("../Audio/" + FileName)) {
		music.play();
		music.setLoop(true);
	}
	else {

	}
}

bool Sound::IfSoundStopped() const
{
	bool theReturn;
	if (this->sound.getStatus() == 0) {
		theReturn = true;
	}
	else {
		theReturn = false;
	}
	return theReturn;

}

bool Sound::IfMusicStopped() const
{
	bool theReturn;
	if (this->music.getStatus() == 0) {
		theReturn = false;
	}
	else {
		theReturn = true;
	}
	return theReturn;
}

void Sound::StopMusic()
{
	this->music.stop();
	
}