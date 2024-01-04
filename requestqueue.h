/**
 * @file requestqueue.h
 * @brief Header file for the RequestQueue class.
 */
#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "request.h"
using namespace std;

class requestqueue
{
    private:
        queue<request*> request_q;

    public:
        /**
         * @brief Default constructor for the request queue.
         */
        requestqueue();

        /**
         * @brief Adds a request to the queue.
         * @param r The request to be added.
         * @see std::queue::push()
         */
        void push(request* request);

        /**
         * @brief Removes and returns a request from the queue.
         * @return The request removed from the queue, or nullptr if the queue is empty.
         * @see std::queue::empty()
         * @see std::queue::front()
         * @see std::queue::pop()
         */
        request* pop();

        /**
         * @brief Provides the size of the queue.
         * @return The size of the queue.
         * @see std::queue::size()
         */
        int get_size();
};

#endif