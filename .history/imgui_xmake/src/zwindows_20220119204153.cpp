#include "zwindows.h"



bool window_mask;
bool show_main_window=true;
bool show_demo_window;


//uart windows
int w_uart_index=0;
bool show_uart_window[255];

 

void main_window()
{
    static float f = 0.0f;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    if(show_main_window)
    {
        ImGui::Begin("zutil", &show_main_window, ImGuiWindowFlags_None);  

        if (ImGui::Button("UART"))
            MySaveFunction();
            
        ImGui::End();
    }

    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);
}


void MySaveFunction ()
{
    if(show_demo_window==true)
        show_demo_window=false;
    else 
        show_demo_window=true;

    w_uart_index++;

    std::cout<<w_uart_index<<std::endl;
        
}


