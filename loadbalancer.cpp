#include "loadbalancer.h"

loadbalancer::loadbalancer(string logfile) : logfile(logfile), clockcycle(0) {
    request_q = new requestqueue();
}

loadbalancer::~loadbalancer() {
    delete request_q;
}

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

void loadbalancer::add_request(request* request) {
    request_q->push(request);
}

void loadbalancer::add_server(webserver* server) {
    servers.push_back(server);
}

webserver* loadbalancer::remove_server() {
    webserver* server = servers.back();
    servers.pop_back();
    return server;
}

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