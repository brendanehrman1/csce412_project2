#include "requestqueue.h"
#include "request.h"

class requestqueue
{
    private:
        queue<request*> request_q;

    public:
        requestqueue() {}

        void push(request* r) {
            request_q.push(r);
        }

        request* pop() {
            request* r = request_q.front();
            request_q.pop();
            return r;
        }
};