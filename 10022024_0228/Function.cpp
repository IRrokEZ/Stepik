
class FunctionPart {
public:
    FunctionPart (char new_operation_symbol, double new_value) {
        operation_symbol = new_operation_symbol;
        value = new_value;
    }

    double Apply (double source_value) const {
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
    void Invert () {
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
private:
    char operation_symbol;
    double value;
};

class Function {
public:
    void AddPart (char operation, double value) {
        parts.push_back({operation, value});
    }
    double Apply (double inp_value) const {
        double value = inp_value;
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert () {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector <FunctionPart> parts;
};

