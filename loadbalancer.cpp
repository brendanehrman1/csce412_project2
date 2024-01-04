/**
 * @file loadbalancer.cpp
 * @brief CPP file for the LoadBalancer class.
 */

#include "loadbalancer.h"

/**
 * @brief Constructor for the LoadBalancer class.
 * @param logfile The path to the log file.
 */
loadbalancer::loadbalancer(string logfile) : logfile(logfile), clockcycle(0) {
    request_q = new requestqueue();
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
    ofstream log;
    log.open(logfile, ios_base::app);
    for (size_t i = 0; i < servers.size(); i++) {
        webserver* server = servers.at(i);
        request* old_request = server->get_request();
        server->update();
        if (server->is_available()) {
            request* new_request = request_q->pop();

            if (old_request) {
                log << clockcycle << " | ";
                log << "Server " << i << " | ";
                log << "Request Complete: " << old_request->get_ip_in() << " -> " << old_request->get_ip_out() << endl;
            }

            if (new_request) {
                server->add_request(new_request);
                log << clockcycle << " | ";
                log << "Server " << i << " | ";
                log << "Request Assigned: " << new_request->get_ip_in() << " -> " << new_request->get_ip_out() << endl;
            }
        }
    }
    log.close();
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
 * @brief Adds a server to the load balancer's list of servers.
 * @param server The server to be added.
 */
void loadbalancer::add_server(webserver* server) {
    servers.push_back(server);
}

/**
 * @brief Removes and returns the last server from the load balancer's list of servers.
 * @return The removed server.
 */
webserver* loadbalancer::remove_server() {
    webserver* server = servers.back();
    servers.pop_back();
    return server;
}

/**
 * @brief Prints the status of servers in the load balancer.
 * @see webserver::get_request()
 */
void loadbalancer::print() {
    cout << "----------------------------------------------------------" << endl;
    for (size_t i = 0; i < servers.size(); i++) {
        cout << "|      Server " << i << "       | ";
        if (servers.at(i)->is_full()) {
            cout << servers.at(i)->get_request()->get_ip_in() << " -> ";
            cout << servers.at(i)->get_request()->get_ip_out() << endl;
        } else {
            cout << "EMPTY" << endl;
        }
        cout << "----------------------------------------------------------" << endl;
    }
}