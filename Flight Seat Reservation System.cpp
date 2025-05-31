#include <iostream>
using namespace std;

void initializeSeats(char seats[6][4]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            seats[i][j] = 'E';
        }
    }
}

void displayChart(char seats[6][4]) {
    cout << "\nSeating Chart (E = Empty, B = Booked):\n";
    for (int i = 0; i < 6; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

void bookSeat(char seats[6][4], int row, int col) {
    if (row < 1 || row > 6 || col < 1 || col > 4) {
        cout << "Invalid seat position!\n";
        return;
    }

    if (seats[row - 1][col - 1] == 'E') {
        seats[row - 1][col - 1] = 'B';
        cout << "Seat booked successfully.\n";
    }
    else {
        cout << "Seat already booked.\n";
    }
}

int countAvailableSeats(char seats[6][4]) {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (seats[i][j] == 'E') {
                count++;
            }
        }
    }
    return count;
}

int rowWithMaxEmpty(char seats[6][4]) {
    int maxEmpty = -1, rowIndex = -1;
    for (int i = 0; i < 6; i++) {
        int emptyCount = 0;
        for (int j = 0; j < 4; j++) {
            if (seats[i][j] == 'E') {
                emptyCount++;
            }
        }
        if (emptyCount > maxEmpty) {
            maxEmpty = emptyCount;
            rowIndex = i;
        }
    }
    return rowIndex;
}

int main() {
    char seats[6][4];
    int choice, row, col;

    initializeSeats(seats);

    do {
        cout << "\n--- Flight Seat Reservation Menu ---\n";
        cout << "1. Display Seating Chart\n";
        cout << "2. Book a Seat\n";
        cout << "3. Count Available Seats\n";
        cout << "4. Find Row with Most Empty Seats\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayChart(seats);
            break;
        case 2:
            cout << "Enter row (1-6): ";
            cin >> row;
            cout << "Enter column (1-4): ";
            cin >> col;
            bookSeat(seats, row, col);
            break;
        case 3:
            cout << "Total available seats: " << countAvailableSeats(seats) << endl;
            break;
        case 4:
            row = rowWithMaxEmpty(seats);
            cout << "Row with most empty seats: Row " << row + 1 << endl;
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
