# DSA_assignment1
Overview
This repository contains three separate implementations:

CPU Process Scheduling Algorithm: A linked list-based implementation that simulates CPU scheduling, where processes cycle through CPU time slots until they complete.

Enhanced CPU Process Scheduling with Dynamic Process Insertion: An extension of the first task, allowing for the insertion of new processes into the scheduling queue while the scheduler is running.

1024-bit Number Primality Test using Linked List: A program that stores a 1024-bit number across multiple nodes of a linked list and checks whether the number is prime.

Approach
1. CPU Process Scheduling Algorithm
Linked List Representation: Each process is represented as a node in a circular linked list. The list cycles through each node, allocating CPU time to each process until it completes its execution.
Time Slice Mechanism: The scheduler assigns a fixed time slice (time quantum) to each process. After each cycle, the remaining execution time of the process is updated.
Process Removal: Once a process completes (remaining time becomes 0), it is removed from the linked list.
Output: The program outputs the state of each process after each cycle, showing the remaining time for each process.
2. Enhanced CPU Process Scheduling with Dynamic Process Insertion
New Process Insertion: Extends the basic process scheduling algorithm by allowing users to insert new processes during the execution of the scheduler.
Circular Linked List: The new process is added to the end of the circular linked list, seamlessly integrating with the existing processes.
User Interaction: After each cycle, the user is prompted to add a new process if desired, ensuring that the new process immediately participates in the scheduling cycle.
3. 1024-bit Number Primality Test using Linked List
Big Number Storage: A 1024-bit number is split into chunks and stored across multiple nodes of a linked list. Each node holds a part of the large number (up to 64 bits).
Prime Test: The program checks whether the entire 1024-bit number is divisible by small prime numbers (up to 47) to determine if it is composite.
Modular Arithmetic: The algorithm uses modular arithmetic across the linked list to calculate the remainder when dividing the number by small primes, ensuring the primality check works across multiple nodes.
Assumptions
CPU Process Scheduling:
Each process has a unique process ID.
The scheduler assigns CPU time fairly, giving each process a fixed quantum in every cycle.
The system will stop once all processes complete.
Enhanced CPU Process Scheduling:
The user can choose to add new processes dynamically during execution.
New processes are added with their initial execution times and join the queue seamlessly.
1024-bit Number Primality Test:
The number is stored in decimal form, and each node can contain a part of the number up to 64 bits.
Primality is checked using small primes to quickly filter out composite numbers.
Challenges Faced
Process Scheduling:

Handling the removal of completed processes from the circular linked list while ensuring the structure of the list remains intact was tricky.
Maintaining fairness in time allocation while dynamically handling process arrivals required careful attention.
Primality Test:

Managing the large size of the number stored across multiple nodes, especially when performing modular arithmetic, was a challenge.
Efficiently handling the primality check without exceeding memory limits and ensuring accuracy across linked list nodes was complex.
Publicly Accessible GitHub Link
You can find the code for these tasks in this repository: GitHub Repository Link
