#include "MouseEventManager.hh"
#include <algorithm>
void MouseEventManager::addHandler(OnMouseEvent event)
{
	this->handlers.push_back(event);
}

void MouseEventManager::trigger(MouseEvent* event)
{
	std::for_each(handlers.begin(), handlers.end(), [&event](OnMouseEvent& handler)
		{
			handler(event);

		});
}
