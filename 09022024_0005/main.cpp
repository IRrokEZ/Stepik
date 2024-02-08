#include <iostream>
#include <string>

using namespace std;

class ReversibleString {
public:
    ReversibleString () {};
    ReversibleString (const string& inp_string) {
        value = inp_string;
    }
    void Reverse () {
        if (value.size() > 0) {
            string rev = "";
            for (size_t i = value.size(); i > 0; -- i) {
                rev += value[i - 1];
            }
            value = rev;
        }
    }
    string ToString () const {
        return value;
    }
private:
    string value;
};

int main()
{
    ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
