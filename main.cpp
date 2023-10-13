#include <iostream>
#include <fstream>
#include <string>
#include<ctime>
#include <chrono>
#include <thread> 
#include <stdlib.h>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;
void welcome();
void recordOfVehicle();
void recordOfVehicle_1(int registrationNum, string ownerName);
void recordOfVehicle_2(int registrationNum);
void recordOfVehicle_3(string ownerName);

void recordOfChallan() ;
void recordOfChallan_1(int registrationNum, string ownerName);
void recordOfChallan_2(int registrationNum);
void recordOfChallan_3(string ownerName);

void trafficContBooth();
void trafficContBooth_1();
void trafficContBooth_2();
void trafficContBooth_3();

int delay_0()
{
sleep_for(nanoseconds(1000000));
sleep_until(system_clock::now() + seconds(1));

return 0;
}
int delay_1()
{

sleep_for(nanoseconds(1000000000));
sleep_until(system_clock::now() + seconds(1));

return 0;
}
int delay_2()
{
sleep_for(nanoseconds(100000000));
sleep_until(system_clock::now() + seconds(1));

return 0;
}

void return_home(char func){
    char userIn;
    while (true){
        cout << "                        Please Enter Valid Option                      " << endl;
        cout << "                                   B or S                              " << endl;
        cin >> userIn;
        if (userIn == 'S' || userIn == 's') {
            if (func == 'v'){
                recordOfVehicle();
            }
            else if (func == 'c'){
                recordOfChallan();
            }
        } else if (userIn == 'B' || userIn == 'b') {
        welcome();
        } else {
            continue;
        }
    }
}

void recordOfVehicle(){
    int recordUserInput;
    int registrationNum;
    string ownerName;
    system("clear");

    cout << "                        ╔══════════════════════════╗" << endl;
    cout << "                        ║  Vehicle Registration    ║" << endl;
    cout << "                        ║         Portal           ║" << endl;
    cout << "                        ╚══════════════════════════╝" << endl;

    cout << " Welcome to Vehicle Registration Portal " << endl;

    cout << "Press number 1 for adding a new vehicle " << endl;
    cout << "Press number 2 for searching for a vehicle" << endl;
    cout << "Press number 3 for searching for a vehicle by the name of the owner" << endl;
    cin >> recordUserInput;

    if (recordUserInput >= 1 && recordUserInput <= 3){
        switch (recordUserInput){
            case 1:
            cout << "Please Enter the Vehicle Registration Number you wanna add" << endl;
            cin >> registrationNum;
            cout << "Please Enter the Owner's Name for the Vehicle you wanna add" << endl;
            cin >> ownerName;
            recordOfVehicle_1(registrationNum, ownerName);
            break;

            case 2:
            cout << "Please Enter the Vehicle Registration Number you wanna search for" << endl;
            cin >> registrationNum;
            recordOfVehicle_2(registrationNum);
            break;

            case 3:
            cout << "Please Enter the Owner of the vehicle's Number you wanna search for" << endl;
            cin >> ownerName;
            recordOfVehicle_3(ownerName);
            break;
        }
    }
}

void recordOfVehicle_1(int registrationNum, string ownerName){
    ofstream MyFile;
    MyFile.open("VehicleRecording.txt", ios::app);
    cout << "                        ╔══════════════════════════╗" << endl;
    cout << "                        ║  Vehicle Registration    ║" << endl;
    cout << "                        ║         Portal           ║" << endl;
    cout << "                        ╚══════════════════════════╝" << endl;
    MyFile << "\n"<< ownerName << " :: " << registrationNum;

    cout << "Do you want to return to the home screen or search for another vehicle?" << endl;
                cout << "                                   B or S                              " << endl;

                return_home('v');

    MyFile.close();

}

void recordOfVehicle_2(int registrationNum) {
    ifstream MyFile;
    string line;
    string name_file;
    string register_file;
    MyFile.open("VehicleRecording.txt", ios::in);

    while (getline(MyFile, line)) {
    cout << "                        ╔══════════════════════════╗" << endl;
    cout << "                        ║  Vehicle Registration    ║" << endl;
    cout << "                        ║         Portal           ║" << endl;
    cout << "                        ╚══════════════════════════╝" << endl;

        size_t delimiterPos = line.find(" :: ");

        if (delimiterPos != string::npos) {
            std::string data1 = line.substr(0, delimiterPos);
            std::string data2 = line.substr(delimiterPos + 3);

            name_file = data1.substr(data1.find_first_not_of(" \t\n\r"), data1.find_last_not_of(" \t\n\r") + 1);
            register_file = data2.substr(data2.find_first_not_of(" \t\n\r"), data2.find_last_not_of(" \t\n\r") + 1);

            if (register_file == to_string(registrationNum)) {
                cout << "There is a vehicle registered for this registration number: " << registrationNum;
                cout << ", The vehicle is registered under the name of: " << name_file << endl;

                cout << "Do you want to return to the home screen or search for another vehicle?" << endl;
                cout << "                                   B or S                              " << endl;

                return_home('v');
            }
            else {
                cout << "There is no vehicles registered for this registartion number" << endl;
                return_home('v');
            }

        }
    }

    MyFile.close(); 
}

void recordOfVehicle_3(string ownerName){
   ifstream MyFile("VehicleRecording.txt");
    string line;
    string name_file;
    string register_file;
    while (getline(MyFile, line)){
    cout << "                        ╔══════════════════════════╗" << endl;
    cout << "                        ║  Vehicle Registration    ║" << endl;
    cout << "                        ║         Portal           ║" << endl;
    cout << "                        ╚══════════════════════════╝" << endl;

        size_t delimiterPos = line.find(" :: ");
        if (delimiterPos != std::string::npos) {
            std::string data1 = line.substr(0, delimiterPos);
            std::string data2 = line.substr(delimiterPos + 3);

            
            name_file = data1.substr(data1.find_first_not_of(" \t\n\r"), data1.find_last_not_of(" \t\n\r") + 1);
            register_file = data2.substr(data2.find_first_not_of(" \t\n\r"), data2.find_last_not_of(" \t\n\r") + 1);

            if (name_file == (ownerName)) {
                cout << "There is a vehicle registered under the name of: " << name_file
                << ", The vehicle is registered for this registration number: " << register_file << endl;

                cout << "Do you want to return to the home screen or search for another vehicle?" << endl;
                cout << "                                   B or S                              " << endl;

                return_home('v');
            }
            else {
                cout << "There is no vehicles registered for this owner name" << endl;
                return_home('v');
            }

        }
    }
    MyFile.close(); 
}

void recordOfChallan(){
    char recordUserInput;
    int registrationNum;
    string ownerName;
    system("clear");
    cout << "                        ╔══════════════════════════╗" << endl;
    cout << "                        ║  Vehicle Registration    ║" << endl;
    cout << "                        ║         Portal           ║" << endl;
    cout << "                        ╚══════════════════════════╝" << endl;

    cout << " Welcome to Vehicle Registration Portal " << endl;

    cout << "Press number 1 for adding a new challan " << endl;
    cout << "Press number 2 for searching for a challan using registration number" << endl;
    cout << "Press number 3 for searching for a challam using the name of the owner" << endl;
    cout << "Press B to go back to the Home Page" << endl;
    cin >> recordUserInput;

    if ((recordUserInput >= '1' && recordUserInput <= '3') || recordUserInput == 'B' || recordUserInput == 'b'){
        switch (recordUserInput){
            case '1':
            cout << "Please Enter the Vehicle Registration Number you wanna add" << endl;
            cin >> registrationNum;
            cout << "Please Enter the Owner's Name for the Vehicle you wanna add" << endl;
            cin >> ownerName;
            recordOfChallan_1(registrationNum, ownerName);
            break;

            case '2':
            cout << "Please Enter the Vehicle Registration Number you wanna search for" << endl;
            cin >> registrationNum;
            recordOfChallan_2(registrationNum);
            break;

            case '3':
            cout << "Please Enter the Owner of the vehicle's Number you wanna search for" << endl;
            cin >> ownerName;
            recordOfChallan_3(ownerName);
            break;

            case 'B':
            cout << "Please" ;
            welcome();
            break;
            case 'b':
             cout << "Please 6" ;
            welcome();
            break;
        }
    }
}
// to add a new challan by inputting a vehicle’s registration number and the owner’s name.
void recordOfChallan_1(int registrationNum, string ownerName){
    ofstream MyFile;
    MyFile.open("ChallanRecording.txt", ios::app);

    MyFile << "\n"<< ownerName << " :: " << registrationNum;

    cout << "Do you want to return to the home screen or search for another vehicle?" << endl;
                cout << "                                   B or S                              " << endl;

                return_home('c');

    MyFile.close();
}
//searches for a challan using the registration number of the vehiclesearches for a challan using the registration number of the vehicle
void recordOfChallan_2(int registrationNum){
    ifstream MyFile;
    string line;
    string name_file;
    string register_file;
    MyFile.open("ChallanRecording.txt", ios::in);

    while (getline(MyFile, line)) {
    cout << "                        ╔══════════════════════════╗" << endl;
    cout << "                        ║  Vehicle Registration    ║" << endl;
    cout << "                        ║         Portal           ║" << endl;
    cout << "                        ╚══════════════════════════╝" << endl;

        size_t delimiterPos = line.find(" :: ");

        if (delimiterPos != string::npos) {
            std::string data1 = line.substr(0, delimiterPos);
            std::string data2 = line.substr(delimiterPos + 3);

            name_file = data1.substr(data1.find_first_not_of(" \t\n\r"), data1.find_last_not_of(" \t\n\r") + 1);
            register_file = data2.substr(data2.find_first_not_of(" \t\n\r"), data2.find_last_not_of(" \t\n\r") + 1);

            if (register_file == to_string(registrationNum)) {
                cout << "There is a challan registered for the vechile with this registration number: " << registrationNum;

                cout << "Do you want to return to the home screen or search for another vehicle?" << endl;
                cout << "                                   B or S                              " << endl;

                 return_home('c');
            }
            else {
                cout << "There is no Challan registered for this registartion number" << endl;
                 return_home('c');
            }
        }
    }

    MyFile.close(); 
}
//searches for a challan using the owner’s name
void recordOfChallan_3(string ownerName){
   ifstream MyFile("VehicleRecording.txt");
    string line;
    string name_file;
    string register_file;
    while (getline(MyFile, line)){
    cout << "                        ╔══════════════════════════╗" << endl;
    cout << "                        ║  Vehicle Registration    ║" << endl;
    cout << "                        ║         Portal           ║" << endl;
    cout << "                        ╚══════════════════════════╝" << endl;

        size_t delimiterPos = line.find(" :: ");
        if (delimiterPos != std::string::npos) {
            std::string data1 = line.substr(0, delimiterPos);
            std::string data2 = line.substr(delimiterPos + 3);

            
            name_file = data1.substr(data1.find_first_not_of(" \t\n\r"), data1.find_last_not_of(" \t\n\r") + 1);
            register_file = data2.substr(data2.find_first_not_of(" \t\n\r"), data2.find_last_not_of(" \t\n\r") + 1);

            if (name_file == (ownerName)) {
                cout << "There is a challan registered for the vechile under the name of: " << name_file;
                cout << ", The vehicle is registered for this registration number: " << register_file << endl;

                cout << "Do you want to return to the home screen or search for another vehicle?" << endl;
                cout << "                                   B or S                              " << endl;

                return_home('c');
            }
            else {
                cout << "There is no Challan registered for this registartion number" << endl;
                return_home('c');
            }

        }
    }
    MyFile.close(); 
}

void trafContBooth(){
    // Traffic Control Booths
    cout<<"* WELCOME TO *"<<endl;
    cout<<"* TRAFFIC MANAGEMENT SYSTEM *"<<endl;
    cout<<"* ----Traffic Control Booths---- *"<<endl;
    cout<<"* *"<<endl;
    cout<<"* Enter your desired Option :- *"<<endl;
    cout<<"* *"<<endl;
    cout<<"* 1.Bhubaneswar Traffic Control Booth *"<<endl;
    cout<<"* 2. Cuttack Traffic Control Booth *"<<endl;
    cout<<"* 3. Puri Traffic Control Booth *"<<endl;
    cout<<"* *"<<endl;
    cout<<"* Press 0 if you want to go back to the home screen *"<<endl;
    cout<<"* Enter your desired choice ___ *"<<endl;
    cout<<"* *"<<endl;

    int TrafficCBChoice;
    cin>>TrafficCBChoice;
    switch (TrafficCBChoice){
        case 0:
            system("clear");
            welcome();
            break;
        case 1:
            trafficContBooth_1();
            break;
        case 2:
            trafficContBooth_2();
            break;
        case 3:
            trafficContBooth_3();
            break;
    }
}

void trafficContBooth_1(){
    system("clear");
    for (int i = 0; i < 100; ++i) {
        cout<<"Traffic Control Booth number 1"<<endl;
        cout<<"Vehicles that are going out of the city Vehicles that are coming into the city"<<endl;
        cout<<endl<<" going out "<<i+1<<" coming in "<<i+5<<endl;
        cout<<endl<<"           "<<i+1<<"           "<<i+5<<endl;
        delay_0();
        system("clear");
    }
}

void trafficContBooth_2(){
    system("clear");
    for (int i = 0; i < 100; ++i) {
        cout<<"Traffic Control Booth number 2"<<endl;
        cout<<"Vehicles that are going out of the city Vehicles that are coming into the city"<<endl;
        cout<<endl<<" going out "<<i+1<<" coming in "<<i+5<<endl;
        cout<<endl<<"           "<<i+5<<"           "<<i*7<<endl;
        delay_1();
        system("clear");
    }
}

void trafficContBooth_3(){
    system("clear");
    for (int i = 0; i < 100; ++i) {
        cout<<" Puri Traffic Control Booth "<<endl;
        cout<<"Vehicles that are going out of the city Vehicles that are coming into the city"<<endl;
        cout<<endl<<" going out "<<i+1<<" coming in "<<i+5<<endl;
        cout<<endl<<"           "<< i*16 <<"           "<< i*22 <<endl;
        system("clear");
        delay_2();
    }
}

void welcome(){
    system("clear");
    int userInput;
    std::cout << "                                       WELCOME TO TRAFFIC MANAGEMENT SYSTEM" << std::endl;
    std::cout<< "                                       **' ENTER YOUR DESIRED OPTION: '**"<<endl;
    cout << endl;
    std::cout<<"                                       **' Press 1 to record new vehicles '**"<<endl;
    std::cout<<"                                       **' Press 2 to get record of challan (traffic violation fine)'**"<<endl;
    std::cout<<"                                       **' Press 3 to search traffic control booths '**"<<endl;


    cin >> userInput;
    if(userInput > 0 && userInput < 4)
    {
    switch (userInput)
    {
        case 1:
            system("clear");
            recordOfVehicle();
        break;
        case 2:
            system("clear");
            recordOfChallan();
        break;
        case 3:
            system("clear");
            trafContBooth();
        break;
    }
    } 
    else{
    cout<<"Please enter a valid option !!"<<endl;
   // delay();
    system("clear");
    welcome();
    }
}

int main (){
    welcome();

    return 0;
}
