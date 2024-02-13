#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Rational {
public:
    Rational () {
        numerator_value = 0;
        denominator_value = 1;
    }
    Rational (int numerator, int denominator) {
        numerator_value = numerator;
        denominator_value = denominator;
        if (numerator_value == 0) {
            denominator_value = 1;
        } else {
            Reduce();
            if (((numerator_value < 0) && (denominator_value < 0)) ||
                ((denominator_value < 0) && (numerator_value > 0))) {
                numerator_value *= -1;
                denominator_value *= -1;
            }
        }
    }

    int Numerator () const {
        return numerator_value;
    }
    int Denominator () const {
        return denominator_value;
    }

    void SetNumerator (const int& new_numerator) {
        numerator_value = new_numerator;
        Reduce();
    }
    void SetDenominator (const int& new_denominator) {
        denominator_value = new_denominator;
        Reduce();
    }

    void Reduce () {
        for (int i = 2; i <= (min(abs(numerator_value), abs(denominator_value))); ++ i) {
            if (((numerator_value % i) == 0) && ((denominator_value % i) == 0)) {
                numerator_value /= i;
                denominator_value /= i;
                -- i;
            }
        }
    }

private:
    int numerator_value, denominator_value;
};

bool operator==  (const Rational& left_arg, const Rational& right_arg) {
    if ((left_arg.Numerator() == right_arg.Numerator()) &&
        (left_arg.Denominator() == right_arg.Denominator())) {
        return true;
    }
    return false;
}

bool operator>  (const Rational& left_arg, const Rational& right_arg) {
    if ((left_arg.Numerator() * right_arg.Denominator()) >
        (left_arg.Denominator() * right_arg.Numerator())) {
        return true;
    }
    return false;
}

bool operator<  (const Rational& left_arg, const Rational& right_arg) {
    if ((left_arg.Numerator() * right_arg.Denominator()) <
        (left_arg.Denominator() * right_arg.Numerator())) {
        return true;
    }
    return false;
}

Rational operator+ (const Rational& left_arg, const Rational& right_arg) {
    int new_numerator = left_arg.Numerator() * right_arg.Denominator() +
                        right_arg.Numerator() * left_arg.Denominator();
    int new_denominator = left_arg.Denominator() * right_arg.Denominator();
    Rational result(new_numerator, new_denominator);
    return result;
}

Rational operator- (const Rational& left_arg, const Rational& right_arg) {
    int new_numerator = left_arg.Numerator() * right_arg.Denominator() -
                        right_arg.Numerator() * left_arg.Denominator();
    int new_denominator = left_arg.Denominator() * right_arg.Denominator();
    Rational result(new_numerator, new_denominator);
    return result;
}

Rational operator* (const Rational& left_arg, const Rational& right_arg) {
    int new_numerator = left_arg.Numerator() * right_arg.Numerator();
    int new_denominator = left_arg.Denominator() * right_arg.Denominator();
    Rational result(new_numerator, new_denominator);
    return result;
}

Rational operator/ (const Rational& left_arg, const Rational& right_arg) {
    int new_numerator = left_arg.Numerator() * right_arg.Denominator();
    int new_denominator = left_arg.Denominator() * right_arg.Numerator();
    Rational result(new_numerator, new_denominator);
    return result;
}

ostream& operator<< (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator>> (istream& stream, Rational& rational) {
    string inp;
    if ((stream.fail()) || (stream.bad())) {
        return stream;
    }
    if (!getline(stream, inp)) {
        return stream;
    }
    stream >> inp;
    if (inp == "") {
        return stream;
    }
    string new_str = "";
    for (const char& c : inp) {
        if(c != ' ') {
            new_str += c;
        }
    }
    inp = new_str;
    int sl_count = 0;
    for (const auto& sym : inp) {
        if (!(((sym >= '0') && (sym <= '9')) || (sym == '/'))) {
            return stream;
        }
        if (sym == '/') {
            ++ sl_count;
        }
    }
    if (sl_count != 1) {
        return stream;
    }
    istringstream ready_to_parce(inp);
    int num, den;
    ready_to_parce >> num;
    ready_to_parce.ignore(1);
    ready_to_parce >> den;
    if (den == 0) {
        return stream;
    }
    if (num == 0) {
        den = 1;
    }
    rational.SetNumerator(num);
    rational.SetDenominator(den);
    return stream;
}

int main()
{
    {
        istringstream input("5/a");
        Rational r;
        input >> r;
        cout<<r;
    }

    cout << "OK" << endl;
    return 0;
}
