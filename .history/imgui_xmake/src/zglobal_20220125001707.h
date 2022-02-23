/*
 * @Author: your name
 * @Date: 2022-01-21 20:31:22
 * @LastEditTime: 2022-01-25 00:17:07
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp_wks\imgui_xmake\src\zglobal.h
 */
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
EXTERN bool show_uart_control_window;
EXTERN bool show_uart_receive_window;
EXTERN bool show_uart_send_window;
EXTERN int w_uart_index;


//log
EXTERN bool show_log_window;

//uart
EXTERN bool uart_window_flag;
EXTERN std::string portName;
EXTERN vector<SerialPortInfo> m_availablePortsList;
EXTERN itas109::CSerialPort sp;
EXTERN bool open_reiceve_flag;


EXTERN const char* uart_port_items[255] ;
EXTERN int uart_port_items_idx ;
EXTERN int uart_port_num;

EXTERN DWORD uart_frame_time;


typedef enum{
    uart_open,
    uart_pause,
    uart_idle,
    uart_close
}uart_statu_t;
EXTERN uart_statu_t uart_statu ;



 
#endif/*__ZGLOBAL_H__*/
