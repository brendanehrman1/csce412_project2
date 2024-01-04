#include "loadbalancer.h"

class loadbalancer {
    private:
        requestqueue q;
        vector<webserver> servers;
        string logfile;

    public:
        loadbalancer() {}

        void update() {}

        void addRequest() {}

        void print() {}
};