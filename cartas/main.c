#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream> 
#include <map>
#include <algorithm>

using namespace std;  

int procura(int *v , int size , int eleme){
    for(int i=0;i<size;i++){
        if(v[i] == eleme)
            return 1;
    }
    return 0;
}

int conta_zeros(int *v , int size ){
    int conta = 0;
    for(int i=0;i<size;i++)
        if(v[i] == 0)
            conta++;

    return conta;
}

int *setTamanho(int *v,int newSize){
    int *novo;
    novo = new int[newSize];
    for(int i=0;i<newSize;i++){
        novo[i] = v[i];
    }
    return novo;
}

int main(){
    int alice,beatriz , i=0 , j = 0,resultado , tmp,num_zero=0;
    map<int, int> cartas_alice;
    map<int, int> cartas_beatriz;
    map<int, int>::iterator it;

    cin >> alice;
    cin >> beatriz;

    while(alice > 0 && beatriz > 0){  

        for(i=0;i<alice;i++){
            cin >> tmp;
            cartas_alice.insert(map<int,int>::value_type(tmp,tmp));
        }
        for(i=0;i<beatriz;i++){
            cin >> tmp;
            cartas_beatriz.insert(map<int,int>::value_type(tmp,tmp));
        }
       

        for( map<int, int>::iterator ii=cartas_alice.begin(); ii!=cartas_alice.end(); ++ii){ 
               if(cartas_beatriz.find(ii->first) != cartas_beatriz.end()){
                    cartas_alice.erase ( cartas_alice.find(ii->first)->first);
                    cartas_beatriz.erase ( cartas_beatriz.find(ii->first)->first);
                }
        } 

        if( cartas_alice.size() < cartas_beatriz.size())
            cout << cartas_alice.size() << endl;
        else
            cout << cartas_beatriz.size() << endl; 
        
        cin >> alice;
        cin >> beatriz;
    }    
 
} 
