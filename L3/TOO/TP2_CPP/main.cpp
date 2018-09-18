/* 
 * File:   main.cpp
 * Author: gcroquefer
 *
 * Created on 18 septembre 2018, 10:23
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool bissextileInt(int year)
{
    return ((year%4==0 && year%100!=0) || year%400==0);
}

bool bissextileTime(time_t date)
{
    tm* now_as_data_structure = gmtime(&date);
    int year = now_as_data_structure->tm_year+1900;
    return ((year%4==0 && year%100!=0) || year%400==0);
}


int main(int argc, char** argv) 
{
    time_t now = time(&now);
    int year=0;
    tm* now_as_data_structure = gmtime(&now);

    
    cout<<"Entrez une année"<<endl;
    cin>>year;
    cout<<"Via int:\nL'année "<<year<<" est bissextile?\n"<<bissextileInt(year)<<endl; 
    cout<<"Via calendar:\nL'année "<<now_as_data_structure->tm_year+1900<<" est bissextile?\n"<<bissextileTime(now)<<endl;
   
    
    return 0;
}

