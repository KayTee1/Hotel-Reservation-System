#include <iostream>
#include <ctime>
using namespace std;

int main(){
    
    int array[5]={1,5,2};
    bool hasAlready{true};
    
    srand(time(0));
    int randNum{};

    int index{};
    randNum=(rand() % 5)+1;

    do{
        for(int i=0;i<=5;i++){
            if(array[i]==randNum){
                hasAlready=true;
                
            }
            else{
                hasAlready=false;
                index=i;
                break;
            }
            
        }
        if(hasAlready==false){
            break;
        }
    }while(hasAlready=false);
    
    cout << index << endl;










    /*
    do{
        randNum=(rand() % 5)+1;
        for(int i=0;i<5;i++){
            if(array[i]!=randNum){
                hasAlready=false;
                index=i;
                cout << endl << randNum <<" this randNum" << endl << endl;
                break;
            }
        
        }
        if(hasAlready==false){
            break;
        }
    }while(hasAlready=false);

    

    cout << endl << index <<" this index" << endl << endl;
    if(array[index]==0){
        array[index]=randNum;
    }
    


    for(int i=0;i<=5;i++){
        cout << array[i] << endl;
    }
*/
/*
            do{
                srand(time(0));
                randomReservationNumber=(rand() % 5)+1;
                for(int i = 1; i<customerCount; i++){
                    if(customerArray[i].reservationNumber!=randomReservationNumber){
                        hasAlready=false;
                        break;
                    }
                }
                if(hasAlready==false){
                    break;
                }
            }while(hasAlready=true);
*/



















    














    return 0;
}