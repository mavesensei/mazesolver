#include "mazefinder.h"
using namespace std;
const int PATH = 0;
const int WALL = 1;
const int VISITED = 2;
const int FINAL = 3;

mazegenerator::mazegenerator(int w, int h) : width(w), height(h){
    maze = new int[width * height];
    for(int i = 0; i < width * height; i++)
        maze[i] = WALL;
    srand(time(0));
    generatemaze(1, 1);
    entranceX = 0;
    entranceY = rand() % height;
    exitX = width - 1;
    exitY = rand() % height;

    maze[entranceY * width + entranceX] = PATH;
    maze[exitY * width + exitX] = PATH;
}

mazegenerator::~mazegenerator(){
    delete[] maze;
}

void mazegenerator::generatemaze(int x, int y){
    maze[y * width + x] = PATH;
    int directions[4][2] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};
    for(int i = 0; i < 4; i++){
        int r = rand() % 4;
        int temp[2] = { directions[i][0], directions[i][1] };
        directions[i][0] = directions[r][0];
        directions[i][1] = directions[r][1];
        directions[r][0] = temp[0];
        directions[r][1] = temp[1];
    }

    for(int i = 0; i < 4; i++){
        int dx = x + directions[i][0];
        int dy = y + directions[i][1];
        if(dx >= 0 && dy >= 0 && dx < width && dy < height && maze[dy * width + dx] == WALL){
            maze[(dy + y) / 2 * width + (dx + x) / 2] = PATH;
            generatemaze(dx, dy);
        }
    }
}

void mazegenerator::printmaze(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(maze[i * width + j] == WALL)
                cout << "# ";
            else if(maze[i * width + j] == FINAL)
                cout << ". ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}

bool mazegenerator::findpath(int x, int y){
    if(x == exitX && y == exitY){
        maze[y * width + x] = FINAL;
        return true;
    }
    if(x < 0 || x >= width || y < 0 || y >= height || maze[y * width + x] != PATH)
        return false;
    maze[y * width + x] = VISITED;
    if(findpath(x + 1, y) || findpath(x - 1, y) ||
       findpath(x, y + 1) || findpath(x, y - 1)){
        maze[y * width + x] = FINAL;
        return true;
    }
    return false;
}