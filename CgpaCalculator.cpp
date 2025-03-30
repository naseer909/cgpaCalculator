#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
// Function to get grade points based on grade
double getGradePoints(const string &grade) {
 map<string, double> gradePoints = {
 {"A", 4.0},
 {"B+", 3.5},
 {"B", 3.0},
 {"C+", 2.5},{"C", 2.0},
 {"D+", 1.5},
 {"D", 1.0},
 {"F", 0.0}
 };
 return gradePoints[grade];
}
// Function to calculate GPA for a semester
double calculateGPA(const vector<pair<double, string>> &courses) {
 double totalCredits = 0;
 double totalGradePoints = 0;for (auto &course : courses) {
 double credits = course.first;
 string grade = course.second;
 double gradePoints = getGradePoints(grade);
 totalCredits += credits;
 totalGradePoints += credits * gradePoints;
 }
 return (totalCredits > 0) ? totalGradePoints / totalCredits : 0;
}
// Function to calculate CGPA across multiple semesters
double calculateCGPA(const vector<vector<pair<double, string>>> &semesters) {
 double totalCredits = 0;
 double totalGradePoints = 0;
 for (auto &semester : semesters) {
 double gpa = calculateGPA(semester);
 double semesterCredits = 0;
 for (auto &course : semester) {
 semesterCredits += course.first;
 }
 totalCredits += semesterCredits;
 totalGradePoints += gpa * semesterCredits;
 }
 return (totalCredits > 0) ? totalGradePoints / totalCredits : 0;
}
int main() {
 int numSemesters;
 cout << "Enter the number of semesters: ";
 cin >> numSemesters;
 vector<vector<pair<double, string>>> semesters; // To store courses of each semester
 for (int i = 0; i < numSemesters; ++i) {
 int numCourses;
 cout << "Enter the number of courses in semester " << i + 1 << ": ";
 cin >> numCourses;
 vector<pair<double, string>> courses; // To store each course's credits and grade
 for (int j = 0; j < numCourses; ++j) {
 double credits;
 string grade;
 cout << "Enter the credits for course " << j + 1 << ": ";
 cin >> credits;
 cout << "Enter the grade for course " << j + 1 << ": ";
 cin >> grade;
 courses.push_back({credits, grade});
 }
 semesters.push_back(courses); // Add the current semester's courses to the semesters list
 }
 // Calculate CGPA
 double cgpa = calculateCGPA(semesters);
  cout << "Your Cumulative Grade Point Average (CGPA) is: " << cgpa << endl;
 return 0;
}
