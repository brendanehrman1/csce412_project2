/**
 * @file requestqueue.cpp
 * @brief CPP file for the RequestQueue class.
 */
#include "requestqueue.h"
#include "request.h"

/**
 * @brief Default constructor for the request queue.
 */
requestqueue::requestqueue() {}

/**
 * @brief Adds a request to the queue.
 * @param r The request to be added.
 * @see std::queue::push()
 */
void requestqueue::push(request* r) {
    request_q.push(r);
}

/**
 * @brief Removes and returns a request from the queue.
 * @return The request removed from the queue, or nullptr if the queue is empty.
 * @see std::queue::empty()
 * @see std::queue::front()
 * @see std::queue::pop()
 */
request* requestqueue::pop() {
    if (request_q.empty()) {
        return nullptr;
    }
    request* r = request_q.front();
    request_q.pop();
    return r;
}

/**
 * @brief Provides the size of the queue.
 * @return The size of the queue.
 * @see std::queue::size()
 */
int requestqueue::get_size() {
    return request_q.size();
}