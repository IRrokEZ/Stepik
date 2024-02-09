#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Incognizable {
public:
    Incognizable () {};
    Incognizable (initializer_list <int> val) {
        for (const auto& v: val) {
            values.push_back(v);
        }
    }
private:
    vector <int> values;
};

int main()
{
    Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
