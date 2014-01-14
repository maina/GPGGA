GPGGA
=====

C++ GPGGA Processing Simulation 

This program is based on a socket with a server (acting as the GPGGA data source) and a client to process display the data served by the server. The program is based on C++ and tested only in Linux.

prompt$ cd directory_containing_the_project
prompt$ make

Above command will compile all of the files in the project, and create the simple_server and simple_client output files.

first prompt:
prompt$ ./simple_server
running....



second prompt:
prompt$ ./simple_client

After second prompt the GPGGA data read by the client from the server should display.
