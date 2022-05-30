#include <player.h>

Player::Player(std::shared_ptr<sf::RenderWindow> &win, float x, float y, float cellSize) {
    this->mXPosition = x/2 * cellSize;
    this->mBoardWidth = x * cellSize;
    this->mYPosition = y * cellSize - 2 * cellSize;
    this->mCellSize = cellSize;
    this->mVelocity = cellSize;
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
    std::cout << "Board Width: " << this->mBoardWidth << std::endl;
    std::cout << "Player Width: " << this->mPlayerWidth << std::endl;
    std::cout << "Player X: " << this->mXPosition << std::endl;
    if(this->mXPosition + this->mPlayerWidth < (this->mBoardWidth - this->mCellSize)) {
        this->mXPosition += mVelocity;
    }
}

void Player::moveLeft() {
    std::cout << "Board Width: " << this->mBoardWidth << std::endl;
    std::cout << "Player Width: " << this->mPlayerWidth << std::endl;
    std::cout << "Player X: " << this->mXPosition << std::endl;
    if(this->mXPosition > this->mCellSize) {
        this->mXPosition -= mVelocity;
    }
}

void Player::setVelocity(float velocity) {
    this->mVelocity = velocity;
}

void Player::setPlayerWidth(float width) {
    this->mPlayerWidth = width;
}
