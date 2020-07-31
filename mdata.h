#include <vector>
using namespace std;

//since I cannot get this data natively
//I'll cache it here in this struct
//I'll assume data for each +1month, relative to
//price date
//SO ALL DISC,TAU,ENDDATES ARE EQUAL LENGTH VECTORS ...
//calling functions can calculate the time multiple and retrive the
//stored numbers
//endTImes = [1month,2month, 3, +2m, ...]
//End times will simply be integers, reprsenting months
//A swap's payment dates will simple be the same, 
//e.g. 5x5 swap will have payment dates as
// [63,66, ..., 120]
// such a swap come and look for the discount factor here

//year fractions should be put here assuming a daycount
//no daycount based calculations should/can appear here
//I might need to be several tau vectors here where daycount
// or freq change  
//default will be something like [0.5, 0.5 , ...]
//an entry for each month, giving year fraction with 
//the PREVIOUS 6 months


//tau[i] is the tau
//for the interval endtimes[i] and endtimes[i-1] 
struct timezero
{
    const vector<double>& tau; //period year fractions
    const vector<unsigned int>& endDates;     
    const vector<double>& disc; //a discount value for each endtime
};