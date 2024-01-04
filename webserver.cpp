#include "webserver.h"

webserver::webserver() : r(nullptr), request_added(-1), clockcycle(0) {}

void webserver::update() {
    if(r != nullptr && request_added != -1 && r->get_time() + request_added == clockcycle) {
        // delete r;
        r = nullptr;
        request_added = -1;
    }
    clockcycle++;
}

bool webserver::is_available() {
    return r == nullptr;
}

bool webserver::is_full() {
    return r != nullptr;
}

void webserver::add_request(request* r) {
    this->r = r;
    request_added = clockcycle;
}

request* webserver::get_request() {
    return r;
}