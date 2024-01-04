#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include "request.h"
using namespace std;

class webserver
{
    private:
        request* r;
        int request_added;
        int clockcycle;

    public:

        /**
        * @brief Constructor for the webserver class. Initializes a new instance of the webserver class with default values.
        * @param None.
        * @return None.
        * @see update(), add_request()
        */
        webserver();

        /**
        * @brief Updates the state of the webserver in each clock cycle.
        * @param None.
        * @return None.
        * @see is_available(), is_full()
        */
        void update();

        /**
        * @brief Checks if the webserver is available to handle a new request.
        * @param None.
        * @return True if the server is available, false otherwise.
        * @see add_request(), is_full()
        */
        bool is_available();

        /**
        * @brief Checks if the webserver is currently full (i.e., processing a request).
        * @param None.
        * @return True if the server is full, false otherwise.
        * @see is_available(), add_request()
        */
        bool is_full();

        /**
        * @brief Adds a new request to the webserver.Assigns a new request to the webserver and sets the request added time to the current clock cycle.
        * @param r Pointer to the request to be added.
        * @return None.
        * @see is_available(), get_request()
        */
        void add_request(request* r);

        request* get_request();
    };

#endif