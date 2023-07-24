
#include"Window.h"

Window::Window(int w, int h, std::string title):m_window(sf::VideoMode(w, h), title)
{
	ImGui::SFML::Init(m_window);
	sf::Clock delclock;
	ImGuiIO& io = ImGui::GetIO();
	
}

Window::~Window() 
{

}

void Window::Run() {
	while (m_window.isOpen()) 
	{
		processedEvents();
		Update();
		Render();
	}
	ImGui::SFML::Shutdown();
	
}

void Window::processedEvents() 
{
	sf::Event events;
	while (m_window.pollEvent(events)) {
		ImGui::SFML::ProcessEvent(events);
		if (events.type == sf::Event::Closed)
			m_window.close();
	}
}



void Window::Update() {
	ImGui::SFML::Update(m_window, deltaClock.restart());

	static float volume = 100;
	static bool pause = false;
	static bool play = true;
	static bool stop  = false;
	static double m_pos = 0;
	pause = !play;
	int duration = player.getlen().asSeconds();

	ImGui::Begin("Volume Manager");
	ImGui::SliderFloat("vol", &volume, 0, 100);
	ImGui::Checkbox("Play", &play);
	ImGui::Checkbox("Pause", &pause);
	ImGui::Checkbox("Stop", &stop);
	ImGui::End();

	if (ImGui::Begin("FILE EXPLORER"))
	{

		if (ImGui::Button("Select Directory"))
			m_browser.Open();
	}
	ImGui::End();


	m_browser.Display();
	if (m_browser.HasSelected()) {
		std::string filePath = m_browser.GetSelected().string();
		std::cout << "Now Playing" << filePath << std::endl;
		player.load(filePath);
		player.play(volume);
		player.pause(pause);
		m_browser.ClearSelected();
	}
	player.setVolume(volume);

	
}

void Window::Render()
{
	m_window.clear();
	ImGui::SFML::Render();
	m_window.display();
}


