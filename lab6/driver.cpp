#include "Pikachu.h"

using namespace std;

void read_pokemon(const Pokemon& pk){
    cout << "Pokemon says " << pk.say() << endl;
}

int twice(int x){return x*2;}
double twice(double x){return x*2;}

int main(){

    /*========================================
    *           Inheritance Example
    *========================================*/
    // We have a regular pokemon object here:
    Pokemon my_pokemon("RAWR");
    cout << "My pokemon says " << my_pokemon.say() << endl;
    my_pokemon.set_stats(1, 1, 1);

    // Now we have a "pikachu" object which inherits from pokemon
    Pikachu pika("PIKA-P", "FluffBall");
    

    // pika can access (or "inherits") all the methods of "Pokemon"
    cout << "Pika says " << pika.say() << endl;
    pika.set_stats(20, 44, 25);

    // in addition we also may have child-specific methods
    pika.who();

    Pokemon test_pokemon("test");

    // Example of down-casting
    read_pokemon(pika);

    // example of operator overloading
    cout << pika + my_pokemon << endl;

    return 0;
}