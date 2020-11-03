#ifndef PIKACHU_H
#define PIKACHU_H

#include "Pokemon.h"
#include <iostream>

using namespace std;


// Pikachu inherits from the class Pokemon
// Inheritance demonstrates a "is-a" relationship
// which contrasts with the "has-a" relationship you saw
// with class composition (the class Deck had the class Card)
class Pikachu :  public Pokemon {
    private:
        char* name;
    public:
        // the big three and constructors are not inherited so we need
        // to rewrite them and also account for any additional dynamically
        // allocated variables
        Pikachu(const char*, const char*);
        Pikachu& operator=(const Pikachu&);

        Pikachu(const Pikachu&);
        ~Pikachu();
        void who() const;
};



#endif 