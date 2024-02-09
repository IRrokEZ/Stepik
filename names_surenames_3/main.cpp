#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Person {
public:
    Person (const string& name, const string& surename, const int& birth_year) {
        burn_year = birth_year;
        ChangeFirstName(burn_year, name);
        ChangeLastName(burn_year, surename);
    }

    void ChangeFirstName (const int& inp_year, const string& inp_first_name) {
        if (save_first_name != inp_first_name) {
            first_name[inp_year] = inp_first_name;
            save_first_name = inp_first_name;
        }
    }

    void ChangeLastName (const int& inp_year, const string& inp_last_name) {
        if (save_last_name != inp_last_name) {
            last_name[inp_year] = inp_last_name;
            save_last_name = inp_last_name;
        }
    }

    string GetFullName (const int& inp_year) const{
        string result;
        if (inp_year < burn_year) {
            result = "No person";
            return result;
        }

        string f_name = GetNameByYear(inp_year, first_name);
        string l_name = GetNameByYear(inp_year, last_name);
        if ((l_name == "") && (f_name == "")) {
            result = "Incognito";
            return result;
        }
        if (l_name == "") {
            result = f_name + " with unknown last name";
            return result;
        }
        if (f_name == "") {
            result = l_name + " with unknown first name";
            return result;
        }
        result = f_name + " " + l_name;
        return result;
    }

    string GetFullNameWithHistory (const int& inp_year) const{
        string result;
        if (inp_year < burn_year) {
            result = "No person";
            return result;
        }

        string f_name = GetNameByYear(inp_year, first_name);
        string f_name_history = GetNameHistoryByYear(inp_year, first_name);
        string l_name = GetNameByYear(inp_year, last_name);
        string l_name_history = GetNameHistoryByYear(inp_year, last_name);

        if ((l_name == "") && (f_name == "")) {
            result = "Incognito";
            return result;
        }

        if (l_name == "") {
            if (f_name != f_name_history) {
                if (f_name_history != "") {
                    f_name_history = " (" + f_name_history + ")";
                }
            } else {
                f_name_history = "";
            }
            result = f_name + f_name_history + " with unknown last name";
            return result;
        }

        if (f_name == "") {
            if (l_name != l_name_history) {
                if (l_name_history != "") {
                    l_name_history = " (" + l_name_history + ")";
                }
            } else {
                l_name_history = "";
            }
            result = l_name + l_name_history + " with unknown first name";
            return result;
        }

        if (f_name != f_name_history) {
            if (f_name_history != "") {
                f_name_history = " (" + f_name_history + ")";
            }
        } else {
            f_name_history = "";
        }

        if (l_name != l_name_history) {
            if (l_name_history != "") {
                l_name_history = " (" + l_name_history + ")";
            }
        } else {
            l_name_history = "";
        }

        result = f_name + f_name_history + " " + l_name + l_name_history;
        return result;
    }
private:
    map <int, string> first_name, last_name;
    int burn_year;
    string save_first_name, save_last_name;

    string GetNameByYear (const int& inp_year, const map <int, string>& name_list) const{
        string name = "";
        for (const auto &pair : name_list) {
            if (pair.first <= inp_year) {
                name = pair.second;
            } else {
                break;
            }
        }
        return name;
    }

    string GetNameHistoryByYear (const int& inp_year, const map <int, string>& name_list) const{
        map <int, string> my_name = name_list;
        vector <int> years(my_name.size()), delete_years;
        size_t counter = 0;
        string name = "";

        for (const auto pair : name_list) {
            my_name[pair.first] = pair.second;
        }

        for (auto &pair : my_name) {
            years[counter] = pair.first;
            ++ counter;
        }

        if (counter > 1) {
            for (counter = 0; counter < years.size(); ++ counter) {
                if (my_name[years[counter]] == my_name[years[counter + 1]]) {
                    delete_years.push_back(years[counter + 1]);
                }
            }
            if (not delete_years.empty()) {
                for (const auto& y : delete_years) {
                    my_name.erase(y);
                }
            }
        }

        counter = 0;

        for (const auto &pair : my_name) {
            if (pair.first <= inp_year) {
                if (name == "") {
                    name = pair.second;
                } else {
                    name = pair.second + ", " + name;
                }
                ++ counter;
            } else {
                break;
            }
        }

        if ((counter == 1) || (name == "")) {
            name = "";
            return name;
        }

        size_t last_string_end = name.find(", ");
        if (last_string_end != string::npos) {
            name = name.substr(last_string_end + 2, name.size() - 1);
        }
        return name;
    }
};

int main() {
    Person person("-1_first", "-1_last", -1);
    int year = 3;
    person.ChangeLastName(year, std::to_string(year) + "_last");

    year = 5;
    person.ChangeFirstName(year, std::to_string(year) + "_first");
    person.ChangeLastName(year, std::to_string(year) + "_last");

    year = 1;
    person.ChangeLastName(year, std::to_string(3) + "_last");
    for (int a : {-2, -1, 1})cout << person.GetFullName(a) << '\n';
    for (int a : {-2, -1, 1})cout << person.GetFullNameWithHistory(a) << '\n';


    return 0;
}
