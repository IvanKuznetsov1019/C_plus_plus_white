#include <iostream>
#include <string>

using namespace std;

const int exception_type = 0; // 0 or 1 or 2 (0 - no exception, 1 - system_error, 2 - invalid_argument)

string AskTimeServer()
{
    if (exception_type == 1)
    {
        throw system_error(error_code());
    }
    else if (exception_type == 2)
    {
        throw invalid_argument("Any exception other than <system error>");
    }
    return "22:17:40";
}

class TimeServer
{
public:
    string GetCurrentTime()
    {
        try
        {
            last_fetched_time = AskTimeServer();
        }
        catch (system_error const &e)
        {
            // don't do anything
        }
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main()
{
    TimeServer time_server;
    try
    {
        cout << time_server.GetCurrentTime() << endl;
    }
    catch (exception const &e)
    {
        cout << "Exception got: " << e.what() << endl;
    }

    return 0;
}