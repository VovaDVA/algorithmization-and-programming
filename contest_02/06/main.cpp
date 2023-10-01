#include <sstream> 
using namespace std;

Student make_student(string line) {
    string name, group;
    size_t pos = line.find(";");
    name = line.substr(0, pos);
    group = line.substr(pos + 1);
    return { name, group };
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
