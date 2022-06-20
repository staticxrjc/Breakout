#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <player.h>
#include <ball.h>
#include <cmath>

class engine {
private:
    // SFML Variables
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event event;
    sf::Clock clock;

    // Breakout Variables
    std::vector<int> mBreakoutMap;
    int mCellSize, mXCells, mYCells;

    // Initialization
    void initVariables();
    void initWindow();

    // Child Classes
    std::shared_ptr<Player> _player;
    std::shared_ptr<Ball> _ball;

    // Breakout Private Functions
    void drawMap();
    int checkCollision(std::shared_ptr<BoundingBox>,std::shared_ptr<BoundingBox>);
    int checkCollision(std::shared_ptr<BoundingBox>,std::vector<int>);

public:
    explicit engine(int, int, int);
    ~engine();
    bool isRunning();
    void update();
    void processEvent();
    void renderScreen();
};
#endif