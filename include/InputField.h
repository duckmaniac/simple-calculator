#ifndef INPUT_FIELD_H
#define INPUT_FIELD_H

#include "Object.h"

constexpr int PROMPT_ANIMATION_TIME = 500;
constexpr const char* ERROR_MESSAGE = "ERROR";
constexpr char PROMPT_CHAR = '|';

class InputField : public Object {
private:

	sf::RectangleShape shape_; // Shape representing the input field.
	sf::Text text_;
	sf::Font font_;
	unsigned int font_size_;
	int character_limit_;
	sf::Color text_color_;
	sf::Color background_color_;

private:
	bool is_text_fit_the_field() const;
	void adjust_font_size();

public:
	InputField(
		const sf::Vector2f& pos,
		const sf::Vector2f& size,
		const std::string& text_string,
		const sf::Font& font,
		const unsigned int font_size,
		const int character_limit,
		const sf::Color& text_color,
		const sf::Color& background_color
	);
	~InputField() override = default;

	void update() override;
	void render(sf::RenderWindow& window_) const override;

	static void set_font(sf::Font font);
	void show_error();
	void clear();
	void set_text(std::string text_string);
	std::string get_text() const;

	// Entering into the field occurs character by character.
	void add_character(const char character);
	void remove_last_character();

	bool is_error_showing();
};

#endif // INPUT_FIELD_H