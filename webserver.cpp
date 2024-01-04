#include "webserver.h"

class webserver
{
    private:
        request* r;
        int request_added;
        int clockcycle;

    public:
        webserver() {
            request_added = -1;
            clockcycle = 0;
        }

        void update() {
            clockcycle++;
            if(r->get_time() + request_added == clockcycle) {
                r = nullptr;
                request_added = -1;
            }
        }

        bool is_available() {
            return r == nullptr;
        }

        bool is_full() {
            return r != nullptr;
        }

        void add_request(request* r) {
            this->r = r;
            request_added = clockcycle;
        }

        request get_request() {
            return *r;
        }
};