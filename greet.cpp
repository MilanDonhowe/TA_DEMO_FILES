#include "greet.h"

using namespace std;

int main(int argc, char **argv){
    valid_args(argc);


    // for more information on ifstreams read the docs: https://www.cplusplus.com/reference/fstream/ifstream/
    
    /*
        ifstream -> input files (reading)
        ofstream -> output files (writing)
        fstream -> both depending on the flags 
    */

    fstream File_Stream;

    // file_stream_id.open("filename", flags)
    File_Stream.open(argv[1], ios::in); 
    // ios::in -> reading from a file
    // ios:out -> writing to a file
    
    // there are a few ways to check if a stream has opened correctly
    // e.g. ".is_open"
    if (File_Stream.fail()){
        cout << "Error: could not open file: \"" << argv[1] << "\"" << endl;
        exit(3);
    }

    // read in the number at the beginning of the file
    int number_of_names = 0;

    // cin & cout  
    // << insertion
    // >> extraction

    // this is analogous to reading in user input from cin
    File_Stream >> number_of_names; 

    // Make sure to explain why we pass ifstream by reference instead of by value
    string* name_arr = read_names(File_Stream, number_of_names); 
    
    // Make sure to close your file streams!
    File_Stream.close();


    // now let's sort our names
    sort_names(name_arr, number_of_names);
    
    // and now let's write them out to a new file
    write_greeting("names_sorted", name_arr, number_of_names);

    // Also remember to free any allocated memory!
    delete[] name_arr;

    return 0;
}

// read x names from file into array of strings


string *read_names(fstream &file, const int x)
{
    string *arr = new string[x];
    for (int i = 0; i < x; i++)
    {
        file >> arr[i];
    }
    return arr;
};

// sort names alphabetically using bubble-sort
// bubble-sort is a very slow sorting algorithm
// which if ever used, is generally for prototyping
void sort_names(string *&names, const int size)
{
    bool sorted = false;


    // [423, 89123, -342, 454]
    // Ascending  a, b, c
    // a < b < c
    // Descending
    // a > b > c

    // 1. WHILE AN ARRAY IS NOT SORTED
    // 2. for each pair of items in an array (a, b) 
    // 3. if (a > b) swap the values a and b.
    // REPEATING STEPS 2 AND 3 UNTIL THE ARRAY IS SORTED     


    while (!sorted)
    {
        sorted = true;

        for (int i = 0; i < size - 1; i++)
        {
            if (names[i][0] > names[i + 1][0])
            {
                // swap name[i] with name[i+1]
                string temp = names[i];
                names[i] = names[i + 1];
                names[i + 1] = temp;
                // since we swapped values we know the array is not sorted
                sorted = false;
            }
        }
    }
    return;
};



// write out greeting messages in new file
void write_greeting(const string& filename, string* names, const int size){
    fstream output;
    output.open(filename.c_str(), ios::out);
    if(output.fail()){
        cout << "Error: could not write file" << endl;
        exit(4);
    }
    for (int i=0; i < size; i++){
        output << names[i] << '\n';
    }
    output.close();
    return;
};


void valid_args(int count)
{
    if (count < 2)
    {
        cout << "Error: insufficient arguments." << endl;
        exit(2);
    }
    return;
};