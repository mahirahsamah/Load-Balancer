#include <iostream>
#include "loadbalancer.h"
#include "classes.h"

using namespace std;



string free_process(){
    // returns the next free process in the web server
}

int main(){
    int servers_num;
    int run_time;

    cout << "Enter the number of servers: " << endl;
    cin >> servers_num;

    cout << "Enter the run time: " << endl;
    cin >> run_time;

    queue<request> q(servers_num * 2);

}