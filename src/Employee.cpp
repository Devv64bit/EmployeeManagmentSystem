#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <sstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

static string firstName;
static string lastName;
static string emailId;
static string phoneNumber;
static string aptNumber;
static string streetAddress;
static string city;
static string state;
static string zipCode;
static string vehicleType;
static string vehicleModel;
static string vehicleColor;
static string vehicleTagNumber;
static string modElement;
static string newData;
static string empData;
static string modifythisElement;
static vector <string> empDetails;
static int inputData = 0;
static void displayInfo();
static void getInfo(string str);
static void userAuthentication();
static void enterEmployeeDetails();
static void deleteInfo();
static void knowInfo(string emailId);
static void displayInfo();
static void modifyInfo(string str);
static void replaceInfo(string str);

int main() {
    // call this method to differentiate between the admin and user.
    // Then, it allows them to do things provided to them.
    userAuthentication();
}

static void userAuthentication() {
    string input;
    string input1;
    cout << "Are you an admin or employee: ";
    cin >> input;

    cout << "What is the password? ";
    cin >> input;

    // only allow the admin to login with this password check
    if (input == "adminiscool") {
        cout << "You succesfully logged in as ADMIN ";
        cout << "\n";
        cout << "\nWhat do you want to do: " << endl;
        cout << "*******************************" << endl;
        cout << "Choice 1: Add an Employee Detail \nChoice 2: Modify an Employee Detail \nChoice 3: Know an Employee Detail \nChoice 4: Delete \n->";
        cin >> input1;

        // nested if statement when the admin choses an option
        if (input1 == "1") {
            // call function to enter employee details.
            enterEmployeeDetails();
        }

        if (input1 == "2") {
            // call function to modify employee details.
            displayInfo();
        }

        if (input1 == "3") {
            // call function to know employee details.
            knowInfo(emailId);
        }

        if (input1 == "4") {
            // call function to delete employee
            deleteInfo();
        }
    }
    // any employees can login with the password given
    else if (input == "cmpsc121") {
        cout << "You succesfully logged in as a EMPLOYEE ";
        cout << "\n";
        cout << "What do you want to do: " << endl;
        cout << "*******************************" << endl;
        cout << "Choice 1: Add an Employee Detail \nChoice 2: Know an Employee Detail \n->";
        cin >> input1;
        // nested if statement when the employee choses an option
        if (input1 == "1") {
            // call function to enter employee details.
            enterEmployeeDetails();
        }

        else if (input1 == "2") {
            // call function to know employee details.
            knowInfo(emailId);
        }
    }
    else {
        cout << "\nUser name or Password is incorrect, try again";
        exit(1);
    }
}

static void enterEmployeeDetails() {
    cout << "\nFirst Name: " << endl;
    cin >> firstName;
    cout << "\n";

    cout << "Last Name: " << endl;
    cin >> lastName;
    cout << "\n";

    cout << "Email Id: " << endl;
    cin >> emailId;
    cout << "\n";

    cout << "Phone Number(use dashes): " << endl;
    cin >> phoneNumber;
    cout << "\n";

    cout << "Apt Number(use dash): " << endl;
    cin >> aptNumber;
    cout << "\n";

    cout << "Street Address(use dashes): " << endl;
    cin >> streetAddress;
    cout << "\n";

    cout << "City(use dashes): " << endl;
    cin >> city;
    cout << "\n";

    cout << "State: " << endl;
    cin >> state;
    cout << "\n";

    cout << "ZipCode: " << endl;
    cin >> zipCode;
    cout << "\n";

    cout << "Vehicle Type: " << endl;
    cin >> vehicleType;
    cout << "\n";

    cout << "Vehicle Model(use dashes): " << endl;
    cin >> vehicleModel;
    cout << "\n";

    cout << "Vehicle Color(use dashes): " << endl;
    cin >> vehicleColor;
    cout << "\n";

    cout << "Vehicle Tag Number: " << endl;
    cin >> vehicleTagNumber;
    cout << "\n";

    // instantiate ofstream object to open txt file
    ofstream myFile("employeesInformation.txt", ios::app);

    // a string variable to concatenate to all the information into one line.
    string alltheInfo = "\n" + firstName + " " + lastName + " " + emailId + " " + phoneNumber + " " + aptNumber + " " + streetAddress + " " + city + " " + state + " " + zipCode + " " + vehicleType + " " + vehicleModel + " " + vehicleColor + " " + vehicleTagNumber + " ";

    myFile << alltheInfo;
    myFile.close();

    cout << "\nDone entering the information into the file";
    exit(1);
}

static void deleteInfo() {
    string input;
    cout << "Enter the name of the employee you want to delete"<< "\n" << endl;
    cin >> input;

    string findName;
    ifstream myFile("employeesInformation.txt");
    ofstream makeCopy("example.txt");

    while (getline(myFile, findName)) {
        // substr method to find where the name is the txt file and delete it.

        if (findName.substr(0, input.size()) != input) {
            makeCopy << findName << endl;
        }
    }
    myFile.close();
    makeCopy.close();
    remove("employeesInformation.txt");
    rename("example.txt", "employeesInformation.txt");
    cout << "\nThe entry was succesfully removed"<< endl;
}

static void knowInfo(string email) {
    cout << "\nPlease enter the exact email given in the txt file"<<endl;
    cout << "Enter an email to know employee details: " << endl;
    cin >> email;
    string employeeDetails[] =
        {
            "First & Last Name: Dev Patel\nVehicle Type: SUV\nVehicle Model: 2018 Toyota RAV4\nVehicle Color: White\nVehicle Tag Number: 2803",
            "First & Last Name: ABD Villers\nVehicle Type: SUV\nVehicle Model: 2016 Lexus RX 350\nVehicle Color: Silver\nVehicle Tag Number: 3600",
            "First & Last Name: Jofra Archer\nVehicle Type: Sedan\nVehicle Model: 2018 BMV M5\nVehicle Color: Black\nVehicle Tag Number: 7659",
            "First & Last Name: David Warner\nVehicle Type: Sedan\nVehicle Model: 2019 Mercedes Benz AMG\nVehicle Color: Blue\nVehicle Tag Number: 0259",
            "First & Last Name: Pat Cummins\nVehicle Type: SUV\nVehicle Model: 2020 Acura RDX\nVehicle Color: Dark Blue\nVehicle Tag Number: 5432",
            "First & Last Name: Kieron Pollard\nVehicle Type: SUV\nVehicle Model: 2018 Jeep Wrangler\nVehicle Color: Red\nVehicle Tag Number: 7402",
            "First & Last Name: Virat Kohli\nVehicle Type: Sedan\nVehicle Model: 2020 Audi R8\nVehicle Color: Yellow\nVehicle Tag Number: 4201",
            "First & Last Name: Chris Gayle\nVehicle Type: SUV\nVehicle Model: 2019 Nissan Rouge\nVehicle Color: Black\nVehicle Tag Number : 3030",
            "First & Last Name: Jonny Baristow\nVehicle Type: Sedan\nVehicle Model: 2013 Mercedes Benz SL500\nVehicle Color: Orange\nVehicle Tag Number : 9738",

        };

    if (email == "dpatel@gmail.com") {
        // call the array index for each email and print the info.

        cout << employeeDetails[0] << endl;
    }
    else if (email == "mr360@gmail.com") {
        cout << employeeDetails[1];
    }
    else if (email == "JA@gmail.com") {
        cout << employeeDetails[2];
    }
    else if (email == "DW@gmail.com") {
        cout << employeeDetails[3];
    }
    else if (email == "PC@gmail.com") {
        cout << employeeDetails[4];
    }
    else if (email == "bigboss@gmail.com") {
        cout << employeeDetails[5];
    }
    else if (email == "VK@gmail.com") {
        cout << employeeDetails[6];
    }
    else if (email == "universeboss@gmail.com") {
        cout << employeeDetails[7];
    } 
    else if(email == "JB@gmail.com"){
        cout << employeeDetails[8];
    }
    else {
        cout << "Email not found in Database";
        exit(1);
    }
}

static void displayInfo() {
    string input;
    cout << "Enter the first name of the employee you would like to modify : ";
    cin >> input;

    cout << "\nPlease type the employee data you would like to modify: \"First_Name\", \"Last_Name\", \"Email_ID\", \"Phone_Number\", \"Apartment_Number\", \"Street_Address\", \"City\", \"State\", \"Zipcode\", \"Vehicle_Type\", \"Vehicle_Model\", \"Vehicle_Color\", or \"Vehicle_Tag_Number\".\n";
    cin >> empData;

    if (empData == "First_Name") {
        // inputData will set the index to the given input
        // eg: First name is at 0 index in the txt file.
        inputData = 0;
    }
    else if (empData == "Last_Name") {
        inputData = 1;
    }
    else if (empData == "Email_ID") {
        inputData = 2;
    }
    else if (empData == "Phone_Number") {
        inputData = 3;
    }
    else if (empData == "Apartment_Number") {
        inputData = 4;
    }
    else if (empData == "Street_Address") {
        inputData = 5;
    }
    else if (empData == "City") {
        inputData = 6;
    }
    else if (empData == "State") {
        inputData = 7;
    }
    else if (empData == "Zipcode") {
        inputData = 8;
    }
    else if (empData == "Vehicle_Type") {
        inputData = 9;
    }
    else if (empData == "Vehicle_Model") {
        inputData = 10;
    }
    else if (empData == "Vehicle_Color") {
        inputData = 11;
    }
    else if (empData == "Vehicle_Tag_Number") {
        inputData = 12;
    }
    else {
        cout << "Not a valid detail\n";
        exit(1);
    }

    fstream newFile;
    newFile.open("employeesInformation.txt", ios::in);
    
    if(newFile.is_open()) {
        string indexFinder;
        while(getline(newFile, indexFinder)) {
            // use find function to find exactly where the input from user is located.

            if(indexFinder.find(input) == 0) {
                // call this method store and locate the input.
                modifyInfo(indexFinder);
            }
        }
        newFile.close();
    }
    cout << "The " + empData + " is currently " + modifythisElement
;
    cout << "\nEnter a new " + empData + ": ";
    cin >> modElement;
    cout << "\nDone processing your request.";

    newFile.open("employeesInformation.txt", ios::in);
    if(newFile.is_open()) {
        string indexFinder;
        while(getline(newFile, indexFinder)) {
            // use find function to find exactly where the input from user is located.

            if(indexFinder.find(input) == 0) {
                // call this method to perform the replacement of the input
                replaceInfo(indexFinder);
            }
        }
        newFile.close();
    }

    string findName;
    ifstream myFile("employeesInformation.txt");
    ofstream makeCopy("example.txt");

    while (getline(myFile, findName)) {
        if (findName.substr(0, input.size()) != input) {
            makeCopy << findName << endl;
        }
    }
    myFile.close();
    makeCopy.close();
    // remove and create a temp txt file to perform the replacement.
    remove("employeesInformation.txt");
    // rename it so that the temp txt file becomes the new one.
    rename("example.txt", "employeesInformation.txt");
    ofstream outFile("employeesInformation.txt", ios_base::app);
    outFile<< newData;
}

static void modifyInfo(string str) {
    string index;
    stringstream searcher(str);

    // while loop to search for the index
    while(searcher >> index) {
        // push back the vector when index is found.
        empDetails.push_back(index);
    }

    // fancy variable to say what the current item is in the txt file
    // eg: Current zip code is 19020. 
    modifythisElement = empDetails[inputData];
}

static void replaceInfo(string str) {
    string index;
    stringstream searcher(str);

    while(searcher >> index) {
        // if statement to check that new index doesn't equal the old index.
        if(index!= modifythisElement
    ) {
            // push back the vector when the replacement is done.
            empDetails.push_back(index);
            // newData variable to compute the index and replace it.
            newData+=index + " ";
        } 
        else {
            newData+=modElement + " ";
        }
    }
}
