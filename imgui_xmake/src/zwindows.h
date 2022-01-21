/*
 * @Author: your name
 * @Date: 2022-01-19 20:41:54
 * @LastEditTime: 2022-01-19 23:36:33
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp_wks\imgui_xmake\src\zwindows.h
 */
#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_freetype.h"
// #include <stdio.h>
// #include <stdint.h>

#include <iostream>

#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#include "zuart.h"
#include "zglobal.h"

void MySaveFunction ();
void main_window();

void control_uart_window();
