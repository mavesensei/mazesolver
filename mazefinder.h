#include <iostream>
class mazegenerator{
    public:
        mazegenerator(int w, int h);
        ~mazegenerator();
        void generatemaze(int x, int y);
        void printmaze();
        bool findpath(int x, int y);
        void printpath();
        int entranceX, entranceY;
    private:
        int width, height;
        int *maze;
        int exitX, exitY;
};