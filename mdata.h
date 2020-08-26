#pragma once
#include <vector>
 

//since I cannot get this data natively
//I'll cache it here in this struct
//I'll assume data for each +1month, relative to
//price date, except the INITIAL POINT


//SO ALL DISC,TAU ARE EQUAL LENGTH VECTORS ...
//calling functions can calculate the time multiple and retrieve the
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

//vol can be normal vol
struct timezero
{
     std::vector<double> tau; //period year fractions     
     std::vector<double> disc; //a discount value for each endtime
     std::vector<double> vol; //a vol for each endtime (for a given strike)

    timezero( std::vector<double> _tau,  std::vector<double> _disc, 
        std::vector<double> _vol): 
            tau(_tau),  disc(_disc), vol(_vol){}
    std::vector<double> getdisc(){
        return disc;
    }        
};

 
struct somedata
{
    std::unique_ptr<double> xyz;
};
 