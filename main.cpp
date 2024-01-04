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

    loadbalancer* lb = new loadbalancer(logfile);

    for (int i = 0; i < num_server; i++) {
        webserver* server = new webserver();
        lb->add_server(server);
        cout << "ADDED SERVER" << endl;
    }
    
    for (int i = 0; i < num_initial_request; i++) {
        request* r = new request();
        lb->add_request(r);
        cout << "ADDED REQUEST" << endl;
    }

    for (int i = 0; i < num_clockcycle; i++) {
        lb->update();
        cout << "UPDATED " << i << endl;
        // system("CLS");
        // lb.print();
    }

    for (int i = 0; i < num_server; i++) {
        delete lb->remove_server();
    }

    delete lb;

    return 0;

}