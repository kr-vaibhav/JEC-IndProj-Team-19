Assignment 2
1. Multi threading
Multi-Threaded Programming With POSIX Threads (villanova.edu)
Multithreading in C++ - GeeksforGeeks
Advanced Programming in the UNIX Environment, 3rd Edition-Chapter 11,12
std::thread - cppreference.com
Tasks:
Report submission:
(5 marks)
1. Submit self-learning notes for revision and future reference on the topics mentioned
here.
Code submission:
(5+5 marks)
1. Do the earlier assignment exercises in multithreaded manner.
2. Try to extend to task for tracker.
Create a tracker program(which is multi-threaded server which saves information about
files provided by peers(in future) with format(which will be discussed) and write in a file,
and read it on demand and provide to a peer on request). This will be explained on what
to implement.
Message from every peer it connects first time to tracker
Peername:Password:UserId:PortNo
Save it a file which managed by tracker
Commandline input
Peer.cpp
Waiting for input
Register
Peername:Password:UserId:PortNo
Print if success
Waiting for input
Get my details (prints details saved in tracker file)
