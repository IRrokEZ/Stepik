#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    string name, surename;
    int birth_day, birth_month, birth_year;
};

int main () {
    size_t N, M;
    cin >> N;
    vector <Student> students(N);
    string nam, suren, request;
    int day, month, year, request_value;
    for (size_t i = 0; i < N; ++ i) {
        cin >> nam >> suren >> day >> month >> year;
        students[i].name = nam;
        students[i].surename = suren;
        students[i].birth_day = day;
        students[i].birth_month = month;
        students[i].birth_year = year;
    }
    cin >> M;
    for (size_t i = 0; i < M; ++ i) {
        cin >> request >> request_value;
        if (request == "name") {
            if (request_value <= 0) {
                cout << "bad request" << endl;
            } else if ((request_value - 1) < int(N)) {
                cout << students[request_value - 1].name << " "
                     << students[request_value - 1].surename << endl;
            } else {
                cout << "bad request" << endl;
            }
        } else if (request == "date") {
            if (request_value <= 0) {
                cout << "bad request" << endl;
            } else if ((request_value - 1) < int(N)) {
                cout << students[request_value - 1].birth_day << "."
                     << students[request_value - 1].birth_month << "."
                     << students[request_value - 1].birth_year << endl;
            } else {
                cout << "bad request" << endl;
            }
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}
