/**
 * @file webserver.cpp
 * @brief CPP file for the WebServer class.
 */

#include "webserver.h"

/**
 * @brief Constructor for the webserver class. Initializes a new instance of the webserver class with default values.
 * @param None.
 * @return None.
 * @see update(), add_request()
 */
webserver::webserver() : r(nullptr), request_added(-1), clockcycle(0) {}

/**
 * @brief Updates the state of the webserver in each clock cycle.
 * @param None.
 * @return None.
 * @see is_available(), is_full()
 */
void webserver::update() {
    if(r != nullptr && request_added != -1 && r->get_time() + request_added == clockcycle) {
        // delete r;
        r = nullptr;
        request_added = -1;
    }
    clockcycle++;
}

/**
 * @brief Checks if the webserver is available to handle a new request.
 * @param None.
 * @return True if the server is available, false otherwise.
 * @see add_request(), is_full()
 */
bool webserver::is_available() {
    return r == nullptr;
}

/**
 * @brief Checks if the webserver is currently full (i.e., processing a request).
 * @param None.
 * @return True if the server is full, false otherwise.
 * @see is_available(), add_request()
 */
bool webserver::is_full() {
    return r != nullptr;
}

/**
 * @brief Adds a new request to the webserver.Assigns a new request to the webserver and sets the request added time to the current clock cycle.
 * @param r Pointer to the request to be added.
 * @return None.
 * @see is_available(), get_request()
 */
void webserver::add_request(request* r) {
    this->r = r;
    request_added = clockcycle;
}

/**
 * @brief Retrieves the current request being processed by the webserver.
 * @param None.
 * @return Pointer to the current request. Returns nullptr if no request is being processed.
 * @see add_request(), is_full()
 */
request* webserver::get_request() {
    return r;
}