#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main () {
    ifstream my_file("input.txt");
    if (my_file) {
        while (!my_file.eof()) {
            double value;
            my_file >> value;
            cout << fixed << setprecision(3) << value << endl;
        }
    }
    return 0;
}
