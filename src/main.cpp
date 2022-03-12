#include <iostream>
#include <engine.h>

int main() {
    engine maze(80, 80, 4);

    while (maze.isRunning())
    {
        // Event Loop
        maze.processEvent();

        // Update
        maze.update();

        // Render
        maze.renderScreen();
    }
}