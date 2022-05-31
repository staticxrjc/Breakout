#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

class Player {
    std::shared_ptr<sf::RenderWindow> window;
    float mXPosition, mYPosition, mCellSize, mVelocity, mPlayerWidth, mBoardWidth, mAcceleration;
    bool mLeftPressed, mRightPressed;

public:
    Player(std::shared_ptr<sf::RenderWindow>&,float,float,float);
    ~Player();
    void drawPlayer();
    void moveRight();
    void moveLeft();
    void movePlayer(float);
    void stop(sf::Event);
    void setVelocity(float);
    void setPlayerWidth(float);
};

#endif //PLAYER_H
