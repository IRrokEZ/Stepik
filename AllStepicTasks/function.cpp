#include "function.hpp"

FunctionPart::FunctionPart (char new_operation_symbol, double new_value) {
    operation_symbol = new_operation_symbol;
    value = new_value;
}

double FunctionPart::Apply (double source_value) const {
    if (operation_symbol == '+') {
        return source_value + value;
    }
    if (operation_symbol == '-') {
        return source_value - value;
    }
    if (operation_symbol == '/') {
        return source_value / value;
    }
    if (operation_symbol == '*') {
        return source_value * value;
    }
    return -50;
}

void FunctionPart::Invert () {
    if (operation_symbol == '+') {
        operation_symbol = '-';
    } else if (operation_symbol == '-') {
        operation_symbol = '+';
    } else if (operation_symbol == '/') {
        operation_symbol = '*';
    } else if (operation_symbol == '*') {
        operation_symbol = '/';
    }
}

void Function::AddPart (char operation, double value) {
    parts.push_back({operation, value});
}

double Function::Apply (double inp_value) const {
    double value = inp_value;
    for (const FunctionPart& part : parts) {
        value = part.Apply(value);
    }
    return value;
}

void Function::Invert () {
    for (FunctionPart& part : parts) {
        part.Invert();
    }
    std::reverse(parts.begin(), parts.end());
}

