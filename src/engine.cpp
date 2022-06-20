#include <engine.h>
#include <player.h>
#include <ball.h>

void engine::initVariables() {
    // Resize vector to size of X * Y cells
    mBreakoutMap.resize(this->mXCells * this->mYCells);

    // Start Clock
    clock.restart();

    // Populate map dynamically
    for(int y = 0; y < this->mYCells; y++) {
        for(int x = 0; x < this->mXCells; x++)
            if (y == 0 || x == (this->mXCells - 1) || x == 0)
                mBreakoutMap[x + (y * this->mXCells)] = -1;
            else if ((y % 8 == 0) && (x > (.2*this->mXCells)) && (x < (.8 * this->mXCells)) && (y < (.6 * this->mYCells))) {
                mBreakoutMap[x + (y * this->mXCells)] = 20;
            }
            else
                mBreakoutMap[x + (y * this->mXCells)] = 0;
    }

    // Create Player
    _player = std::make_shared<Player>(window, this->mXCells, this->mYCells, float(this->mCellSize));

    // Create Ball
    _ball = std::make_unique<Ball>(window, (mXCells * mCellSize)/2 - mCellSize/2,(mYCells * mCellSize)/1.5,mCellSize);
};

void engine::initWindow(){
    //
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(this->mXCells * this->mCellSize, this->mYCells * this->mCellSize), "Breakout!");
}

void engine::drawMap() {
    // draws map based on mBreakoutMap array
    sf::RectangleShape shape(sf::Vector2f(float(this->mCellSize), float(this->mCellSize)));

    // Draw if not == 0, nothing is there
    for(int y = 0; y < this->mYCells; y++) {
        for (int x = 0; x < this->mXCells; x++) {
            // set the shape color to green
            shape.setFillColor(sf::Color(100, 250, 50));
            if(this->mBreakoutMap[x + (y * mXCells)] == -1) {
                shape.setPosition(sf::Vector2f(float(x*this->mCellSize),float(y*this->mCellSize)));
                this->window->draw(shape);
            }
            else if (this->mBreakoutMap[x + (y * mXCells)] >= 1) {
                shape.setFillColor(sf::Color(55, 55 ,150));
                shape.setPosition(sf::Vector2f(float(x*this->mCellSize), float(y*this->mCellSize)));
                this->window->draw(shape);
            }
        }
    }
}

engine::engine(int x, int y, int size) {
    this->mCellSize = size;
    this->mXCells = x;
    this->mYCells = y;
    initWindow();
    initVariables();
}

engine::~engine() {
    //
    std::cout << "Engine Destroyed" << std::endl;
}

bool engine::isRunning(){
    return this->window->isOpen();
}

void engine::update() {
    //
    this->_player->movePlayer(clock.getElapsedTime().asSeconds() * 10);
    std::shared_ptr<BoundingBox> ball = this->_ball->moveBall(clock.getElapsedTime().asSeconds() * 10);

    // Check Ball Collision Map
    switch(checkCollision(ball,mBreakoutMap)) {
        case 0:
            this->_ball->bounceSide();
            break;
        case 1:
            this->_ball->bounceVert();
            break;

    }

    clock.restart();
}

void engine::processEvent() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window->close();
        else if (this->event.type == sf::Event::KeyPressed) {
            if(this->event.key.code == sf::Keyboard::Right)
                this->_player->moveRight();
            else if(this->event.key.code == sf::Keyboard::Left)
                this->_player->moveLeft();
            else
                std::cout << this->event.key.code << std::endl;
        }
        else if (this->event.type == sf::Event::KeyReleased)  {
            if(this->event.key.code == sf::Keyboard::Right || this->event.key.code == sf::Keyboard::Left)
                this->_player->stop(event);
            else
                std::cout << this->event.key.code << std::endl;
        }
    }
}

void engine::renderScreen() {
    // clear window
    this->window->clear(sf::Color::Black);

    this->drawMap();
    this->_player->drawPlayer();
    this->_ball->drawBall();
    this->_ball->drawBounding();

    // Display frame
    this->window->display();
}

int engine::checkCollision(std::shared_ptr<BoundingBox> first, std::shared_ptr<BoundingBox> second) {
    return false;
}

int engine::checkCollision(std::shared_ptr<BoundingBox> box, std::vector<int> map) {
    int x = std::floor(box->getTopLeft().x/mCellSize);
    int y = std::floor(box->getTopLeft().y/mCellSize);
    int index = x + mXCells * y;
    if(map[index] != 0) {
        printf("X = %i\n",x);
        printf("Y = %i\n",y);
        printf("Index = %i\n",index);
        printf("Map Value = %i\n",map[index]);
        if(map[index] == -1) {
            if(y == 0)
                return 1;
            return 0;
        }
        else {
            return 1;
        }
    }
    x = std::floor(box->getTopRight().x/mCellSize);
    y = std::floor(box->getTopRight().y/mCellSize);
    index = x + mXCells * y;
    if(map[index] != 0) {
        printf("X = %i\n",x);
        printf("Y = %i\n",y);
        printf("Index = %i\n",index);
        printf("Map Value = %i\n",map[index]);
        if(y == 0)
            return 1;
        return 0;
    }
    x = std::floor(box->getBottomRight().x/mCellSize);
    y = std::floor(box->getBottomRight().y/mCellSize);
    index = x + mXCells * y;
    if(map[index] != 0) {
        printf("X = %i\n",x);
        printf("Y = %i\n",y);
        printf("Index = %i\n",index);
        printf("Map Value = %i\n",map[index]);
        return true;
    }
    x = std::floor(box->getBottomLeft().x/mCellSize);
    y = std::floor(box->getBottomLeft().y/mCellSize);
    index = x + mXCells * y;
    if(map[index] != 0) {
        printf("X = %i\n",x);
        printf("Y = %i\n",y);
        printf("Index = %i\n",index);
        printf("Map Value = %i\n",map[index]);
        return true;
    }
    return -1;
}
