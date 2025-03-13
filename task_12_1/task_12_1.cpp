# define M_PIl          3.141592653589793238462643383279502884L
#include <iostream>

void circle(const double& radius, double& circumference, double& area) {

    circumference = 2 * radius * M_PIl;
    area = M_PIl * (radius * radius);

}

int main() {

    double radius = 0.5;
    double area = 3.0;
    double circumference;

    circle(radius, circumference, area);
    std::cout <<
    "Circum: " << circumference << std::endl;

}
