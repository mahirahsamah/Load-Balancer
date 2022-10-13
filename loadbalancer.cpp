#include <iostream>
#include "classes.h"
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

int add_request_time(){

    return (5 + ( std::rand() % ( 1001 ) ));
}


int main(){

    // user prompt
    /*int servers_num;
    int run_time;

    cout << "Enter the number of servers: ";
    cin >> servers_num;

    cout << "Enter the run time: ";
    cin >> run_time;*/

    int servers_num = 10;
    int run_time = 100;

    // create request queue
    queue<request> request_q;

    // make requests and populate request queue
    for(int i = 0; i < servers_num * 2; i++){
        request r;
        request_q.push(r);
    }

    // create webservers and populate them with webprocessors
    webserver web_server(servers_num);

    // record start time of the run time
    high_resolution_clock::time_point start = high_resolution_clock::now();

    // display starting size of the request queue
    cout << "Starting queue size: " << request_q.size() << endl;

    // run clock cycles
    for(int i = 0; i < run_time; i++){

        // add requests in the request queue randomly
        if(add_request_time() %3 == 0 ){
            request q;
            request_q.push(q);
        }

        // check if request queue is empty at any point
        if(request_q.empty() && web_server.are_all_processors_empty()){
            cout << "All requests have been completed... exiting..." << endl;
            break;
        }

        // if request queue is not empty in that cycle, find the next free webprocessor in the webserver
        int free_index = web_server.check_next_free_index();

        // if no webprocessor in the webserver is free
        if(free_index == -1){
            cout << "Wait, the web server is full" << endl;
        }

        // if a webprocessor is free, pop a request from the request queue and put it in that webprocessor
        else{
            web_server.access(free_index)->add_request(request_q.front());
            request_q.pop();
        }

        // decrement the processing times of all the requests that are currently in the webserver
        web_server.decrement_all_request_time(i);
    }

    // record end time of the run time
    high_resolution_clock::time_point end = high_resolution_clock::now();

    // display starting size of the request queue
    cout << "Ending queue size: " << request_q.size() << endl;

    // display the range of processing times of requests in the queue
    cout << "Range of request processing times: 5 to 60 cycles" << endl;

    // find how long the operation takes
    auto duration = (end - start).count();

    // display the time taken
    cout << "Time taken: " << duration << endl;

    return 0;
}