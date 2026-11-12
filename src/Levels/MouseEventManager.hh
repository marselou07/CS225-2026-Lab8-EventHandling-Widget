#pragma once
#include "../Framework/event.hh"
#include <functional>
#include <vector>

class MouseEvent : public Event
{
	public:

};


typedef std::function<void(MouseEvent* event)> OnMouseEvent;



class MouseEventManager
{
protected:
	std::vector<OnMouseEvent> handlers;



};