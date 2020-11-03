#include "Pokemon.h"

using namespace std;

Pokemon::Pokemon(const char* sound_param){

    int size = strlen(sound_param) + 1;
    this->sound = new char [size];
    strncpy(this->sound, sound_param, size-1);    
    
    this->atk = 0;
    this->hp = 0;
    this->spd = 0;

}

Pokemon::~Pokemon(){
    if (this->sound != NULL){
        delete [] this->sound;
    }
}

void Pokemon::set_stats(const int& hp, const int& atk, const int& spd){
    this->hp = hp;
    this->atk = atk;
    this->spd = spd;
}

void Pokemon::get_stats(int& hp, int& atk, int& spd) const{
    hp = this->hp;
    atk = this->atk;
    spd = this->spd;
}


const char* Pokemon::say() const {
    return this->sound;
}

Pokemon::Pokemon(const Pokemon& pk){
    if (this->sound != NULL){
        delete [] this->sound;
        this->sound = NULL;
    }
    this->hp = pk.hp;
    this->atk = pk.atk;
    this->spd = pk.spd;

    if (pk.sound != NULL){
        int size = strlen(pk.sound);
        this->sound = new char [size+1];
        strncpy(this->sound, sound, size);
    }

}


int operator+(const Pokemon& a, const Pokemon& b){
    return a.atk + b.atk;
}