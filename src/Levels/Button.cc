#include "Button.hh"

Button::Button(AEVec2 pos, AEVec2 size, unsigned int color, const char* text) : position(pos), size(size),color(color), text(text)
{

}

void Button::Draw()
{
	AEGfxRect(position.x, position.y, 0, size.x, size.y, color);
	AEGfxPrint(position.x + AEGetSysWindowWidth()/2, position.y + AEGetSysWindowHeight() / 2, color, text);
}

void Button::Update()
{

}
