#include <iostream>
#include "loadbalancer.h"
#define SIZE 10000

using namespace std;


class request{
    public:
        string ip_in;
        string ip_out;
        int time;
    private:
        bool is_request;
};


class processor{

};

class webserver{
};

class request_queue{
    unsigned int capacity;
    int curr_size, front, rear;
    int *array;

    public:
        request_queue(int size = SIZE);
        request pop();
        void push();
        request peek();
        int size();
        bool is_empty();
        bool is_full();

};

// reqeust queue constructor
request_queue::request_queue(int size)
{
    arr = new int[size];
    capacity = size;
    curr_size = 0;
}

// request_queue pop function
request request_queue::pop(){
    if (is_empty){
        cout << "There are no requests in the queue" << endl;
    }
}