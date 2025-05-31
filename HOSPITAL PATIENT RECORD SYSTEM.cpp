#include <iostream>
using namespace std;

void inputStatus(char status[5][7]) {
    for (int i = 0; i < 5; i++) {
        cout << "Enter status for Patient " << i + 1 << " (S/C/R for 7 days):\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> status[i][j];
        }
    }
}

void countOverallStatus(char status[5][7], int& stable, int& critical, int& recovered) {
    stable = critical = recovered = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (status[i][j] == 'S') stable++;
            else if (status[i][j] == 'C') critical++;
            else if (status[i][j] == 'R') recovered++;
        }
    }
}

void criticalDaysPerPatient(char status[5][7], int criticalCount[5]) {
    for (int i = 0; i < 5; i++) {
        criticalCount[i] = 0;
        for (int j = 0; j < 7; j++) {
            if (status[i][j] == 'C') {
                criticalCount[i]++;
            }
        }
    }
}

int main() {
    char status[5][7];
    int stable, critical, recovered;
    int criticalCount[5];

    inputStatus(status);
    countOverallStatus(status, stable, critical, recovered);
    criticalDaysPerPatient(status, criticalCount);

    cout << "\n--- Total Status Counts ---\n";
    cout << "Stable: " << stable << "\n";
    cout << "Critical: " << critical << "\n";
    cout << "Recovered: " << recovered << "\n";

    cout << "\n--- Critical Days Per Patient ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "Patient " << i + 1 << ": " << criticalCount[i] << " days\n";
    }

    return 0;
}
