#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "request.h"
using namespace std;

class requestqueue
{
private:
    queue<request> request_q;

public:
    requestqueue() {}

    void push() {}

    bool pop() {}
};

#endif