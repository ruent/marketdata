#pragma once
#include <vector>
#include <fstream>
#include <sstream>

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

std::vector<std::vector<string>> getCurveData(std::string curvedata_location, size_t N =3){        
        //read a txt file for swap, futures data
        std::ifstream t(curvedata_location);
        std::string token;
        std::vector<std::vector<string>> allData; //10 instruments

        while(std::getline(t, token, '\n')){  
            //token is the line, ideally containing info enough for an instrument
            //delimited with commas        

            std::istringstream iss(token);
            std::string item;
            std::vector<string> some_data; //an instrument should have 5 data points (expiry, etc.)
            while (std::getline(iss, item, ',')) { //don't fuck up! in C++ "," is not the same as ','!
                std::cout << item<< '\n';
                some_data.push_back(item);
            }
            some_data.resize(N);
            allData.push_back(some_data);
        }
        return allData;
    }