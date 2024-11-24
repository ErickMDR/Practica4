#include <iostream>
#include <cmath>
using namespace std;

struct Punto2D {
    double x;
    double y;

    Punto2D() : x(0), y(0) {}

    Punto2D(double x, double y) {
        this->x=x;
        this->y=y;
    }
};

double ProductoCruz(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}

double ProductoEscalar(double x1, double y1, double x2, double y2) {
    return x1 * x2 + y1 * y2;
}

int Lineas(double v1x, double v1y, double v2x, double v2y) {
    double Cruz = ProductoCruz(v1x, v1y, v2x, v2y);
    if (Cruz == 0) {
        return 0;
    }
    return 1;
}

int Lineas(double v1x, double v1y, double v2x, double v2y, int x) {

    if (x == 1) {
        cout << "Se inicializo la funcion sobrecargada." << endl;
    } 
    double Escalar = ProductoEscalar(v1x, v1y, v2x, v2y);
    if (Escalar == 0) {
        return 1;
    }
    
    double Cruz = ProductoCruz(v1x, v1y, v2x, v2y);
    if (Cruz == 0) {
        return 0;
    }
    
    return -1;
}

int main() {
    Punto2D P[4];

    for (int i=0; i<4; i++) {
        cout << "Introduce las coordenadas: " << endl; 
        cout << "(x" << i+1<< ", y" << i+1 << "): "; cin >> P[i].x >> P[i].y;
    }

    double v1x = P[1].x - P[0].x, v1y = P[1].y - P[0].y;
    double v2x = P[3].x - P[2].x, v2y = P[3].y - P[2].y; 

    cout << "RESULTADOS:" << endl;
    int resultado = Lineas(v1x, v1y, v2x, v2y);
    if (resultado == 1) {
        cout << "Las lineas se cruzan." << endl;
    } else if (resultado == 0) {
        cout << "Las lineas son paralelas." << endl;
    } else {
        cout << "Las lineas no se cruzan ni son paralelas." << endl;
    }

    int x = 1;
    int resultado2 = Lineas(v1x, v1y, v2x, v2y, x);
    if (resultado2 == 1) {
        cout << "Las lineas son perpendiculares." << endl;
    } else if (resultado2 == 0) {
        cout << "Las lineas son paralelas." << endl;
    } else {
        cout << "Las lineas se cruzan." << endl;
    }
    
    return 0;
}
