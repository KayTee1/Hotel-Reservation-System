#include <iostream>
#include <ctime>

using namespace std;

const int MAX_CUSTOMERS = 50;

//customer struct
struct CUSTOMER{
    string firstName{};
    string lastName{};
    int age{};
    int reservationNumber{};
    int roomType{};
    int nights{};
};

void newCustomer(CUSTOMER customerArray[MAX_CUSTOMERS], int customerCount);
void leavingCustomer(CUSTOMER customerArray[MAX_CUSTOMERS], int customerCount);

int inputValidation(int target, int x, int y);

int main(){

    CUSTOMER customerArray[MAX_CUSTOMERS];
    int customerCount{-1};
    bool isActive{true};

    while(isActive){
        //counting customer count from 0
        customerCount++;

        //outputs and inputs for action
        int action{};
        cout << "\nHello how can I help you?\n" << endl;
        cout << "Check in (1) \nCheck out (2)\nExit(3)\nTerminate program(4)\n";

        //input validation
        action = inputValidation(action, 1, 4);

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
                break;
            }
            case 4:{
                isActive=false;
                break;
            }
            default:{
                break;
            }
        }
    }


}

int inputValidation(int target, int x, int y){

    cin >> target;

    if(target < x || target > y){
        cin.clear();
        cin.ignore(80, '\n');
        cout << "Invalid input. Please enter a number between " << x << " and " << y << endl;
        cin >> target;
    }

    return target;
}

void newCustomer(CUSTOMER customerArray[MAX_CUSTOMERS], int customerCount){
    //initializing essential variables for newCustomer function
    int yesNo{};
    int roomType{};
    int nights{};

    do{

        cout << endl << "Welcome To My Hotel!!" << endl;
        cout << "We have rooms for 1 and rooms for 2.\n";
        cout << "(1) for 1 room, (2) for 2 room\n";

        //input validation
        roomType = inputValidation(roomType, 1, 2);

        customerArray[customerCount].roomType=roomType;


        cout << "How many nights will you be staying?\n";

        //input validation
        nights = inputValidation(nights, 1, 7);


        customerArray[customerCount].nights=nights;

        cout << "Enter your first name.\n";
        cin >> customerArray[customerCount].firstName;
        cout << "Enter your last name.\n";
        cin >> customerArray[customerCount].lastName;
        cout << "Enter your age.\n";
        //input validation

        customerArray[customerCount].age = inputValidation(customerArray[customerCount].age, 16, 100);

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
        cout << endl << "Are the details correct? yes(1) no(2)";
        //input validation
        yesNo = inputValidation(yesNo, 1, 2);

    }while(yesNo !=1);

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

void leavingCustomer(CUSTOMER customerArray[MAX_CUSTOMERS], int customerCount){
    int rNumber;

    cout << "\nEnter your reservation number.\n";
    //input validation
    rNumber = inputValidation(rNumber, 0, MAX_CUSTOMERS);

    int yesNo;

    //if reservation number not found then it will send user back to main menu
    bool rNumberFound{true};

    //for loop to go through all customer reservation numbers
    for (int i = 0;i<MAX_CUSTOMERS;i++){

        //if a match is found, the program will check if it is you
        if(rNumber==customerArray[i].reservationNumber){
            cout << "\nIs this you?\n";
            cout << "First Name: " << customerArray[i].firstName << endl;
            cout << "Last Name: " << customerArray[i].lastName << endl;
            cout << "Room Type: " << customerArray[i].roomType << endl;

            cout << "\nYour informations will be deleted\n";
            cout << "Yes(1) / No(2)";
            //input validation
            yesNo = inputValidation(yesNo, 1, 2);

            //if the right person is found, the program will delete the persons information
            if(yesNo == 1){
                customerArray[i].firstName=" ";
                customerArray[i].lastName=" ";
                customerArray[i].age=0;
                customerArray[i].reservationNumber=0;
                customerArray[i].roomType=0;
                cout << "Thank you for choosing us!\n";
                break;
            }
            //if the wrong person was found, the program will send the user back to the main menu
            else if(yesNo == 2){
                cout << "Guiding you back to main menu...\n";
                break;
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
    }
}