#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
int main ( int argc, int argv[] )
{
  std::cout << "running....\n";
  std::string gpgga[]  ={"--,$GPGGA,185177,0259.956,S,05323.639,E,1,08,0.9,545.4,M,46.9,M,,*57,",

					"--,$GPGGA,185180,0259.956,S,05323.639,E,1,08,0.9,545.4,M,46.9,M,,*5F,",

					"--,$GPGGA,185183,0259.956,S,05323.639,E,1,08,0.9,545.4,M,46.9,M,,*5C,",

					"--,$GPGGA,185186,0259.956,S,05323.639,E,1,08,0.9,545.4,M,46.9,M,,*59,",

					"--,$GPGGA,185189,0259.379,S,05324.142,E,1,08,0.9,545.4,M,46.9,M,,*5D,",

					"--,$GPGGA,185192,0259.379,S,05324.142,E,1,08,0.9,545.4,M,46.9,M,,*57,",

					"--,$GPGGA,185195,0258.102,S,05324.670,E,1,08,0.9,545.4,M,46.9,M,,*59,"

};
  try
    {
      // Create the socket
      ServerSocket server ( 30000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data="awesome stuff from the server";
		 // new_sock >> data;
		  int i=0;
		  while (i<7) {
			  data=gpgga[i];
			  new_sock << data;
			  i++;
		  }


		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
