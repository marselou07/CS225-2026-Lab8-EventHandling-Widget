#pragma once
#include "../Framework/event.hh"
#include <functional>
#include <vector>
#include "AECore/inc/AEEngine.h"
class MouseEvent : public Event
{
	public:
		AEVec2 position;
};


typedef std::function<void(MouseEvent* event)> OnMouseEvent;



class MouseEventManager
{
protected:
	std::vector<OnMouseEvent> handlers;
public:
	void addHandler(OnMouseEvent event);
	void trigger(MouseEvent* event);


};