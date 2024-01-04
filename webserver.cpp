#include "webserver.h"

/**
 * @brief Constructor for the web server.
 */
webserver::webserver() : r(nullptr), request_added(-1), clockcycle(0) {}

/**
 * @brief Updates the web server's state.
 */
void webserver::update() {
    if (r != nullptr && request_added != -1 && r->get_time() + request_added == clockcycle) {
        r = nullptr;
        request_added = -1;
    }
    clockcycle++;
}

/**
 * @brief Checks if the web server is available (no request being processed).
 * @return True if the server is available, false otherwise.
 */
bool webserver::is_available() {
    return r == nullptr;
}

/**
 * @brief Checks if the web server is full (processing a request).
 * @return True if the server is full, false otherwise.
 */
bool webserver::is_full() {
    return r != nullptr;
}

/**
 * @brief Adds a request to the web server for processing.
 * @param r The request to be processed.
 */
void webserver::add_request(request* r) {
    this->r = r;
    request_added = clockcycle;
}

/**
 * @brief Retrieves the current request being processed by the web server.
 * @return The request being processed, or nullptr if no request is being processed.
 */
request* webserver::get_request() {
    return r;
}
