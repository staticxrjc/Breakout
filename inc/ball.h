#ifndef BALL_H
#define BALL_H
#define PI 3.14159265

#include <SFML/Graphics.hpp>
#include <memory>
#include <boundingBox.h>
#include <vector2.h>
#include <cmath>

class Ball {
private:
    Vector2 _pos,_tr,_br,_bl;
    std::shared_ptr<BoundingBox> _boundingBox;
    std::shared_ptr<sf::RenderWindow> _window;
    float _width;
    float _velocity;
    float _angle;

    // Private Functions
    void _updateBounding();

public:
    Ball(const std::shared_ptr<sf::RenderWindow>&, float,float,float);
    ~Ball();
    void drawBall();
    void drawBounding();
    void bounceSide();
    void bounceVert();
    std::shared_ptr<BoundingBox> moveBall(float);
};

#endif // BALL_H
