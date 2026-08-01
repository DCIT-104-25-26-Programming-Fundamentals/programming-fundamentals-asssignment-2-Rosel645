// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>

def add_student():
    name = input("Student name: ")
    student_id = input("Student ID: ")

    scores = []

    number_of_scores = int(input("How many scores? "))

    for i in range(number_of_scores):
        score = float(input("Enter score " + str(i + 1) + ": "))
        scores.append(score)

    student = {
        "name": name,
        "id": student_id,
        "scores": scores
    }

    students.append(student)

    print('Student "' + name + '" added successfully.')



def display_students():

    if len(students) == 0:
        print("No students have been added yet.")
        return

    print("\n--------------------------------------------------------------")
    print("Name\t\tID\t\tScores\t\tAverage")
    print("--------------------------------------------------------------")

    for student in students:
        total = sum(student["scores"])
        average = total / len(student["scores"])

        score_list = ""

        for i in range(len(student["scores"])):
            score_list += str(student["scores"][i])

            if i != len(student["scores"]) - 1:
                score_list += ", "

        print(student["name"], "\t", student["id"], "\t", score_list, "\t", round(average, 2))

    print("--------------------------------------------------------------")



def calculate_average():

    student_id = input("Enter student ID: ")

    found = False

    for student in students:

        if student["id"] == student_id:

            average = sum(student["scores"]) / len(student["scores"])

            print(student["name"] + "'s average score:", round(average, 2))

            found = True
            break

    if found == False:
        print("Error: Student ID not found.")



def show_menu():
    print("\n================================")
    print("   STUDENT RECORD SYSTEM MENU")
    print("================================")
    print("1. Add student")
    print("2. Display all students")
    print("3. Calculate average score")
    print("4. Quit")



while True:

    show_menu()

    choice = input("Enter your choice (1-4): ")

    if choice == "1":
        add_student()

    elif choice == "2":
        display_students()

    elif choice == "3":
        calculate_average()

    elif choice == "4":
        print("Goodbye!")
        break

    else:
        print("Error: Invalid choice. Please enter a number from 1 to 4.")
#include <iomanip>
using namespace std;

