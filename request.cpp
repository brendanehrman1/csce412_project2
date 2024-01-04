#include "request.h"

request::request(string in, string out, int time) : ip_in(in), ip_out(out), time(time) {}

request::request() : request(generate_ip(), generate_ip(), generate_time()) {}

string request::generate_ip() {
    int num1 = rand() % 256;
    int num2 = rand() % 256;
    int num3 = rand() % 256;
    int num4 = rand() % 256;
    return to_string(num1) + "." + to_string(num2) + "." + to_string(num3) + "." + to_string(num4);
}

int request::generate_time() {
    return rand() % 96 + 4;
}

string request::get_ip_in() {
    return ip_in;
}

string request::get_ip_out() {
    return ip_out;
}

int request::get_time() {
    return time;
}