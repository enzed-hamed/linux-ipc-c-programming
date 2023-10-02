# Linux Interprocess Communication projects In C
A Collection of simple c programs to play with Interprocess Communication. In these projects I experiment with ***Semaphores***, ***Shared Memory***, ***Concurrency***, etc.


### signal_handler-forking
This is a single `c` code to practice signal handling and multi-processing. Main function spawns into two processes. Then custom signal handlers are defined and registered for signal ***SIGUSR1*** for both parrent and child process. Finally two processes communicate and exit.

###
