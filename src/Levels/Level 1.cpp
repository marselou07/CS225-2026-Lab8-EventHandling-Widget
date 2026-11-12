#include <AEEngine.h>
#include <imgui/imgui.h>
#include "Level 1.h"
#include "Button.hh"
#include "MouseEventManager.hh"
int mode = 0;

bool ShowFrameworkMenu();
Button button(AEVec2(0.f,0.f), AEVec2(120.f,30.f), AE_COLORS_GREEN_YELLOW,"Button");
MouseEventManager eventManager;
void Level_1_Load()
{
    Button* btn = &button;
    eventManager.addHandler([btn](MouseEvent * event) {
        btn->OnMouseClick(event);
        });
}

void Level_1_Init()
{

}

void Level_1_Update()
{
    // core keyboard shortcuts and GUI, do not delete this code!
    KeyboardInput();
    bool guiActive = ShowFrameworkMenu();


    if (AEInputMousePressed(0))
    {
        MouseEvent event;
        eventManager.trigger(&event);
    }
}

void Level_1_Render()
{
    // clear frame buffer, do not delete this code
    AEGfxSetClearColor(AEGfxColor(0, 0, 0));
    AEGfxClearBuffer();
    button.Draw();
}

void Level_1_Free()
{

}

void Level_1_Unload()
{
}

void KeyboardInput()
{
    if (AEInputKeyTriggered('R'))
        AESetGameStateNext(AE_GS_RESTART);
    if (AEInputKeyTriggered('Q') && AEInputKeyPressed(AE_KEY_CTRL))
        AESetGameStateNext(AE_GS_QUIT);
}

bool ShowFrameworkMenu()
{
    bool isGuiActive = false;
    mode = 0;

    // show File options 
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Mode")) {

            if (ImGui::MenuItem("Restart", "1"))
                mode = 1;

            ImGui::EndMenu();
        }

        auto mSize = ImGui::GetWindowHeight();
        AEVec2 mouseVP = AEGetMouseData().position + AEVec2((float)AEGetSysWindowWidth() / 2.0f, (float)AEGetSysWindowHeight() / 2.0f);
        auto inMenu = mouseVP.y >= (AEGetSysWindowHeight() - mSize);
        isGuiActive = ImGui::IsAnyItemActive() || ImGui::IsAnyItemHovered() || inMenu;

        ImGui::EndMainMenuBar();
    }

    if (mode == 1) {
        AESetGameStateNext(AE_GS_RESTART);
    }

    return isGuiActive;
}

