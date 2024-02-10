#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <vector>

class FunctionPart {
public:
    FunctionPart (char new_operation_symbol, double new_value);

    double Apply (double source_value) const;
    void Invert ();
private:
    char operation_symbol;
    double value;
};

class Function {
public:
    void AddPart (char operation, double value);
    double Apply (double inp_value) const;
    void Invert ();
private:
    vector <FunctionPart> parts;
};

#endif // FUNCTION_H_INCLUDED
