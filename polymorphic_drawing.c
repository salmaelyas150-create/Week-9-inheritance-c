
#include <stdio.h>

// BASE STRUCT
struct Shape {
    void (*draw)();
};

// DERIVED STRUCTS
struct Circle {
    struct Shape base;
};

struct Rectangle {
    struct Shape base;
};

struct Triangle {
    struct Shape base;
};

// Specific drawing functions
void drawCircle() {
    printf("Drawing a Circle ◯\n");
}

void drawRectangle() {
    printf("Drawing a Rectangle ▭\n");
}

void drawTriangle() {
    printf("Drawing a Triangle △\n");
}

// Polymorphic function
void renderCanvas(struct Shape* shapePtr) {
    shapePtr->draw();
}

int main() {

    // Create derived objects
    struct Circle c1;
    c1.base.draw = drawCircle;

    struct Rectangle r1;
    r1.base.draw = drawRectangle;

    struct Triangle t1;
    t1.base.draw = drawTriangle;

    struct Circle c2;
    c2.base.draw = drawCircle;

    // Array of base structure pointers
    struct Shape* canvas[4];

    canvas[0] = (struct Shape*)&c1;
    canvas[1] = (struct Shape*)&r1;
    canvas[2] = (struct Shape*)&t1;
    canvas[3] = (struct Shape*)&c2;

    printf("--- Rendering Canvas ---\n");

    // Draw all shapes
    for (int i = 0; i < 4; i++) {
        renderCanvas(canvas[i]);
    }

    return 0;
}
