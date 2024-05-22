#pragma once

#include <algorithm>
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
    std::vector <FunctionPart> parts;
};
