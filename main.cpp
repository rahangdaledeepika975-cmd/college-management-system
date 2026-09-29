#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// ==================== STUDENT ====================

class Student
{
    int rollNo;
    string name;
    string branch;
    int semester;

public:

    Student() {}

    Student(int r, string n, string b, int s)
    {
        rollNo = r;
        name = n;
        branch = b;
        semester = s;
    }

    int getRollNo() const
    {
        return rollNo;
    }

    void display() const
    {
        cout << left << setw(10) << rollNo
             << setw(25) << name
             << setw(15) << branch
             << setw(10) << semester << endl;
    }

    void save(ofstream &file) const
    {
        file << rollNo << endl;
        file << name << endl;
        file << branch << endl;
        file << semester << endl;
    }

    static Student load(ifstream &file)
    {
        int r, s;
        string n, b;

        file >> r;
        file.ignore();

        getline(file, n);
        getline(file, b);

        file >> s;
        file.ignore();

        return Student(r, n, b, s);
    }
};

// ==================== FACULTY ====================

class Faculty
{
    int id;
    string name;
    string department;
    string subject;

public:

    Faculty() {}

    Faculty(int i, string n, string d, string s)
    {
        id = i;
        name = n;
        department = d;
        subject = s;
    }

    int getId() const
    {
        return id;
    }

    void display() const
    {
        cout << left << setw(10) << id
             << setw(25) << name
             << setw(20) << department
             << setw(20) << subject << endl;
    }

    void save(ofstream &file) const
    {
        file << id << endl;
        file << name << endl;
        file << department << endl;
        file << subject << endl;
    }

    static Faculty load(ifstream &file)
    {
        int i;
        string n, d, s;

        file >> i;
        file.ignore();

        getline(file, n);
        getline(file, d);
        getline(file, s);

        return Faculty(i, n, d, s);
    }
};

// ==================== COURSE ====================

class Course
{
    int courseId;
    string courseName;
    int credits;
    int facultyId;

public:

    Course() {}

    Course(int c, string n, int cr, int f)
    {
        courseId = c;
        courseName = n;
        credits = cr;
        facultyId = f;
    }

    int getCourseId() const
    {
        return courseId;
    }

    void display() const
    {
        cout << left << setw(12) << courseId
             << setw(25) << courseName
             << setw(10) << credits
             << setw(12) << facultyId << endl;
    }

    void save(ofstream &file) const
    {
        file << courseId << endl;
        file << courseName << endl;
        file << credits << endl;
        file << facultyId << endl;
    }

    static Course load(ifstream &file)
    {
        int c, cr, f;
        string n;

        file >> c;
        file.ignore();

        getline(file, n);

        file >> cr;
        file >> f;
        file.ignore();

        return Course(c, n, cr, f);
    }
};

// ==================== ATTENDANCE ====================

class Attendance
{
    int rollNo;
    int totalClasses;
    int attendedClasses;

public:

    Attendance() {}

    Attendance(int r, int t, int a)
    {
        rollNo = r;
        totalClasses = t;
        attendedClasses = a;
    }

    int getRollNo() const
    {
        return rollNo;
    }

    double percentage() const
    {
        if (totalClasses == 0)
            return 0;

        return (attendedClasses * 100.0) / totalClasses;
    }

    void display() const
    {
        cout << left << setw(10) << rollNo
             << setw(15) << totalClasses
             << setw(18) << attendedClasses
             << fixed << setprecision(2)
             << percentage() << "%" << endl;
    }

    void save(ofstream &file) const
    {
        file << rollNo << " "
             << totalClasses << " "
             << attendedClasses << endl;
    }

    static Attendance load(ifstream &file)
    {
        int r, t, a;

        file >> r >> t >> a;

        return Attendance(r, t, a);
    }
};

// ==================== RESULT ====================

class Result
{
    int rollNo;
    string subject;
    int marks;

public:

    Result() {}

    Result(int r, string s, int m)
    {
        rollNo = r;
        subject = s;
        marks = m;
    }

    int getRollNo() const
    {
        return rollNo;
    }

    string getSubject() const
    {
        return subject;
    }

    string getGrade() const
    {
        if (marks >= 90)
            return "A+";
        else if (marks >= 80)
            return "A";
        else if (marks >= 70)
            return "B";
        else if (marks >= 60)
            return "C";
        else if (marks >= 50)
            return "D";
        else
            return "F";
    }

    void display() const
    {
        cout << left << setw(10) << rollNo
             << setw(25) << subject
             << setw(10) << marks
             << setw(10) << getGrade() << endl;
    }

    void save(ofstream &file) const
    {
        file << rollNo << endl;
        file << subject << endl;
        file << marks << endl;
    }

    static Result load(ifstream &file)
    {
        int r, m;
        string s;

        file >> r;
        file.ignore();

        getline(file, s);

        file >> m;
        file.ignore();

        return Result(r, s, m);
    }
};

// ==================== FEES ====================

class Fees
{
    int rollNo;
    double totalFees;
    double paidFees;

public:

    Fees() {}

    Fees(int r, double t, double p)
    {
        rollNo = r;
        totalFees = t;
        paidFees = p;
    }

    int getRollNo() const
    {
        return rollNo;
    }

    double remainingFees() const
    {
        return totalFees - paidFees;
    }

    string getStatus() const
    {
        if (paidFees >= totalFees)
            return "Paid";

        return "Pending";
    }

    void display() const
    {
        cout << left << setw(10) << rollNo
             << setw(15) << totalFees
             << setw(15) << paidFees
             << setw(15) << remainingFees()
             << setw(12) << getStatus() << endl;
    }

    void save(ofstream &file) const
    {
        file << rollNo << " "
             << totalFees << " "
             << paidFees << endl;
    }

    static Fees load(ifstream &file)
    {
        int r;
        double t, p;

        file >> r >> t >> p;

        return Fees(r, t, p);
    }
};

// ==================== GLOBAL VECTORS ====================

vector<Student> students;
vector<Faculty> faculties;
vector<Course> courses;
vector<Attendance> attendanceList;
vector<Result> results;
vector<Fees> feesList;

// ==================== FILE HANDLING ====================

void saveStudents()
{
    ofstream file("students.txt");

    for (const Student &s : students)
        s.save(file);

    file.close();
}

void loadStudents()
{
    ifstream file("students.txt");

    if (!file)
        return;

    while (file.peek() != EOF)
        students.push_back(Student::load(file));

    file.close();
}

void saveFaculties()
{
    ofstream file("faculty.txt");

    for (const Faculty &f : faculties)
        f.save(file);

    file.close();
}

void loadFaculties()
{
    ifstream file("faculty.txt");

    if (!file)
        return;

    while (file.peek() != EOF)
        faculties.push_back(Faculty::load(file));

    file.close();
}

void saveCourses()
{
    ofstream file("courses.txt");

    for (const Course &c : courses)
        c.save(file);

    file.close();
}

void loadCourses()
{
    ifstream file("courses.txt");

    if (!file)
        return;

    while (file.peek() != EOF)
        courses.push_back(Course::load(file));

    file.close();
}

void saveAttendance()
{
    ofstream file("attendance.txt");

    for (const Attendance &a : attendanceList)
        a.save(file);

    file.close();
}

void loadAttendance()
{
    ifstream file("attendance.txt");

    if (!file)
        return;

    while (file.peek() != EOF)
        attendanceList.push_back(Attendance::load(file));

    file.close();
}

void saveResults()
{
    ofstream file("results.txt");

    for (const Result &r : results)
        r.save(file);

    file.close();
}

void loadResults()
{
    ifstream file("results.txt");

    if (!file)
        return;

    while (file.peek() != EOF)
        results.push_back(Result::load(file));

    file.close();
}

void saveFees()
{
    ofstream file("fees.txt");

    for (const Fees &f : feesList)
        f.save(file);

    file.close();
}

void loadFees()
{
    ifstream file("fees.txt");

    if (!file)
        return;

    while (file.peek() != EOF)
        feesList.push_back(Fees::load(file));

    file.close();
}

void loadAllData()
{
    loadStudents();
    loadFaculties();
    loadCourses();
    loadAttendance();
    loadResults();
    loadFees();
}

void saveAllData()
{
    saveStudents();
    saveFaculties();
    saveCourses();
    saveAttendance();
    saveResults();
    saveFees();
}

// ==================== STUDENT MANAGEMENT ====================

void addStudent()
{
    int rollNo, semester;
    string name, branch;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    for (const Student &s : students)
    {
        if (s.getRollNo() == rollNo)
        {
            cout << "Roll Number already exists!" << endl;
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Branch: ";
    getline(cin, branch);

    cout << "Enter Semester: ";
    cin >> semester;

    if (semester <= 0)
    {
        cout << "Invalid semester!" << endl;
        return;
    }

    students.push_back(Student(rollNo, name, branch, semester));

    saveStudents();

    cout << "Student added successfully!" << endl;
}

void viewStudents()
{
    if (students.empty())
    {
        cout << "No students found." << endl;
        return;
    }

    cout << left << setw(10) << "Roll No"
         << setw(25) << "Name"
         << setw(15) << "Branch"
         << setw(10) << "Semester" << endl;

    cout << "------------------------------------------------------------" << endl;

    for (const Student &s : students)
        s.display();
}

void searchStudent()
{
    int rollNo;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    for (const Student &s : students)
    {
        if (s.getRollNo() == rollNo)
        {
            s.display();
            return;
        }
    }

    cout << "Student not found." << endl;
}

void updateStudent()
{
    int rollNo;

    cout << "Enter Roll Number to update: ";
    cin >> rollNo;

    for (Student &s : students)
    {
        if (s.getRollNo() == rollNo)
        {
            string name, branch;
            int semester;

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Branch: ";
            getline(cin, branch);

            cout << "Enter New Semester: ";
            cin >> semester;

            if (semester <= 0)
            {
                cout << "Invalid semester!" << endl;
                return;
            }

            s = Student(rollNo, name, branch, semester);

            saveStudents();

            cout << "Student updated successfully!" << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

void deleteStudent()
{
    int rollNo;

    cout << "Enter Roll Number to delete: ";
    cin >> rollNo;

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->getRollNo() == rollNo)
        {
            students.erase(it);
            saveStudents();

            cout << "Student deleted successfully!" << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

void studentMenu()
{
    int choice;

    do
    {
        cout << endl;
        cout << "===== STUDENT MANAGEMENT =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: break;
            default: cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);
}

// ==================== FACULTY MANAGEMENT ====================

void addFaculty()
{
    int id;
    string name, department, subject;

    cout << "Enter Faculty ID: ";
    cin >> id;

    for (const Faculty &f : faculties)
    {
        if (f.getId() == id)
        {
            cout << "Faculty ID already exists!" << endl;
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Subject: ";
    getline(cin, subject);

    faculties.push_back(Faculty(id, name, department, subject));

    saveFaculties();

    cout << "Faculty added successfully!" << endl;
}

void viewFaculty()
{
    if (faculties.empty())
    {
        cout << "No faculty found." << endl;
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(20) << "Department"
         << setw(20) << "Subject" << endl;

    cout << "----------------------------------------------------------------" << endl;

    for (const Faculty &f : faculties)
        f.display();
}

void searchFaculty()
{
    int id;

    cout << "Enter Faculty ID: ";
    cin >> id;

    for (const Faculty &f : faculties)
    {
        if (f.getId() == id)
        {
            f.display();
            return;
        }
    }

    cout << "Faculty not found." << endl;
}

void updateFaculty()
{
    int id;

    cout << "Enter Faculty ID to update: ";
    cin >> id;

    for (Faculty &f : faculties)
    {
        if (f.getId() == id)
        {
            string name, department, subject;

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Department: ";
            getline(cin, department);

            cout << "Enter New Subject: ";
            getline(cin, subject);

            f = Faculty(id, name, department, subject);

            saveFaculties();

            cout << "Faculty updated successfully!" << endl;
            return;
        }
    }

    cout << "Faculty not found." << endl;
}

void deleteFaculty()
{
    int id;

    cout << "Enter Faculty ID to delete: ";
    cin >> id;

    for (auto it = faculties.begin(); it != faculties.end(); ++it)
    {
        if (it->getId() == id)
        {
            faculties.erase(it);
            saveFaculties();

            cout << "Faculty deleted successfully!" << endl;
            return;
        }
    }

    cout << "Faculty not found." << endl;
}

void facultyMenu()
{
    int choice;

    do
    {
        cout << endl;
        cout << "===== FACULTY MANAGEMENT =====" << endl;
        cout << "1. Add Faculty" << endl;
        cout << "2. View Faculty" << endl;
        cout << "3. Search Faculty" << endl;
        cout << "4. Update Faculty" << endl;
        cout << "5. Delete Faculty" << endl;
        cout << "6. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addFaculty(); break;
            case 2: viewFaculty(); break;
            case 3: searchFaculty(); break;
            case 4: updateFaculty(); break;
            case 5: deleteFaculty(); break;
            case 6: break;
            default: cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);
}

// ==================== COURSE MANAGEMENT ====================

void addCourse()
{
    int courseId, credits, facultyId;
    string courseName;

    cout << "Enter Course ID: ";
    cin >> courseId;

    for (const Course &c : courses)
    {
        if (c.getCourseId() == courseId)
        {
            cout << "Course ID already exists!" << endl;
            return;
        }
    }

    cin.ignore();

    cout << "Enter Course Name: ";
    getline(cin, courseName);

    cout << "Enter Credits: ";
    cin >> credits;

    cout << "Enter Faculty ID: ";
    cin >> facultyId;

    if (credits <= 0)
    {
        cout << "Credits must be greater than 0." << endl;
        return;
    }

    courses.push_back(Course(courseId, courseName, credits, facultyId));

    saveCourses();

    cout << "Course added successfully!" << endl;
}

void viewCourses()
{
    if (courses.empty())
    {
        cout << "No courses found." << endl;
        return;
    }

    cout << left << setw(12) << "Course ID"
         << setw(25) << "Course Name"
         << setw(10) << "Credits"
         << setw(12) << "Faculty ID" << endl;

    cout << "------------------------------------------------------------" << endl;

    for (const Course &c : courses)
        c.display();
}

void searchCourse()
{
    int courseId;

    cout << "Enter Course ID: ";
    cin >> courseId;

    for (const Course &c : courses)
    {
        if (c.getCourseId() == courseId)
        {
            c.display();
            return;
        }
    }

    cout << "Course not found." << endl;
}

void updateCourse()
{
    int courseId;

    cout << "Enter Course ID to update: ";
    cin >> courseId;

    for (Course &c : courses)
    {
        if (c.getCourseId() == courseId)
        {
            string name;
            int credits, facultyId;

            cin.ignore();

            cout << "Enter New Course Name: ";
            getline(cin, name);

            cout << "Enter New Credits: ";
            cin >> credits;

            cout << "Enter New Faculty ID: ";
            cin >> facultyId;

            if (credits <= 0)
            {
                cout << "Credits must be greater than 0." << endl;
                return;
            }

            c = Course(courseId, name, credits, facultyId);

            saveCourses();

            cout << "Course updated successfully!" << endl;
            return;
        }
    }

    cout << "Course not found." << endl;
}

void deleteCourse()
{
    int courseId;

    cout << "Enter Course ID to delete: ";
    cin >> courseId;

    for (auto it = courses.begin(); it != courses.end(); ++it)
    {
        if (it->getCourseId() == courseId)
        {
            courses.erase(it);
            saveCourses();

            cout << "Course deleted successfully!" << endl;
            return;
        }
    }

    cout << "Course not found." << endl;
}

void courseMenu()
{
    int choice;

    do
    {
        cout << endl;
        cout << "===== COURSE MANAGEMENT =====" << endl;
        cout << "1. Add Course" << endl;
        cout << "2. View Courses" << endl;
        cout << "3. Search Course" << endl;
        cout << "4. Update Course" << endl;
        cout << "5. Delete Course" << endl;
        cout << "6. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addCourse(); break;
            case 2: viewCourses(); break;
            case 3: searchCourse(); break;
            case 4: updateCourse(); break;
            case 5: deleteCourse(); break;
            case 6: break;
            default: cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);
}

// ==================== ATTENDANCE MANAGEMENT ====================

void addAttendance()
{
    int rollNo, total, attended;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    for (const Attendance &a : attendanceList)
    {
        if (a.getRollNo() == rollNo)
        {
            cout << "Attendance record already exists!" << endl;
            return;
        }
    }

    cout << "Enter Total Classes: ";
    cin >> total;

    cout << "Enter Attended Classes: ";
    cin >> attended;

    if (total <= 0)
    {
        cout << "Total classes must be greater than 0." << endl;
        return;
    }

    if (attended < 0 || attended > total)
    {
        cout << "Invalid attended classes." << endl;
        return;
    }

    attendanceList.push_back(Attendance(rollNo, total, attended));

    saveAttendance();

    cout << "Attendance added successfully!" << endl;
}

void viewAttendance()
{
    if (attendanceList.empty())
    {
        cout << "No attendance records found." << endl;
        return;
    }

    cout << left << setw(10) << "Roll No"
         << setw(15) << "Total"
         << setw(18) << "Attended"
         << setw(15) << "Percentage" << endl;

    cout << "------------------------------------------------------------" << endl;

    for (const Attendance &a : attendanceList)
        a.display();
}

void searchAttendance()
{
    int rollNo;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    for (const Attendance &a : attendanceList)
    {
        if (a.getRollNo() == rollNo)
        {
            a.display();
            return;
        }
    }

    cout << "Attendance record not found." << endl;
}

void attendanceMenu()
{
    int choice;

    do
    {
        cout << endl;
        cout << "===== ATTENDANCE MANAGEMENT =====" << endl;
        cout << "1. Add Attendance" << endl;
        cout << "2. View Attendance" << endl;
        cout << "3. Search Attendance" << endl;
        cout << "4. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addAttendance(); break;
            case 2: viewAttendance(); break;
            case 3: searchAttendance(); break;
            case 4: break;
            default: cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);
}

// ==================== RESULT MANAGEMENT ====================

void addResult()
{
    int rollNo, marks;
    string subject;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    cin.ignore();

    cout << "Enter Subject: ";
    getline(cin, subject);

    for (const Result &r : results)
    {
        if (r.getRollNo() == rollNo &&
            r.getSubject() == subject)
        {
            cout << "Result for this subject already exists!" << endl;
            return;
        }
    }

    cout << "Enter Marks: ";
    cin >> marks;

    if (marks < 0 || marks > 100)
    {
        cout << "Marks must be between 0 and 100." << endl;
        return;
    }

    results.push_back(Result(rollNo, subject, marks));

    saveResults();

    cout << "Result added successfully!" << endl;
}

void viewResults()
{
    if (results.empty())
    {
        cout << "No result records found." << endl;
        return;
    }

    cout << left << setw(10) << "Roll No"
         << setw(25) << "Subject"
         << setw(10) << "Marks"
         << setw(10) << "Grade" << endl;

    cout << "------------------------------------------------------------" << endl;

    for (const Result &r : results)
        r.display();
}

void searchResult()
{
    int rollNo;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    bool found = false;

    for (const Result &r : results)
    {
        if (r.getRollNo() == rollNo)
        {
            r.display();
            found = true;
        }
    }

    if (!found)
        cout << "Result not found." << endl;
}

void resultMenu()
{
    int choice;

    do
    {
        cout << endl;
        cout << "===== RESULT MANAGEMENT =====" << endl;
        cout << "1. Add Result" << endl;
        cout << "2. View Results" << endl;
        cout << "3. Search Result" << endl;
        cout << "4. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addResult(); break;
            case 2: viewResults(); break;
            case 3: searchResult(); break;
            case 4: break;
            default: cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);
}

// ==================== FEES MANAGEMENT ====================

void addFees()
{
    int rollNo;
    double total, paid;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    for (const Fees &f : feesList)
    {
        if (f.getRollNo() == rollNo)
        {
            cout << "Fees record already exists!" << endl;
            return;
        }
    }

    cout << "Enter Total Fees: ";
    cin >> total;

    cout << "Enter Paid Fees: ";
    cin >> paid;

    if (total <= 0)
    {
        cout << "Total fees must be greater than 0." << endl;
        return;
    }

    if (paid < 0 || paid > total)
    {
        cout << "Invalid paid fees." << endl;
        return;
    }

    feesList.push_back(Fees(rollNo, total, paid));

    saveFees();

    cout << "Fees record added successfully!" << endl;
}

void viewFees()
{
    if (feesList.empty())
    {
        cout << "No fees records found." << endl;
        return;
    }

    cout << left << setw(10) << "Roll No"
         << setw(15) << "Total Fees"
         << setw(15) << "Paid Fees"
         << setw(15) << "Remaining"
         << setw(12) << "Status" << endl;

    cout << "----------------------------------------------------------------" << endl;

    for (const Fees &f : feesList)
        f.display();
}

void searchFees()
{
    int rollNo;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    for (const Fees &f : feesList)
    {
        if (f.getRollNo() == rollNo)
        {
            f.display();
            return;
        }
    }

    cout << "Fees record not found." << endl;
}

void feesMenu()
{
    int choice;

    do
    {
        cout << endl;
        cout << "===== FEES MANAGEMENT =====" << endl;
        cout << "1. Add Fees" << endl;
        cout << "2. View Fees" << endl;
        cout << "3. Search Fees" << endl;
        cout << "4. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addFees(); break;
            case 2: viewFees(); break;
            case 3: searchFees(); break;
            case 4: break;
            default: cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);
}

// ==================== MAIN ====================

int main()
{
    loadAllData();

    int choice;

    do
    {
        cout << endl;
        cout << "============================================" << endl;
        cout << "         COLLEGE MANAGEMENT SYSTEM          " << endl;
        cout << "============================================" << endl;

        cout << "1. Student Management" << endl;
        cout << "2. Faculty Management" << endl;
        cout << "3. Course Management" << endl;
        cout << "4. Attendance Management" << endl;
        cout << "5. Result Management" << endl;
        cout << "6. Fees Management" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                studentMenu();
                break;

            case 2:
                facultyMenu();
                break;

            case 3:
                courseMenu();
                break;

            case 4:
                attendanceMenu();
                break;

            case 5:
                resultMenu();
                break;

            case 6:
                feesMenu();
                break;

            case 7:
                saveAllData();
                cout << "Data saved successfully." << endl;
                cout << "Thank you for using College Management System!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}