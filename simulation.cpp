#include <bits/stdc++.h>
using namespace std;

class Request {
    string name;
    string person;
    string time;
    string remaining_time;

    public:
        Request(string name, string person, string time) {
            this->name = name;
            this->person = person;
            this->time = time;
            this->remaining_time = time;
        }
};

class RoundRobin {
    private:
        int time_slice;
        queue<Request> qS;
        queue<Request> qT;
        // current time
        int cur;

    public:
        RoundRobin(int time_slice, string requests[][5]) {
            this->time_slice = time_slice;
            // this->requests = requests
        }

};

int main() {

    // Enter time slice
    int tq;
    cout << "Enter time for each appointment: ";
    cin >> tq;

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

        transform(data[i][4].begin(), data[i][4].end(), data[i][4].begin(), ::tolower);

        Request(data[i][1], data[i][4], data[i][3]);

        cout << '\n';
    }

    // Create scheduler object
    RoundRobin scheduler(tq, data);

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