// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

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
        print("Error: Invalid choice. Please enter a number fr

#include <iostream>
using namespace std;

