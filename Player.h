#pragma once
#include "iostream"
#include"SFML/Audio.hpp"
#include"SFML/System.hpp"


class MusicPlayer :private  sf::NonCopyable
{
public:

	MusicPlayer();
	~MusicPlayer();

	void play( float volume);
	void stop();
	void setVolume(float volume);
	bool isPlaying() const;
	void pause(bool paused);
	void load(const std::string& filePath);
	void loadThread(const std::string& filePath);
	

	sf::Time getlen();
	sf::Music& getMusic();

private:

	sf::Music myMusic;
	std::string file;
	sf::SoundSource::Status status;

	float mVolume;
	bool paused;

	sf::Mutex mutex;



};










