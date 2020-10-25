#pragma once
#include <vector>
 

//since I cannot get this data natively, I'll cache it here 

//depending on payment dates etc. data should be made available here 
//year fractions should be put here assuming a daycount
//no daycount based calculations should/can appear here
//I might need to be several tau vectors here where daycount
// or freq change  

struct timezero
{
     std::map<size_t, std::vector<double>, std::less<size_t>> data;
     //std::vector<double> tau; //period year fractions     
     //std::vector<double> disc; //a discount value for each endtime
     //std::vector<double> vol; //a vol for each endtime (for a given strike)

    //timezero( std::vector<double> _tau,  std::vector<double> _disc, 
    //    std::vector<double> _vol): 
    //        tau(_tau),  disc(_disc), vol(_vol){}
    timezero(std::map<size_t, std::vector<double>, std::less<size_t>> _data): 
            data(_data){}

    double tau(size_t i){
        return data[i][0];
    }
    double disc(size_t i){
        return data[i][1];
    }        
};

 
struct somedata
{
    //std::unique_ptr<double> xyz;
};
 