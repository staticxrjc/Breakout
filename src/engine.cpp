#include <engine.h>
#include <iostream>

void engine::initVariables(int xCells, int yCells) {
    //
    breakoutMap.resize(xCells*yCells);
    for(int y = 0; y < yCells; y++) {
        for(int x = 0; x < xCells; x++) {
            if (y == 0 || x == (xCells -1) || x == 0)
                breakoutMap[x + (y * xCells)] = -1;
            else if ((y % 5 == 0) && (x > (.2*xCells)) && (x < (.8*xCells)) && (y < (.5*yCells)))
                breakoutMap[x + (y * xCells)] = 1;
            else
                breakoutMap[x + (y * xCells)] = 0;
            std::cout << breakoutMap[x + (y * xCells)];
        }
        std::printf("\n");
    }
};

void engine::initWindow(int x, int y){
    //
}

engine::engine(int xCells, int yCells, int cellSize) {
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(xCells*cellSize,yCells*cellSize), "Hello SFML!");
    initVariables(xCells, yCells);
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
    }
}

void engine::renderScreen() {
    // clear window
    this->window->clear(sf::Color::Black);

    sf::CircleShape shape(50.f);

    // set the shape color to green
    shape.setFillColor(sf::Color(100, 250, 50));

    this->window->draw(shape);
    
    // Display frame
    this->window->display();
}