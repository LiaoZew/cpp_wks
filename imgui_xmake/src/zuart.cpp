#include "zuart.h"


void open_uart()
{

    if(!uart_window_flag)
    {
        uart_window_flag=true;

        m_availablePortsList = itas109::CSerialPortInfo::availablePortInfos();


        std::cout << "availableFriendlyPorts : " << std::endl;
            
        for (int i = 0; i < m_availablePortsList.size(); i++)
        {
            std::cout << i << " - " << m_availablePortsList[i].portName << " " << m_availablePortsList[i].description << std::endl;
        }
    }



}



