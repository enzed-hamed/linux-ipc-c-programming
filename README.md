# Linux Interprocess Communication projects In C
A Collection of simple c programs to play with Interprocess Communication. In these projects I experiment with ***Semaphores***, ***Shared Memory***, ***Concurrency***, etc. All of the programs can be compiled using a standard ***C*** compiler e.g. gcc.


### parrent-child ipc
This is a single ***C*** program to practice signal handling and multi-processing. Main function spawns into two processes. Then custom signal handlers are defined and registered for signal ***SIGUSR1*** for both parrent and child process. Finally two processes communicate and exit.

### consumer-producer ipc
In this project we have two seperate ***C*** programs that communicate with each other upon executing. ***Producer*** Generates a random code which stores on ***secret.txt***, then signals the ***consumer*** and goes to sleep. ***Consumer*** reads the secret and signals the ***Producer*** and goes to sleep. This continues until programs are terminated.

### consumer-producer shared memory
The ***producer*** program generates a random code and puts it into shared memory object, and calles the ***Consumer*** and goes to sleep. ***Consumer*** reads and prints out the secret from shared memory and wakes up the ***producer*** before going to sleep.

### upper-bouncer semaphore
The header file defines some global parameters and a buffer structure. `pshm_ucase_send` program takes two command-line argument, name of the memory share and the text to put into memory respectively. Then declares and maps memory to hold the structure containing two unnamed semaphores and text. In this project we are effectively using semaphore lock-release mechanism to replace signalling in order to implement ipc. First program does its job releases second semaphore, locks on the first one. Upon release of second semamphore, second program becomes active, does its job, releases first semaphore and locks on the second one. Here the task of second program is to flip the case of text in the shared memory. It receives shared memory name as its only command-line argument.
