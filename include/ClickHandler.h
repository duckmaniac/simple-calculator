#ifndef CLICK_HANDLER_H
#define CLICK_HANDLER_H

#include <functional>
#include "Object.h"

using std::function;

// Handle the mouse click on the object.
struct ClickHandler {
	std::function<void()> on_mouse_pressed;
};

#endif // CLICK_HANDLER_H