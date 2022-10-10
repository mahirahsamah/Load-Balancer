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
};

#endif