#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    string value;

    explicit Specialization (string new_value) {
        value = new_value;
    }
};

struct Course {
    string value;

    explicit Course (string new_value) {
        value = new_value;
    }
};

struct Week {
    string value;

    explicit Week (string new_value) {
        value = new_value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle (Specialization new_spec,
                  Course new_cource,
                  Week new_week) {

        specialization = new_spec.value;
        course = new_cource.value;
        week = new_week.value;
    }
};

int main()
{
    return 0;
}
