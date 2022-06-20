#include <vector2.h>
#include <iostream>

Vector2::Vector2() {
//    std::cout << "Vector 2 Created" << std::endl;
    x = 0.0f;
    y = 0.0f;
}

Vector2::Vector2(float lX, float lY) {
    x = lX;
    y = lY;
}

Vector2::~Vector2() {
//    std::cout << "Vector 2 Destroyed" << std::endl;
}