#include <iostream>
using namespace std;

void inputData(float defects[3][7]) {
    cout << "Enter defect percentage for each shift (3 shifts) over 7 days:\n";
    for (int shift = 0; shift < 3; shift++) {
        cout << "Shift " << shift + 1 << ":\n";
        for (int day = 0; day < 7; day++) {
            cout << "  Day " << day + 1 << ": ";
            cin >> defects[shift][day];
        }
    }
}

void avgDefectsPerShift(float defects[3][7], float avgShift[3]) {
    for (int shift = 0; shift < 3; shift++) {
        float sum = 0;
        for (int day = 0; day < 7; day++) {
            sum += defects[shift][day];
        }
        avgShift[shift] = sum / 7.0;
    }
}

void avgDefectsPerDay(float defects[3][7], float avgDay[7]) {
    for (int day = 0; day < 7; day++) {
        float sum = 0;
        for (int shift = 0; shift < 3; shift++) {
            sum += defects[shift][day];
        }
        avgDay[day] = sum / 3.0;
    }
}

void identifyCriticalShifts(float avgShift[3]) {
    cout << "\nCritical shifts with average defects > 10%:\n";
    bool found = false;
    for (int shift = 0; shift < 3; shift++) {
        if (avgShift[shift] > 10.0) {
            cout << "Shift " << shift + 1 << " with average defect: " << avgShift[shift] << "%\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No critical shifts found.\n";
    }
}

int main() {
    float defects[3][7], avgShift[3], avgDay[7];

    inputData(defects);
    avgDefectsPerShift(defects, avgShift);
    avgDefectsPerDay(defects, avgDay);

    cout << "\nAverage defect percentages per shift:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Shift " << i + 1 << ": " << avgShift[i] << "%\n";
    }

    cout << "\nAverage defect percentages per day:\n";
    for (int i = 0; i < 7; i++) {
        cout << "Day " << i + 1 << ": " << avgDay[i] << "%\n";
    }

    identifyCriticalShifts(avgShift);

    return 0;
}
