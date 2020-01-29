#include "SoundManager.h"


Sound::Sound()
{
	//this->volume = SettingsVolume();
	this->volume = 1;
	sound.setVolume(volume);
	music.setVolume(volume);
	
}
Sound::~Sound()
{
}
void Sound::LoadSound(std::string FileName, float volume)
{
	if (volume != -1.0f) {
		sound.setVolume(volume * this->volume);
	}
	buffer.loadFromFile("../../Bin/Sound/" + FileName);
	this->sound.setBuffer(buffer);
	
	
}
void Sound::PlayLoadSound()
{
	this->sound.play();
}

void Sound::PlaySounds(std::string FileName, float volume)
{
	if (volume != -1.0f) {
		sound.setVolume(volume * this->volume);
	}
	if (buffer.loadFromFile("../../Bin/Sound/" + FileName)) {
		this->sound.setBuffer(buffer);
		this->sound.play();
	}
	else {

	}
	
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
