#include "Player.h"

MusicPlayer::MusicPlayer():myMusic(), file(), mVolume(100.0f) 
{
	setVolume(mVolume);
}

MusicPlayer::~MusicPlayer()
{
	
}



void MusicPlayer::play(float volume) {
	paused = false;
	setVolume(volume);
	myMusic.play();
	
}
void MusicPlayer::stop()
{
	myMusic.stop();
}
void MusicPlayer::pause(bool paused)
{
	if (paused)
		myMusic.pause();
	else
		myMusic.play();
}

void MusicPlayer::setVolume(float volume) 
{
	myMusic.setVolume(volume);
}

void MusicPlayer::load(const std::string& filePath) {
	sf::Thread thread([this, filePath]() {loadThread(filePath); });
	thread.launch();
}

void MusicPlayer::loadThread(const std::string& filePath)
{
	sf::Lock lock(mutex);
	if (!myMusic.openFromFile(filePath)) {
		throw std::runtime_error("File loading failed");
	}
	myMusic.setLoop(true);
}

bool MusicPlayer::isPlaying() const
{
	return myMusic.getStatus() == sf::SoundSource::Status::Stopped;
}
 

sf::Time MusicPlayer::getlen()
{
	return myMusic.getDuration();
}