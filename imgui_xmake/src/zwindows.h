#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_freetype.h"
// #include <stdio.h>
// #include <stdint.h>

#include <iostream>


extern bool show_main_window;
extern bool show_demo_window;
extern int w_uart_index;
extern bool show_uart_window[255];

extern void MySaveFunction ();
extern void main_window();