#include <vector>
using namespace std;

//since I cannot get this data natively
//I'll cache it here in this struct
//I'll assume data for each +1month, relative to
//price date
//calling functions can calculate the time multiple and retrive the
//stored numbers

struct timezero
{
    const vector<double>& tau; //period year fractions
    const vector<double>& endTimes;  
    const vector<double>& discVector; //a discount value for each endtime
};