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
        int clockcycle;
        int num_servers;

    public:
        /**
         * @brief Constructor for the LoadBalancer class.
         * @param num_server The number of running servers.
         */
        loadbalancer(int num_server);
 
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
         * @brief Provides the current number of requests in the requestqueue
         * @see requestqueue::get_size()
         */
        int get_request_size();
};

#endif