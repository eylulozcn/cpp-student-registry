#include <iostream>
#include <string>
#include <list>

class Student {
private:
    int number;
    std::string name;

public:
    Student(int num, std::string n) {
        number = num;
        name = n;
    }

    int getNumber() const {
        return number;
    }

    std::string getName() const {
        return name;
    }
};


// CHECK STUDENT NUMBER
bool StudentExists(const std::list<Student>& students, int number) {

    for (const Student& s : students) {
        if (s.getNumber() == number) {
            return true;
        }
    }

    return false;
}


// ADD STUDENT
void addStudent(std::list<Student>& students) {

    int number;
    std::string name;

    std::cout << "Enter student number: ";
    std::cin >> number;

    if (StudentExists(students, number)) {
        std::cout << "Student number already exists!\n";
        return;
    }

    std::cout << "Enter student name: ";
    std::getline(std::cin >> std::ws, name);

    students.push_back(Student(number, name));

    std::cout << "Student added successfully!\n";
}


// DISPLAY STUDENTS
void displayStudents(const std::list<Student>& students) {

    if (students.empty()) {
        std::cout << "No students registered!\n";
        return;
    }

    std::cout << "\n--- Student List ---\n";

    for (const Student& s : students) {
        std::cout << "Number: " << s.getNumber()
                  << " | Name: " << s.getName()
                  << "\n";
    }
}


// SORT BY NUMBER
void sortByNumber(const std::list<Student>& students) {

    std::list<Student> sorted = students;

    sorted.sort([](const Student& a, const Student& b) {
        return a.getNumber() < b.getNumber();
    });

    std::cout << "\n--- Sorted by Number ---\n";

    for (const Student& s : sorted) {
        std::cout << s.getNumber()
                  << " - " << s.getName()
                  << "\n";
    }
}


// SORT BY NAME
void sortByName(const std::list<Student>& students) {

    std::list<Student> sorted = students;

    sorted.sort([](const Student& a, const Student& b) {
        return a.getName() < b.getName();
    });

    std::cout << "\n--- Sorted by Name ---\n";

    for (const Student& s : sorted) {
        std::cout << s.getNumber()
                  << " - " << s.getName()
                  << "\n";
    }
}


// DELETE STUDENT
void deleteStudent(std::list<Student>& students) {

    int number;

    std::cout << "Enter student number to delete: ";
    std::cin >> number;

    for (auto it = students.begin(); it != students.end(); ++it) {

        if (it->getNumber() == number) {

            students.erase(it);

            std::cout << "Student deleted successfully!\n";
            return;
        }
    }

    std::cout << "Student not found!\n";
}


// INSERT STUDENT AT POSITION
void insertStudent(std::list<Student>& students) {

    int number;
    int position;
    std::string name;

    std::cout << "Enter student number: ";
    std::cin >> number;

    if (StudentExists(students, number)) {
        std::cout << "Student number already exists!\n";
        return;
    }

    std::cout << "Enter student name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter position: ";
    std::cin >> position;

    if (position < 1 ||
        position > static_cast<int>(students.size()) + 1) {

        std::cout << "Invalid position!\n";
        return;
    }

    auto it = students.begin();

    for (int i = 1; i < position; i++) {
        ++it;
    }

    students.insert(it, Student(number, name));

    std::cout << "Student inserted successfully!\n";
}


// SEARCH STUDENT
void searchStudent(const std::list<Student>& students) {

    int number;

    std::cout << "Enter student number to search: ";
    std::cin >> number;

    for (const Student& s : students) {

        if (s.getNumber() == number) {

            std::cout << "Student found!\n";

            std::cout << "Number: " << s.getNumber()
                      << "\nName: " << s.getName()
                      << "\n";
            return;
        }
    }

    std::cout << "Student not found!\n";
}


// COUNT STUDENTS
void countStudents(const std::list<Student>& students) {

    std::cout << "Total Students: "
              << students.size()
              << "\n";
}


// MAIN FUNCTION
int main() {

    std::list<Student> students;

    int choice;

    while (true) {

        std::cout << "\n=================== STUDENT REGISTRY ===================\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Students\n";
        std::cout << "3. Sort Students by Number\n";
        std::cout << "4. Sort Students by Name\n";
        std::cout << "5. Delete Student by Number\n";
        std::cout << "6. Insert Student at Position\n";
        std::cout << "7. Search Student\n";
        std::cout << "8. Total Student Count\n";
        std::cout << "0. Exit\n";

        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid Input! Program closed!\n";
            return 1;
        }

        switch (choice) {

            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                sortByNumber(students);
                break;

            case 4:
                sortByName(students);
                break;

            case 5:
                deleteStudent(students);
                break;

            case 6:
                insertStudent(students);
                break;

            case 7:
                searchStudent(students);
                break;

            case 8:
                countStudents(students);
                break;

            case 0:
                std::cout << "Program closed. Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}