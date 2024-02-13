#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ifstream my_file("input.txt");
    if (my_file) {
        string line;
        while (getline(my_file, line)) {
            cout << line << endl;
        }
    }
    return 0;
}
