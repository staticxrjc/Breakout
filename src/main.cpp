#include <engine.h>

int main() {
    engine maze(160, 160, 4);

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