#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <sstream>
#include <vector>
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
static string elementToMod;
static vector <string> empDetails;
static int dataNum = 0;
static void displayInfo();
static void getInfo(string str);
static void userAuth();
static void enterEmployeeDetails();
static void deleteInfo();
static void knowInfo(string emailId);
static void displayInfo();
static void modifyInfo(string str);
static void replaceInfo(string str);

int main()
{
    userAuth();
}

static void userAuth()
{
    string input;
    string input1;
    cout << "Are you an admin or employee: ";
    cin >> input;

    cout << "What is the password? ";
    cin >> input;

    // only allow the admin to login with this password check
    if (input == "adminiscool")
    {
        cout << "\nYou succesfully logged in as admin ";
        cout << "\nWhat do you want to do: " << endl;
        cout << "Choice 1: Add an Employee Detail \nChoice 2: Modify an Employee Detail \nChoice 3: Know an Employee Detail \nChoice 4: Delete \n->";
        cin >> input1;

        // nested if statement when the admin choses an option
        if (input1 == "1")
        {
            enterEmployeeDetails();
        }

        if (input1 == "2")
        {
            displayInfo();
        }

        if (input1 == "3")
        {
            knowInfo(emailId);
        }

        if (input1 == "4")
        {
            deleteInfo();
        }
    }
    // any employees can login with the password given
    else if (input == "cmpsc121")
    {
        cout << "You succesfully logged in as a employee ";
        cout << "\nWhat do you want to do: " << endl;
        cout << "Choice 1: Add an employee detail \nChoice 2: Know an Employee Detail \n->";
        cin >> input1;
        // nested if statement when the employee choses an option
        if (input1 == "1")
        {
            enterEmployeeDetails();
        }

        else if (input1 == "2")
        {
            knowInfo(emailId);
        }
    }
    else
    {
        cout << "Password is incorrect, try again";
        exit(1);
    }
}

static void enterEmployeeDetails()
{
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

    ofstream myFile("employeesInformation.txt", ios::app);
    string alltheInfo = "\n" + firstName + " " + lastName + " " + emailId + " " + phoneNumber + " " + aptNumber + " " + streetAddress + " " + city + " " + state + " " + zipCode + " " + vehicleType + " " + vehicleModel + " " + vehicleColor + " " + vehicleTagNumber + " ";

    // instantiate ofstream object to open txt file
    myFile << alltheInfo;
    myFile.close();

    cout << "\nDone entering the information into the file";
    exit(0);
}

static void deleteInfo()
{
    string input;
    cout << "Enter the name of the employee you want to delete"
         << "\n"
         << endl;
    cin >> input;

    string findName;
    ifstream myFile("employeesInformation.txt");
    ofstream makeCopy("example.txt");

    while (getline(myFile, findName))
    {
        if (findName.substr(0, input.size()) != input)
        {
            makeCopy << findName << endl;
        }
    }
    myFile.close();
    makeCopy.close();
    remove("employeesInformation.txt");
    rename("example.txt", "employeesInformation.txt");
}

static void knowInfo(string email)
{

    cout << "\nEnter an email to know employee details: " << endl;
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
            "First & Last Name: Chris Gayle\nVehicle Type: SUV\nVehicle Model: 2019 Nissan Rouge\nVehicle Color: Black\nVehcle Tag Number : 3030"

        };

    if (email == "dpatel@gmail.com")
    {
        cout << employeeDetails[0] << endl;
    }
    else if (email == "mr360@gmail.com")
    {
        cout << employeeDetails[1];
    }
    else if (email == "JA@gmail.com")
    {
        cout << employeeDetails[2];
    }
    else if (email == "DW@gmail.com")
    {
        cout << employeeDetails[3];
    }
    else if (email == "PC@gmail.com")
    {
        cout << employeeDetails[4];
    }
    else if (email == "bigboss@gmail.com")
    {
        cout << employeeDetails[5];
    }
    else if (email == "VK@gmail.com")
    {
        cout << employeeDetails[6];
    }
    else if (email == "universeboss@gmail.com")
    {
        cout << employeeDetails[7];
    }
}

static void displayInfo()
{
    string input;
    cout << "Enter the first name of the employee you would like to modify :";
    cin >> input;

    cout << "Please type the employee data you would like to modify: \"First_Name\", \"Last_Name\", \"Email_ID\", \"Phone_Number\", \"Apartment_Number\", \"Street_Address\", \"City\", \"State\", \"Zipcode\", \"Vehicle_Type\", \"Vehicle_Model\", \"Vehicle_Color\", or \"Vehicle_Tag_Number\".\n";
    cin >> empData;

    if (empData == "First_Name")
    {
        dataNum = 0;
    }
    else if (empData == "Last_Name")
    {
        dataNum = 1;
    }
    else if (empData == "Email_ID")
    {
        dataNum = 2;
    }
    else if (empData == "Phone_Number")
    {
        dataNum = 3;
    }
    else if (empData == "Apartment_Number")
    {
        dataNum = 4;
    }
    else if (empData == "Street_Address")
    {
        dataNum = 5;
    }
    else if (empData == "City")
    {
        dataNum = 6;
    }
    else if (empData == "State")
    {
        dataNum = 7;
    }
    else if (empData == "Zipcode")
    {
        dataNum = 8;
    }
    else if (empData == "Vehicle_Type")
    {
        dataNum = 9;
    }
    else if (empData == "Vehicle_Model")
    {
        dataNum = 10;
    }
    else if (empData == "Vehicle_Color")
    {
        dataNum = 11;
    }
    else if (empData == "Vehicle_Tag_Number")
    {
        dataNum = 12;
    }
    else
    {
        cout << "Not a valid detail\n";
        exit(1);
    }

    fstream newFile;
    newFile.open("employeesInformation.txt", ios::in);
    
    if(newFile.is_open()){
        string indexFinder;
        while(getline(newFile, indexFinder)){
            if(indexFinder.find(input) == 0){
                modifyInfo(indexFinder);
            }
        }
        newFile.close();
    }
    cout << "The " + empData + " is currently " + elementToMod;
    cout << "\nEnter a new " + empData + ": ";
    cin >> modElement;
    cout << "\nDone processing your request.";

    newFile.open("employeesInformation.txt", ios::in);
    if(newFile.is_open()) {
        string indexFinder;
        while(getline(newFile, indexFinder)){
            if(indexFinder.find(input) ==0){
                replaceInfo(indexFinder);
            }
        }
        newFile.close();
    }

    string findName;
    ifstream myFile("employeesInformation.txt");
    ofstream makeCopy("example.txt");

    while (getline(myFile, findName))
    {
        if (findName.substr(0, input.size()) != input)
        {
            makeCopy << findName << endl;
        }
    }
    myFile.close();
    makeCopy.close();
    remove("employeesInformation.txt");
    rename("example.txt", "employeesInformation.txt");
    ofstream outFile("employeesInformation.txt", ios_base::app);
    outFile<< newData;
}

static void modifyInfo(string str)
{
    string index;
    stringstream searcher(str);

    while(searcher >> index){
        empDetails.push_back(index);
    }
    elementToMod = empDetails[dataNum];
}

static void replaceInfo(string str)
{
    string element;
    stringstream searcher(str);

    while(searcher >> element){
        if(element!=elementToMod){
            empDetails.push_back(element);
            newData+=element + " ";
        } else {
            newData+=modElement + " ";
        }
    }
}
