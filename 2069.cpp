#include <bits/stdc++.h>
using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

class Robot {
public:
    int x = 0;
    int y = 0;
    int direction = EAST;

    int width;
    int height;
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
    }
    
    void step(int num) {
        int zero = num;
        num = num % ((width + height - 2) * 2);
        if (zero != 0) num += ((width + height - 2) * 2);
        for (int i = 0; i < num; i++) {
            if (direction == EAST and x + 1 >= width) direction = NORTH;
            else if (direction == NORTH and y + 1 >= height) direction = WEST;
            else if (direction == WEST and x <= 0) direction = SOUTH;
            else if (direction == SOUTH and y <= 0) direction = EAST;

            if (direction == EAST) x++;
            else if (direction == NORTH) y++;
            else if (direction == WEST) x--;
            else if (direction == SOUTH) y--;
        }
    }
    
    vector<int> getPos() {
        vector<int> res;
        res.push_back(x);
        res.push_back(y);
        return res;
    }
    
    string getDir() {
        if (direction == EAST) return "East";
        if (direction == WEST) return "West";
        if (direction == SOUTH) return "South";
        if (direction == NORTH) return "North";
        return "North";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */