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
    webserver web_server(servers_num);

    int req_time = 0;
    int temp = 0;

    // create clock cycles
    for(int i = 0; i < run_time; i++){

        /*for(int k = 0; k < servers_num; k++){
            cout << web_server.access(k)->get_time() << " ";
        }
        cout << endl;*/

        if(add_request_time() % 2 == 0){
            request q;
            request_q.push(q);
        }

        // check if request queue is empty at any point
        if(request_q.empty() && web_server.are_all_processors_empty()){
            cout << "All requests have been completed... exiting..." << endl;
            break;
        }

        int free_index = web_server.check_next_free_index();
        if(free_index == -1){
            //cout << "Wait, the web server is full" << endl;
        }
        else{
            web_server.access(free_index)->add_request(request_q.front());
            request_q.pop();
        }
    
        web_server.decrement_all_request_time(i);
    }
    return 0;
}