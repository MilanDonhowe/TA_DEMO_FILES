#ifndef POKEMON_H
#define POKEMON_H

#include <cstdlib>
#include <cstring>

using namespace std;

class Pokemon {
    private:
        int hp;
        int atk;
        int spd;
        char* sound;
    
    public:
        Pokemon(const char*);
        Pokemon& operator=(const Pokemon&);
        Pokemon(const Pokemon&);
        ~Pokemon();
        void set_stats(const int&, const int&, const int&);
        void get_stats(int&, int&, int&) const;
        const char* say() const;

        /*OPERATOR OVERLOADING*/
        /*We can define unique behavior for operators when given different typed-operands*/
        /*Much like we can overload functions
        
        int twice(int x) {return x*2;};
        double twice(double x){return x*2;};
        */
       /* General operator overload syntax:
            <return type> operator<symbol>(operands);
       */
        bool operator==(const Pokemon& a){
            if (this->atk == a.atk) return true;
            return false;
        };

        friend int operator+(const Pokemon& a, const Pokemon& b);
        // the only operators that cannot be overloaded are:
        // the . operator, ()?: ternary if, :: scope resolution, ".*" pointer to member
        // "sizeof", "typeid" also cannot be overloaded
};





#endif