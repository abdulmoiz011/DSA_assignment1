#include <iostream>
using namespace std;

struct Process {
    int process_id;      
    int execution_time;  
    int remaining_time;  
    Process* next;       
};

class ProcessScheduler {
public:
    Process* head;       
    ProcessScheduler() {
        head = nullptr;  
    }


    void addProcess(int id, int exec_time) {
        Process* newProcess = new Process{id, exec_time, exec_time, nullptr};
        if (head == nullptr) {
            head = newProcess;
            newProcess->next = head;
        } else {
            Process* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newProcess;
            newProcess->next = head;
        }
    }

    void displayProcesses() {
        if (head == nullptr) {
            cout << "All processes have completed execution." << endl;
            return;
        }

        Process* temp = head;
        do {
            cout << "Process " << temp->process_id << ": Remaining time = " 
                 << temp->remaining_time << " units" << endl;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void schedule(int time_quantum) {
        if (head == nullptr) return;

        while (head != nullptr) {
            Process* current = head;
            Process* prev = nullptr;

            do {
                if (current->remaining_time > 0) {
                    int timeToRun = min(current->remaining_time, time_quantum);
                    current->remaining_time -= timeToRun;

                    cout << "Running Process " << current->process_id 
                         << " for " << timeToRun << " units. "
                         << "Remaining time: " << current->remaining_time << endl;


                    if (current->remaining_time <= 0) {
                        cout << "Process " << current->process_id << " has finished execution." << endl;
                    }
                }

                prev = current;
                current = current->next;

            } while (current != head);

            removeCompletedProcesses();

            if (head != nullptr) {
                displayProcesses();
            }
        }
    }

    void removeCompletedProcesses() {
        if (head == nullptr) return;

        Process* temp = head;
        Process* prev = nullptr;

        do {
            if (temp->remaining_time <= 0) {
                if (temp == head) {  
                    Process* tail = head;
                    while (tail->next != head) {
                        tail = tail->next;
                    }

                    if (head == head->next) { 
                        delete head;
                        head = nullptr;
                        return;
                    } else {
                        head = head->next;
                        tail->next = head;
                        delete temp;
                        temp = head;
                    }
                } else {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        } while (temp != head);
    }
};

int main() {
    ProcessScheduler scheduler;
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    for (int i = 0; i < numProcesses; i++) {
        int exec_time;
        cout << "Enter execution time for Process " << (i + 1) << ": ";
        cin >> exec_time;
        scheduler.addProcess(i + 1, exec_time);
    }

    int time_quantum;
    cout << "Enter time quantum: ";
    cin >> time_quantum;

    scheduler.schedule(time_quantum);

    return 0;
}
