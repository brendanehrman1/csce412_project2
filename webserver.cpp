#include "webserver.h"

webserver::webserver() {
    request_added = -1;
    clockcycle = 0;
}

void webserver::update() {
    clockcycle++;
    if(r->get_time() + request_added == clockcycle) {
        delete r;
        r = nullptr;
        request_added = -1;
    }
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