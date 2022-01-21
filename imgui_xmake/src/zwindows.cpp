/*
 * @Author: your name
 * @Date: 2022-01-19 20:41:54
 * @LastEditTime: 2022-01-19 23:56:01
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp_wks\imgui_xmake\src\zwindows.cpp
 */
#include "zwindows.h"
 

void main_window()
{
    static float f = 0.0f;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    if(show_main_window)
    {
        ImGui::Begin("zutil", &show_main_window, ImGuiWindowFlags_None);  

        if (ImGui::Button("UART"))
            control_uart_window();

        if (ImGui::Button("DEMO"))
            MySaveFunction();    
            
        ImGui::End();
    }

    if(show_uart_window)
    {
        open_uart();
        ImGui::Begin("uart", &show_uart_window, ImGuiWindowFlags_None);  

        ImGui::Text("端  口:");
        ImGui::Text("波特率:");
        ImGui::Text("数据位:");
        ImGui::Text("校验位:");
        ImGui::Text("流  控:");
            
        ImGui::End();
    }
    else 
    {
        uart_window_flag=false;
    }

    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);
}


void control_uart_window()
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


