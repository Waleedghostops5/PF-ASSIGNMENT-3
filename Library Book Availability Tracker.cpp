#include <iostream>
using namespace std;

void inputStatus(char books[5][5]) {
    cout << "Enter book status for 5 shelves and 5 books each (A=Available, I=Issued, M=Missing):\n";
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ": ";
        for (int j = 0; j < 5; j++) {
            char c;
            do {
                cin >> c;
                if (c != 'A' && c != 'I' && c != 'M') {
                    cout << "Invalid input, enter A, I, or M only.\n";
                }
            } while (c != 'A' && c != 'I' && c != 'M');
            books[i][j] = c;
        }
    }
}

void displayStatus(char books[5][5]) {
    cout << "\nLibrary Book Status:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ": ";
        for (int j = 0; j < 5; j++) {
            cout << books[i][j] << ' ';
        }
        cout << endl;
    }
}

void countStatus(char books[5][5], int& available, int& issued, int& missing) {
    available = issued = missing = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            if (books[i][j] == 'A') available++;
            else if (books[i][j] == 'I') issued++;
            else if (books[i][j] == 'M') missing++;
        }
}

void findShelvesMaxMissing(char books[5][5]) {
    int maxMissing = 0;
    int missingCount[5] = { 0 };

    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (books[i][j] == 'M') count++;
        }
        missingCount[i] = count;
        if (count > maxMissing)
            maxMissing = count;
    }

    cout << "\nShelf(s) with highest missing books (" << maxMissing << "): ";
    for (int i = 0; i < 5; i++) {
        if (missingCount[i] == maxMissing)
            cout << (i + 1) << " ";
    }
    cout << endl;
}

int main() {
    char library[5][5];
    int availableBooks, issuedBooks, missingBooks;

    inputStatus(library);
    displayStatus(library);
    countStatus(library, availableBooks, issuedBooks, missingBooks);

    cout << "\nTotal Available: " << availableBooks;
    cout << "\nTotal Issued: " << issuedBooks;
    cout << "\nTotal Missing: " << missingBooks << endl;

    findShelvesMaxMissing(library);

    return 0;
}
