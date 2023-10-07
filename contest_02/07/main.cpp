#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

using namespace std;

Student make_student(string line) {

    vector<Course> courses;

    size_t pos = 0;
    string token;
    vector<string> arr;

    while ((pos = line.find(";")) != string::npos) {
        token = line.substr(0, pos);
        arr.push_back(token);
        line.erase(0, pos + 1);
    }
    arr.push_back(line);

    string name = arr[0];
    string group = arr[1];

    for (int i = 0; i < size(arr); i++) {
        cout << arr[i] << endl;
    }

    courses.push_back({ arr[2], stoi(arr[3]), !!stoi(arr[4]) });
    courses.push_back({ arr[5], stoi(arr[6]), !!stoi(arr[7]) });
    courses.push_back({ arr[8], stoi(arr[9]), !!stoi(arr[10]) });
    courses.push_back({ arr[11], stoi(arr[12]), !!stoi(arr[13]) });

    return { name, group, courses };
}

bool is_upper(Student left, Student right) {

    if (left.group == right.group) {
        return left.name < right.name;
    }
    else {
        return left.group < right.group;
    }
}

void print(const vector<Student>& students) {

    if (students.empty()) {
        cout << "Empty list!";
    }
    else {
        string group = students[0].group;
        cout << group << endl;

        for (const Student& student : students) {

            if (student.group != group) {
                group = student.group;
                cout << group << endl;
            }
            cout << "- " << student.name << endl;
        }
    }

}

bool is_debtor(const Student& student, const int& cur_semester, const int& max_debt) {

    int debts = 0;
    for (auto& course : student.courses) {
        if (course.semester < cur_semester) {
            if (!course.finished) debts++;
        }
    }
    return debts > max_debt;
}

int main()
{
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(stud_count);
    for (auto& student : students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }

    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
        students.end(),
        std::back_inserter(expulsion_candidates),
        [cur_semester, max_debt](const Student& student) {
            return is_debtor(student, cur_semester, max_debt);
        });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);
}
