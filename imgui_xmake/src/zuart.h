#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_freetype.h"
// #include <stdio.h>
// #include <stdint.h>

#include <iostream>


#include <GLFW/glfw3.h> // Will drag system OpenGL headers


#include "CSerialPort/SerialPort.h"
#include "CSerialPort/SerialPortInfo.h"

#include "zglobal.h"


void open_uart();
