#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"
#include "Colors.h"
#include "ClickHandler.h"
#include <memory>

// Base class for any drawable object within the game or application.
class Object {

protected:
    sf::Vector2f position_{ 0, 0 }; // 2D position of the object.
    sf::Vector2f size_; // Size of the bounding box.
    std::shared_ptr<ClickHandler> p_click_handler_; // Handle click on the object.
    std::shared_ptr<sf::Clock> p_clock_; // Clock for animations.

public:
    Object(const sf::Vector2f& pos, const sf::Vector2f& size);
    virtual ~Object() = default;

    // Updates the state of the object.
    virtual void update() = 0;

    // Renders the object.
    // @param window_: The RenderWindow object where the object will be drawn.
    virtual void render(sf::RenderWindow& window_) const = 0;

    // Calculates the boundary of the object.
    // @return coordinates of the left-upper corner and the right-bottom corner of the bounding box.
    std::pair<sf::Vector2f, sf::Vector2f> get_global_bounds() const;

    bool is_clickable() const;
    void set_click_handler(std::shared_ptr<ClickHandler> p_click_handler);
    std::shared_ptr<ClickHandler> get_click_handler();
};

#endif // OBJECT_H