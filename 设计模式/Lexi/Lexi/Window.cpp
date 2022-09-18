//
//  Window.cpp
//  Lexi
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#include "Window.hpp"

void Window::drawCharacter(char c) {
    std::cout << "window draw character: " << c << std::endl;
}

void Window::drawRect(double x, double y, double width, double height) {
    printf("window draw rect: x - %f, y - %f, width - %f, heght - %f",x, y, width, height);
}
