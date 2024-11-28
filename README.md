# Operating System Scheduling and Memory Management Algorithms

## Overview
This repository contains implementations of various operating system scheduling algorithms, process management techniques, and memory management strategies. The code is designed to demonstrate key concepts in operating system design and provide practical examples of different algorithmic approaches.

## Algorithms Implemented

### CPU Scheduling Algorithms

#### 1. First Come First Serve (FCFS)
- Non-preemptive scheduling algorithm
- Processes are executed in the order they arrive
- Simple and fair, but can lead to convoy effect

#### 2. Shortest Job First (SJF)
##### a. Preemptive SJF
- Selects the process with the shortest expected execution time
- Can preempt currently running process if a shorter job arrives
- Minimizes average waiting time

##### b. Non-Preemptive SJF
- Selects the process with the shortest expected execution time
- Once a process starts, it runs to completion
- Optimal for batch processing systems

#### 3. Round Robin (RR)
- Preemptive scheduling algorithm
- Uses time quantum to allocate CPU
- Provides fair sharing of processor time
- Prevents process starvation

#### 4. Priority Scheduling
- Assigns priority to each process
- Can be preemptive or non-preemptive
- Supports dynamic and static priority mechanisms

### Memory Management Algorithms

#### 1. Page Replacement Algorithms
##### a. First In First Out (FIFO)
- Simplest page replacement strategy
- Replaces the oldest page in memory
- Can suffer from Belady's anomaly

##### b. Least Recently Used (LRU)
- Replaces the page that hasn't been used for the longest time
- More efficient than FIFO
- Requires tracking page usage history

### Additional Algorithms

#### Banker's Algorithm
- Deadlock avoidance algorithm
- Manages resource allocation to prevent potential deadlocks
- Ensures system remains in a safe state

## Project Structure
```
os-algorithms/
│
├── scheduling/
│   ├── fcfs.py
│   ├── sjf_preemptive.py
│   ├── sjf_non_preemptive.py
│   ├── round_robin.py
│   └── priority_scheduling.py
│
├── memory_management/
│   ├── fifo_page_replacement.py
│   └── lru_page_replacement.py
│
└── resource_management/
    └── bankers_algorithm.py
```

## Requirements
- Python 3.8+
- NumPy (optional, for advanced calculations)

## Usage
Each algorithm is implemented as a separate Python script. You can run individual scripts to see demonstrations of the algorithms.

Example:
```bash
python scheduling/fcfs.py
python memory_management/lru_page_replacement.py
```

## Contributing
1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingAlgorithm`)
3. Commit your changes (`git commit -m 'Add some algorithm'`)
4. Push to the branch (`git push origin feature/AmazingAlgorithm`)
5. Open a Pull Request

## License
This project is open-source. See the [LICENSE](LICENSE) file for details.

## Disclaimer
These implementations are for educational purposes and may not represent production-ready code. They are designed to illustrate algorithmic concepts in operating systems.

## References
- Operating System Concepts by Silberschatz, Galvin, and Gagne
- Modern Operating Systems by Andrew S. Tanenbaum
```
