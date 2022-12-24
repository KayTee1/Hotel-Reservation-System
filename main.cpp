#include <iostream>
#include <ctime>
using namespace std;

//customer struct
struct CUSTOMER{
    string firstName{};
    string lastName{};
    int age{};
    int reservationNumber{};
    int roomType{};
    int nights{};
};

void welcomeScreen(CUSTOMER customerArray[10], int customerCount);
void newCustomer(CUSTOMER customerArray[10], int customerCount);
void leavingCustomer(CUSTOMER customerArray[10], int customerCount);

const int MAX_CUSTOMERS=50;

int main(){

    //initializing essential variables
    CUSTOMER customerArray[MAX_CUSTOMERS];
    int customerCount{};
    //main function start
    welcomeScreen(customerArray, customerCount);
    
    return 0;
}

void welcomeScreen(CUSTOMER customerArray[MAX_CUSTOMERS], int customerCount){
    
    //forever loop with "active" -bool=false
    bool active{true};

    do{
        //counting total customers
        customerCount++;

        //outputs and inputs for action
        int action{};
        cout << "\nHello how can I help you?\n" << endl;
        cout << "Check in (1) \nCheck out (2)\nExit(3)\nTerminate program(4)\n";
        cin >> action;

        //input validation   
        while(!cin || action < 1 || action > 4){
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Please input option again \n";
            cin >> action;
        }

        //customer selecting what to do
        switch(action)
        {
            case 1:{
                //new customer funciton
                newCustomer(customerArray, customerCount);
                break;
            }
            case 2:{
                //leaving customer function
                leavingCustomer(customerArray,customerCount);
                break;
            }
            case 3:{
                //back to main menu
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

void newCustomer(CUSTOMER customerArray[MAX_CUSTOMERS], int customerCount){
    
    //initializing essential variables for newCustomer function
    char yesNo{};
    int roomType{};
    int nights{};

    do{
        
        cout << endl << "Welcome To My Hotel!!" << endl;
        cout << "We have rooms for 1 and rooms for 2.\n";
        cout << "(1) for 1 room, (2) for 2 room, (3) for exit\n";
        cin >> roomType;

        //input validation
        while(!cin || roomType<1||roomType > 3){
            cin.clear();
            cin.ignore(80,'\n');
            cout << "Please input option again \n";
            cin >> roomType;
        }
        if(roomType==3){
            welcomeScreen(customerArray,customerCount);
        }
        customerArray[customerCount].roomType=roomType;

        

        cout << "How many nights will you be staying?\n";
        cin >> nights;

        //input validation
        while(!cin || nights<1||nights > 7){
            cin.clear();
            cin.ignore(80,'\n');
            cout << "Please input option again \n";
            cin >> nights;
        }

        customerArray[customerCount].nights=nights;

        cout << "Enter your first name.\n";
        cin >> customerArray[customerCount].firstName;
        cout << "Enter your last name.\n";
        cin >> customerArray[customerCount].lastName;
        cout << "Enter your age.\n";
        cin >> customerArray[customerCount].age;
    
        int randomReservationNumber{};
        srand(time(0));

        randomReservationNumber=(rand() % MAX_CUSTOMERS)+1;

        customerArray[customerCount].reservationNumber=randomReservationNumber;
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
        cout << "Room Type: " << customerArray[customerCount].roomType;
        cout << endl;
        cout << "Nights staying: " << customerArray[customerCount].nights;

        //yesNo char to confirm if the details are correct
        cout << endl << "Are the details correct? (y/n)";
        cin >> yesNo;
        while (!cin || yesNo != 'y' && yesNo !='n'){
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Please input option again \n";
            cin >> yesNo;
        }
    }while(yesNo !='y');
    
    //prices section
    /*
    single room 50 double room 100
    multiplied by nights stayed
    */

    int roomPrice = roomType*50;
    int price = roomPrice * nights;
    int pay{};


    cout << "This stay will cost you: " << price << endl;
    //input validation
    do{
        cout << "Enter this value: " << price << endl;
        cin >> pay;
    }while(pay!=price);
    
    cout << "\nThank You, Enjoy your Stay!\n";
    

}

void leavingCustomer(CUSTOMER customerArray[10], int customerCount){
    int rNumber;

    cout << "\nEnter your reservation number.\n";
    cin >> rNumber;
    while(!cin || rNumber < 0 ||rNumber > MAX_CUSTOMERS){
        cin.clear();
        cin.ignore(80,'\n');
        cout << "Please input option again \n";
        cin >> rNumber;
    }   

    char yesNo;

    //if reservation number not found then it will send user back to main menu
    bool rNumberFound{true};

    //for loop to go through all customer reservation numbers
    for (int i = 1;i<MAX_CUSTOMERS;i++){
        
        //if a match is found, the program will check if it is you
        if(rNumber==customerArray[i].reservationNumber){
            cout << "\nIs this you?\n";
            cout << "First Name: " << customerArray[i].firstName << endl;
            cout << "Last Name: " << customerArray[i].lastName << endl;
            cout << "Room Type: " << customerArray[i].roomType << endl;

            cout << "\nYour informations will be deleted\n";
            cout << "Yes(y) / No(n)";
            cin >>yesNo;

            //input validation
            while (!cin || yesNo != 'y' && yesNo !='n'){
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Please input option again \n";
                cin >> yesNo;
            }
            //if the right person is found, the program will delete the persons information
            if(yesNo=='y'){
                customerArray[i].firstName=" ";
                customerArray[i].lastName=" ";
                customerArray[i].age=0;
                customerArray[i].reservationNumber=0;
                customerArray[i].roomType=0;
                cout << "Thank you for choosing us!\n";
                welcomeScreen(customerArray, customerCount);
            }
            //if the wrong person was found, the program will send the user back to the main menu
            else if(yesNo=='n'){
                cout << "Guiding you back to main menu...\n";
                welcomeScreen(customerArray, customerCount);
            }
        }
        //if the reservation number is not found at all, rNumberFound = false
        else{
            rNumberFound=false;
        }
        
    }
    //the program will send the user back to the main menu if reservation number is not found
    if(rNumberFound==false){
        cout << "This reservation number does not match any of our customers.\n";
        cout << "Guiding you back to main menu...\n";
        welcomeScreen(customerArray, customerCount);
    }
   
}