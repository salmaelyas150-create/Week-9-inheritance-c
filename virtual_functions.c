
#include <stdio.h>
#include <string.h>

// Function pointer type
typedef void (*SpeakFunction)();

// BASE STRUCT
struct Animal {
    SpeakFunction speak;
};

// DERIVED STRUCT
struct Dog {
    struct Animal base;
};

// Actual functions
void genericSound() {
    printf("Animal makes a generic sound.\n");
}

void dogBark() {
    printf("Dog barks: Woof! Woof!\n");
}

int main() {

    printf("--- Simulating Non-Virtual (Base only) ---\n");

    struct Animal myAnimal;
    myAnimal.speak = genericSound;

    myAnimal.speak();

    printf("\n--- Simulating Virtual (Dynamic binding) ---\n");

    struct Dog myDog;

    // Override the inherited function pointer
    myDog.base.speak = dogBark;

    // Cast Dog pointer to Animal pointer
    struct Animal* pet = (struct Animal*)&myDog;

    // Call the function through the pointer
    pet->speak();

    return 0;
}
