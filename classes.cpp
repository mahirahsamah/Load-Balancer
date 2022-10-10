#include <iostream>
#include "classes.h"
#include <cstdlib>
#include <unistd.h>

using namespace std;

string generate_IP_in(){
    srand(time(NULL));
    string one = to_string(0 + rand() % 255);
    string two = to_string(0 + rand() % 255);
    string three = to_string(0 + rand() % 255);
    string four = to_string(0 + rand() % 255);

    return one + '.' + two + '.' + three + '.' + four;
}

string generate_IP_out(){
    srand(49 * time(NULL));
    string one = to_string(0 + rand() % 255);
    string two = to_string(0 + rand() % 255);
    string three = to_string(0 + rand() % 255);
    string four = to_string(0 + rand() % 255);

    return one + '.' + two + '.' + three + '.' + four;
}

int generate_time(){
    srand(time(NULL));
    return (0 + rand() % 61); // the max time a request can be run is 1 minute
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


// REQUEST QUEUE CONSTRUCTOR
template <class X>
queue<X>::queue(int size)
{
    arr = new X[size];
    capacity = size;
    count = 0;
    front = 0;
    rear = -1;
}

// request_queue pop function
template <class X>
X queue<X>::pop()
{
    // check for queue underflow
    if (is_empty())
    {
        cout << "Cannot pop, queue is empty" << endl;
    }
    request r = arr[front];
    string output = "Removing " + r.print_request();
    cout << output << endl;
 
    front = (front + 1) % capacity;
    count--;

    return arr[front];
}

template <class X>
X queue<X>::access(unsigned int idx){
    return arr[idx];
}

// request_queue push function
template <class X>
void queue<X>::push(X item)
{
    // check for queue overflow
    if (is_full())
    {
        cout << "Cannot push, queue is full" << endl;
    }
 
    //cout << "Inserting " << r.print_request() << endl;
    string output = "Inserting " + item.print_request();
    cout << output << endl;
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
 
//function to return the size of the queue
template <class X>
int queue<X>::size() {
    return count;
}
 
//function to check if the queue is empty or not
template <class X>
bool queue<X>::is_empty() {
    return (size() == 0);
}

//function to check if the queue is full or not
template <class X>
bool queue<X>::is_full() {
    return (size() == capacity);
}








// WEB PROCESSOR FUNCTIONS
webprocessor::webprocessor(){
    empty = true;
}

// web processor hold
void webprocessor::processing(request r){

    // time is in seconds
    // sleep() returns 0 when the interval is over

    empty = false;

    sleep(r.get_time());

    empty = true;
    //return empty;
}

bool webprocessor::is_empty(){
    return empty;
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

template <class X>
void webserver<X>::processing(request r){

    // time is in seconds
    // sleep() returns 0 when the interval is over

    empty_slot = false;

    sleep(r.get_time());

    empty_slot = true;
    //return empty;
}

int main(){
    
    // make webserver queue
    webserver<webprocessor> w(3); // webserver is just a queue that contains webprocessors

    request one;
    request two;
    request three;

    cout << two.get_time() << endl;

    w.access(1).processing(two); // TO MAKE A PROCESSOR IN INDEX 1 PROCESS A REQUEST



    /*
    queue<request> q(3);
    request r;
    request t;
    request s;

    q.push(r);
    q.push(t);
    q.push(s);

    cout << t.get_time() << endl;

    cout << q.access(1).get_time() << endl;

    return 0; */
    
}