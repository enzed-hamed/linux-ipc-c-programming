# Linux Interprocess Communication projects In C
A Collection of simple c programs to play with Interprocess Communication. In these projects I experiment with ***Semaphores***, ***Shared Memory***, ***Concurrency***, etc. All of the programs can be compiled using a standard ***C*** compiler e.g. gcc.


### parrent-child ipc
This is a single ***C*** program to practice signal handling and multi-processing. Main function spawns into two processes. Then custom signal handlers are defined and registered for signal ***SIGUSR1*** for both parrent and child process. Finally two processes communicate and exit.

### consumer-producer ipc
In this project we have two seperate ***C*** program that communicate with each other upon executing. ***Producer*** Generates a random code which stores on """secret.txt""", then signals the ***consume*** and goes to sleep. ***Consumer*** reads the secret and signals the ***Producer*** and goes to sleep. This continues until programs are terminated.
