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
        request(string in, string out, int time) {}

        request() {}

        string generate_ip() {}

        int generate_time() {}

        string get_ip_in() {}

        string get_ip_out() {}

        int get_time() {}
};

#endif