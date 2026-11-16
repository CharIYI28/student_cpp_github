#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct student {
    string name;
    int score;
};

// Find student by name
int findStudent(const vector<student>& students, string name) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            return i;
        }
    }
    return -1;
}

// Insert all of the student names into the struct variable
// press -1 to stop inserting
// by default, each student will get a score of -2. Temporary int
void insert_student(vector<student>& students){
    string stu_name;
    int resume = 1;
    int index = 1;
    cout << "Insert the names" << endl;
    cout << "No." << " " << "Name (press -1 to finish)" << endl;
    while (resume == 1){
        cout << index << "   ";
        cin >> stu_name;
        index ++;
        if (stu_name == "-1"){
            resume = -1;
        } else {
            students.push_back({stu_name, -2});
        }
    }
}

// Insert score to each student
// if student's score is not -2, they will be ignored
void insert_score(vector<student>& students){
    int score;
    if (students.empty()){
        cout << "Please insert the names first." << endl;
    } else{
        cout << "Name" << " " << "Score" << endl;
        for (int i = 0; i < students.size(); i++){
            if (students[i].score == -2){
                cout << students[i].name << "   ";
                cin >> score;
                students[i].score = score;
            } else{
                cout << students[i].name << "   " << students[i].score << endl;
            }
            
        }
    }
}


// present the list of all students
void show_all(vector<student>& students){
    cout << "Name" << " " << "Score" << endl;
    for (const auto& i : students){
        cout << i.name << " " << i.score << endl;
    }
}

// 3. Search student
void searchStudent(const vector<student>& students) {
    string name;

    cout << "\nEnter student name to search: ";
    // getline(cin, name);
    cin >> name;

    int index = findStudent(students, name);

    if (index == -1) {
        cout << "Student not found.\n";
    } else {
        cout << "Student found!\n";
        cout << "Name: " << students[index].name << "\n";
        cout << "Score: " << students[index].score << "\n";
    }
}

// 4. Sort students by score (Bubble Sort)
void sortStudents(vector<student>& students) {
    if (students.empty()) {
        cout << "\nNo students to sort.\n";
        return;
    }

    for (int i = 0; i < students.size() - 1; i++) {
        for (int j = 0; j < students.size() - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    cout << "\nStudents sorted from highest to lowest:\n";

    for (int i = 0; i < students.size(); i++) {
        cout << i + 1 << ". "
             << students[i].name
             << " - Score: " << students[i].score << "\n";
    }
}

// 5. Statistics
void showStatistics(const vector<student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    int highest = students[0].score;
    int lowest = students[0].score;
    int total = 0;
    int passing = 0;

    for (const student& s : students) {
        total += s.score;

        if (s.score > highest) {
            highest = s.score;
        }

        if (s.score < lowest) {
            lowest = s.score;
        }

        if (s.score >= 50) {
            passing++;
        }
    }

    double average = static_cast<double>(total) / students.size();

    cout << "\n=== Class Statistics ===\n";
    cout << fixed << setprecision(2);
    cout << "Average score: " << average << "\n";
    cout << "Highest score: " << highest << "\n";
    cout << "Lowest score: " << lowest << "\n";
    cout << "Number passing: " << passing << "\n";
}

// 6. Remove student
void removeStudent(vector<student>& students) {
    string name;

    cout << "\nEnter student name to remove: ";
    cin >> name;

    int index = findStudent(students, name);

    if (index == -1) {
        cout << "Student not found.\n";
    } else {
        students.erase(students.begin() + index);
        cout << "Student removed successfully!\n";
    }
}

// Managing each action, frequently ask what action do user want to take?
void action_manager(vector<student>& students){
    string action;
    string resume;
    cout << "What action? (name, score, show, search, sort, statistic, remove): ";
    cin >> action;
    if (action == "name"){
        insert_student(students);
    } else if (action == "score")
    {
        insert_score(students);
    } else if (action == "show"){
        show_all(students);
    } else if (action == "search"){
        searchStudent(students);
    } else if (action == "sort"){
        sortStudents(students);
    } else if (action == "statistic"){
        showStatistics(students);
    } else if (action == "remove"){
        removeStudent(students);
    }
    cout << "Continue? (y/n): ";
    cin >> resume;
    if (resume == "y"){
        action_manager(students);
    }
}


main(){
    vector<student> students;
    action_manager(students);
    return 0;
}