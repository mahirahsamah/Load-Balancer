#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <vector>

using namespace std;


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

class webprocessor{

    bool filled; // to check if a slot is empty

    string ip_in;
    string ip_out;
    int time;

    public:
        webprocessor();
        void processing(request r);
        void is_filled(bool e);
        bool get_filled(){
            return filled;
        }
        void dec_time(){
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

//template <typename X>
class webserver{

    int capacity;
    std::vector<webprocessor> arr;
    //std::vector<webprocessor> arr;
    bool empty_slot;
    int size();

    public:
        webserver(int size = SIZE);
        webprocessor access(unsigned int idx);
        int check_next_free_index();
        int get_size(){
            return capacity;
        }
        void decrement_all_request_time();
};

#endif