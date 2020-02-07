#pragma once
#include <SFML/Audio.hpp>


class Sound {
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;
	float volume;
public:
	Sound();
	virtual ~Sound();
	void PlaySounds(sf::SoundBuffer * File, float volume = -1.0f);
	//playMusic
	void PlayMusic(std::string FileName, float volume = -1.0f);
	void StopMusic();
	//In beta
	void RestartSound();
	//check if music or sound has stopped playing
	bool IfSoundStopped()const;
	bool IfMusicStopped()const;
};


