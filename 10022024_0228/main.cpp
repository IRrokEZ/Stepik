#include <iostream>
#include <vector>
#include <algorithm>
//#include <Function.hpp>

using namespace std;

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
    /*
    void Prt () const{
        cout << operation_symbol << " " << value << endl;
    }
    */
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
        //int counter = 0;
        for (FunctionPart& part : parts) {
            part.Invert();

            /*
            cout << "F_inv " << ++ counter << endl;
            part.Prt();
            cout << endl;
            */
        }
        reverse(begin(parts), end(parts));
    }
    /*
    void Print () {
        for (const auto& p : parts) {
            p.Prt();
        }
    }
    */
private:
    vector <FunctionPart> parts;
};

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  /*
  Function func;
  cout << endl << endl << "make *****************************************" << endl;
  func.Print();
  system("pause");
  func.AddPart('-', image.freshness * params.a + params.b);
  func.Print();
  system("pause");
  func.AddPart('+', image.rating * params.c);
  func.Print();
  system("pause");
  cout << "make *****************************************" << endl << endl << endl;
  */
  Function func;
  func.AddPart('*', params.a);
  func.AddPart('-', image.freshness * params.b);
  func.AddPart('+', image.rating * params.c);
  return func;

  return func;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function func = MakeWeightFunction(params, image);
  return func.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  /*
  Function func = MakeWeightFunction(params, image);
  cout << endl << endl << "COMP *****************************************" << endl;
  func.Print();
  system("pause");
  func.Invert();
  func.Print();
  system("pause");
  cout << "COMP *****************************************" << endl << endl << endl;
  */
  Function func = MakeWeightFunction(params, image);
  func.Invert();

  return func.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
