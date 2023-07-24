#pragma once
#include"imgui/imgui.h"
#include"SFML-2.5.1/include/SFML/Graphics.hpp"
#include"imgui/imgui-SFML.h"
#include "Player.h"
#include"imfilebrowser.h"
#include <iostream>
#include "Player.h"

class Window
{
public:
	Window(int w, int h, std::string title);
	~Window();

	void Run();

private:

	sf::RenderWindow m_window;
	sf::Clock deltaClock;
	sf::SoundBuffer s_buffer;

	ImGui::FileBrowser m_browser;

	void processedEvents();
	void Update();
	void Render();

	MusicPlayer player;
};
