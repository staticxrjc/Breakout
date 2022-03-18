#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include <memory>

class engine {
private:
    // SFML Variables
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event event{};

    // Breakout Variables
    std::vector<int> mBreakoutMap;
    int mCellSize, mXCells, mYCells;

    // Initialization
    void initVariables();
    void initWindow();

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