/*
 * @Author: your name
 * @Date: 2022-01-21 20:31:22
 * @LastEditTime: 2022-01-23 22:32:21
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp_wks\imgui_xmake\src\zuart.cpp
 */
#include "zuart.h"


class mySlot : public has_slots<>
{
public:
    mySlot(itas109::CSerialPort * sp)
    {
	    recLen = -1;
        p_sp = sp;
    };

	void OnSendMessage()
	{
		//read
        recLen = p_sp->readAllData(str);

		if(recLen > 0)
		{
			std::cout << recLen<< std::endl;
			str[recLen] = '\0';
			std::cout << "receive data : " << str << ", receive size : " << recLen << ", receive count : " << std::endl;

		}
	};

private:
	mySlot(){};

private:
    itas109::CSerialPort * p_sp;

	char str[1024];
	int recLen;
};


//add ne5
static auto vector_getter = [](void* vec, int idx, const char** out_text)
{
    auto& vector = *static_cast<std::vector<SerialPortInfo>*>(vec);
    if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }

    *out_text = vector.at(idx).display.c_str();
    return true;
};

bool Combo(const char* label, int* currIndex, std::vector<SerialPortInfo>& values)
{
    if (values.empty()) { return false; }
    return ImGui::Combo(label, currIndex, vector_getter,
        static_cast<void*>(&values), values.size());
}



void open_uart()
{
    //uart parameters set
    const char* uart_baudrate_items[] = { "1000000", "115200", "9600"};
    static int uart_baudrate_items_idx = 1;

    if(!uart_window_flag)
    {
        uart_window_flag=true;

        uart_statu = uart_close;
        

        m_availablePortsList = itas109::CSerialPortInfo::availablePortInfos();
        // std::cout << "availableFriendlyPorts : " << std::endl;

    if(m_availablePortsList.empty())
    {
        uart_port_items_idx=-1;
        std::cout << "Version : " << sp.getVersion() << std::endl << std::endl;
    }    
    else
    {
        if(uart_port_items_idx==-1)
        {
            uart_port_items_idx=0;
        }
        mySlot receive(&sp);
    }
        
    }

        ImGui::Text("端  口:");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(200);

        
        if(Combo("##port", &uart_port_items_idx, m_availablePortsList ))
        {
            printf("\n1");
            sp.close();
        }

        
        ImGui::SameLine();
        if(ImGui::RadioButton("打开",(int *)&uart_statu,uart_open))
        {
            if(uart_port_items_idx>-1)
            {
                portName = m_availablePortsList[uart_port_items_idx].portName;

                sp.init(portName);
                 
                
                if(!sp.isOpened())
                {
                  sp.open();
                }

                if(sp.isOpened())
                {
                    ImGuiStyle& style = ImGui::GetStyle();

                    style.Colors[ImGuiCol_Button]=ImVec4(1,1,1,1);
                }

                std::cout<<"uart_statu:"<<sp.isOpened()<<std::endl;


            }
        }
        ImGui::SameLine();
        if(ImGui::RadioButton("暂停",(int *)&uart_statu,uart_pause));
        ImGui::SameLine();
        if(ImGui::RadioButton("关闭",(int *)&uart_statu,uart_close));





        ImGui::Text("波特率:");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(200);
        ImGui::Combo("##baudrate", &uart_baudrate_items_idx, uart_baudrate_items, IM_ARRAYSIZE(uart_baudrate_items));

	


        ImGui::Separator();





}



