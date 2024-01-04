#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <string>
#include "request.h"
#include "requestqueue.h"
#include "webserver.h"
#include <vector>

using namespace std;

class loadbalancer {
    private:
        requestqueue q;
        vector<webserver> servers;
        string logfile;

    public:
        loadbalancer() {}

        void update() {}

        void addRequest() {}

        void print() {}
};

#endif