/*! \mainpage Load Balancer
 *
 * \section intro_sec Introduction
 *
 * Our documentation for the load balancer project.
 * 
 */

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
 * @brief Simulates load balancer with specified number of servers and clock cycles.
 * @return 0 if successful
 * @see std::stoi()
 * @see loadbalancer::add_server()
 * @see loadbalancer::add_request()
 * @see loadbalancer::update()
 * @see loadbalancer::remove_server()
 */
int main(int argc, char* argv[]) {
    // Check if the correct number of command line arguments is provided
    if (argc < 3) {
        std::cout << "Usage: ./main <num_server> <num_clockcycle> <request_rate?>" << std::endl;
        return 1;
    }

    // Parse command line arguments
    int num_server = stoi(argv[1]);
    int num_clockcycle = stoi(argv[2]);
    double rate = 0.2;
    if (argc == 4)
        rate = stof(argv[3]);
    int num_initial_request = num_server * 20;
    int time_lower = 4;
    int time_upper = 100;
    
    cout << "Initial Request Queue Size: " << num_initial_request << endl;
    cout << "Request Time Range: [" << time_lower << ", " << time_upper << ")" << endl;

    // Create a load balancer instance and add servers
    loadbalancer* lb = new loadbalancer(num_server);
    
    // Add specified number of initial requests to the load balancer
    for (int i = 0; i < num_initial_request; i++) {
        request* initial_request = new request(time_lower, time_upper);
        lb->add_request(initial_request);
    }

    // Simulate the specified number of clock cycles
    for (int i = 0; i < num_clockcycle; i++) {
        // Introduce new requests randomly with a probability specified by the user
        if ((double)rand() / RAND_MAX < rate) {
            request* rand_request = new request(time_lower, time_upper);
            lb->add_request(rand_request);
        }
        // Update the load balancer's state for each clock cycle
        lb->update();
    }

    cout << "Final Request Queue Size: " << lb->get_request_size() << endl;

    delete lb;

    return 0;
}