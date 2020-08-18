#pragma once
#include <vector>
using namespace std;

//since I cannot get this data natively
//I'll cache it here in this struct
//I'll assume data for each +1month, relative to
//price date
//SO ALL DISC,TAU ARE EQUAL LENGTH VECTORS ...
//calling functions can calculate the time multiple and retrive the
//stored numbers
 
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

//if a swaption has paym date 12 (i.e. at 1year), then disc[12]
//is right if disc has a zero entry, meaning it should start from 0th month
//this should also be the case for tau


//tau[i] is the tau
//for the interval endtimes[i] and endtimes[i-1] 

//make vol data also in this format
//as long as lin-interp is used, interpolating 1monhly data
//should be ok.
//alternative is to have a dictinonary structure:
// vol at 3m, at 1year etc.
struct timezero
{
     const vector<double>& tau; //period year fractions     
     const vector<double>& disc; //a discount value for each endtime
     const vector<double>& vol; //a vol for each endtime (for a given strike)

    timezero( vector<double>& _tau,  vector<double>& _disc, 
        vector<double>& _vol): 
            tau(_tau),  disc(_disc), vol(_vol){}
};