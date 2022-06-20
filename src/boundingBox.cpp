#include <boundingBox.h>
#include <iostream>
#include <utility>

BoundingBox::BoundingBox(const Vector2& tl, const Vector2& tr, const Vector2& br, const Vector2& bl) {
    std::cout << "Bounding Box Created!" << std::endl;
    _topLeft = tl;
    _topRight = tr;
    _bottomRight = br;
    _bottomLeft = bl;
}

BoundingBox::~BoundingBox() {
    std::cout << "Bounding Box Destroyed!" << std::endl;
}

void BoundingBox::update(const Vector2& tl, const Vector2& tr, const Vector2& br , const Vector2 &bl) {
    _topLeft = tl;
    _topRight = tr;
    _bottomRight = br;
    _bottomLeft = bl;
}

BoundingBox::BoundingBox() {
    _topLeft = Vector2(0.0f, 0.0f);
    _topRight = Vector2(0.0f, 0.0f);
    _bottomRight = Vector2(0.0f, 0.0f);
    _bottomLeft = Vector2(0.0f, 0.0f);
}

Vector2 BoundingBox::getTopLeft() {
    return _topLeft;
}

Vector2 BoundingBox::getTopRight() {
    return _topRight;
}

Vector2 BoundingBox::getBottomLeft() {
    return _bottomLeft;
}

Vector2 BoundingBox::getBottomRight() {
    return _bottomRight;
}
