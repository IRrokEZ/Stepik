#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "0123456789";
    for (const auto& el : a) {
        cout << el << " " << int(el) << endl;
    }
    return 0;
}
