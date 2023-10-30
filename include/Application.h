#ifndef APPLICATION_H
#define APPLICATION_H

#include "Button.h"
#include "InputField.h"
#include "Resources.h"

using EventHandler = std::function<void(const sf::Event&)>;

class Application {
private:
	std::vector<std::shared_ptr<Object>> p_objects_;
	std::vector<std::shared_ptr<Object>> p_clickable_objects_;

	sf::RenderWindow window_;
	sf::Event event_;
	EventHandler p_event_handler_;
	sf::Vector2i mouse_position_;

private:
	void update();
	void render();
	void update_events();
	void update_mouse_position();

public:
	Application(std::string title, int width, int height, int fps_limit);

	// Starts application's main cycle.
	void start();

	const bool is_running() const;

	void add_object(std::shared_ptr<Object> object);
	void add_objects(const std::vector<std::shared_ptr<Object>>& objects);
	void add_event_handler(EventHandler event_handler);

	void set_icon(const sf::Image& icon);

	template <typename T>
	T load_resource(const std::string& resource_name);
};

template<typename T>
inline T Application::load_resource(const std::string& resource_name)
{
	T resource = T();
	EmbeddedResource data = load_embedded_resource(resource_name);
	if (!resource.loadFromMemory(data.p_resource, data.size_in_memory)) {
		throw std::runtime_error("Failed to load resource: " + resource_name);
	}

	return resource;
}

#endif // APPLICATION_H