#include <bits/stdc++.h>
using namespace std;

int main() {

    // Ask for number of requests from user
    int requests;
    cout << "Enter number of requests: ";
    cin >> requests;

    // Store data in 2D array
    string data[requests][5];

    // Ask user for input
    for(int i = 0; i < requests; i++) {
        data[i][0] = "P" + (to_string(i + 1));

        cout << "Enter your name: ";
        cin >> data[i][1];

        int atime = 0;
        do
        {
            cout << "Enter arrival time (HHMM) between 1000 and 1200: ";
            cin >> data[i][2];
            atime = stoi(data[i][2]);
        }
        while (atime < 1000 || atime > 1200);

        int btime = 0;
        do
        {
            cout << "Enter burst time (in minutes): ";
            cin >> data[i][3];
            btime = stoi(data[i][3]);
        }
        while(btime > 120 || btime <= 0);

        do
        {
            cout << "Select student (s/S) or teacher (t/T): ";
            cin >> data[i][4];
        }
        while(data[i][4] != "s" && data[i][4] != "t" && data[i][4] != "S" && data[i][4] != "T");

        cout << '\n';
    }

    // Display data
    cout << "Process ID: " << "      " << "Name: " << "      " << "Arrival Time" << "      " << "Burst Time: " << "      " << "Student/Teacher" << '\n';

    for(int i = 0; i < requests; i++) {
        for(int j = 0; j < 5; j++) {
            cout << data[i][j] << "      ";
        }
        cout << '\n';
    }

    return 0;
}