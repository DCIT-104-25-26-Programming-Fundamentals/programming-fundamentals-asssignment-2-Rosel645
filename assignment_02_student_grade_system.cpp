// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// =============================================================================
//
// TASK: Student Grade System
//
// Write a C++ program that reads a student's score and outputs the
// corresponding letter grade based on the scale below.
//
// Grading Scale:
//   Score 80 – 100  →  Grade A
//   Score 70 – 79   →  Grade B
//   Score 60 – 69   →  Grade C
//   Score 50 – 59   →  Grade D
//   Score below 50  →  Grade F
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter student score (0-100): 85
//   Grade: A
//
//   Enter student score (0-100): 73
//   Grade: B
//
//   Enter student score (0-100): 45
//   Grade: F
//
//   Enter student score (0-100): 110
//   Error: Score must be between 0 and 100.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST use functions (see scaffold below).
// - Validate the score inside getGrade(). If it is out of range, return '\0'
//   (null character) and let main() print the error message.
// - Use if / else if / else to determine the grade.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
#include <string>

using namespace std;

// Function to determine the grade
string get_grade(float n)
{
    if (n < 0 || n > 100)
    {
        return "INVALID";
    }
    else if (n >= 80)
    {
        return "A";
    }
    else if (n >= 70 && n <= 79)
    {
        return "B";
    }
    else if (n >= 60 && n <= 69)
    {
        return "C";
    }
    else if (n >= 50 && n <= 59)
    {
        return "D";
    }
    else
    {
        return "F";
    }
}

int main()
{
    float number;

    cout << "==============================" << endl;
    cout << "      GRADE CALCULATOR" << endl;
    cout << "==============================" << endl;

    cout << "Enter score: ";
    cin >> number;

    string final_grade = get_grade(number);

    if (final_grade == "INVALID")
    {
        cout << "Invalid input, try again." << endl;
    }
    else if (final_grade == "A")
    {
        cout << "Grade: A 'PERFECT'" << endl;
    }
    else if (final_grade == "B")
    {
        cout << "Grade: B 'GOOD'" << endl;
    }
    else if (final_grade == "C")
    {
        cout << "Grade: C 'AVERAGE'" << endl;
    }
    else if (final_grade == "D")
    {
        cout << "Grade: D 'BAD'" << endl;
    }
    else
    {
        cout << "Grade: F 'FAIL'" << endl;
    }

    return 0;
}
