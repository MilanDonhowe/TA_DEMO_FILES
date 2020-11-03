#include <iostream>

using namespace std;


int twice(int x) {return x*2;}
float twice(float x){return x*2;}

class Example {

    private:

        int number;

    public:

    friend bool operator==(Example&, Example&);

    bool operator==(int x){
        return true;        
    }

    Example(int number){
        this->number = number;
    }

};


bool operator==(Example& a, Example& b){
   return a.number == b.number;
}

int main(int argc, char **argv){

    Example box1(22);

    Example box2(22);

    cout << (box1 == box2) << endl;

    return 0;
}