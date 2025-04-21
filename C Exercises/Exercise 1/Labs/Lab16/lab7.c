#include <stdio.h>
#include <math.h> 

#define PI 3.14

typedef struct {
    float width;
    float height;
} Rectangle;

typedef struct {
    float radius;
} Circle;

typedef struct {
    float side1;
    float side2;
    float side3;
} Triangle;

void calculate_area(Rectangle rectangle, Circle circle, Triangle triangle, double areas[3]) {

    areas[0] = rectangle.width * rectangle.height;

    areas[1] = PI * pow(circle.radius,2);

    float s = (triangle.side1 + triangle.side2 + triangle.side3) / 2;
    
    areas[2] = sqrt(s * (s - triangle.side1) * (s - triangle.side2) * (s - triangle.side3));
}

int main() {
    Rectangle rectangle = {10.0, 6.0}; 
    Circle circle = {4.0};             
    Triangle triangle = {6.0, 8.0, 10.0}; 

    double areas[3];
    calculate_area(rectangle, circle, triangle, areas);

    printf("Area of rectangle: %.2lf\n", areas[0]);
    printf("Area of circle: %.2lf\n", areas[1]);
    printf("Area of triangle: %.2lf\n", areas[2]);

    return 0;
}

