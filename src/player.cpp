#include <player.h>

Player::Player(std::shared_ptr<sf::RenderWindow> &win, float x, float y, float cellSize) {
    this->mXPosition = x/2 * cellSize - (cellSize * 10)/2;
    this->mBoardWidth = x * cellSize;
    this->mYPosition = y * cellSize - 2 * cellSize;
    this->mCellSize = cellSize;
    this->mAcceleration = 2* cellSize;
    this->mVelocity = 0;
    this->mPlayerWidth = cellSize * 10;
    this->window = win;
}

Player::~Player() {
}

void Player::drawPlayer() {
    // Create a Rectangle that is player width and height
    sf::RectangleShape shape(sf::Vector2(this->mPlayerWidth, this->mCellSize));

    shape.setFillColor(sf::Color(255,255,255));
    shape.setPosition(this->mXPosition,this->mYPosition);
    this->window->draw(shape);
}

void Player::moveRight() {
    this->mVelocity = this->mAcceleration;
    this->mRightPressed = true;
}

void Player::moveLeft() {
    this->mVelocity = this->mAcceleration * -1;
    this->mLeftPressed = true;
}

void Player::stop(sf::Event event) {
    this->mVelocity = 0;
    if(event.key.code == sf::Keyboard::Right) {
        this->mRightPressed = false;
        if(this->mLeftPressed)
            this->moveLeft();
    }
    if(event.key.code == sf::Keyboard::Left) {
        this->mLeftPressed = false;
        if(this->mRightPressed)
            this->moveRight();
    }
}

void Player::movePlayer(float elapsedTime) {
    if(this->mXPosition > this->mCellSize && this->mVelocity < 0) {
        this->mXPosition = this->mXPosition + this->mVelocity * elapsedTime;
    }
    if(this->mXPosition + this->mPlayerWidth < (this->mBoardWidth - this->mCellSize) && this->mVelocity > 0) {
        this->mXPosition = this->mXPosition + this->mVelocity * elapsedTime;
    }
}

void Player::setVelocity(float velocity) {
    this->mVelocity = velocity;
}

void Player::setPlayerWidth(float width) {
    this->mPlayerWidth = width;
}
