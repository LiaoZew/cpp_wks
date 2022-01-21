#ifndef __ZGLOBAL_H__
#define __ZGLOBAL_H__

#ifdef EXPORT_GLOBALS
#define EXTERN
#else
#define EXTERN extern
#endif

#include <iostream>
#include "CSerialPort/SerialPort.h"
#include "CSerialPort/SerialPortInfo.h"
#include <vector>

//window
EXTERN bool show_main_window;
EXTERN bool show_demo_window;
EXTERN bool show_uart_window;
EXTERN int w_uart_index;

//uart
EXTERN bool uart_window_flag;
EXTERN std::string portName;
EXTERN vector<SerialPortInfo> m_availablePortsList;
EXTERN itas109::CSerialPort sp;


 
#endif/*__ZGLOBAL_H__*/
