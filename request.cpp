#include "request.h"

class request {
    private:
        string ip_in;
        string ip_out;
        int time;

    public:
        request(string in, string out, int time) : ip_in(in), ip_out(out), time(time) {}

        request() : request(generate_ip(), generate_ip(), generate_time()) {}

        string generate_ip() {
            int num1 = rand() % 256;
            int num2 = rand() % 256;
            int num3 = rand() % 256;
            int num4 = rand() % 256;
            return to_string(num1) + "." + to_string(num2) + "." + to_string(num3) + "." + to_string(num4);
        }

        int generate_time() {
            return rand() % 97 + 4;
        }

        string get_ip_in() {
            return ip_in;
        }

        string get_ip_out() {
            return ip_out;
        }

        int get_time() {
            return time;
        }
};