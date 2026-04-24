#include <bits/stdc++.h>
using namespace std;

struct Student {
    string id;    // 9-digit string
    string name;  // 1..19 ascii letters (per problem, no spaces)
    int score;    // 0..100
    int idx;      // insertion order
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Student> students;
    students.reserve(10000);
    unordered_map<string,int> idToIndex; // map id to index in students
    idToIndex.reserve(16384);
    unordered_map<string,int> nameToIndex; // name to index (unique name guaranteed)
    nameToIndex.reserve(16384);

    int cmd;
    int nextIdx = 0;
    while (cin >> cmd) {
        if (cmd == 1) {
            string id, name; int score;
            if (!(cin >> id >> name >> score)) break;
            if (idToIndex.find(id) != idToIndex.end()) {
                cout << "FAILED\n";
                continue;
            }
            Student s{ id, name, score, nextIdx++ };
            idToIndex[id] = (int)students.size();
            nameToIndex[name] = (int)students.size();
            students.push_back(std::move(s));
            cout << "SUCCESS\n";
        } else if (cmd == 2) {
            // display all in insertion order
            if (!students.empty()) {
                for (const auto &s : students) {
                    cout << s.id << ' ' << s.name << ' ' << s.score << '\n';
                }
            }
        } else if (cmd == 3) {
            string id; cin >> id;
            int idx;
            auto it = idToIndex.find(id);
            if (it != idToIndex.end()) {
                idx = it->second;
                const auto &s = students[idx];
                cout << s.id << ' ' << s.name << ' ' << s.score << '\n';
            }
        } else if (cmd == 4) {
            string name; cin >> name;
            int idx;
            auto it = nameToIndex.find(name);
            if (it != nameToIndex.end()) {
                idx = it->second;
                const auto &s = students[idx];
                cout << s.id << ' ' << s.name << ' ' << s.score << '\n';
            }
        } else if (cmd == 5) {
            // sort by id ascending (string compare since 9 digits, numeric == lexicographic)
            if (!students.empty()) {
                vector<int> order(students.size());
                iota(order.begin(), order.end(), 0);
                stable_sort(order.begin(), order.end(), [&](int a, int b){
                    return students[a].id < students[b].id;
                });
                for (size_t i = 0; i < order.size(); ++i) {
                    const auto &s = students[order[i]];
                    cout << s.id << ' ' << s.name << ' ' << s.score << '\n';
                }
            }
        } else if (cmd == 6) {
            // sort by score descending; when tie, by insertion order
            if (!students.empty()) {
                vector<int> order(students.size());
                iota(order.begin(), order.end(), 0);
                stable_sort(order.begin(), order.end(), [&](int a, int b){
                    if (students[a].score != students[b].score) return students[a].score > students[b].score;
                    return students[a].idx < students[b].idx; // insertion order
                });
                for (size_t i = 0; i < order.size(); ++i) {
                    const auto &s = students[order[i]];
                    cout << s.id << ' ' << s.name << ' ' << s.score << '\n';
                }
            }
        } else if (cmd == 7) {
            cout << "END\n";
            break;
        } else {
            // Unknown command; consume rest of the line to avoid infinite loop
            string rest;
            getline(cin, rest);
        }
    }

    return 0;
}

