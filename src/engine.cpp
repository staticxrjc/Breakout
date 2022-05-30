#include <engine.h>
#include <player.h>

void engine::initVariables() {
    // Resize vector to size of X * Y cells
    mBreakoutMap.resize(this->mXCells * this->mYCells);

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
    player = std::make_shared<Player>(window, this->mXCells,this->mYCells,float(this->mCellSize));
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
}

bool engine::isRunning(){
    return this->window->isOpen();
}

void engine::update() {
    //
}

void engine::processEvent() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window->close();
        else if (this->event.type == sf::Event::KeyPressed) {
            if(this->event.key.code == sf::Keyboard::Right)
                this->player->moveRight();
            else if(this->event.key.code == sf::Keyboard::Left)
                this->player->moveLeft();
            else
                std::cout << this->event.key.code << std::endl;
        }
    }
}

void engine::renderScreen() {
    // clear window
    this->window->clear(sf::Color::Black);

    this->drawMap();
    this->player->drawPlayer();

    // Display frame
    this->window->display();
}