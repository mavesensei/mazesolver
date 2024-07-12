#include "mazefinder.cpp"
using namespace std;
int main(){
    int width = 25;
    int height = 25;

    mazegenerator maze(width, height);
    maze.printmaze();
    cout << "\nFinding path...\n\n";
    if(!maze.findpath(maze.entranceX, maze.entranceY))
        cout << "No path found!\n";
    else
        maze.printmaze();
        
    return 0;
}