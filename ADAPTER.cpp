#include <iostream>
#include <cmath>
using namespace std;

class RoundHole {
private:
    float radius;

public:
    RoundHole(float radius) : radius(radius) {}

    float getRadius() const {
        return radius;
    }

    bool fits(const class RoundPeg* peg);
};

class RoundPeg {
private:
    float radius;

public:
    RoundPeg() : radius(0) {} // Constructor por defecto

    RoundPeg(float radius) : radius(radius) {}

    float getRadius() const {
        return radius;
    }
};

bool RoundHole::fits(const RoundPeg* peg) {
    return (getRadius() >= peg->getRadius());
}

class Triangulo {
private:
    int base;
    int altura;

public:
    Triangulo(int _base, int _altura) : base(_base), altura(_altura){}
    float getBase()  {
        return base;
    }

    float getAltura() {
        return altura;
    }
};

class AdaptadorTriangulo : public RoundPeg {
private:
    Triangulo* peg;

public:
    AdaptadorTriangulo(Triangulo* _peg) : peg(_peg) {}

    float getRadius() {
        float radius = (peg->getBase() * sqrt(3)) / 6;
        return radius;
    }
};

int main() {
    RoundHole hole(6);
    RoundPeg rpeg(5);
    cout << hole.fits(&rpeg) << endl;

    Triangulo tpeg(6, 3);
    AdaptadorTriangulo tpegAdapter(&tpeg);

    cout << hole.fits(&tpegAdapter) << endl;

    return 0;
}
