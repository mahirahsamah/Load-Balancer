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
        int get_time(){
            return time;
        }
        void dec_time(int clock_cycle, int idx){
            //cout << "at dec_time" << endl;
            time--;
            //cout << time << endl;
            if(time == 0){
                //cout << "at time=0" << endl;
                filled = false;
                // cout here
                cout << "At " << clock_cycle << ", Processor " << std::to_string(idx) << " completed request from " << ip_in << " to " << ip_out << endl;
            }
        }
        void add_request(request r){
            filled = true;
            ip_in = r.get_ip_in();
            ip_out = r.get_ip_out();
            time = r.get_time();
            //cout << filled << endl;
        }
};

//template <typename X>
class webserver{

    //int capacity;
    std::vector<webprocessor> arr;
    //std::vector<webprocessor> arr;
    bool empty_slot;
    //int size();

    public:
        webserver(int size = SIZE);
        webprocessor* access(unsigned int idx);
        int check_next_free_index();
        int get_size(){
            return arr.size();
        }
        void decrement_all_request_time(int clock_cycle);
        bool are_all_processors_empty();
};

#endif