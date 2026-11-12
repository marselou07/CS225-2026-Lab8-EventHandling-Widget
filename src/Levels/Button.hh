#pragma once
#include "AECore//inc/AEEngine.h"
#include "../Framework/entity.hh"
#include "MouseEventManager.hh"
class Button : public Entity
{
	public:
		AEVec2 position;
		AEVec2 size;
		unsigned int color;
		const char* text;

		Button(AEVec2 pos, AEVec2 size, unsigned int color, const char* text);
		void Draw() override;
		void Update() override;

		void OnMouseClick(MouseEvent* event);
};