/**
 * @file request.cpp
 * @brief CPP file for the Request class.
 */
#include "request.h"

/**
 * @brief Constructor to initialize a request with given parameters.
 * @param in Input IP address.
 * @param out Output IP address.
 * @param time Time of the request.
 */
request::request(std::string in, std::string out, int time) : ip_in(in), ip_out(out), time(time) {}

/**
 * @brief Constructor to initialize a request with a given time range.
 * @param lower The lower bound of the time range.
 * @param upper The upper bound of the time range.
 */
request::request(int lower, int upper) : request(generate_ip(), generate_ip(), generate_time(lower, upper)) {}

/**
 * @brief Default constructor generating random IP addresses and time for the request.
 */
request::request() : request(4, 100) {}

/**
 * @brief Generates a random IP address.
 * @return A randomly generated IP address.
 */
std::string request::generate_ip() {
    int num1 = rand() % 256;
    int num2 = rand() % 256;
    int num3 = rand() % 256;
    int num4 = rand() % 256;
    return to_string(num1) + "." + to_string(num2) + "." + to_string(num3) + "." + to_string(num4);
}

/**
 * @brief Generates a random time for the request.
 * @param min the lower bound.
 * @param max the upper bound.
 * @return A randomly generated time.
 */
int request::generate_time(int min, int max) {
    return rand() % (max - min) + min;
}

/**
 * @brief Getter for the input IP address.
 * @return The input IP address.
 */
std::string request::get_ip_in() {
    return ip_in;
}

/**
 * @brief Getter for the output IP address.
 * @return The output IP address.
 */
std::string request::get_ip_out() {
    return ip_out;
}

/**
 * @brief Getter for the time of the request.
 * @return The time of the request.
 */
int request::get_time() {
    return time;
}
