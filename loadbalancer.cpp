#include <iostream>
#include "classes.h"
#include <queue>

using namespace std;

int add_request_time(){
    srand(time(NULL));
    return (1 + rand() % 60); // the max time a request can be run is 1 minute
}


int main(){

    int servers_num;
    int run_time;

    cout << "Enter the number of servers: ";
    cin >> servers_num;

    cout << "Enter the run time: ";
    cin >> run_time;

    // create request queue
    queue<request> request_q;

    // populate request queue
    for(int i = 0; i < servers_num * 2; i++){
        request r;
        request_q.push(r);
    }

    // create webservers
    webserver<webprocessor> web_server(servers_num);

    int req_time = 0;
    int temp = 0;

    // create clock cycles
    for(int i = 0; i < run_time; i++){

        // check if request queue is empty at any point
        if(request_q.empty()){
            cout << "All requests have been completed... exiting..." << endl;
            break;
        }

        int free_index = web_server.check_next_free_index();
        if(free_index == -1){
            cout << "Wait, the web server is full" << endl;
        }
        else{

            //web_server.access(free_index).processing(request_q.front());
            web_server.access(free_index).add_request(request_q.front());
            request_q.pop();
            //req_time = request_q.front().get_time();
            //web_server.access(free_index).is_filled(true);

            /*if(temp == req_time){
                web_server.access(free_index).is_filled(false);
            }*/

        }
        web_server.decrement_all_request_time();
    }
}