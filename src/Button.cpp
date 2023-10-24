#include "Button.h"

Button::Button(
	const sf::Vector2f& pos,
	const sf::Vector2f& size,
	const std::string& text_string,
	const sf::Font& font,
	const int font_size,
	const sf::Color& background_color,
	const sf::Color& background_pressed_color
) : Object{ pos, size },
	font_size_(font_size),
	background_color_{ background_color },
	background_pressed_color_{ background_pressed_color } {

	// Init the shape_.
	shape_.setPosition(position_);
	shape_.setSize(size_);
	shape_.setFillColor(background_color_);

	// Init the text_.
	text_.setFont(font);
	text_.setString(text_string);
	text_.setCharacterSize(font_size_);

	// Center the text_.
	sf::FloatRect textRect = text_.getLocalBounds();
	text_.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text_.setPosition(sf::Vector2f(position_.x + size_.x / 2.0f, position_.y + size_.y / 2.0f));
}

void Button::update() {
	if (!p_clock_) return;

	if (p_clock_->getElapsedTime() < sf::milliseconds(CLICK_ANIMATION_TIME)) {
		shape_.setFillColor(background_pressed_color_);
	}
	else {
		shape_.setFillColor(background_color_);
	}
}

void Button::render(sf::RenderWindow& p_window_) const {
	p_window_.draw(shape_);
	p_window_.draw(text_);
}

std::string Button::get_text() const {
	return text_.getString().toAnsiString();
}

void Button::animate_button_click() {
	if (!p_clock_) p_clock_ = std::make_unique<sf::Clock>();
	p_clock_->restart();
}