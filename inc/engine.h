#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <player.h>

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
    std::shared_ptr<Player> player;

    // Breakout Private Functions
    void drawMap();

public:
    explicit engine(int, int, int);
    ~engine();
    bool isRunning();
    void update();
    void processEvent();
    void renderScreen();
};
#endif