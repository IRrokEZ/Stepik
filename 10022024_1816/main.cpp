#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ifstream my_file("input.txt");
    ofstream my_out_file("output.txt");
    if (my_file) {
        string line;
        while (getline(my_file, line)) {
            //cout << line << endl;
            my_out_file << line << endl;
        }
    }
    return 0;
}
