#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "request.h"
#include "requestqueue.h"
#include "webserver.h"
#include "loadbalancer.h"
using namespace std;

int main (int argc, char* argv[]) {
    if (argc != 5) {
        cout << "Usage: ./main <num_server> <num_clockcycle> <num_initial_request> <logfile>" << endl;
        return 1;
    }

    int num_server = stoi(argv[1]);
    int num_clockcycle = stoi(argv[2]);
    int num_initial_request = stoi(argv[3]);
    string logfile = argv[4];

    loadbalancer lb(logfile);

    for (int i = 0; i < num_server; i++) {
        webserver server;
        lb.add_server(server);
    }
    
    for (int i = 0; i < num_initial_request; i++) {
        request request;
        lb.add_request(&request);
    }

    for (int i = 0; i < num_clockcycle; i++) {
        lb.update();
        system("CLS");
        lb.print();
    }

    return 0;

}