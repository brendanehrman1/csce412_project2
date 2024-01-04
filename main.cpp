/**
 * @file main.cpp
 * @brief CPP file for the main program.
 */
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


/**
 * @brief Simulates load balancer with specified number of servers, clock cycles, and requests.
 * @return 0 if successful
 * @see std::stoi()
 * @see loadbalancer::add_server()
 * @see loadbalancer::add_request()
 * @see loadbalancer::update()
 * @see loadbalancer::remove_server()
 */
int main(int argc, char* argv[]) {
    // Check if the correct number of command line arguments is provided
    if (argc != 5) {
        std::cout << "Usage: ./main <num_server> <num_clockcycle> <num_initial_request> <logfile>" << std::endl;
        return 1;
    }

    // Parse command line arguments
    int num_server = stoi(argv[1]);
    int num_clockcycle = stoi(argv[2]);
    int num_initial_request = stoi(argv[3]);
    string logfile = argv[4];

    // Remove existing log file (if any)
    filesystem::remove(logfile);

    // Create a load balancer instance
    loadbalancer* lb = new loadbalancer(logfile);

    // Add specified number of web servers to the load balancer
    for (int i = 0; i < num_server; i++) {
        webserver* server = new webserver();
        lb->add_server(server);
    }
    
    // Add specified number of initial requests to the load balancer
    for (int i = 0; i < num_initial_request; i++) {
        request* initial_request = new request();
        lb->add_request(initial_request);
    }

    // Simulate the specified number of clock cycles
    for (int i = 0; i < num_clockcycle; i++) {
        // Introduce new requests randomly with a probability of 20%
        if (rand() % 100 < 20) {
            request* rand_request = new request();
            lb->add_request(rand_request);
        }
        // Update the load balancer's state for each clock cycle
        lb->update();

        // Print server status every 1000 clock cycles
        if (i % 1000 == 0) {
            system("CLS"); // Clear console screen (for Windows)
            lb->print();
        }
    }

    // Clean up memory by deleting servers and load balancer instance
    for (int i = 0; i < num_server; i++) {
        delete lb->remove_server();
    }

    delete lb;

    return 0;
}