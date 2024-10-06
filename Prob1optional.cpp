#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Process {
    string processId;
    int totalDuration;
    int timeRemaining;
    Process* nextProcess;
};

class Scheduler {
public:
    Process* currentProcess;

    Scheduler() {
        currentProcess = nullptr;
    }

    void insertProcess(Process* newProcess) {
        if (currentProcess == nullptr) {
            currentProcess = newProcess;
            newProcess->nextProcess = newProcess;
        } else {
            Process* temp = currentProcess;
            while (temp->nextProcess != currentProcess) {
                temp = temp->nextProcess;
            }
            temp->nextProcess = newProcess;
            newProcess->nextProcess = currentProcess;
        }
    }

    void showCurrentProcesses(int cycle) {
        if (currentProcess == nullptr) {
            return;
        }
        cout << "Cycle " << cycle << ": ";
        Process* temp = currentProcess;
        do {
            cout << temp->processId << " (Remaining: " << temp->timeRemaining << "), ";
            temp = temp->nextProcess;
        } while (temp != currentProcess);
        cout << endl;
    }

    void executeProcesses(int timeQuantum) {
        if (currentProcess == nullptr) return;

        int cycle = 1;  

        while (currentProcess != nullptr) {
            Process* processBeingExecuted = currentProcess;
            bool cycleComplete = false;

            while (true) {
                if (processBeingExecuted->timeRemaining > 0) {
                    int timeExecuted = min(processBeingExecuted->timeRemaining, timeQuantum);
                    processBeingExecuted->timeRemaining -= timeExecuted;
                }

                processBeingExecuted = processBeingExecuted->nextProcess;

                if (processBeingExecuted == currentProcess) {
                    cycleComplete = true;
                    break;
                }
            }

            showCurrentProcesses(cycle); 
            cycle++;

            Process* temp = currentProcess;
            Process* prev = nullptr;

            do {
                if (temp->timeRemaining <= 0) {
                    if (prev) {
                        prev->nextProcess = temp->nextProcess;
                    } else {
                        if (temp->nextProcess == currentProcess) {
                            currentProcess = nullptr;
                        } else {
                            currentProcess = temp->nextProcess;
                            Process* lastProcess = currentProcess;
                            while (lastProcess->nextProcess != temp) {
                                lastProcess = lastProcess->nextProcess;
                            }
                            lastProcess->nextProcess = currentProcess;
                        }
                    }
                    delete temp;
                    temp = (prev) ? prev->nextProcess : currentProcess;
                    continue;
                }
                prev = temp;
                temp = temp->nextProcess;
            } while (temp != currentProcess);


            if (currentProcess == nullptr) {
                cout << "All processes have been completed." << endl;
                break;
            }

            char addProcess;
            cout << "Would you like to add a new process? (y/n): ";
            cin >> addProcess;

            if (addProcess == 'y' || addProcess == 'Y') {
                int newProcessDuration;
                cout << "Enter duration for the new process: ";
                cin >> newProcessDuration;
                insertProcess(new Process{"P" + to_string(rand() % 100 + 1), newProcessDuration, newProcessDuration, nullptr});
                cout << "New process added to the queue." << endl;
            }
        }
    }
};

int main() {
    Scheduler taskManager;
    int initialProcessCount;

    cout << "Enter the number of initial processes: ";
    cin >> initialProcessCount;

    cout << "Initial Processes:";
    for (int i = 0; i < initialProcessCount; i++) {
        int processDuration;
        cout << "\nEnter the duration for Process P" << (i + 1) << ": ";
        cin >> processDuration;
        // if (i > 0) {
        //     cout << ", ";
        // }
        cout << "(P" << (i + 1) << ", " << processDuration << ")";
        taskManager.insertProcess(new Process{"P" + to_string(i + 1), processDuration, processDuration, nullptr});
    }
    cout<< endl;

    int timeQuantum;
    cout << "Enter time quantum for each process: ";
    cin >> timeQuantum;
    cout << "CPU Time per Process per Cycle: " << timeQuantum << endl;

    taskManager.executeProcesses(timeQuantum);

    return 0;
}
