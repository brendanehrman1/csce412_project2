#include "requestqueue.h"
#include "request.h"

requestqueue::requestqueue() {}

void requestqueue::push(request* r) {
    request_q.push(r);
}

request* requestqueue::pop() {
    request* r = request_q.front();
    request_q.pop();
    return r;
}