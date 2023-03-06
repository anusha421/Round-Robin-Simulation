#include <bits/stdc++.h>
using namespace std;

class Request {
    public:
        int process_id;
        string name;
        char person;
        int atime;
        int btime;
        int remaining_time;

        Request() {}
        Request(int process_id, string name, char person, int atime, int btime) {
            this->process_id = process_id;
            this->name = name;
            this->person = person;
            this->atime = atime;
            this->btime = btime;
            this->remaining_time = atime;
        }
};

class RoundRobin {
    private:
        // time quantum
        int time_slice;

        // student and teacher queues
        queue<Request> qS;
        queue<Request> qT;

        // current time
        int cur;

    public:
        RoundRobin(int time_slice, Request requests[]) {
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
    Request data[requests];

    // Ask user for input
    for(int i = 0; i < requests; i++) {
        int id = (i + 1);

        string name;
        cout << "Enter your name: ";
        cin >> name;

        int atime = 0;
        do
        {
            cout << "Enter arrival time (HHMM) between 1000 and 1200: ";
            cin >> atime;
        }
        while (atime < 1000 || atime > 1200);

        int btime = 0;
        do
        {
            cout << "Enter burst time (in minutes): ";
            cin >> btime;
        }
        while(btime > 120 || btime <= 0);

        char person;
        do
        {
            cout << "Select student (s/S) or teacher (t/T): ";
            cin >> person;
        }
        while(person != 's' && person != 't' && person != 'S' && person != 'T');

        Request obj(id, name, person, atime, btime);
        data[i] = obj;

        cout << '\n';
    }

    // Create scheduler object
    RoundRobin scheduler(tq, data);

    // Display data
    cout << "Process ID: " << "      " << "Name: " << "      " << "Arrival Time" << "      " << "Burst Time: " << "      " << "Student/Teacher" << '\n';

    for(int i = 0; i < requests; i++) {
        cout << data[i].process_id << "      " << data[i].name << "      " << data[i].atime << "      " << data[i].btime << "      " << data[i].person << '\n';
    }

    return 0;
}