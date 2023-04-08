# Round Robin Simulation
Round robin simulation using two queues alternately.

### Problem Statement
Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. 
Since there can be multiple requests at any time, he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. 
He will log into the system from 10am to 12am only. He wants to have separate requests queues for students and faculty.
Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries and average query time.
​
### Approach
A structure (Process) is used to store every request.
These requests are loaded into their respective queues i.e. teacher(q1) and student(q2) queue.
These requests are then loaded into an Arrival Time (AT) queue which indicates the next process to be loaded.


#### struct Process
Attributes provided are:
+ id - unique process id starting from 100
+ priority - teacher or student
+ arrivalTime - time when request arrived
+ burstTime - total time for request
+ remainingTime - time reamining for each request (initially set to burstTime)

#### Flags 

2 flags are used

+ queueFlag indicating teacher(1) or student(0). 
+ idle indicating if a process is running(1) or not(0).  

#### Variables
+ currentTime - indicates a particular instant of time
+ queryTime - total time queries have been scheduled


### Functions
2 functions are used:
+ createProcess() returns a vector of Process time.  
In this function each request (process) is created from user inputs.
+ setArrivalTimeQueue takes to parameters; a queue with Process objects and a vector with Process objects.  
This function sorts the given vector and then pushes it into the queue.  

These two functions are used in the beginning of the main function. 


### Scheduling

Scheduling is done while the total time is less than 2 hours and any of the queues are not empty and idle is not 0.
First both the processes are loaded into their queues from the AT queue.
If the system is in an idle state (no process running) then we will check if q1 or q2 is empty.
Depending on these conditions, a new process will start running and queueFlag and idle will be updated.
If the system is STILL idle then there is no process at this point of time and the loop will continue to the next iteration while also updating the current time.

Here, the scheduling will start. A time slice is taken by selecting minimum of time quantum and the remaining time of the current process.
If the current time + time slice is greater than 120 then this is the last process and it can not be completed so the loop will end here itself. If not then current time is updated.
Now the AT queue is re-loaded and the total query time updated.
If the remaining time is zero then the process has been completed and a new current process is re allocated by checking the empty queues and the queueFlag again.
If the remaining time is not zero then the process is almost similar the only exception being that the same process is not popped completely instead its pushed back into its queue with updated remaining time.


### Conclusion
At the end of the program, the completion time of each process is added. The total query time and the average query time is displayed.