#include "Pikachu.h"

// we call the parent's constructor in the initializer list
// Order in which constructors are called:
// Parent -> Child
Pikachu::Pikachu(const char* sound, const char* name): Pokemon(sound){
    
    int size = strlen(name);
    this->name = new char [size+1];
    strncpy(this->name, name, size);

}


// Order in which destructors are called:
// Child -> Parent
Pikachu::~Pikachu(){
    if (this->name != NULL){
        delete [] this->name;
    }
}

void Pikachu::who() const {
    cout << "POKEMON NAME: " << this->name << endl;
    cout << "POKEMON STATS:" << endl;

   
    /* even though we inherit all member functions and variables
       we cannot access the private member variables of our parent
    cout << "HP: " << this->hp << endl;
    cout << "ATK: " << this->atk << endl;
    cout << "SPD: " << this->spd << endl;
        // if we set these variables as "protected" instead of
        // private then we would have 
    */

   int h, a, s;
   // As such we must use the "getters" and "setters" to access
   // the parent's member variables  
   this->get_stats(h, a, s);
   cout << "HP: " << h << endl;
   cout << "ATK: " << a << endl;
   cout << "SPD: " << s << endl;

}