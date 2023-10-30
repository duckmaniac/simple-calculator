#ifndef BUTTON_H
#define BUTTON_H

#include "Object.h"

constexpr int CLICK_ANIMATION_TIME = 80;

// Represents a button used in a graphical user interface.
class Button : public Object {
private:

	int font_size_;

	sf::RectangleShape shape_; // Shape representing the button.
	sf::Text text_; // Text displayed on the button.
	sf::Color background_color_; // Color of the button.
	sf::Color background_pressed_color_; // Color of the pressed button.

public:
	Button(
		const sf::Vector2f& pos,
		const sf::Vector2f& size,
		const std::string& text_string,
		const sf::Font& font,
		const int font_size,
		const sf::Color& background_color,
		const sf::Color& background_pressed_color
	);

	// Updates the button.
	void update() override;

	// Renders the button to the specified window_.
	void render(sf::RenderWindow& window_) const override;

	// Sets the shared font for all buttons.
	static void set_font(sf::Font font);

	// Returns the text_ displayed on the button.
	std::string get_text() const;

	void animate_button_click();
};

#endif // BUTTON_H