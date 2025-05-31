#include <iostream>
using namespace std;

void inputMarks(int marks[][5], int students, int subjects) {
    for (int i = 0; i < students; i++) {
        cout << "Enter marks for student " << i + 1 << ":\n";
        for (int j = 0; j < subjects; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }
}

int calculateTotal(int marks[], int subjects) {
    int total = 0;
    for (int i = 0; i < subjects; i++) {
        total += marks[i];
    }
    return total;
}

float calculateAverage(int total, int subjects) {
    return total / (float)subjects;
}

char getGrade(float average) {
    if (average >= 85) return 'A';
    else if (average >= 70) return 'B';
    else if (average >= 50) return 'C';
    else return 'F';
}

int findTopScorer(int marks[][5], int students, int subjects) {
    int topIndex = 0, maxTotal = 0;
    for (int i = 0; i < students; i++) {
        int total = calculateTotal(marks[i], subjects);
        if (total > maxTotal) {
            maxTotal = total;
            topIndex = i;
        }
    }
    return topIndex;
}

int main() {
    int students = 10, subjects = 5;
    int marks[10][5];

    inputMarks(marks, students, subjects);

    cout << "\n--- Results ---\n";
    for (int i = 0; i < students; i++) {
        int total = calculateTotal(marks[i], subjects);
        float avg = calculateAverage(total, subjects);
        char grade = getGrade(avg);
        cout << "Student " << i + 1 << " - Total: " << total << ", Average: " << avg << ", Grade: " << grade << "\n";
    }

    int topScorer = findTopScorer(marks, students, subjects);
    cout << "\nTop Scorer: Student " << topScorer + 1 << "\n";

    return 0;
}
