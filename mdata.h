#pragma once
#include <vector>

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
        if(data.find(i) == data.end()){
            std::cout << "mdata.h: no data found for: " << i <<"\n";
           return 0.0;}
        else return data[i][0];
    }
    double disc(size_t i){
        if(data.find(i) == data.end()){
            std::cout << "mdata.h: no data found for: " << i <<"\n";
            return 0.0;}
        else return data[i][1];
    }   
    double disc_fwd(size_t i){
        if(data.find(i) == data.end()){
            std::cout << "mdata.h: no data found for: " << i <<"\n";
            return 0.0;}
        else return data[i][2];
    }            
};

 
struct somedata
{
    std::unique_ptr<double> xyz;
};