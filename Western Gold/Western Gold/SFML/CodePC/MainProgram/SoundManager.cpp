#include "SoundManager.h"
#include <iostream>


Sound::Sound()
{
	//this->volume = SettingsVolume();
	this->volume = 10;
	sound.setVolume(volume);
	music.setVolume(volume);
	//buffer.loadFromFile("../Sound/test.wav");
	//this->sound.setBuffer(buffer);
}
Sound::~Sound()
{
}
//void Sound::LoadSound(std::string FileName, float volume)
//{
//	if (volume != -1.0f) {
//		sound.setVolume(volume * this->volume);
//	}
//	buffer.loadFromFile("../../Bin/Sound/" + FileName);
//	this->sound.setBuffer(buffer);
//	
//	
//}
void Sound::LoadSound(sf::SoundBuffer File, float volume)
{
	if (volume != -1.0f) {
		sound.setVolume(volume * this->volume);
	}
	this->sound.setBuffer(File);
}
void Sound::PlayLoadSound()
{
	std::cout << "penis" << std::endl;
	this->sound.play();
}

//void Sound::PlaySounds(std::string FileName, float volume)
//{
//	if (volume != -1.0f) {
//		sound.setVolume(volume * this->volume);
//	}
//	if (buffer.loadFromFile("../../Bin/Sound/" + FileName)) {
//		this->sound.setBuffer(buffer);
//		this->sound.play();
//	}
//	else {
//
//	}
//	
//}

void Sound::PlaySounds(sf::SoundBuffer *File, float volume)
{
	if (volume != -1.0f) {
		sound.setVolume(volume * this->volume);
	}
	std::cout << "penis" << std::endl;
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

void Sound::RestartSound()
{
	//this is under construction
	//this->volume = SettingsVolume();
}
