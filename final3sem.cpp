#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>   //for getch()
#include <windows.h> //for colour
#include <cstdio>
#include <algorithm>
using namespace std;
class ConsoleColor
{
public:
    static void setColor(int color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
};
void pressEnterToContinue()
{
    ConsoleColor::setColor(6);
    cout << "\n\n\n\t\t\t\t\t\tPress Enter to continue...";
    getchar();
    while (getchar() != '\n')
        ;
}
class Bus
{
public:
    string bus_id;
    int capacity;
    vector<bool> seats; // true for booked (1)
    Bus(string id, int cap) : bus_id(id), capacity(cap), seats(cap, false) {}
    string getBusID() const { return bus_id; }
    int getCapacity() const { return capacity; }
    void loadSeatsFromFile(ifstream &file)
    {
        for (int i = 0; i < capacity; ++i)
        {
            bool status;
            file >> status;
            seats[i] = status;
        }
    }
    void saveSeatsToFile(ofstream &file) const
    {
        file << bus_id << " " << capacity << " ";
        for (size_t i = 0; i < seats.size(); ++i)
        {
            file << seats[i] << " ";
        }
        file << "\n";
    }
    friend ostream &operator<<(ostream &os, const Bus &bus)
    {
        os << bus.bus_id << " " << bus.capacity << " ";
        for (size_t i = 0; i < bus.seats.size(); ++i)
        {
            os << bus.seats[i] << " ";
        }
        os << "\n";
        return os;
    }
};
class User
{
protected:
    string username;
    string password;

public:
    User() {}
    User(string u, string p) : username(u), password(p) {}
    virtual ~User() {}
    virtual void userMenu() = 0;                              // Pure virtual function for user menu
    static bool login(const string &user, const string &pass) // checks if entered details matched any stored details
    {
        ifstream userFile("users.txt");
        if (!userFile)
        {
            cout << "\n\nError opening file for reading.\n";
            return false;
        }
        string u, p;
        while (userFile >> u >> p)
        {
            if (u == user && p == pass)
            {
                return true;
            }
        }
        return false;
    }
    static void registerUser()
    {
        ConsoleColor::setColor(3);
        system("cls");
        cout << "\n\t\t\t\t\t\t\t\t~~USER REGISTRATION~~\n";
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
        ConsoleColor::setColor(7);

        string username, password;
        cout << "\n\n\n\n\n\t\t\t\t\t\tEnter Username: ";
        cin >> username;
        cout << "\n\t\t\t\t\t\tEnter Password: ";
        cin >> password;
        ofstream userFile("users.txt", ios::app);
        if (!userFile)
        {
            cout << "\n\nError opening file for writing.\n";
            return;
        }
        userFile << username << " " << password << "\n";
        userFile.close();
        ConsoleColor::setColor(2);
        cout << "\n\n\n\n\n\t\t\t\tRegistration successful!.....\n\n\n\n";
        pressEnterToContinue();
        system("cls");
    }
};
class RegularUser : public User
{
public:
    RegularUser(string u, string p) : User(u, p) {}
    void userMenu()
    {
        int choice;
        while (true)
        {
            system("cls");
            ConsoleColor::setColor(3);
            cout << "\t\t\t\t\t\t\t\t~~~~USER MENU~~~~\n\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
            ConsoleColor::setColor(7);
            cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t|-------|------------------------|\n";
            cout << "\t\t\t\t\t\t\t|  S.N  |       User Menu        |\n";
            cout << "\t\t\t\t\t\t\t|-------|------------------------|\n";
            cout << "\t\t\t\t\t\t\t|   1.  | Display Available Buses|\n";
            cout << "\t\t\t\t\t\t\t|   2.  |      Book Seat         |\n";
            cout << "\t\t\t\t\t\t\t|   3.  |    Cancel Booking      |\n";
            cout << "\t\t\t\t\t\t\t|   4.  |    Display Booking     |\n";
            cout << "\t\t\t\t\t\t\t|   5.  |      User Info         |\n";
            cout << "\t\t\t\t\t\t\t|   6.  |       Log Out          |\n";
            cout << "\t\t\t\t\t\t\t|-------|------------------------|\n";
            cout << "\n\n\n\n\t\t\t\t\t\tEnter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                displayBuses();
                break;
            case 2:
                manageBooking(true);
                break;
            case 3:
                manageBooking(false);
                break;
            case 4:
                displayBooking();
                break;
            case 5:
                userInfo();
                break;
            case 6:
                system("cls");
                ConsoleColor::setColor(2);
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t~~~Logging Out~~~\n\n\n\n\n\n\n\n\n\n\n";
                cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t   ~~Thank you for visiting~~";
                pressEnterToContinue();
                ConsoleColor::setColor(7);
                return;
            default:
                ConsoleColor::setColor(4);
                cout << "\n\n\n\t\t\t\t\t\t\t\tInvalid Choice!\n";
                break;
            }
            pressEnterToContinue();
        }
    }
    void manageBooking(bool isBooking)
    {
        system("cls");
        ConsoleColor::setColor(3);
        cout << "\t\t\t\t\t\t\t\t" << (isBooking ? "~~BOOK TICKET~~" : "~~CANCEL BOOKING~~") << "\n";
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
        ConsoleColor::setColor(7);

        string busId, userName;
        cout << "\n\t\tEnter Your Name: ";
        cin.ignore();
        getline(cin, userName);
        cout << "\n\t\tEnter Bus ID: ";
        cin >> busId;

        ifstream busFile("buses.txt");
        vector<Bus> buses;
        string id;
        int cap;

        while (busFile >> id >> cap)
        {
            Bus bus(id, cap);
            bus.loadSeatsFromFile(busFile);
            buses.push_back(bus);
        }
        busFile.close();

        bool busFound = false;

        for (size_t i = 0; i < buses.size(); ++i)
        {
            if (buses[i].bus_id == busId)
            {
                busFound = true;

                if (isBooking)
                {

                    ifstream inFile((userName + "_bookings.txt").c_str());
                    string tempName, tempBusId;
                    bool userExists = false;
                    streampos userPosition;

                    while (inFile >> tempName >> tempBusId)
                    {
                        if (tempName == userName && tempBusId == busId)
                        {
                            userExists = true;
                            userPosition = inFile.tellg();
                            break;
                        }

                        while (inFile.peek() != '\n' && inFile.good())
                        {
                            inFile.ignore(100, ' ');
                        }
                    }

                    inFile.close();

                    cout << "\n\n\t\tAVAILABLE SEAT NUMBERS: \n";
                    for (size_t j = 0; j < buses[i].seats.size(); ++j)
                    {
                        if (!buses[i].seats[j])
                        {
                            ConsoleColor::setColor((j % 2 == 0) ? 2 : 11);
                            cout << j + 1 << " ";
                        }
                    }
                    ConsoleColor::setColor(11);
                    cout << "\n\n\t\tWindow seats --> Sky blue\t\t   SEATS ARE ARRANGED AS::";
                    ConsoleColor::setColor(2);
                    cout << "\n\t\tAisle seats --> Green";
                    ConsoleColor::setColor(7);
                    cout << "    \t\t||  1    2       4    3  ||\n\t\t\t\t\t\t\t||  5    6       8    7  ||\n\t\t\t\t\t\t\t||  9    10      12   11 ||";

                    int numSeats;
                    cout << "\n\t\tEnter number of seats to book: ";
                    cin >> numSeats;

                    if (numSeats > buses[i].capacity || numSeats <= 0)
                    {
                        ConsoleColor::setColor(4);
                        cout << "\n\t\tInvalid number of seats to book: " << numSeats << "\n";
                        return;
                    }

                    vector<int> seatNumbers(numSeats);
                    cout << "\n\t\tEnter seat numbers to book: ";
                    for (int j = 0; j < numSeats; ++j)
                    {
                        cin >> seatNumbers[j];
                        if (seatNumbers[j] <= 0 || seatNumbers[j] > buses[i].capacity || buses[i].seats[seatNumbers[j] - 1])
                        {
                            ConsoleColor::setColor(4);
                            cout << "\n\t\tInvalid seat number: " << seatNumbers[j] << "\n";
                            return;
                        }
                    }

                    for (int j = 0; j < numSeats; ++j)
                    {
                        buses[i].seats[seatNumbers[j] - 1] = true;
                    }

                    ofstream outFile("buses.txt");
                    for (size_t k = 0; k < buses.size(); ++k)
                    {
                        buses[k].saveSeatsToFile(outFile);
                    }
                    outFile.close();

                    ofstream outFileUser((userName + "_bookings.txt").c_str(), ios::in | ios::out | ios::app);
                    if (userExists)
                    {
                        outFileUser.seekp(userPosition);
                        for (int j = 0; j < numSeats; ++j)
                        {
                            outFileUser << seatNumbers[j] << " ";
                        }
                        outFileUser << "\n";
                    }
                    else
                    {
                        outFileUser << userName << " " << busId << " ";
                        for (int j = 0; j < numSeats; ++j)
                        {
                            outFileUser << seatNumbers[j] << " ";
                        }
                        outFileUser << "\n";
                    }
                    outFileUser.close();

                    ConsoleColor::setColor(2);
                    cout << "\n\nBooking successful!\n";
                }

                else
                {
                    cout << "\n\n\t\tBOOKED SEAT NUMBERS: ";
                    ifstream userFile((userName + "_bookings.txt").c_str());
                    vector<int> bookedSeats;
                    bool foundSeats = false;
                    string tempName, tempBusId;

                    while (userFile >> tempName >> tempBusId)
                    {
                        if (tempName == userName && tempBusId == busId)
                        {
                            foundSeats = true;
                            int seat;
                            while (userFile >> seat)
                            {
                                bookedSeats.push_back(seat);
                            }
                            break;
                        }
                        else
                        {
                            while (userFile.peek() != '\n' && userFile.good())
                            {
                                userFile.ignore(100, ' ');
                            }
                        }
                    }
                    userFile.close();

                    if (!foundSeats)
                    {
                        ConsoleColor::setColor(4);
                        cout << "\n\t\tNo booking available for " << userName << " on bus ID " << busId << ".\n";
                        return;
                    }

                    for (size_t j = 0; j < bookedSeats.size(); ++j)
                    {
                        cout << bookedSeats[j] << " ";
                    }

                    cout << "\n";
                    int numSeats;
                    cout << "\n\t\tEnter number of seats to cancel: ";
                    cin >> numSeats;

                    if (numSeats > bookedSeats.size() || numSeats <= 0)
                    {
                        ConsoleColor::setColor(4);
                        cout << "\n\t\tInvalid number of seats to cancel: " << numSeats << "\n";
                        return;
                    }

                    vector<int> seatNumbers(numSeats);
                    cout << "\n\t\tEnter seat numbers to cancel: ";
                    for (int j = 0; j < numSeats; ++j)
                    {
                        cin >> seatNumbers[j];
                        if (find(bookedSeats.begin(), bookedSeats.end(), seatNumbers[j]) == bookedSeats.end())
                        {
                            ConsoleColor::setColor(4);
                            cout << "\n\t\tInvalid seat number: " << seatNumbers[j] << "\n";
                            return;
                        }
                    }

                    for (int j = 0; j < numSeats; ++j)
                    {
                        buses[i].seats[seatNumbers[j] - 1] = false;
                    }

                    ifstream inFile((userName + "_bookings.txt").c_str());
                    ofstream tempFile("temp.txt");
                    string name, id;
                    bool allSeatsCanceled = true;

                    while (inFile >> name >> id)
                    {
                        vector<int> updatedBookedSeats;
                        if (name == userName && id == busId)
                        {
                            int seat;
                            while (inFile >> seat)
                            {
                                if (find(seatNumbers.begin(), seatNumbers.end(), seat) == seatNumbers.end())
                                {
                                    updatedBookedSeats.push_back(seat);
                                    allSeatsCanceled = false;
                                }
                            }
                            if (!updatedBookedSeats.empty())
                            {
                                tempFile << name << " " << id << " ";
                                for (size_t j = 0; j < updatedBookedSeats.size(); ++j)
                                {
                                    tempFile << updatedBookedSeats[j] << " ";
                                }
                                tempFile << "\n";
                            }
                        }
                        else
                        {
                            tempFile << name << " " << id << " ";
                            while (inFile.peek() != '\n' && inFile.good())
                            {
                                int seat;
                                inFile >> seat;
                                tempFile << seat << " ";
                            }
                            tempFile << "\n";
                        }
                    }
                    inFile.close();
                    tempFile.close();
                    remove((userName + "_bookings.txt").c_str());
                    rename("temp.txt", (userName + "_bookings.txt").c_str());

                    if (allSeatsCanceled)
                    {
                        remove((userName + "_bookings.txt").c_str());
                        ConsoleColor::setColor(2);
                        cout << "\n\nAll bookings canceled. Booking file deleted.\n";
                    }

                    ofstream outFile("buses.txt");
                    for (size_t k = 0; k < buses.size(); ++k)
                    {
                        buses[k].saveSeatsToFile(outFile);
                    }
                    outFile.close();

                    ConsoleColor::setColor(2);
                    cout << "\n\nCancellation successful!\n";
                }
                break;
            }
        }

        if (!busFound)
        {
            ConsoleColor::setColor(4);
            cout << "\n\t\t\t\t\t\tBus not found.\n";
        }
    }
    void displayBooking()
    {
        system("cls");
        ConsoleColor::setColor(3);
        cout << "\t\t\t\t\t\t\t\t~~~BOOKING DISPLAY~\n";
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        ConsoleColor::setColor(7);
        ifstream busFile("buses.txt");
        if (!busFile)
        {
            cout << "\n\n\n\n\t\t\t\t\t\tError opening file.\n";
            return;
        }
        vector<Bus> buses; // buses is a vector that stores multiple bus objects
        string id;
        int cap;
        while (busFile >> id >> cap)
        {
            Bus bus(id, cap);
            bus.loadSeatsFromFile(busFile); // this function gives bus seat info (booked/not)
            buses.push_back(bus);           // bus object is added to the buses vector
        }
        busFile.close();
        cout << "\n\n\t\tAre you a admin? (y/n):  ";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << "\n\n\n\t\tEnter password:  ";
            string pw;
            cin >> pw;
            if (pw == "admin")
            {
                string busId;
                cout << "\n\n\t\tEnter Bus ID: ";
                cin >> busId;
                cout << "\n\n\n\n\t\t\t\t\t\tBooking Details\n";
                cout << "\t\t\t\t\t\t------------------\n";
                cout << "\t\t\t\t\t\tBus ID: " << busId << "\n\n";
                for (size_t i = 0; i < buses.size(); ++i) // checks if i is less than no of elements in bus vector
                {
                    if (buses[i].bus_id == busId) // The function searches for the bus in the buses vector
                    {
                        int c = 0;
                        cout << "\t\t\t\t\t\tBooked Seats: ";
                        for (size_t j = 0; j < buses[i].seats.size(); ++j)
                        {
                            if (buses[i].seats[j])
                            {
                                c++;
                                cout << j + 1 << " ";
                            }
                        }
                        if (!c)
                            cout << "0" << " ";
                        cout << "\n";
                        return;
                    }
                }
                cout << "\n\n\n\t\t\t\t\t\t\tBus not found.\n";
            }
            else
            {
                cout << "\n\n\n\t\t\t The password you've entered is wrong.";
                return;
            }
        }
        else
        {
            cout << "\n\n\n\t\t\t Sorry. This feature is only for admin.";
            return;
        }
    }
    void userInfo()
    {
        system("cls");
        ConsoleColor::setColor(3);
        cout << "\t\t\t\t\t\t\t\t~~~USER INFORMATION~\n";
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
        ConsoleColor::setColor(7);
        cout << "\n\n\t\tAre you a admin? (y/n):  ";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << "\n\n\n\t\tEnter password:  ";
            string pw;
            cin >> pw;
            if (pw == "admin")
            {
                ifstream userFile("users.txt", ios::in | ios::binary);
                if (!userFile)
                {
                    cout << "\n\n\n\n\t\t\t\t\t\tError opening file.\n";
                    return;
                }
                string username, password;
                cout << "\n\n\t\t\t\t\t\tUser Details\n";
                cout << "\t\t\t\t\t\t--------------\n";
                while (userFile >> username >> password)
                {
                    cout << "\n\t\t\t\t\t\tUsername: " << username;
                    cout << "\n\t\t\t\t\t\tPassword: " << password << "\n";
                }
                userFile.close();
            }
            else
            {
                cout << "\n\n\n\t\t\t The password you've entered is wrong.";
                return;
            }
        }
        else
        {
            cout << "\n\n\n\t\t\t Sorry. This feature is only for admin.";
            return;
        }
    }
    void displayBuses()
    {
        system("cls");
        Bus buses[] = {
            Bus("BUS001", 52),
            Bus("BUS002", 40),
            Bus("BUS003", 32),
            Bus("BUS004", 60)};

        ifstream checkFile("buses.txt");
        if (!checkFile)
        {
            ofstream busFile("buses.txt");
            if (!busFile)
            {
                ConsoleColor::setColor(4);
                cout << "\n\nError opening file for writing.\n";
                return;
            }
            for (int i = 0; i < sizeof(buses) / sizeof(buses[0]); ++i)
            {
                busFile << buses[i];
            }
            busFile.close();
        }
        checkFile.close();

        ConsoleColor::setColor(3);
        cout << "\t\t\t\t\t\t\t\t~~DISPLAY BUSES~~\n";
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
        ConsoleColor::setColor(7);

        ifstream busFile("buses.txt");
        if (!busFile)
        {
            ConsoleColor::setColor(4);
            cout << "\n\nError opening file.\n";
            return;
        }

        string id;
        int cap;

        while (busFile >> id >> cap)
        {
            Bus bus(id, cap);
            bus.loadSeatsFromFile(busFile);
            cout << "\nBus ID: " << bus.getBusID() << "\nCapacity: " << bus.getCapacity() << "\nSeats: ";

            for (size_t i = 0; i < bus.seats.size(); ++i)
            {
                ConsoleColor::setColor(bus.seats[i] ? 4 : 2); // Red for booked, Green for available
                cout << (bus.seats[i] ? "N " : "Y ");         // Display 'N' for booked, 'Y' for available
            }

            ConsoleColor::setColor(7);
            cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        }
        ConsoleColor::setColor(2);
        cout << "\n\n\n\n\n\t\t\t\t\t\tBUS001::Pokhara-->Kathmandu\tDeparture time::6 am\n\t\t\t\t\t\tBUS002::Pokhara-->Kathmandu\tDeparture time::2 pm\n\t\t\t\t\t\tBUS003::Pokhara-->Chitwan\tDeparture time::6 am\n\t\t\t\t\t\tBUS004::Pokhara-->Chitwan\tDeparture time::2 pm\n\n\n";

        busFile.close();
    }
};
int main()
{
    system("cls");
    ConsoleColor::setColor(3);
    cout << "\t\t\t\t\t\t\t~~~~BUS TICKET BOOKING SYSTEM~~~~\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
    cout << "\n\n\n\n\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";

    ConsoleColor::setColor(5);
    cout << "\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "\t\t\t\t\t        =                 WELCOME                   =\n";
    cout << "\t\t\t\t\t        =                   TO                      =\n";
    cout << "\t\t\t\t\t        =                   BUS                     =\n";
    cout << "\t\t\t\t\t        =                 TICKET                    =\n";
    cout << "\t\t\t\t\t        =                 BOOKING                   =\n";
    cout << "\t\t\t\t\t        =                  SYSTEM                   =\n";
    cout << "\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    ConsoleColor::setColor(3);
    cout << "\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n\n\n\n";
    pressEnterToContinue();
    system("cls");

    int choice;
    while (true)
    {
        system("cls");
        ConsoleColor::setColor(3);
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t---------------------~LOGIN~--------------------\n\n\n\n";

        ConsoleColor::setColor(7);
        cout << "\n\n\t\t\t\t\t\t1. Register\n";
        cout << "\t\t\t\t\t\t2. Login\n";
        cout << "\t\t\t\t\t\t3. Exit\n";
        cout << "\n\n\n\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            User::registerUser();
            break;
        case 2:
        {
            system("cls");
            string username, password;
            ConsoleColor::setColor(3);
            cout << "\n\t\t\t\t\t\t\t\t~~USER LOGIN~~\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
            ConsoleColor::setColor(7);
            cout << "\n\t\tEnter Username: ";
            cin >> username;
            cout << "\n\t\tEnter Password: ";
            cin >> password;
            if (User::login(username, password))
            {
                RegularUser user(username, password);
                ConsoleColor::setColor(2);
                cout << "\n\n\t\t\t\t\tLogin Successful......";
                pressEnterToContinue();
                user.userMenu();
            }
            else
            {
                ConsoleColor::setColor(4);
                cout << "\n\n\t\tInvalid username or password.\n";
                pressEnterToContinue();
                system("cls");
            }
            break;
        }
        case 3:
            ConsoleColor::setColor(2);
            cout << "\n\n\n\t\t\t\t\t\t\t\t~~Exiting~~\n";
            return 0;
        default:
            ConsoleColor::setColor(4);
            cout << "\n\n\t\tInvalid Choice!\n";
            pressEnterToContinue();
            break;
        }
        ConsoleColor::setColor(7);
    }
    return 0;
}
