#include "Object.h"

Object::Object(const sf::Vector2f& pos, const sf::Vector2f& size) : position_{ pos }, size_{ size }, p_clock_{nullptr} {}

std::pair<sf::Vector2f, sf::Vector2f> Object::get_global_bounds() const {
	return std::pair<sf::Vector2f, sf::Vector2f>(
		position_, 
		sf::Vector2f(position_.x + size_.x, position_.y + size_.y)
	);
}

bool Object::is_clickable() const {
	return p_click_handler_ != nullptr;
}

void Object::set_click_handler(std::shared_ptr<ClickHandler> p_click_handler) {
	p_click_handler_ = p_click_handler;
}

std::shared_ptr<ClickHandler> Object::get_click_handler() {
	return p_click_handler_;
}