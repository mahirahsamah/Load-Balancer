#include <string>
//#include <bits/stdc++.h>
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
        string get_ip_in(){
            return ip_in;
        }
        string get_ip_out(){
            return ip_out;
        }
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
        //void processing(request r);
        int check_next_free_index();
        int get_size(){
            return capacity;
        }
        void decrement_all_request_time();
};

class webprocessor{

    bool filled; // to check if a slot is empty

    string ip_in;
    string ip_out;
    int time;

    public:
        webprocessor(request r);
        void processing(request r);
        bool is_filled(bool e);
        bool get_filled(){
            return filled;
        }
        int dec_time(){
            time--;
            if(time == 0){
                filled = false;
            }
        }
        void add_request(request r){
            filled = true;
            ip_in = r.get_ip_in();
            ip_out = r.get_ip_out();
            time = r.get_time();
        }
};

#endif