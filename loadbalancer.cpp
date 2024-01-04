/**
 * @file loadbalancer.cpp
 * @brief CPP file for the LoadBalancer class.
 */

#include "loadbalancer.h"

/**
 * @brief Constructor for the LoadBalancer class.
 * @param logfile The path to the log file.
 */
loadbalancer::loadbalancer(int num_servers) : clockcycle(0), num_servers(num_servers) {
    request_q = new requestqueue();
    for (size_t i = 0; i < num_servers; i++) {
        webserver* server = new webserver();
        servers.push_back(server);
    }
}

/**
 * @brief Destructor for the LoadBalancer class.
 */
loadbalancer::~loadbalancer() {
    delete request_q;
}

/**
 * @brief Updates the load balancer, assigning requests to servers and logging activities.
 * @see webserver::get_request()
 * @see webserver::update()
 * @see requestqueue::pop()
 * @see requestqueue::push()
 */
void loadbalancer::update() {
    for (size_t i = 0; i < servers.size(); i++) {
        webserver* server = servers.at(i);
        if (!server)
            continue;
        request* old_request = server->get_request();
        server->update();
        if (server->is_available()) {
            if (request_q->get_size() < 15 * num_servers) {
                cout << clockcycle << " | ";
                cout << "Server " << i << " | Deleting Server..." << endl;
                delete server;
                servers.at(i) = nullptr;
                num_servers--;
            } else {
                if (request_q->get_size() > 25 * num_servers) {
                    cout << clockcycle << " | ";
                    cout << "Server " << servers.size() << " | Creating Server..." << endl;
                    webserver* server = new webserver();
                    servers.push_back(server);
                    num_servers++;
                }
                request* new_request = request_q->pop();

                if (old_request) {
                    cout << clockcycle << " | ";
                    cout << "Server " << i << " | ";
                    cout << "Request Complete: " << old_request->get_ip_in() << " -> " << old_request->get_ip_out() << endl;
                }

                if (new_request) {
                    server->add_request(new_request);
                    cout << clockcycle << " | ";
                    cout << "Server " << i << " | ";
                    cout << "Request Assigned: " << new_request->get_ip_in() << " -> " << new_request->get_ip_out() << " | Time to Complete: " << new_request->get_time() << endl;
                }
            }
        }
    }
    clockcycle++;
}

/**
 * @brief Adds a request to the load balancer's request queue.
 * @param request The request to be added.
 * @see requestqueue::push()
 */
void loadbalancer::add_request(request* request) {
    request_q->push(request);
}

/**
 * @brief Provides the current number of requests in the requestqueue
 * @see requestqueue::get_size()
 */
int loadbalancer::get_request_size() {
    return request_q->get_size();
}