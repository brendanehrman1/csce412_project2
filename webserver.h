#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include "request.h"
using namespace std;

class webserver
{
    private:
        request r;
        int request_added;
        int clockcycle;

    public:
        webserver() {}

        void update() {}

        bool is_available() {}

        bool is_full() {}

        void add_request(request* r) {}

        request get_request() {}
    };

#endif