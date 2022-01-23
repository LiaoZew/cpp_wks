/*
 * @Author: your name
 * @Date: 2022-01-21 20:31:22
 * @LastEditTime: 2022-01-22 14:27:33
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp_wks\imgui_xmake\src\zuart.cpp
 */
#include "zuart.h"


class mySlot : public has_slots<>
{
public:
    mySlot(itaCSerialPort * sp)
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
			countRead++;
			std::cout << recLen<< std::endl;

			str[recLen] = '\0';
			std::cout << "receive data : " << str << ", receive size : " << recLen << ", receive count : " << countRead << std::endl;

			if(countRead > 7)
			{
				std::cout << "close serial port when receive count > 7" << std::endl;
				p_sp->close();
			}
			else
			{		
				// return receive data
				p_sp->writeData(str, recLen);
			}
		}
	};

private:
	mySlot(){};

private:
    CSerialPort * p_sp;

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

        std::cout << "Version : " << sp.getVersion() << std::endl << std::endl;
            
    }

        ImGui::Text("端  口:");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(200);

        Combo("##port", &uart_port_items_idx, m_availablePortsList );

        
        ImGui::SameLine();
        if(ImGui::RadioButton("打开",(int *)&uart_statu,uart_open));
        ImGui::SameLine();
        if(ImGui::RadioButton("暂停",(int *)&uart_statu,uart_idle));
        ImGui::SameLine();
        if(ImGui::RadioButton("关闭",(int *)&uart_statu,uart_close));


        ImGui::Text("波特率:");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(200);
        ImGui::Combo("##baudrate", &uart_baudrate_items_idx, uart_baudrate_items, IM_ARRAYSIZE(uart_baudrate_items));

	


        ImGui::Separator();





}



