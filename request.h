/**
 * @file request.h
 * @brief Header file for the Request class.
 */
#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <random>
using namespace std;

class request {
    private:
        string ip_in;
        string ip_out;
        int time;

    public:
        /**
         * @brief Constructor to initialize a request with given parameters.
         * @param in Input IP address.
         * @param out Output IP address.
         * @param time Time of the request.
         */
        request(string in, string out, int time);

        /**
         * @brief Default constructor generating random IP addresses and time for the request.
         */
        request();

        /**
         * @brief Generates a random IP address.
         * @return A randomly generated IP address.
         */
        string generate_ip();

        /**
         * @brief Generates a random time for the request.
         * @return A randomly generated time.
         */
        int generate_time();

        /**
         * @brief Getter for the input IP address.
         * @return The input IP address.
         */
        string get_ip_in();

        /**
         * @brief Getter for the output IP address.
         * @return The output IP address.
         */
        string get_ip_out();

        /**
         * @brief Getter for the time of the request.
         * @return The time of the request.
         */
        int get_time();
};

#endif