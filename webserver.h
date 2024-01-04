#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include "request.h"
using namespace std;

class webserver
{
private:
    request request;
    int request_added;
    int clockcycle;

public:
    webserver() {}

    void update() {}

    bool isAvailable() {}

    bool isFull() {}

    void addRequest() {}
};

#endif