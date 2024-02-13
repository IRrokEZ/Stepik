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
        if (denominator == 0) {
            throw invalid_argument("Division by zero");
        }
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
    if (right_arg.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
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
    if (!stream) {
        return stream;
    }
    string inp;
    stream >> inp;
    if (inp == "") {
        return stream;
    }
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

Rational Calculator (string& stream) {
    string inp = "", incorr_inp = stream;
    if (incorr_inp == "") {
        throw invalid_argument("Invalid argument");
    }
    for (const char& s : incorr_inp) {
        if (s != ' ') {
            inp += s;
        }
    }
    int sl_count = 0, oper_count = 0, sym_count = 0;
    for (const char& sym : inp) {
        if ((sym == '+') ||
            (sym == '-') ||
            (sym == '*')) {
            ++ oper_count;
        }
        if (sym == '/') {
            ++ sl_count;
        }
        if ((sym >= '0') && (sym <= '9')) {
            ++ sym_count;
        }
    }
    if ((sl_count < 2) ||
        (sl_count > 3) ||
        ((sl_count == 2) && (oper_count < 1)) ||
        (oper_count > 1)) {
        throw invalid_argument("Invalid argument");
    }
    if (size_t(sl_count + oper_count + sym_count) != inp.size()) {
        throw invalid_argument("Invalid argument");
    }
    istringstream ready_to_parce(inp);
    int l_num, l_den, r_num, r_den;
    char oper;
    ready_to_parce >> l_num;
    ready_to_parce.ignore(1);
    ready_to_parce >> l_den;
    ready_to_parce >> oper;
    ready_to_parce >> r_num;
    ready_to_parce.ignore(1);
    ready_to_parce >> r_den;
    if ((l_den == 0) || (r_den == 0)) {
        throw invalid_argument("Invalid argument");
    }
    if (oper == '/') {
        if (r_num == 0) {
            throw domain_error("Division by zero");
        }
    }
    if (oper == '+') {
        Rational left_arg(l_num, l_den);
        Rational right_arg(r_num, r_den);
        return left_arg + right_arg;
    }
    if (oper == '-') {
        Rational left_arg(l_num, l_den);
        Rational right_arg(r_num, r_den);
        return left_arg - right_arg;
    }
    if (oper == '*') {
        Rational left_arg(l_num, l_den);
        Rational right_arg(r_num, r_den);
        return left_arg * right_arg;
    }
    if (oper == '/') {
        Rational left_arg(l_num, l_den);
        Rational right_arg(r_num, r_den);
        return left_arg / right_arg;
    }
    return Rational(0, 1);
}

int main()
{
    string st = "4/5 / 0/8";
    cout << Calculator(st) << endl;
    return 0;
}
