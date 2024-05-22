#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

#include "function.hpp"

const std::vector <size_t> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Summ () {
    long int a, b;
    std::cin >> a >> b;
    std::cout << a + b;
}

void MinimumString () {
    std::string a, b, c;
    std::cin >> a >> b >> c;
    if((a <= b) && (a <= c)){
        std::cout << a;
        return void();
    }
    if((b < a) && (b <= c)){
        std::cout << b;
        return void();
    }
    if((c < a) && (c < b)){
        std::cout << c;
        return void();
    }
}

void QuadraticEquationRoots () {
    double a, b, c;
    std::cin >> a >> b >> c;
    if (a != 0) {
        double D = b * b - 4 * a * c;
        if (D > 0) {
            std::cout << (-b + sqrt(D)) / 2.0 / a << " " << (-b - sqrt(D)) / 2.0 / a;
        } else if (D < 0) {
            return void();
        } else {
            std::cout << - (b / 2.0 / a);
        }
    } else {
        if (b != 0) {
            std::cout << -(c / b);
        }
    }
}

void IntegerDivision () {
    int a, b;
    std::cin >> a >> b;
    if (b == 0) {
        std::cout << "Impossible";
        return void();
    }
    std::cout << a / b;
}

void Discount () {
    double n, a, b, x, y;
    std::cin >> n >> a >> b >> x >> y;
    if (n > b) {
        std::cout << n - n * y / 100.0;
        return void();
    }
    if (n > a) {
        std::cout << n - n * x / 100.0;
        return void();
    }
    std::cout << n;
}

void EvenNumbersBetweenAB () {
    int a, b;
    std::cin >> a >> b;
    for(int i = a; i <= b; ++ i) {
        if ((i % 2) == 0) {
            std::cout << i << " ";
        }
    }
}

void NOD () {
    int a, b, c, d;
    std::cin >> a >> b;
    c = std::max(a, b);
    d = std::min(a, b);
    while (true) {
        int t = c % d;
        if (t == 0) {
            std::cout << d;
            return void();
        } else {
            c = d;
            d = t;
        }
    }
}

void IntToBinary () {
    int a, b, c;
    std::cin >> a;
    if (a == 1) {
        std::cout << "1";
        return void();
    }
    std::string rez = "";
    while (true) {
        b = a / 2;
        c = a % 2;
        if (c == 1){
            rez += "1";
        } else {
            rez += "0";
        }
        if (b == 1) {
            rez += "1";
            break;
        }
        a = b;
    }
    std::reverse(rez.begin(), rez.end());
    std::cout << rez;
}

int SimpleFactorial(int a){
    if (a <= 1) {
        return 1;
    }
    int rez = 1;
    for(int i = 2; i <= a; ++ i) {
        rez *= i;
    }
    return rez;
}

bool IsPalindrom(std::string& s){
    if (s.size() < 2){
        return true;
    }
    for(size_t i = 0; i < s.size() / 2; ++ i) {
        if(s[i] != s[s.size() - i - 1]){
            return false;
        }
    }
    return true;
}

std::vector <std::string> PalindromFilter(std::vector <std::string> &words, int minLength){
    size_t sz;
    std::vector <std::string> rez;
    if (minLength >= 0) {
        sz = minLength;
    } else {
        sz = 0;
    }
    for (auto str : words) {
        if (str.size() >= sz) {
            if (IsPalindrom(str)) {
                rez.push_back(str);
            }
        }
    }
    return rez;
}

void UpdateIfGreater(const int& first, int& second) {
    if (first > second) {
        second = first;
    }
}

void MoveStrings (std::vector<std::string>& source, std::vector<std::string>& destination) {
    for (const auto &str : source) {
        destination.push_back(str);
    }
    source.clear();
}

void Reverse(std::vector<int>& v) {
    size_t vsize = v.size();
    for(size_t i = 0; i < vsize / 2; ++ i) {
        std::swap(v[i], v[vsize - i - 1]);
    }
}

std::vector<int> Reversed(const std::vector<int>& v) {
    std::vector <int> rez;
    if (v.size() <= 1) {
        rez = v;
        return rez;
    }
    for (size_t i = v.size(); i > 0; --i) {
        rez.push_back(v[i - 1]);
    }
    return rez;
}

void SearchEqualToArithmeticMean () {
    int N;
    std::cin >> N;
    if (N <= 0) {
        return void();
    }
    std::vector <double> temp(N);
    std::string rez = "";
    double srar = 0;
    int counter = 0;
    for (int i = 0; i < N; ++ i) {
        std::cin >> temp[i];
        srar += temp[i];
    }
    srar /= N;
    for (int i = 0; i < N; ++ i) {
        if (temp[i] > srar) {
            ++ counter;
            rez += std::to_string(i) + " ";
        }
    }
    std::cout << counter << std::endl << rez << std::endl;
}

void Queue () {
    std::vector <int> que;
    int Q, i = 0, arg;
    std::string command;
    std::cin >> Q;
    while (i < Q) {
        std::cin >> command;
        if (command == "WORRY") {
            std::cin >> arg;
            que[arg] = 1;
        } else if (command == "QUIET") {
            std::cin >> arg;
            que[arg] = 0;
        } else if (command == "COME") {
            std::cin >> arg;
            if (arg > 0) {
                for (int p = 0; p < arg; ++ p) {
                    que.push_back(0);
                }
            } else {
                arg *= -1;
                for (int p = 0; p < arg; ++ p) {
                    que.pop_back();
                }
            }
        } else if (command == "WORRY_COUNT") {
            int counter = 0;
            for (auto p : que) {
                if (p == 1) {
                    ++ counter;
                }
            }
            std::cout << counter << std::endl;
        }
        ++ i;
    }
}

void Timesheet () {
    int Q, i = 0, current_month = 0;
    std::vector<std::pair<int, std::vector<std::string>>> timesheet (31, make_pair(0, std::vector<std::string>())); // вектор пар чисо, список дел
    std::string command, name;
    size_t arg, days_before, dif, current_days;

    for (size_t j = 0; j < days_in_month[current_month]; ++ j) {
        timesheet[j].first = j + 1;
    }

    std::cin >> Q;

    while (i < Q) {
        std::cin >> command;
        if (command == "ADD") {
            std::cin >> arg >> name;
            timesheet[arg - 1].second.push_back(name);
        } else if (command == "DUMP") {
            std::cin >> arg;
            std::cout << timesheet[arg - 1].second.size() << " ";
            for (const auto& wrk : timesheet[arg - 1].second) {
                std::cout << wrk << " ";
            }
            std::cout << std::endl;
        } else if (command == "NEXT") {
            days_before = days_in_month[current_month];
            ++ current_month;
            if (current_month > 11) {
                current_month = 0;
            }
            current_days = days_in_month[current_month];
            if (current_days < days_before) {
                dif = days_before - current_days;
                for (size_t p = 0; p < dif; ++ p) {
                    timesheet[current_days - 1].second.insert(end(timesheet[current_days - 1].second),
                                                              begin(timesheet[current_days + p].second),
                                                              end(timesheet[current_days + p].second));
                    timesheet[current_days + p].second.clear();
                }
            }
        }
        ++ i;
    }
}

void SomeMapTask () {
    std::map <char, int> letters;
    int N, let_counter;
    bool flag;
    std::string first, second;
    std::vector<std::string> answer;
    std::cin >> N;
    for (int i = 0; i < N; ++ i) {
        flag = true;
        letters.clear();
        let_counter = 0;
        std::cin >> first >> second;
        for (size_t j = 0; j < first.size(); ++ j) {
            ++ letters[first[j]];
            ++ let_counter;
        }
        for (size_t j = 0; j < second.size(); ++ j) {
            -- letters[second[j]];
            if (letters[second[j]] < 0) {
                flag = false;
            }
            -- let_counter;
        }
        if ((flag) && (let_counter == 0)) {
            answer.push_back("YES");
        } else {
            answer.push_back("NO");
        }
    }
    for (const auto& el : answer) {
        std::cout << el << std::endl;
    }
}

void CountriesAndCapitals () {
    std::map<std::string, std::string> my_map;
    int Q;
    std::string command, p1, p2, save;
    std::vector<std::string> result;
    std::cin >> Q;
    for(int i = 0; i < Q; ++ i) {
        std::cin >> command;
        if (command == "CHANGE_CAPITAL") {
            std::cin >> p1 >> p2;
            if (my_map.find(p1) == my_map.end()) {
                my_map[p1] = p2;
                result.push_back("Introduce new country " + p1 + " with capital " + p2);
            } else {
                if (my_map[p1] == p2) {
                    result.push_back("Country " + p1 + " hasn't changed its capital");
                } else {
                    result.push_back("Country  " + p1 + "  has changed its capital from " + my_map[p1]
                                     + " to " + p2);
                    my_map[p1] = p2;
                }
            }
        } else if (command == "RENAME") {
            std::cin >> p1 >> p2;
            if ((p1 == p2)
               || (my_map.find(p2) != my_map.end())
               || (my_map.find(p1) == my_map.end())) {
                result.push_back("Incorrect rename, skip");
            } else {
                save = my_map[p1];
                my_map.erase(p1);
                my_map[p2] = save;
                result.push_back("Country " + p1 + " with capital " + save + " has been renamed to " + p2);
            }
        } else if (command == "ABOUT") {
            std::cin >> p1;
            if (my_map.find(p1) == my_map.end()) {
                result.push_back("Country " + p1 + " doesn't exist");
            } else {
                result.push_back("Country " + p1 + " has capital " + my_map[p1]);
            }
        } else if (command == "DUMP") {
            if (my_map.empty()) {
                result.push_back("There are no countries in the world");
            } else {
                for (const auto& el : my_map) {
                    result.push_back(el.first + "/" + el.second);
                }
            }
        }
    }
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }
}

void BusStops1 () {
    std::map<std::string, std::vector<std::string>> bus_stop; // bus + stop_array
    std::map<std::string, std::vector<std::string>> stop_bus; // stop + all buses
    int Q, stop_count;
    std::string command, bus, stop_name, last_bus;
    std::cin >> Q;
    for (int i = 0; i < Q; ++ i) {
        std::cin >> command;
        if (command == "NEW_BUS") {
            std::cin >> bus >> stop_count;
            last_bus = bus;
            for (int j = 0; j < stop_count; ++ j) {
                std::cin >> stop_name;
                bus_stop[bus].push_back(stop_name);
                stop_bus[stop_name].push_back(bus);
            }
        } else if (command == "BUSES_FOR_STOP") {
            std::cin >> stop_name;
            if (stop_bus.find(stop_name) == stop_bus.end()) {
                std::cout << "No stop" << std::endl;
            } else {
                // cout << "Stop " << stop_name << ": ";
                for (const auto& st : stop_bus[stop_name]) {
                    std::cout << st << " ";
                }
                std::cout << std::endl;
            }
        } else if (command == "STOPS_FOR_BUS") {
            std::cin >> bus;
            if (bus_stop.find(bus) == bus_stop.end()) {
                std::cout << "No bus" << std::endl;
            } else {
                for (const auto& bs : bus_stop[bus]) {
                    std::cout << "Stop " + bs << ": ";
                    if (stop_bus[bs].size() == 1) {
                        std::cout << "no interchange" << std::endl;
                    } else {
                        for (const auto& st: stop_bus[bs]) {
                            if (st != bus) {
                                std::cout << st << " ";
                            }
                        }
                        std::cout << std::endl;
                    }
                }
            }
        } else if (command == "ALL_BUSES") {
            if (bus_stop.empty()) {
                std::cout << "No buses" << std::endl;
            } else {
                for (const auto& el : bus_stop) {
                    std::cout << "Bus " << el.first << ": ";
                    for (const auto& stp : el.second) {
                        std::cout << stp << " ";
                    }
                    std::cout << std::endl;
                }
            }
        }
    }
}

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
    std::set<std::string> result;
    for (const auto& el : m) {
        result.insert(el.second);
    }
    return result;
}

void CountriesCapitalsTemplate () {
    int Q;
    std::string command, word1, word2;
    std::map<std::string, std::set<std::string>> dict;
    std::cin >> Q;
    for (int i = 0; i < Q; ++ i) {
        std::cin >> command;
        if (command == "ADD") {
            std::cin >> word1 >> word2;
            dict[word1].insert(word2);
            dict[word2].insert(word1);
        } else if (command == "COUNT") {
            std::cin >> word1;
            std::cout << dict[word1].size() << std::endl;
        } else if (command == "CHECK") {
            std::cin >> word1 >> word2;
            bool flag = true;
            if (dict[word1].find(word2) == dict[word1].end()) {
                flag = false;
            } else if (dict[word2].find(word1) == dict[word2].end()) {
                flag = false;
            }
            if (flag) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
}

void PrintIntVector(const std::vector<int>& arr) {
    for (const auto& elt : arr) {
        std::cout << elt << " ";
    }
    std::cout << std::endl;
}

void FirstLambda () {
    int N;
    std::cin >> N;
    std::vector<int> ar(N);
    for (auto &el : ar) {
        std::cin >> el;
    }
    std::sort(ar.begin(), ar.end(), [](int& a, int& b){return abs(a) < abs(b);});
    PrintIntVector(ar);
}

void PrintPairStrStr1 (const std::vector<std::pair<std::string, std::string>>& arr) {
    for (const auto& elt : arr) {
        std::cout << elt.second << " ";
    }
}

void PrintPairStrStr2(const std::vector<std::pair<std::string, std::string>>& arr) {
    for (const auto& elt : arr) {
        std::cout << elt.first << " ";
    }
    std::cout << std::endl;
    for (const auto& elt : arr) {
        std::cout << elt.second << " ";
    }
    std::cout << std::endl;
}

void VectorPairtask () {
    int N;
    std::cin >> N;
    std::vector<std::pair<std::string, std::string>> ar(N);
    std::string str;
    for (int i = 0; i < N; ++ i) {
        std::cin >> str;
        ar[i].first = "";
        ar[i].second = str;
        for (const auto& el : ar[i].second) {
            ar[i].first += tolower(el);
        }
    }
    std::sort(ar.begin(), ar.end());
    PrintPairStrStr1(ar);
}

class SortedStrings {
public:
    void AddString(const std::string& s) {
        my_strings.insert(s);
    }
    std::vector<std::string> GetSortedStrings() {
        std::vector <std::string> result (my_strings.size());
        int cnt = 0;
        for (const auto& str : my_strings) {
            result[cnt] = str;
            ++ cnt;
        }
        return result;
  }
private:
    std::multiset<std::string> my_strings;
};

void PrintStringVector(const std::vector<std::string>& arr) {
    for (const auto& elt : arr) {
        std::cout << elt << " ";
    }
    std::cout << std::endl;
}

void WorkWithSortedStringsClass () {
    SortedStrings strings;
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintStringVector(strings.GetSortedStrings());
    strings.AddString("second");
    PrintStringVector(strings.GetSortedStrings());
}

class Person {
public:
    void ChangeFirstName (const int& inp_year, const std::string& inp_first_name) {
        first_name[inp_year] = inp_first_name;
    }

    void ChangeLastName (const int& inp_year, const std::string& inp_last_name) {
        last_name[inp_year] = inp_last_name;
    }

    std::string GetFullName (const int& inp_year) {
        std::string f_name = GetNameByYear(inp_year, first_name);
        std::string l_name = GetNameByYear(inp_year, last_name);
        std::string result;
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
private:
    std::map <int, std::string> first_name, last_name;

    std::string GetNameByYear (const int& inp_year, const std::map<int, std::string>& name_list) {
        std::string name = "";
        for (const auto &el : name_list) {
            if (el.first <= inp_year) {
                name = el.second;
            } else {
                break;
            }
        }
        return name;
    }
};

class PersonUpgrade {
public:
    void ChangeFirstName (const int& inp_year, const std::string& inp_first_name) {
        if (save_first_name != inp_first_name) {
            first_name[inp_year] = inp_first_name;
            save_first_name = inp_first_name;
        }
    }

    void ChangeLastName (const int& inp_year, const std::string& inp_last_name) {
        if (save_last_name != inp_last_name) {
            last_name[inp_year] = inp_last_name;
            save_last_name = inp_last_name;
        }
    }

    std::string GetFullName (const int& inp_year) {
        std::string f_name = GetNameByYear(inp_year, first_name),
                    l_name = GetNameByYear(inp_year, last_name),
                    result;
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

    std::string GetFullNameWithHistory (const int& inp_year) {
        std::string f_name = GetNameByYear(inp_year, first_name),
                    f_name_history = GetNameHistoryByYear(inp_year, first_name),
                    l_name = GetNameByYear(inp_year, last_name),
                    l_name_history = GetNameHistoryByYear(inp_year, last_name),
                    result;
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
    std::map<int, std::string> first_name, last_name;
    std::string save_first_name, save_last_name;

    std::string GetNameByYear (const int& inp_year, const std::map<int, std::string>& name_list) {
        std::string name = "";
        for (const auto &el : name_list) {
            if (el.first <= inp_year) {
                name = el.second;
            } else {
                break;
            }
        }
        return name;
    }

    void RemakeNameList (std::map<int, std::string>& name_list) {
        std::vector<int> years(name_list.size()), delete_years;
        size_t counter = 0;
        for (auto &el : name_list) {
            years[counter] = el.first;
            ++ counter;
        }
        if (counter > 1) {
            for (counter = 0; counter < years.size(); ++ counter) {
                if (name_list[years[counter]] == name_list[years[counter + 1]]) {
                    delete_years.push_back(years[counter + 1]);
                }
            }
            if (not delete_years.empty()) {
                for (const auto& y : delete_years) {
                    name_list.erase(y);
                }
            }
        }
    }

    std::string GetNameHistoryByYear (const int& inp_year, const std::map<int, std::string>& name_list) {
        std::string name = "";
        int counter = 0;
        for (const auto &elem : name_list) {
            if (elem.first <= inp_year) {
                if (name == "") {
                    name = elem.second;
                } else {
                    name = elem.second + ", " + name;
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
        else {
            size_t last_string_end = name.find(", ");
            if (last_string_end != std::string::npos) {
                name = name.substr(last_string_end + 2, name.size() - 1);
            }
        }
        return name;
    }
};

void WorkWithPersonUpgrade () {
    PersonUpgrade person;

    int year = 1;
    person.ChangeLastName(year, std::to_string(year)+"_last");
    std::cout << "year: " << year << '\n'
              << person.GetFullNameWithHistory(year) << '\n'
              << person.GetFullName(year) << '\n';

    year = 2;
    person.ChangeLastName(year, std::to_string(year)+"_last");
    std::cout << "year: " << year << '\n'
              << person.GetFullNameWithHistory(year) << '\n'
              << person.GetFullName(year) << '\n';
}

class ReversibleString {
public:
    ReversibleString () {};
    ReversibleString (const std::string& inp_string) {
        value = inp_string;
    }
    void Reverse () {
        if (value.size() > 0) {
            std::string rev = "";
            for (size_t i = value.size(); i > 0; -- i) {
                rev += value[i - 1];
            }
            value = rev;
        }
    }
    std::string ToString () const {
        return value;
    }
private:
    std::string value;
};

void WorkWithReversibleString () {
    ReversibleString s("live");
    s.Reverse();
    std::cout << s.ToString() << std::endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    std::string tmp = s_ref.ToString();
    std::cout << tmp << std::endl;

    ReversibleString empt;
    std::cout << '"' << empt.ToString() << '"' << std::endl;
}

class PersonVer3 {
public:
    PersonVer3 (const std::string& name, const std::string& surename, const int& birth_year) {
        burn_year = birth_year;
        first_name[burn_year] = name;
        last_name[burn_year] = surename;
    }

    void ChangeFirstName (const int& inp_year, const std::string& inp_first_name) {
        if (inp_year >= burn_year) {
            if (save_first_name != inp_first_name) {
                first_name[inp_year] = inp_first_name;
                save_first_name = inp_first_name;
            }
        }
    }

    void ChangeLastName (const int& inp_year, const std::string& inp_last_name) {
        if (inp_year >= burn_year) {
            if (save_last_name != inp_last_name) {
                last_name[inp_year] = inp_last_name;
                save_last_name = inp_last_name;
            }
        }
    }

    std::string GetFullName (const int& inp_year) const{
        std::string result;
        if (inp_year < burn_year) {
            result = "No person";
            return result;
        }
        std::string f_name = GetNameByYear(inp_year, first_name);
        std::string l_name = GetNameByYear(inp_year, last_name);
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

    std::string GetFullNameWithHistory (const int& inp_year) const{
        std::string result;
        if (inp_year < burn_year) {
            result = "No person";
            return result;
        }
        std::string f_name = GetNameByYear(inp_year, first_name);
        std::string f_name_history = GetNameHistoryByYear(inp_year, first_name);
        std::string l_name = GetNameByYear(inp_year, last_name);
        std::string l_name_history = GetNameHistoryByYear(inp_year, last_name);
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
    std::map<int, std::string> first_name, last_name;
    int burn_year;
    std::string save_first_name, save_last_name;

    std::string GetNameByYear (const int& inp_year, const std::map<int, std::string>& name_list) const{
        std::string name = "";
        for (const auto &el : name_list) {
            if (el.first <= inp_year) {
                name = el.second;
            } else {
                break;
            }
        }
        return name;
    }

    void RemakeNameList (std::map<int, std::string>& name_list) {
        std::vector<int> years(name_list.size()), delete_years;
        size_t counter = 0;
        for (auto &el : name_list) {
            years[counter] = el.first;
            ++ counter;
        }
        if (counter > 1) {
            for (counter = 0; counter < years.size(); ++ counter) {
                if (name_list[years[counter]] == name_list[years[counter + 1]]) {
                    delete_years.push_back(years[counter + 1]);
                }
            }
            if (not delete_years.empty()) {
                for (const auto& y : delete_years) {
                    name_list.erase(y);
                }
            }
        }
    }

    std::string GetNameHistoryByYear (const int& inp_year, const std::map<int, std::string>& name_list) const{
        std::string name = "";
        int counter = 0;
        for (const auto &el : name_list) {
            if (el.first <= inp_year) {
                if (name == "") {
                    name = el.second;
                } else {
                    name = el.second + ", " + name;
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
        else {
            size_t last_string_end = name.find(", ");
            if (last_string_end != std::string::npos) {
                name = name.substr(last_string_end + 2, name.size() - 1);
            }
        }
        return name;
    }
};

void WorkWithPersonVer3 () {
    PersonVer3 person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }
}

struct Specialization {
    std::string value;

    explicit Specialization (std::string new_value) {
        value = new_value;
    }
};

struct Course {
    std::string value;

    explicit Course (std::string new_value) {
        value = new_value;
    }
};

struct Week {
    std::string value;

    explicit Week (std::string new_value) {
        value = new_value;
    }
};

struct LectureTitle {
    std::string specialization;
    std::string course;
    std::string week;

    LectureTitle (Specialization new_spec,
                  Course new_cource,
                  Week new_week) {
        specialization = new_spec.value;
        course = new_cource.value;
        week = new_week.value;
    }
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
  Function func;
  func.AddPart('*', params.a);
  func.AddPart('-', image.freshness * params.b);
  func.AddPart('+', image.rating * params.c);
  return func;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function func = MakeWeightFunction(params, image);
  return func.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function func = MakeWeightFunction(params, image);
  func.Invert();
  return func.Apply(weight);
}

void WorjWithImageClasses () {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  std::cout << ComputeImageWeight(params, image) << std::endl;
  std::cout << ComputeQualityByWeight(params, image, 52) << std::endl;
}

void PrintFile () {
    std::ifstream my_file("input.txt");
    if (my_file) {
        std::string line;
        while (getline(my_file, line)) {
            std::cout << line << std::endl;
        }
    }
}

void CopyDataBetweenFiles () {
    std::ifstream my_file("input.txt");
    std::ofstream my_out_file("output.txt");
    if (my_file) {
        std::string line;
        while (getline(my_file, line)) {
            my_out_file << line << std::endl;
        }
    }
}

void IomanipWithFiles () {
    std::ifstream my_file("input.txt");
    if (my_file) {
        while (!my_file.eof()) {
            double value;
            my_file >> value;
            std::cout << std::fixed << std::setprecision(3) << value << std::endl;
        }
    }
}

struct Student {
    std::string name, surename;
    int birth_day, birth_month, birth_year;
};

void WorjWithStudent () {
    size_t N, M;
    std::cin >> N;
    std::vector<Student> students(N);
    std::string nam, suren, request;
    int day, month, year, request_value;
    for (size_t i = 0; i < N; ++ i) {
        std::cin >> nam >> suren >> day >> month >> year;
        students[i].name = nam;
        students[i].surename = suren;
        students[i].birth_day = day;
        students[i].birth_month = month;
        students[i].birth_year = year;
    }
    std::cin >> M;
    for (size_t i = 0; i < M; ++ i) {
        std::cin >> request >> request_value;
        if (request == "name") {
            if (request_value <= 0) {
                std::cout << "bad request" << std::endl;
            } else if ((request_value - 1) < int(N)) {
                std::cout << students[request_value - 1].name << " "
                          << students[request_value - 1].surename << std::endl;
            } else {
                std::cout << "bad request" << std::endl;
            }
        } else if (request == "date") {
            if (request_value <= 0) {
                std::cout << "bad request" << std::endl;
            } else if ((request_value - 1) < int(N)) {
                std::cout << students[request_value - 1].birth_day << "."
                          << students[request_value - 1].birth_month << "."
                          << students[request_value - 1].birth_year << std::endl;
            } else {
                std::cout << "bad request" << std::endl;
            }
        } else {
            std::cout << "bad request" << std::endl;
        }
    }
}

void EnsureEqual(const std::string& left, const std::string& right) {
    if (left != right) {
        throw std::runtime_error(left + " != " + right);
    }
}

void TryExceptions () {
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

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
            throw std::invalid_argument("Division by zero");
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
        for (int i = 2; i <= (std::min(abs(numerator_value), abs(denominator_value))); ++ i) {
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
        throw std::domain_error("Division by zero");
    }
    int new_numerator = left_arg.Numerator() * right_arg.Denominator();
    int new_denominator = left_arg.Denominator() * right_arg.Numerator();
    Rational result(new_numerator, new_denominator);
    return result;
}

std::ostream& operator<< (std::ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

std::istream& operator>> (std::istream& stream, Rational& rational) {
    if (!stream) {
        return stream;
    }
    std::string inp;
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
    std::istringstream ready_to_parce(inp);
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

Rational Calculator (std::string& stream) {
    std::string inp = "", incorr_inp = stream;
    if (incorr_inp == "") {
        throw std::invalid_argument("Invalid argument");
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
        throw std::invalid_argument("Invalid argument");
    }
    if (size_t(sl_count + oper_count + sym_count) != inp.size()) {
        throw std::invalid_argument("Invalid argument");
    }
    std::istringstream ready_to_parce(inp);
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
        throw std::invalid_argument("Invalid argument");
    }
    if (oper == '/') {
        if (r_num == 0) {
            throw std::domain_error("Division by zero");
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
    return 0;
}
