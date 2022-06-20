#include <ball.h>
#include <iostream>

Ball::Ball(const std::shared_ptr<sf::RenderWindow>& window, float x, float y, float w) {
    _pos.x = x;
    _pos.y = y;
    _boundingBox = std::make_shared<BoundingBox>();
    _updateBounding();
    _width = w;
    _window = window;
    _velocity = 10;
    _angle = -80;
    std::cout << "Ball Created" << std::endl;
}

Ball::~Ball() {
    std::cout << "Ball Destroyed" << std::endl;
}

void Ball::drawBall() {
    // Create a circle that is a _ball width and height
    sf::CircleShape shape(_width);

    shape.setFillColor(sf::Color(0,255,0));
    shape.setPosition(_pos.x,_pos.y);
    this->_window->draw(shape);
}

void Ball::drawBounding() {
    sf::RectangleShape top(sf::Vector2(_tr.x - _pos.x,1.0f));
    sf::RectangleShape right(sf::Vector2(_bl.y - _tr.y, 1.0f));
    sf::RectangleShape bottom(sf::Vector2(_br.x - _bl.x, 1.0f));
    sf::RectangleShape left(sf::Vector2(_bl.y - _pos.y, 1.0f));

    top.setFillColor(sf::Color::Red);
    right.setFillColor(sf::Color::Red);
    bottom.setFillColor(sf::Color::Red);
    left.setFillColor(sf::Color::Red);
    top.setPosition(_pos.x,_pos.y);
    right.setPosition(_tr.x,_tr.y);
    right.rotate(90);
    bottom.setPosition(_bl.x,_br.y);
    left.setPosition(_pos.x,_pos.y);
    left.rotate(90);

    this->_window->draw(top);
    this->_window->draw(right);
    this->_window->draw(bottom);
    this->_window->draw(left);
}

std::shared_ptr<BoundingBox> Ball::moveBall(float eTime) {
    float velocityX = eTime * _velocity * std::cos(_angle * PI/180);
    float velocityY = eTime * _velocity * std::sin(_angle * PI/180);
    _pos.x += velocityX;
    _pos.y += velocityY;
    _updateBounding();

    return _boundingBox;
}

void Ball::_updateBounding() {
    _tr.x = _pos.x+2*_width;
    _tr.y = _pos.y;
    _bl.x = _pos.x;
    _bl.y = _pos.y+2*_width;
    _br.x = _pos.x+2*_width;
    _br.y = _pos.y+2*_width;

    _boundingBox->update(_pos,_tr,_br,_bl);
}

void Ball::bounceSide() {
    float velocityX = -_velocity * std::cos(_angle * PI/180);
    float velocityY = _velocity * std::sin(_angle * PI/180);
    printf("x vel: %f\ny vel: %f\n", velocityX, velocityY);
    _angle = std::atan(velocityY / velocityX) * 180/PI;
    _velocity = -1 * _velocity;
    std::cout << _angle << std::endl;
    if (_angle > 360)
        _angle -= 360;
    if (_angle < -360)
        _angle += 360;
    moveBall(1);
}

void Ball::bounceVert() {
    float velocityX = _velocity * std::cos(_angle * PI/180);
    float velocityY = -_velocity * std::sin(_angle * PI/180);
    printf("x vel: %f\ny vel: %f\n", velocityX, velocityY);
    _angle = std::atan(velocityY / velocityX) * 180/PI;
    std::cout << _angle << std::endl;
    if (_angle > 360)
        _angle -= 360;
    if (_angle < -360)
        _angle += 360;
    moveBall(1);
}
