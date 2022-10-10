#include <string>
using namespace std;
#ifndef CLASSES_H
#define CLASSES_H

const int SIZE = 10000;

class request{
    string ip_in;
    string ip_out;
    int time;

    public:
        request();
        string print_request();
        bool is_request();
        int get_time(){
            return time;
        }
};

template <typename X>
class queue{
    int capacity;
    int count, front, rear;
    X *arr;

    public:
        queue(int size = SIZE);
        X pop();
        void push(X r);
        int size();
        bool is_empty();
        bool is_full();
        X access(unsigned int idx);
};

template <typename X>
class webserver{

    int capacity;
    X *arr;
    bool empty_slot;
    int size();

    public:
        webserver(int size = SIZE);
        bool is_empty();
        bool is_full();
        X access(unsigned int idx);
        void processing(request r);
};

class webprocessor{

    bool empty; // to check if a slot is empty

    public:
        webprocessor();
        //void push_request(request r);
        void processing(request r);
        bool is_empty();
};

#endif