#include <iostream>
#include "classes.h"
#include <queue>
#include <cstdlib>
#include <unistd.h>

using std::cout;
using std::cin;
using std::endl;

string generate_IP_in(){
    //srand(time(NULL));
    string one = to_string(rand() % 256);
    string two = to_string(rand() % 256);
    string three = to_string(rand() % 256);
    string four = to_string(rand() % 256);

    return one + '.' + two + '.' + three + '.' + four;
}

string generate_IP_out(){
    //srand(49 * time(NULL));
    string one = to_string(rand() % 256);
    string two = to_string(rand() % 256);
    string three = to_string(rand() % 256);
    string four = to_string(rand() % 256);

    return one + '.' + two + '.' + three + '.' + four;
}

int generate_time(){
    srand(time(NULL));
    return (0 + rand() % 41); // the max time a request can be run is 1 minute
}

// REQUEST CONSTRUCTOR
request::request(){
    ip_in = generate_IP_in();
    ip_out = generate_IP_out();
    time = generate_time(); 
}

string request::print_request(){
    string s = "request - IP in: " + ip_in + " and IP out: " + ip_out;
    return s;
}

bool request::is_request(){
    if(ip_in == "" || ip_out == "" || time <= 0){
        return false;
    }
    return true;
}

// WEB PROCESSOR FUNCTIONS
webprocessor::webprocessor(request r){
    filled = true;
    ip_in = r.get_ip_in();
    ip_out = r.get_ip_out();
    time = r.get_time();
}

// web processor hold
/*
void webprocessor::processing(request r){

    r.get_time()--;
    if(r.get_time() == 0){
        filled = false;
    }
}*/

bool webprocessor::is_filled(bool e){
    filled = e;
}

// WEB SERVER
template <class X>
webserver<X>::webserver(int size)
{
    arr = new X[size];
    capacity = size;
}

template <class X>
X webserver<X>::access(unsigned int idx){
    return arr[idx];
}

//function to check if the queue is empty or not
template <class X>
bool webserver<X>::is_empty() {
    return (size() == 0);
}

//function to check if the queue is full or not
template <class X>
bool webserver<X>::is_full() {
    return (size() == capacity);
}

// to find next free web processor
template <class X>
int webserver<X>::check_next_free_index(){
    for(int i =0; i< capacity; i++){
        if(!arr[i].get_filled()){
            return i;
        }
    }
    return -1;
}

template <class X>
int webserver<X>::decrement_all_request_time(){
    for(int i = 0; i < capacity; i++{
        if(arr[i].get_filled){
            arr[i].dec_time();
        }
    }
}

/*
int main(){
    // make webserver queue
    webserver<webprocessor> w(3); // webserver is just a queue that contains webprocessors

    request one;
    request two;
    request three;

    //cout << two.get_time() << endl;

    w.access(0).processing(two); // TO MAKE A PROCESSOR IN INDEX 1 PROCESS A REQUEST
    w.access(1).processing(one);

    w.check_next_free_index();

    w.access(2).processing(three);
    return 0;
    
}*/