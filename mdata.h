#include <vector>
using namespace std;

//since I cannot get this data natively
//I'll cache it here in this struct
//I'll assume data for each +1month, relative to
//price date
//calling functions can calculate the time multiple and retrive the
//stored numbers
//endTImes = [0,1,2, +1m, +2m, ...]
//year fractions should be put here assuming a daycount
//no daycount based calculations should/can appear here
struct timezero
{
    const vector<double>& tau; //period year fractions
    const vector<unsigned int>& endTimes;  
    const vector<double>& discVector; //a discount value for each endtime
};