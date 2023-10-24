#include "Application.h"

Application::Application(
    std::string title, 
    int width, 
    int height,
    int fps_limit
) : video_mode_{ sf::VideoMode(width, height) },
    p_window_{ nullptr },
    event_{sf::Event()} {

    p_window_ = std::make_unique<sf::RenderWindow>(video_mode_, title, sf::Style::Titlebar | sf::Style::Close);
    p_window_->setFramerateLimit(fps_limit);
}

void Application::update() {
    update_events();
    update_mouse_position();

    for (std::shared_ptr<Object> object : p_objects_) {
        object->update();
    }
}

void Application::render() {
    p_window_->clear(Colors::WHITE);
    for (std::shared_ptr<Object> object : p_objects_) {
        object->render(*p_window_);
    }
    p_window_->display();
}

void Application::update_events() {
    // Event polling.
    while (p_window_->pollEvent(event_)) {
        if (p_event_handler_) p_event_handler_(event_);
        switch (event_.type) {

            // Process window closing.
            case sf::Event::Closed:
                p_window_->close();
                break;

            // Process pressed keys.
            case sf::Event::KeyPressed:
                switch (event_.key.code) {
                case sf::Keyboard::Escape:
                    p_window_->close();
                    break;
                }

            // Process mouse button click.
            case sf::Event::MouseButtonPressed: {
                if (event_.mouseButton.button == sf::Mouse::Left) {
                    for (std::shared_ptr<Object> object : p_clickable_objects_) {
                        auto bounds = object->get_global_bounds();
                        auto leftUpper = bounds.first;
                        auto rightBottom = bounds.second;
                        if (mouse_position_.x >= leftUpper.x &&
                            mouse_position_.x <= rightBottom.x &&
                            mouse_position_.y >= leftUpper.y &&
                            mouse_position_.y <= rightBottom.y &&
                            object->get_click_handler()) {
                            object->get_click_handler()->on_mouse_pressed();
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
}

void Application::update_mouse_position() {
    mouse_position_ = sf::Mouse::getPosition(*p_window_);
}

void Application::start() {
    while (is_running()) {
        update();
        render();
    }
}

const bool Application::is_running() const {
    return p_window_->isOpen();
}

void Application::add_object(std::shared_ptr<Object> object) {
    p_objects_.push_back(object);
    if (object->is_clickable()) {
        p_clickable_objects_.push_back(object);
    }
}

void Application::add_objects(const std::vector<std::shared_ptr<Object>>& objects) {
    for (std::shared_ptr<Object> object : objects) {
        add_object(object);
    }
}

void Application::add_event_handler(EventHandler p_event_handler) {
    p_event_handler_ = p_event_handler;
}

void Application::set_icon(const sf::Image& icon) {
    p_window_->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}