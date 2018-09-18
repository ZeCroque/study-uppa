/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gcroquefer
 *
 * Created on 18 septembre 2018, 09:52
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {

    long long userINSEE=0;
    int userKey=0;
    int calculatedKey=0;
    
    cout<<"Entrez un INSEE"<<endl;
    cin>>userINSEE;
    cout<<"Entrez une clé"<<endl;
    cin>>userKey;
    
    calculatedKey=97-(userINSEE%97);
    
    if(calculatedKey=userKey)
    {
        cout<<"Le numéro est valide"<<endl;
    }
    
    
    return 0;
}

