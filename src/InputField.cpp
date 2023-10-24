#include "InputField.h"

bool InputField::is_text_fit_the_field() const {
	return (text_.getLocalBounds().width + 
		font_.getGlyph(PROMPT_CHAR, text_.getCharacterSize(), false).advance) <= size_.x;
}

void InputField::adjust_font_size() {
	text_.setCharacterSize(font_size_);
	while (!is_text_fit_the_field()) {
		text_.setCharacterSize(text_.getCharacterSize() - 1);
	}
}

InputField::InputField(
	const sf::Vector2f& pos,
	const sf::Vector2f& size,
	const std::string& text_string,
	const sf::Font& font,
	const unsigned int font_size,
	const int character_limit,
	const sf::Color& text_color,
	const sf::Color& background_color
) : Object{ pos, size },
	font_(font),
	font_size_{ font_size },
	character_limit_{ character_limit },
	text_color_{ text_color },
	background_color_{ background_color } {

	// Init the shape_.
	shape_.setPosition(position_);
	shape_.setSize(size_);
	shape_.setFillColor(background_color_);

	// Init the text_.
	text_.setFont(font);
	text_.setString(text_string);
	text_.setCharacterSize(font_size_);
	text_.setFillColor(text_color_);
	text_.setPosition(position_);

	// Init the clock.
	p_clock_ = std::make_unique<sf::Clock>();
}

void InputField::update() {
	// Animation of the input prompt.
	if (p_clock_->getElapsedTime() > sf::milliseconds(PROMPT_ANIMATION_TIME)) {
		p_clock_->restart();
		std::string text_string = text_.getString().toAnsiString();
		if (text_string.empty() || text_string.back() != PROMPT_CHAR) {
			text_string.push_back(PROMPT_CHAR);
		}
		else {
			text_string.pop_back();
		}

		text_.setString(text_string);
	}
};

void InputField::render(sf::RenderWindow& p_window_) const {
	p_window_.draw(shape_);
	p_window_.draw(text_);
}

void InputField::show_error() {
	set_text(ERROR_MESSAGE);
}

void InputField::clear() {
	text_.setCharacterSize(font_size_);
	text_.setString("");
}

void InputField::set_text(std::string text_string) {
	text_.setString(text_string);
	adjust_font_size();
}

std::string InputField::get_text() const {
	auto text_string = text_.getString().toAnsiString();

	// Remove input prompt character from output string.
	if (!text_string.empty() && text_string.back() == PROMPT_CHAR) {
		text_string.pop_back();
	}

	return text_string;
}

void InputField::add_character(const char character) {
	std::string text_string = get_text();

	// Hide the error message.
	if (text_string == ERROR_MESSAGE) {
		text_string = "";
	}

	// Add character in the field.
	text_string.push_back(character);
	text_.setString(text_string);

	// If we can't fit new character in the field then remove it.
	if (text_.getString().getSize() > character_limit_ && !text_string.empty()) {
		text_string.pop_back();
	}
	else {
		adjust_font_size();
	}

	text_.setString(text_string);
}

void InputField::remove_last_character() {
	std::string text_string = get_text();

	// Remove last character.
	if (!text_string.empty()) {
		text_string.pop_back();
	}

	// Adjust the font size.
	text_.setString(text_string);
	while (is_text_fit_the_field() && text_.getCharacterSize() < font_size_) {
		text_.setCharacterSize(text_.getCharacterSize() + 1);
	}
	text_.setCharacterSize(text_.getCharacterSize() - 1);
	text_.setString(text_string);
}