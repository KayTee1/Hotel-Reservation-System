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
void leavingCustomer(CUSTOMER customerArray[10], int customerCount);

int main(){

    CUSTOMER customerArray[10];
    int customerCount{};
    welcomeScreen(customerArray, customerCount);
    
    return 0;
}

void welcomeScreen(CUSTOMER customerArray[10], int customerCount){
    bool active{true};
    do{
        customerCount++;
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
            leavingCustomer(customerArray,customerCount);
            break;
        }
        case 3:{
            welcomeScreen(customerArray,customerCount);
            break;
        }
        case 4:{
            active=false;
            break;
        }
        default:{
            
            break;
        }

    }
    }while(active);
    


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

void leavingCustomer(CUSTOMER customerArray[10], int customerCount){
    int rNumber;

    cout << "Enter your reservation number.\n";
    cin >> rNumber;
    while(!cin || rNumber < 0 ||rNumber > 10){
        cin.clear();
        cin.ignore(80,'\n');
        cout << "Please input option again \n";
        cin >> rNumber;
    }   

    char yesNo;

    //if reservation number not found then it will send user back to main menu in line 196
    bool rNumberFound{true};

    for (int i = 1;i<10;i++){
        
        if(rNumber==customerArray[i].reservationNumber){
            cout << "Is this you?\n";
            cout << customerArray[i].firstName << endl;
            customerArray[i].lastName << endl;
            customerArray[i].age << endl;
            customerArray[i].reservationNumber << endl;
            customerArray[i].roomType << endl;

            cout << "Your informations will be deleted\n";
            cout << "Yes(y) / No(n)";
            cin >>yesNo;

            while (!cin || yesNo != 'y' && yesNo !='n'){
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Please input option again \n";
                cin >> yesNo;
            }
            if(yesNo=='y'){
                customerArray[i].firstName=" ";
                customerArray[i].lastName=" ";
                customerArray[i].age=0;
                customerArray[i].reservationNumber=0;
                customerArray[i].roomType=0;
                cout << "Thank you for choosing us!\n";
                welcomeScreen(customerArray, customerCount);
            }
            else if(yesNo=='n'){
                cout << "Guiding you back to main menu...\n";
                welcomeScreen(customerArray, customerCount);
            }
        }
        else{
            rNumberFound=false;
        }
        
    }
    if(rNumberFound==false){
        cout << "This reservation number does not match any of our customers.\n";
        cout << "Guiding you back to main menu...\n";
        welcomeScreen(customerArray, customerCount);
    }
   
}

