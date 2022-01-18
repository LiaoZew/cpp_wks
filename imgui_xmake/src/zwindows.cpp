#include "zwindows.h"

bool show_main_window=true;
bool show_demo_window;
int a;

void main_window()
{
    static float f = 0.0f;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    ImGui::Begin("zutil", &show_main_window, ImGuiWindowFlags_None);  
     // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
    ImGui::Text("我的  test  %d",a);

    ImGui::SameLine();
    if (ImGui::Button("open"))
        MySaveFunction();



    // ImGui::InputText("string", buf, IM_ARRAYSIZE(buf));
    // ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    ImGui::End();
}


void MySaveFunction ()
{
    if(show_demo_window==true)
        show_demo_window=false;
    else 
        show_demo_window=true;

    a++;
}


