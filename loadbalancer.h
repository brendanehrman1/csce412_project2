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
        loadbalancer(string logfile);

        ~loadbalancer();

        void update();

        void add_request(request* request);

        void add_server(webserver* server);

        webserver* remove_server();

        void print();
};

#endif