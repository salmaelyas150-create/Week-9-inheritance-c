
#include <stdio.h>
#include <string.h>

// Base structure (Parent)
struct Shape {
    char color[20];
};

// Derived structure (Child)
struct Circle {
    struct Shape base;
    double radius;
};

int main() {
    // Create a Circle
    struct Circle myCircle;

    // Initialize inherited data
    strcpy(myCircle.base.color, "Red");

    // Initialize Circle-specific data
    myCircle.radius = 5.0;

    // Display information
    printf("Circle Color (Inherited): %s\n",
           myCircle.base.color);

    printf("Circle Radius (Specific): %.2f\n",
           myCircle.radius);

    return 0;
}
