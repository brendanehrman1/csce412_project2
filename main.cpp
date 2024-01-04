#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
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

    filesystem::remove(logfile);
    loadbalancer* lb = new loadbalancer(logfile);

    for (int i = 0; i < num_server; i++) {
        webserver* server = new webserver();
        lb->add_server(server);
    }
    
    for (int i = 0; i < num_initial_request; i++) {
        request* initial_request = new request();
        lb->add_request(initial_request);
    }

    for (int i = 0; i < num_clockcycle; i++) {
        if (rand() % 100 < 20) {
            request* rand_request = new request();
            lb->add_request(rand_request);
        }
        lb->update();
        if (i % 1000 == 0) {
            system("CLS");
            lb->print();
        }
    }

    for (int i = 0; i < num_server; i++) {
        delete lb->remove_server();
    }

    delete lb;

    return 0;

}