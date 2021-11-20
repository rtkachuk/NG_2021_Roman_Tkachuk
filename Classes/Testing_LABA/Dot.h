#ifndef DOT_H
#define DOT_H

class Dot {
public:
    Dot () {
        configureVariables(0,0);
    }

    Dot (int x, int y) {
        configureVariables(x, y);
    }

    int getX() { return x; }
    void setX(int x) { this->x = x; }
    int getY() { return y; }
    void setY(int y) { this->y = y; }

private:
    void configureVariables(int x, int y) {
        setX(x);
        setY(y);
    }

    int x;
    int y;
};

#endif // DOT_H
