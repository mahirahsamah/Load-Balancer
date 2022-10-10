#include <iostream>
#include "classes.h"
#include <cstdlib>

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

// reqeust queue constructor
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

// Processor inside web server
class processor{

};

// Web server class 
class webserver{

};

int main(){
    
    queue<request> q(10*2);
    request r;

    q.push(r);

    if(q.is_empty()){
        cout << "q is empty"<< endl;
    }
    else{
        cout << "q isnt empty" << endl;
    }

    return 0;
}