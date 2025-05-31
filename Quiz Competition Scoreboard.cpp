#include <iostream>
using namespace std;

void inputScores(int scores[6][4]) {
    for (int team = 0; team < 6; team++) {
        cout << "Enter scores for Team " << team + 1 << ":\n";
        for (int round = 0; round < 4; round++) {
            cout << "  Round " << round + 1 << ": ";
            cin >> scores[team][round];
        }
    }
}

void calculateTotals(int scores[6][4], int total[6]) {
    for (int team = 0; team < 6; team++) {
        total[team] = 0;
        for (int round = 0; round < 4; round++) {
            total[team] += scores[team][round];
        }
    }
}

void findWinners(int total[6], int& winner, int& runner) {
    int max1 = -1, max2 = -1;
    winner = -1;
    runner = -1;
    for (int i = 0; i < 6; i++) {
        if (total[i] > max1) {
            max2 = max1;
            runner = winner;
            max1 = total[i];
            winner = i;
        }
        else if (total[i] > max2) {
            max2 = total[i];
            runner = i;
        }
    }
}

void findLowScorers(int scores[6][4]) {
    cout << "\nTeams that scored 10 or less in any round:\n";
    for (int team = 0; team < 6; team++) {
        bool low = false;
        for (int round = 0; round < 4; round++) {
            if (scores[team][round] <= 10) {
                low = true;
                break;
            }
        }
        if (low) {
            cout << "Team " << team + 1 << "\n";
        }
    }
}

int main() {
    int scores[6][4];
    int total[6];
    int winner, runner;

    inputScores(scores);
    calculateTotals(scores, total);
    findWinners(total, winner, runner);

    cout << "\n--- Total Scores ---\n";
    for (int i = 0; i < 6; i++) {
        cout << "Team " << i + 1 << ": " << total[i] << "\n";
    }

    cout << "\nWinner: Team " << winner + 1;
    cout << "\nRunner-Up: Team " << runner + 1 << "\n";

    findLowScorers(scores);

    return 0;
}
