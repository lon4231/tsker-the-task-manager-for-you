#pragma once
#include <iostream>
#include <Windows.h>

void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        std::cerr << "Error al obtener el manejador de la salida estándar." << std::endl;
        return;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        std::cerr << "Error al obtener el modo de la consola." << std::endl;
        return;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(hOut, dwMode)) {
        std::cerr << "Error al establecer el modo de la consola." << std::endl;
        return;
    }
}

void movecursor(int x,int y){
 std::cout<<"\033[" + std::to_string(y) + ";" + std::to_string(x) + "H";
}

void setbackgroundcolor(int colorCode) {
        std::cout<<"\033[48;5;" + std::to_string(colorCode%256) + "m";
}

void settextcolor(int colorCode) {
   std::cout << "\033["<<(colorCode%8)+30<<"m";
}

void clearscreen(){std::cout<<"\033[2J\033[1;1H";}