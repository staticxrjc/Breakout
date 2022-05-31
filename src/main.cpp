#include <engine.h>
#include <chrono>
#include <thread>
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

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}