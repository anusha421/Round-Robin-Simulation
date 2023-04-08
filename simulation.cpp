// Multi Queue Round Robin

#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int priority;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int executedTime;
};

int pId = 100;

vector<Process> createProcess() {
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    // Create an array of process(obj).
    vector<Process> p(n);

    for (int i = 0; i <= n; ++i)
    {
    
        // clear screen for each input.
        system("cls"); 

        if (i == n) break;

        // allocate processId 
        p[i].id = pId++;

        cout << "Process Id : " << p[i].id << endl << "\n";

        // Take input: Arrival time, Burst time, Priority of the process.
        cout << "Enter arrivalTime [0-120]: ";
        cin >> p[i].arrivalTime;
        cout << "Enter burstTime: ";
        cin >> p[i].burstTime;
        cout << "Enter priority(1: Teacher | 0: Student): ";
        cin >> p[i].priority;

        // Set remaining time and executed time.
        p[i].remainingTime = p[i].burstTime;
        p[i].executedTime = 0;
    }

    return p;
}

void setArrivalTimeQueue(queue<Process> &AT, vector<Process> &p) {
    sort(p.begin(), p.end(), [](Process &v1, Process &v2){return v1.arrivalTime < v2.arrivalTime;});
    for(auto &it: p) {AT.push(it);}
}

int main () {

    // Teacher, Student wait queue 
    // Q1: Teacher queue. 
    // Q2: Student queue.
    queue<Process> q1, q2;

    // Arrival time
    queue<Process> AT;

    // Time quantum
    int tq;
    cout << "Enter the time quantum: ";
    cin >> tq;

    vector<Process> p = createProcess();
    setArrivalTimeQueue(AT, p);

    int idle = 1, queueFlag = 0;
    // 0 : queueFlag , Q1 queue : Teacher 
    int currentTime = 0, queryTime = 0;

    Process currentProcess = Process();

    while((!AT.empty() || !q1.empty() || !q2.empty() || !idle) && currentTime < 120) {

        // Arrival Cycle

        // Load Arrived processes 
        while(!AT.empty() && currentTime >= AT.front().arrivalTime) {
            if(AT.front().priority) {
                q1.push(AT.front());
            }
            else {
                q2.push(AT.front());
            }
            AT.pop();
        }

        if (idle) {
            if(!q1.empty() && !q2.empty()) {
                if (q1.front().arrivalTime <= q2.front().arrivalTime) {
                    currentProcess = q1.front();
                    q1.pop();
                    queueFlag = 0;
                }
                else {
                    currentProcess = q2.front();
                    q2.pop();
                    queueFlag = 1;
                }
                idle = 0;
            }
            else if (!q1.empty()) {
                currentProcess = q1.front();
                q1.pop();
                idle = 0;
                queueFlag = 0;
            }
            else if (!q2.empty()) {
                currentProcess = q2.front();
                q2.pop();
                idle = 0;
                queueFlag = 1;
            }
        }

        // Execution cycle 
        if (idle) {
            currentTime++;
            continue;
        }

        int timeSlice = min(tq, currentProcess.remainingTime);
        currentProcess.remainingTime -= timeSlice;
        currentProcess.executedTime += timeSlice;
        if(currentTime + timeSlice > 120){
            break;
        }else{
            currentTime += timeSlice;
        }

        while(!AT.empty() && currentTime >= AT.front().arrivalTime) {
            if(AT.front().priority) {
                q1.push(AT.front());
            }
            else {
                q2.push(AT.front());
            }
            AT.pop();
        }

        // Query Prcessed for timeSlice mins.
        queryTime += timeSlice;

        // Completion Cycle 
        if (currentProcess.remainingTime == 0) {

            if(currentTime <= 59) 
                cout << "Process " << currentProcess.id << " finished at time 10:" << currentTime << endl;
            else if(currentTime == 60) {
                cout << "Process " << currentProcess.id << " finished at time 11:00" << endl;
            }
            else if(currentTime > 60 && currentTime < 120)
                cout << "Process " << currentProcess.id << " finished at time 11:" << currentTime - 60 << endl;
            else
                cout << "Process " << currentProcess.id << " finished at time 12:00" << endl;

            currentProcess = Process();
            idle = 1;

            if(!q1.empty() && !q2.empty()) {
                if(queueFlag){
                    currentProcess = q1.front();
                    q1.pop();
                    queueFlag = 0;
                }else{
                    currentProcess = q2.front();
                    q2.pop();
                    queueFlag = 1;
                }
                idle = 0;
            }
            else if (!q1.empty()) {
                currentProcess = q1.front();
                q1.pop();
                idle = 0;
                queueFlag = 0;
            }
            else if (!q2.empty()) {
                currentProcess = q2.front();
                q2.pop();
                idle = 0;
                queueFlag = 1;
            }
            
        }
        else {
            if (queueFlag) {
                // Q2 Execution Done -> Now load from Q1.
                q2.push(currentProcess);

                if (!q1.empty()) {
                    currentProcess = q1.front();
                    q1.pop();
                    queueFlag = 0;
                }
                else {
                    currentProcess = q2.front();
                    q2.pop();
                }
            }
            else {
                // Q1 Execution Done -> Now load from Q2

                q1.push(currentProcess);

                if (!q2.empty()) {
                    currentProcess = q2.front();
                    q2.pop();
                    queueFlag = 1;
                } 
                else {
                    currentProcess = q1.front();
                    q1.pop();
                }
            }
        }

    }

    cout << "Total query time taken is " << queryTime << endl;
    cout << "Average query time is " << ((queryTime * 5) / 6) << "%";
    
    return 0;
}