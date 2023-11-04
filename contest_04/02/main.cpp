#include "json.hpp"
#include <iostream>
#include <fstream>
using json = nlohmann::json;

using namespace std;

int main() {
    std::ifstream input_file("data.json");
    json data = json::parse(input_file);

    int user_id;
    cin >> user_id;

    int completed_tasks = 0;
    for (const auto& project : data) {
        for (const auto& task : project["tasks"]) {
            if (task["user_id"] == user_id && task["completed"]) {
               completed_tasks++;
                }
            }
        }
    cout << completed_tasks;

    return 0;
}
