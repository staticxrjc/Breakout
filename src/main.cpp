#include <engine.h>

int main() {
    engine maze(80, 50, 16);

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