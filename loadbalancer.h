/**
 * @file loadbalancer.h
 * @brief Header file for the LoadBalancer class.
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "request.h"
#include "requestqueue.h"
#include "webserver.h"
using namespace std;

class loadbalancer {
    private:
        requestqueue* request_q;
        vector<webserver*> servers;
        string logfile;
        int clockcycle;

    public:
        /**
         * @brief Constructor for the LoadBalancer class.
         * @param logfile The path to the log file.
         */
        loadbalancer(string logfile);
 
        /**
         * @brief Destructor for the LoadBalancer class.
         */
        ~loadbalancer();

        /**
         * @brief Updates the load balancer, assigning requests to servers and logging activities.
         * @see webserver::get_request()
         * @see webserver::update()
         * @see requestqueue::pop()
         * @see requestqueue::push()
         */
        void update();

        /**
         * @brief Adds a request to the load balancer's request queue.
         * @param request The request to be added.
         * @see requestqueue::push()
         */
        void add_request(request* request);

        /**
         * @brief Adds a server to the load balancer's list of servers.
         * @param server The server to be added.
         */
        void add_server(webserver* server);

        /**
         * @brief Removes and returns the last server from the load balancer's list of servers.
         * @return The removed server.
         */
        webserver* remove_server();

        /**
         * @brief Prints the status of servers in the load balancer.
         * @see webserver::get_request()
         */
        void print();
};

#endif