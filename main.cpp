#include <iostream>
#include <ctime>
using namespace std;

struct CUSTOMER{
    string firstName{};
    string lastName{};
    int age{};
    int reservationNumber{};
    int roomType{};
};

void welcomeScreen(CUSTOMER customerArray[10], int customerCount);
void newCustomer(CUSTOMER customerArray[10], int customerCount);
void leavingCustomer();
int end();


int main(){

    CUSTOMER customerArray[10];
    int customerCount{};
    welcomeScreen(customerArray, customerCount);
    
    return 0;
}

void welcomeScreen(CUSTOMER customerArray[10], int customerCount){
    customerCount++;
    do{
        //outputs and inputs for action
    int action{};
    cout << "Hello how can I help you?\n" << endl;
    cout << "Check in (1) \nCheck out (2)\nExit(3)\nTerminate program(4)\n";
    cin >> action;

    //input validation   
    while(!cin || action < 1 || action > 4){
        cin.clear();
        cin.ignore(80, '\n');
        cout << "Please input option again \n";
        cin >> action;
    }

    switch(action)
    {
        case 1:{
            newCustomer(customerArray, customerCount);
            break;
        }
        case 2:{
            leavingCustomer();
            break;
        }
        case 3:{
            welcomeScreen(customerArray,customerCount);
            break;
        }
        case 4:{
            end();
            break;
        }
        default:{
            welcomeScreen(customerArray,customerCount);
            break;
        }

    }
    }while(true);
    


}

void newCustomer(CUSTOMER customerArray[10], int customerCount){

    int roomType{};

    cout << endl << "Welcome To My Hotel!!" << endl;
    cout << "We have rooms for 1 and 2.\n";
    cout << "(1) for 1 room, (2) for 2 room\n";
    cin >> roomType;

    //input validation
    while(!cin || roomType<1||roomType > 2){
        cin.clear();
        cin.ignore(80,'\n');
        cout << "Please input option again \n";
        cin >> roomType;
    }
    customerArray[customerCount].roomType=roomType;

    char yesNo{};

    do{
        cout << "Enter your first name.\n";
        cin >> customerArray[customerCount].firstName;
        cout << "Enter your last name.\n";
        cin >> customerArray[customerCount].lastName;
        cout << "Enter your age.\n";
        cin >> customerArray[customerCount].age;

        int randomGeneratedReservationNumber{};
        srand(time(0));
        randomGeneratedReservationNumber=(rand() % 10)+1;

        customerArray[customerCount].reservationNumber=randomGeneratedReservationNumber;
        cout << "Your reservation number is " << customerArray[customerCount].reservationNumber << endl;

        cout << "Checking your details.\n";
        cout << endl;
        cout << "First Name: " << customerArray[customerCount].firstName;
        cout << endl;
        cout << "Last Name: " << customerArray[customerCount].lastName;
        cout << endl;
        cout << "Age: " << customerArray[customerCount].age;
        cout << endl;
        cout << "Reservation Number: " << customerArray[customerCount].reservationNumber;
        cout << endl;
        cout << "Reservation Number: " << customerArray[customerCount].roomType;

        cout << endl << "Are the details correct? (y/n)";
        cin >> yesNo;
        while (!cin || yesNo != 'y' && yesNo !='n'){
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Please input option again \n";
            cin >> yesNo;
        }
    }while(yesNo !='y');
    


}

void leavingCustomer(){
    cout << "work in progress\n";
}
int end(){
    return 0;
}