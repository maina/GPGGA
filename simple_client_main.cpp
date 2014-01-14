#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<string> split(const string& s, const string& delim, const bool keep_empty = true) {
    vector<string> result;
    if (delim.empty()) {
        result.push_back(s);
        return result;
    }
    string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = search(substart, s.end(), delim.begin(), delim.end());
        string temp(substart, subend);
        if (keep_empty || !temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delim.size();
    }
    return result;
}
int main(int argc, int argv[]) {
	try {

		ClientSocket client_socket("localhost", 30000);

		std::string reply,output;

		try {
			client_socket << "Test message.";
			client_socket >> reply;
		} catch (SocketException&) {
		}
		//cout << reply;
		std::vector<std::string> arr;
		arr = split(reply, ",");
		for (size_t i = 0; i < arr.size(); i++){
			std::string token=arr[i].c_str();
			//std::cout << output;
			if(token=="--"){
				output+="\n";
				std::cout << output;
			}else{
				output+="\t"+token;

			}
		}

		;

	} catch (SocketException& e) {
		std::cout << "Exception was caught:" << e.description() << "\n";
	}

	return 0;
}
