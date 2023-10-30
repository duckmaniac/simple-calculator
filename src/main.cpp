#include "Application.h"
#include "Calculator.h"

static const std::map<sf::Keyboard::Key, std::string> key_to_button_map = {
	{sf::Keyboard::Num0, "0"}, {sf::Keyboard::Numpad0, "0"},
	{sf::Keyboard::Num1, "1"}, {sf::Keyboard::Numpad1, "1"},
	{sf::Keyboard::Num2, "2"}, {sf::Keyboard::Numpad2, "2"},
	{sf::Keyboard::Num3, "3"}, {sf::Keyboard::Numpad3, "3"},
	{sf::Keyboard::Num4, "4"}, {sf::Keyboard::Numpad4, "4"},
	{sf::Keyboard::Num5, "5"}, {sf::Keyboard::Numpad5, "5"},
	{sf::Keyboard::Num6, "6"}, {sf::Keyboard::Numpad6, "6"},
	{sf::Keyboard::Num7, "7"}, {sf::Keyboard::Numpad7, "7"},
	{sf::Keyboard::Num8, "8"}, {sf::Keyboard::Numpad8, "8"},
	{sf::Keyboard::Num9, "9"}, {sf::Keyboard::Numpad9, "9"},
	{sf::Keyboard::Comma, "."}, {sf::Keyboard::Period, "."},
	{sf::Keyboard::Divide, "/"}, {sf::Keyboard::Slash, "/"},
	{sf::Keyboard::Multiply, "*"},
	{sf::Keyboard::Subtract, "-"}, {sf::Keyboard::Hyphen , "-"},
	{sf::Keyboard::Add, "+"},
	{sf::Keyboard::Enter, "="}, {sf::Keyboard::Equal, "="},
	{sf::Keyboard::BackSpace, "<-"},
	{sf::Keyboard::Delete, "AC"}
};

static const std::map<sf::Keyboard::Key, std::string> key_to_button_with_shift_map = {
	{sf::Keyboard::Num8, "*"},
	{sf::Keyboard::Equal, "+"}
};

void process_physical_click(const sf::Event event, const std::map<std::string, std::shared_ptr<Button>>& buttons_map,
	const std::map<sf::Keyboard::Key, std::string>& key_to_button_map) {
	auto it = key_to_button_map.find(event.key.code);
	if (it != key_to_button_map.end()) {
		auto button = buttons_map.find(it->second);
		if (button != buttons_map.end()) {
			if (event.type == sf::Event::KeyPressed) {
				button->second->get_click_handler()->on_mouse_pressed();
			}
		}
	}
}

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {

	try {
		Application app("Simple calculator", 480, 720, 30);

		// Load resources.
		auto font = app.load_resource<sf::Font>("ID_FONT_MAIN");
		auto icon = app.load_resource<sf::Image>("ID_IMAGE_ICON");

		// Setup window's icon.
		app.set_icon(icon);

		// Setup display.
		auto display = std::make_shared<InputField>(InputField({ 25, 25 }, {430, 135}, "", font, 80, 25, Colors::YELLOW, Colors::WHITE));
		app.add_object(display);

		// Setup keyboard.
		const sf::Vector2f button_size = {100.0f, 100.0f};
		const int button_font_size = 30;
		std::map<std::string, std::shared_ptr<Button>> buttons_map{
			{"7", std::make_shared<Button>(Button({25, 155}, button_size, "7", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"8", std::make_shared<Button>(Button({135, 155}, button_size, "8", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"9", std::make_shared<Button>(Button({245, 155}, button_size, "9", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"/", std::make_shared<Button>(Button({355, 155}, button_size, "/", font, button_font_size, Colors::BLUE, Colors::YELLOW))},

			{"4", std::make_shared<Button>(Button({25, 265}, button_size, "4", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"5", std::make_shared<Button>(Button({135, 265}, button_size, "5", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"6", std::make_shared<Button>(Button({245, 265}, button_size, "6", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"*", std::make_shared<Button>(Button({355, 265}, button_size, "*", font, button_font_size, Colors::BLUE, Colors::YELLOW))},

			{"1", std::make_shared<Button>(Button({25, 375}, button_size, "1", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"2", std::make_shared<Button>(Button({135, 375}, button_size, "2", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"3", std::make_shared<Button>(Button({245, 375}, button_size, "3", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"-", std::make_shared<Button>(Button({355, 375}, button_size, "-", font, button_font_size, Colors::BLUE, Colors::YELLOW))},

			{"0", std::make_shared<Button>(Button({25, 485}, button_size, "0", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{".", std::make_shared<Button>(Button({135, 485}, button_size, ".", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"<-", std::make_shared<Button>(Button({245, 485}, button_size, "<-", font, button_font_size, Colors::GREEN, Colors::YELLOW))},
			{"+", std::make_shared<Button>(Button({355, 485}, button_size, "+", font, button_font_size, Colors::BLUE, Colors::YELLOW))},

			{"=", std::make_shared<Button>(Button({25, 595}, {320.0f, 100.0f}, "=", font, 50, Colors::GREEN, Colors::YELLOW))},
			{"AC", std::make_shared<Button>(Button({355, 595}, button_size, "AC", font, button_font_size, Colors::BLUE, Colors::YELLOW))}
		};

		std::vector <std::shared_ptr<Object>> buttons_vector;
		for (std::pair<std::string,std::shared_ptr<Button>> item : buttons_map) {
			auto click_handler = std::make_shared<ClickHandler>();

			if (item.second->get_text() == "<-") {
				click_handler->on_mouse_pressed = [item, display]() {
					display->remove_last_character();
					item.second->animate_button_click();
				};
			}
			else if (item.second->get_text() == "AC") {
				click_handler->on_mouse_pressed = [item, display]() {
					display->clear();
					item.second->animate_button_click();
				};
			}
			else if (item.second->get_text() == "=") {
				click_handler->on_mouse_pressed = [item, display]() {
					try {
						big_float answer = Calculator::calculate(display->get_text());
						display->set_text(answer.str().substr(0, PRECISION));
					}
					catch (const std::exception) {
						display->show_error();
					}
					
					item.second->animate_button_click();
				};
			}
			else {
				click_handler->on_mouse_pressed = [item, display]() {
					display->add_character(item.second->get_text()[0]);
					item.second->animate_button_click();
				};
			}
			item.second->set_click_handler(click_handler);

			buttons_vector.push_back(item.second);
		}
		app.add_objects(buttons_vector);

		app.add_event_handler([buttons_map](const sf::Event& event) {
			if (event.type != sf::Event::KeyPressed) return;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
				process_physical_click(event, buttons_map, key_to_button_with_shift_map);
			}
			else {
				process_physical_click(event, buttons_map, key_to_button_map);
			}
		});

		
		// Start the application.
		app.start();
	}
	catch (const std::exception& e) {
		MessageBox(NULL, e.what(), "Error!", MB_ICONERROR | MB_OK);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}