#include <iostream>
#include "classes.h"
using namespace std;

//const int SIZE = 10000;

// Request class
/*class request{
    string ip_in;
    string ip_out;
    int time;

    public:
        request(string iin, string iout, int t);
        void print_request();
        bool is_request();
};*/

request::request(string iin, string iout, int t){
    ip_in = iin;
    ip_out = iout;
    time = t;
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

// request_queue class definition start

// Request Queue class to store requests
/*template <typename X>
class request_queue{
    int capacity;
    int count, front, rear;
    int *arr;

    public:
        request_queue(int size = SIZE);
        X pop();
        void push(X r);
        int size();
        bool is_empty();
        bool is_full();
};*/

// reqeust queue constructor
template <class X>
request_queue<X>::request_queue(int size)
{
    arr = new X[size];
    capacity = size;
    count = 0;
    front = 0;
    rear = -1;
}

// request_queue pop function
template <class X>
X request_queue<X>::pop()
{
    // check for queue underflow
    if (is_empty())
    {
        cout << "Cannot pop, request_queue is empty" << endl;
    }
    request r = arr[front];
    string output = "Removing " + r.print_request();
    cout << output << endl;
 
    front = (front + 1) % capacity;
    count--;

    return arr[front];
}

// request_queue push function
template <class X>
void request_queue<X>::push(X r)
{
    // check for queue overflow
    if (is_full())
    {
        cout << "Cannot push, queue is full" << endl;
    }
 
    //cout << "Inserting " << r.print_request() << endl;
    string output = "Inserting " + r.print_request();
    cout << output << endl;
 
    rear = (rear + 1) % capacity;
    arr[rear] = r;
    count++;
}
 
//function to return the size of the queue
template <class X>
int request_queue<X>::size() {
    return count;
}
 
//function to check if the queue is empty or not
template <class X>
bool request_queue<X>::is_empty() {
    return (size() == 0);
}

//function to check if the queue is full or not
template <class X>
bool request_queue<X>::is_full() {
    return (size() == capacity);
}

// request_queue class definition end

// Processor inside web server
class processor{

};

// Web server class 
class webserver{

};

int main(){
    request r("hi", "bye", 10);
    cout << r.print_request();
}