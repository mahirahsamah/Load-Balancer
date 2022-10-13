#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <vector>

using namespace std;

/// @brief The Request class defines a request.
///
/// Defines an object Request that contains an incoming IP address (ip_in), an outgoing IP address (ip_out), and a time (time) needed for the Request to be processed.
class request{

    string ip_in;
    string ip_out;
    int time;

    public:

        request();

        int get_time();

        string get_ip_in();

        string get_ip_out();
};

/// @brief The Webprocessor class defines the object that handles a request. 
///
/// The Webprocessor processes a Request and holds it for the time that the Request needs to be processed. A Webprocessor has attributes filled which defines if that Webprocessor is currently holding a Reqeust, and it has the same attributes of the Request it is holding (ip_in, ip_out, time).
class webprocessor{

    bool filled; // to check if a slot is empty

    string ip_in;
    string ip_out;
    int time;

    public:
        webprocessor();

        bool get_filled();

        int get_time();

        void dec_time(int clock_cycle, int idx);

        void add_request(request r);
};

/// @brief The Webserver class defines the data structure that holds a number of Webprocessor objects.
///
/// A Webserver is a vector that contains Webprocessor objects. The Webserver class can loop through its vector to check which Webprocessors are free, allows all Webprocessors to process Requests' times, and if all Webprocessors are idle.
class webserver{

    std::vector<webprocessor> arr;

    public:
        webserver(int size = 0);

        webprocessor* access(unsigned int idx);

        int check_next_free_index();

        int get_size();

        void decrement_all_request_time(int clock_cycle);
        
        bool are_all_processors_empty();
};

#endif