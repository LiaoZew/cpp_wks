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


EXTERN const char* uart_port_items[255] ;
EXTERN int uart_port_items_idx ;
EXTERN int uart_port_num;


typedef enum{
    uart_open,
    uart_idle,
    uart_close
}uart_statu_t;
EXTERN uart_statu_t uart_statu ;



 
#endif/*__ZGLOBAL_H__*/
