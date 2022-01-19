/*
 * @Author: your name
 * @Date: 2022-01-19 20:41:54
 * @LastEditTime: 2022-01-19 23:53:49
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp_wks\imgui_xmake\src\zwindows.cpp
 */
#include "zwindows.h"



bool window_mask;
bool show_main_window=true;
bool show_demo_window;


//uart windows
int w_uart_index=0;
bool show_uart_window;

 

void main_window()
{
    static float f = 0.0f;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    if(show_main_window)
    {
        ImGui::Begin("zutil", &show_main_window, ImGuiWindowFlags_None);  

        if (ImGui::Button("UART"))
            openuart();

        if (ImGui::Button("DEMO"))
            MySaveFunction();    
            
        ImGui::End();
    }

    if(show_uart_window)
    {
        ImGui::Begin("uart", &show_uart_window, ImGuiWindowFlags_None);  

        ImGui::Text("port:");
        ImGui::Text("baudrate:");
        ImGui::Text("data bits:");
        ImGui::Text("check bit:");
        ImGui::Text("flow control:");
            
        ImGui::End();
    }

    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);
}


void openuart()
{
    if(show_uart_window==true)
        show_uart_window=false;
    else 
        show_uart_window=true;
        
}

void MySaveFunction ()
{
    if(show_demo_window==true)
        show_demo_window=false;
    else 
        show_demo_window=true;
        
}


