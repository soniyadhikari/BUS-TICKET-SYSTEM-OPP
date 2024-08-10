//#include <iostream>
//#include <fstream>
//#include <limits>
//#include <string>
//#include <conio.h>
//#include <iomanip>
//
//using namespace std;
//
//class User {
//protected:
//    string username;
//    string password;
//
//public:
//    bool login();
//    bool registerUser();
//    static void displayUserLogins();
//};
//
//class Admin : public User {
//private:
//    static const string adminUsername;
//    static const string adminPassword;
//
//public:
//    bool adminLogin();
//    void addRoute();
//    void deleteRoute();
//    void displayRoutes();
//    void viewUserLogins();
//};
//
//class BusRoute {
//public:
//    static void displayRoutes();
//    static bool isRouteExists(int routeNumber);
//    static void addRoute();
//    static void deleteRoute();
//    static void displayRoutesByUserChoice();
//    static void displayRoutesBySourceAndDestination(const string &source, const string &destination) ;
//};
//
//// Predefined admin credentials
//const string Admin::adminUsername = "admin";
//const string Admin::adminPassword = "adminpass";
//
//// Helper functions for file operations
//bool checkFileOpen(ifstream &file, const string &filename) {
//    if (!file.is_open()) {
//        cerr << "Error opening file: " << filename << endl;
//        return false;
//    }
//    return true;
//}
//
//bool checkFileOpen(ofstream &file, const string &filename) {
//    if (!file.is_open()) {
//        cerr << "Error opening file: " << filename << endl;
//        return false;
//    }
//    return true;
//}
//
//// Helper function to pause and wait for user input
//void pressEnterToContinue() {
//	cout << "\033[1;93m";
//    cout << "\n\n\t\t\t\t\tPress Enter to continue...";
//    cout<<"\033[0m";
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    cin.get();
//}
//
//// Implementation of User class methods
//bool User::login() {
//    system("cls"); // Use "clear" for UNIX-based systems
//    cout << "\033[92m";
//    cout << "\n\n\n\t\t\t\t\t\t\t\t~~~LOGIN~~~";
//    cout << "\n\t\t\t\t\t\t\t   \033[1;96m <------------------>\033[0m\n\n\n ";
//    cout << "\n\n\n\n\t\t\t\t \x1b[36m Enter your login credentials\033[0m  ";
//    cout << "\n\n\t\t\t\t Username: ";
//    cin >> username;
//    cout << "\n\t\t\t\t Password: ";
//    cin >> password;
//
//    ifstream file("user_data.txt");
//    if (!checkFileOpen(file, "user_data.txt")) {
//        // File does not exist or cannot be opened for reading
//        cout << "\n\n\t\t\t\tNo users registered yet.\n";
//        pressEnterToContinue();
//        return false;
//    }
//
//    string fileUsername, filePassword;
//    bool loginSuccessful = false;
//    while (file >> fileUsername >> filePassword) {
//        if (fileUsername == username && filePassword == password) {
//            loginSuccessful = true;
//            break;
//        }
//    }
//    file.close();
//
//    if (loginSuccessful) {
//        cout <<"\033[0;32m"<< "\n\n\n\n\n\t\t\t\t\t\t\t~~Login successful!~~\n\n\n\n\n";
//    } else {
//        cout <<"\033[0;91m"<< "\n\n\n\n\n\t\t\t\tInvalid username or password.\n\n\n\n\n";
//    }
//    pressEnterToContinue();
//    return loginSuccessful;
//}
//
//
//bool User::registerUser() {
//    system("cls"); // Use "clear" for UNIX-based systems
//    cout << "\033[92m";
//    cout << "\n\n\n\t\t\t\t\t\t\t\t*--REGISTRATION--*";
//    cout << "\n\t\t\t\t\t\t\t   \033[1;96m <------------------------->\033[0m\n\n ";
//    cout << "\n\n\n\n\t\t\t\t \x1b[36m Enter the details\033[0m  ";
//    cout << "\n\n\t\t\t\t Username: ";
//    cin >> username;
//
//    // Check if username already exists
//    ifstream checkFile("user_data.txt");
//    bool usernameTaken = false; // Flag to check if the username is already taken
//    
//    if (!checkFile) {
//        // File does not exist or cannot be opened for reading
//        // This is not an error; we'll create the file on the next write operation
//        checkFile.close();
//    } else {
//        // File exists, check for existing username
//        string existingUsername, existingPassword;
//        while (checkFile >> existingUsername >> existingPassword) {
//            if (existingUsername == username) {
//                usernameTaken = true;
//                break;
//            }
//        }
//        checkFile.close();
//    }
//    
//    if (usernameTaken) {
//        cout << "\n\n\n\n\t\t\t\t\033[1;96m Username already taken, please choose another:\033[0m";
//        _getch(); // Wait for user input
//        return registerUser(); // Recursive call to re-register
//    }
//    
//    cout << "\n\t\t\t\tEnter password:\t";
//    cin >> password;
//    while (password.length() < 6) {
//        cout << "\n\n\t\t\t\t\t\033[1;96m Password too short! Enter password again:\033[0m";
//        cin >> password;
//    }
//    
//    ofstream fp("user_data.txt", ios::app);
//    if (!fp) {
//        cerr << "\n\n\t\t\t\t\tError opening user data file for writing.\n";
//        pressEnterToContinue();
//        return false;
//    }
//    
//    fp << username << " " << password << endl;
//    fp.close();
//    
//    system("cls");
//    cout << "\n\n\n\t\033[1;96mCheck user: \033[0m";
//    cout << "\n\n\t\t\tUSERNAME:\t" << username;
//    cout << "\n\n\t\t\tPASSWORD:\t" << password;
//    
//    cout << "\033[1;32m"; // Green text
//    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tSuccessfully registered!\n";
//    cout << "\n\n\n\n\t\t\t\t\t\t\t\t Welcome, " << username << "!";
//    cout << "\033[0m"; // Reset text color to default
//    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t Enter any key to continue.....\n\n\n\n\n";
//    pressEnterToContinue();
//    return true;
//}
//// Implementation of Admin class methods
//bool Admin::adminLogin() {
//	system("cls");
//	 cout<<"\033[92m";
//    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tADMIN LOGIN";
//    cout<<"\n\t\t\t\t\t\t\t\033[1;96m          <--------------------->\033[0m\n\n ";
//    cout<<"\033[1;94m";
//    cout << "\n\n\n\n\t\t\t\tEnter admin credentials:\n";
//    cout << "\t\t\t\t************************\n\n\n\n";
//    cout<<"\033[0;95m";
//    cout << "\n\t\t\t\tUsername: ";
//    cin >> username;
//    cout << "\n\t\t\t\tPassword: ";
//    cin >> password;
//    cout<<"\033[0m";
//
//    if (username == adminUsername && password == adminPassword) {
//        cout << "\n\n\n\n\n\n\t\t\t\t\t\tAdmin login successful!\n\n\n\n\n\n\n";
//        pressEnterToContinue();
//        return true;
//    }
//    cout << "\n\n\t\t\t\tInvalid admin credentials.";
//    pressEnterToContinue();
//    return false;
//}
//
//void Admin::addRoute() {
//    BusRoute::addRoute();
//}
//
//void Admin::deleteRoute() {
//    BusRoute::deleteRoute();
//}
//
//void Admin::displayRoutes() {
//    BusRoute::displayRoutes();
//}
//void Admin::viewUserLogins() {
//    ifstream file("user_data.txt");
//    if (!checkFileOpen(file, "user_data.txt")) return;
//    system("cls");
//    	cout<<"\033[0;31m";
//	cout<<"\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**";
//     cout<<"\033[1;92m";
//    cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//    cout<<"\n\t\t\t\t\t        =                 USER INFO                 =";
//    cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//    	cout<<"\033[0;31m";
//	cout<<"\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n\n\n\n\n";
//     cout<<"\033[37m";
//    cout << "\033[0;96m"<<"\n\t\t\t\t\tUsername\tPassword\n";
//     cout<< "\t\t\t\t\t*-*-*-*-\t*-*-*-*-\n";
//    
//    string fileUsername, filePassword;
//    while (file >> fileUsername >> filePassword) {
//        cout << "\033[0m"<<"\n\t\t\t\t\t" << fileUsername << "\t\t" << filePassword;
//    }
//    cout<<"\n\n\n\n\n\n\n";
//    file.close();
//    pressEnterToContinue();
//}
//// Implementation of BusRoute class methods
//
//void BusRoute::displayRoutes() {
//	system("cls");
//    ifstream file("bus_routes.txt");
//    if (!checkFileOpen(file, "bus_routes.txt")) return;
//	cout<<"\033[0;31m";
//	cout<<"\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**";
//    cout<<"\033[1;92m";
//    cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//    cout<<"\n\t\t\t\t\t        =             AVAILABLE BUS ROUTES           =";
//    cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//    cout<<"\033[0;31m";
//	cout<<"\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n\n\n";
//     cout<<"\033[37m";
//    cout << "\n" << setw(20) << "\033[0;96m"<<"Route Number" 
//         << setw(20) << "Source" 
//         << setw(20) << "Destination" 
//         << setw(20) << "Regular Fare" 
//         << setw(20) << "Student Fare" 
//         << setw(20) << "Departure Time" 
//         << setw(15) << "Arrival Time" 
//         << endl;
//
//    cout << setfill('-') 
//         << setw(140) << "-" 
//         << setfill(' ') <<"\033[0m"
//         << endl;
//
//    int routeNumber;
//    string source, destination, departureTime, arrivalTime;
//    float regularFare, studentFare;
//
//    // Read and display route data
//    while (file >> routeNumber >> source >> destination >> regularFare >> studentFare >> departureTime >> arrivalTime) {
//        cout << "" 
//             << setw(20) << routeNumber 
//             << setw(20) << source 
//             << setw(20) << destination 
//             << setw(20) << regularFare 
//             << setw(20) << studentFare 
//             << setw(20) << departureTime 
//             << setw(15) << arrivalTime 
//             << endl;
//    }
//    cout<<"\n\n\n\n\n\n\n\n\n";
//
//    file.close();
//    pressEnterToContinue();
//}
//bool BusRoute::isRouteExists(int routeNumber) {
//    ifstream file("bus_routes.txt");
//    if (!checkFileOpen(file, "bus_routes.txt")) return false;
//
//    int route;
//    while (file >> route) {
//        file.ignore(numeric_limits<streamsize>::max(), '\n');
//        if (route == routeNumber) {
//            file.close();
//            return true;
//        }
//    }
//    file.close();
//    return false;
//}
//
//void BusRoute::addRoute() {
//	system("cls");
//	cout<<"\033[0;31m";
//	cout<<"\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**";
//	 cout<<"\033[1;92m";
//    cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//    cout<<"\n\t\t\t\t\t        =               ADD NEW ROUTE                =";
//    cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
//    cout<<"\033[0;31m";
//	cout<<"\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n\n";
//     cout<<"\033[37m";
//    ofstream file("bus_routes.txt", ios::app);
//    if (!checkFileOpen(file, "bus_routes.txt")) return;
//
//    int routeNumber;
//    string source, destination;
//    float regularFare, studentFare;
//    string departureTime, arrivalTime; // New fields for time
//    cout << "\n\n\n\n\t\t\t\t  Enter the following details:\n\n\n";
//    cout<<"\033[0;96m";
//    cout << "\n\t\t\t\tRoute Number: ";
//    cin >> routeNumber;
//
//    if (isRouteExists(routeNumber)) {
//        cerr <<"\033[0;31m"<< "\n\n\t\t\t\tRoute number already exists.\n"<< "\033[0m";
//        file.close();
//        pressEnterToContinue();
//        return;
//    }
//
//    cin.ignore(); // Clear input buffer before using getline
//
//    cout << "\n\t\t\t\tSource: ";
//    getline(cin, source); // Allow spaces in source name
//
//    cout << "\n\t\t\t\tDestination: ";
//    getline(cin, destination); // Allow spaces in destination name
//
//    cout << "\n\t\t\t\tRegular Fare: ";
//    while (!(cin >> regularFare) || regularFare < 0) {
//        cout << "\033[0;31m"<< "\n\t\t\t\tInvalid input. Please enter a positive number for Regular Fare: "<< "\033[0m";
//        cin.clear(); // Clear error flag
//        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
//    }
//
//    cout << "\n\t\t\t\tStudent Fare: ";
//    while (!(cin >> studentFare) || studentFare < 0) {
//         cout << "\033[0;31m"<< "\n\t\t\t\tInvalid input. Please enter a positive number for Student Fare: "<< "\033[0m";
//        cin.clear(); // Clear error flag
//        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
//    }
//
//    cout << "\n\t\t\t\tDeparture Time (HH:MM): ";
//    cin >> departureTime;
//
//    cout << "\n\t\t\t\tArrival Time (HH:MM): ";
//    cin >> arrivalTime;
//
//    file << routeNumber << " " << source << " " << destination << " " 
//         << regularFare << " " << studentFare << " " 
//         << departureTime << " " << arrivalTime << "\n";
//    file.close();
//    cout<<"\033[1;92m";
//    cout << "\n\n\t\t\t\t\t     Route added successfully!";
//    pressEnterToContinue();
//}
//
//void BusRoute::deleteRoute() {
//	system("cls");
//		cout<<"\033[0;31m";
//	cout<<"\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**";
//	 cout<<"\033[1;92m";
//    cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//    cout<<"\n\t\t\t\t\t        =             DELETE BUS ROUTE                =";
//   cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//   	cout<<"\033[0;31m";
//	cout<<"\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n\n\n";
//    cout<<"\033[37m";
//    ifstream file("bus_routes.txt");
//    if (!checkFileOpen(file, "bus_routes.txt")) return;
//
//    ofstream tempFile("temp.txt");
//    if (!checkFileOpen(tempFile, "temp.txt")) return;
//
//    int routeNumber;
//    cout<<"\033[0;96m";
//    cout << "\n\n\n\n\t\t\t\tEnter the Route Number to delete: ";
//    cin >> routeNumber;
//
//    int route;
//    string source, destination;
//    float regularFare, studentFare;
//    bool found = false;
//    while (file >> route >> source >> destination >> regularFare >> studentFare) {
//        if (route != routeNumber) {
//            tempFile << route << " " << source << " " << destination << " " << regularFare << " " << studentFare << "\n";
//        } else {
//            found = true;
//        }
//    }
//    file.close();
//    tempFile.close();
//
//    if (found) {
//        remove("bus_routes.txt");
//        rename("temp.txt", "bus_routes.txt");
//        cout <<"\033[0;32m" <<"\n\n\n\n\t\t\t\t\t    Route deleted successfully!\n\n\n";
//    } else {
//        cerr <<"\033[0;31m"<< "\n\n\n\n\t\t\t\t\t    Route not found!\n\n\n";
//    }
//    pressEnterToContinue();
//}
//
//void BusRoute::displayRoutesBySourceAndDestination(const string &source, const string &destination) {
//
//    ifstream file("bus_routes.txt");
//    if (!checkFileOpen(file, "bus_routes.txt")) return;
//
//    bool routeFound = false;
//
//    cout << "\033[0;92m"<<"\n\n\n\n\t\t\t\t\tDisplaying Routes from " << source << " to " << destination << ":";
//    cout << "\n\t\t\t\t   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
//
// cout << "\n" << setw(20) << "\033[0;96m"<<"Route Number" 
//         << setw(20) << "Source" 
//         << setw(20) << "Destination" 
//         << setw(20) << "Regular Fare" 
//         << setw(20) << "Student Fare" 
//         << setw(20) << "Departure Time" 
//         << setw(15) << "Arrival Time" 
//         << endl;
//
//    cout << setfill('-') 
//         << setw(140) << "-" 
//         << setfill(' ') <<"\033[0m"
//         << endl;
//
//
//
//    int routeNumber;
//    string fileSource, fileDestination, departureTime, arrivalTime;
//    float regularFare, studentFare;
//
//    while (file >> routeNumber >> fileSource >> fileDestination >> regularFare >> studentFare >> departureTime >> arrivalTime) {
//        if (fileSource == source && fileDestination == destination) {
//            cout << "" 
//                 << setw(20) << routeNumber 
//                 << setw(20) << fileSource 
//                 << setw(20) << fileDestination 
//                 << setw(20) << regularFare 
//                 << setw(20) << studentFare 
//                 << setw(20) << departureTime 
//                 << setw(15) << arrivalTime 
//                 << endl;
//            routeFound = true;
//        }
//    }
//        cout<<"\n\n\n\n\n\n\n\n\n";
// 
//    if (!routeFound) {
//        cout <<"\033[0;91m"<< "\n\n\n\n\t\t\t\t\tNo routes found from " << source << " to " << destination << "\n\n\n\n\n";
//    }
//
//    file.close();
//    pressEnterToContinue();
//}
//void displayUserMenu(User &user) {
//system("cls");
//
//int choice;
//do{
//	system("cls");
//
//       cout<<"\033[92m";	
//       cout<<"\n\n\n\t\t\t\t\t\t\t\t*~~User Page~~*";
//       cout<<"\n\t\t\t\t\t\t\t   \033[1;96m <---------------------->\033[0m\n\n ";
//       cout<<"\n\n\n";
//        cout<<"\033[0;31m"<<"\n\n\n\n\t\t\t\t\t\t\t*************************************";
//        cout<<"\x1b[36m";
//        cout<<"\n\t\t\t\t\t\t\t*       ||     User Menu    ||      *";
//        cout<<"\033[0;31m"<<"\n\t\t\t\t\t\t\t*************************************\n";
//        cout<<"\033[0m";
//        
//    cout << "\t\t\t\t\t\t\t 1. Display All Routes";
//    cout << "\n\t\t\t\t\t\t\t 2. Search Route by Source and Destination";
//    cout << "\n\t\t\t\t\t\t\t 3. Logout\n";
//    cout<<"\033[0;31m"<<"\t\t\t\t\t\t\t*************************************"<<"\033[0m";
//    cout <<"\033[0;35m"<<"\n\n\n\n\n\n\t\t\t\t\t\t\t Enter your choice: ";
//    cin>>choice;
//
//    switch (choice) {
//        case 1:
//            // Display all routes
//            BusRoute::displayRoutes();
//            break;
//
//        case 2: {
//        	system("cls");
//            string source, destination;
//           	cout<<"\033[0;31m";
//	cout<<"\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**";
//         cout<<"\033[1;92m";
//        cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//        cout<<"\n\t\t\t\t\t        =        DISPLAY BUS ROUTES BY CHOICE        =";
//        cout<<"\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//      	cout<<"\033[0;31m";
//	cout<<"\n\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n\n";
//          cout<<"\033[0;94m";
//            cout << "\n\n\t\t\t\t Enter Source: ";
//            cin.ignore(); // Clear the input buffer
//            getline(cin, source);
//
//            cout << "\n\n\t\t\t\t Enter Destination: ";
//            getline(cin, destination);
//
//            // Display route details based on source and destination
//            BusRoute::displayRoutesBySourceAndDestination(source, destination);
//            break;
//        }
//
//       case 3:
//system("cls");
//cout<<"\033[0;96m"<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t~~Thank you for visiting~~\n\n\n\n\n";
//                cout << "\033[0;31m"<<"\n\n\t\t\t\t\t\tLogging out...\n\n\n\n\n\n\n\n\n\n";
//                pressEnterToContinue();
//                break;
//
//        default:
//            cerr <<"\033[0;31m"<< "\n\n\n\n\t\t\t\t\t\t Invalid choice!\n";
//            pressEnterToContinue();
//    }
//}while (choice != 3);
//}
//void displayAdminMenu(Admin &admin) {
//    int choice;
//    do {
//    	system("cls");
//    	cout<<"\033[0;32m";
//    	cout<<"\t\t\t\t\t\t\t\t\tADMINISSTRATION SYSTEM\n";
//    	cout << "\033[1;96m";
//    	cout<<"\t\t\t\t\t\t\t     <------------------------------------------->\n\n\n\n\n\n";
//        cout << "\033[0m";
//		cout << "\t\t\t\t\t\t\t\t*****************************";
//		cout<<"\033[0;34m"; 
//    cout << "\n\t\t\t\t\t\t\t\t*   ||Administrator Menu||  *\n";
//    cout<<"\033[0m";
//    cout << "\t\t\t\t\t\t\t\t*****************************\n";
//    cout << "\t\t\t\t\t\t\t\t| " << setw(2) << "1." << " | " << setw(20) << left << "Add Route" << " |\n";
//    cout << "\t\t\t\t\t\t\t\t| " << setw(2) << "2." << " | " << setw(20) << left << "Delete Route" << " |\n";
//    cout << "\t\t\t\t\t\t\t\t| " << setw(2) << "3." << " | " << setw(20) << left << "Display Routes" << " |\n";
//    cout << "\t\t\t\t\t\t\t\t| " << setw(2) << "4." << " | " << setw(20) << left << "User Info" << " |\n";
//    cout << "\t\t\t\t\t\t\t\t| " << setw(2) << "5." << " | " << setw(20) << left << "Log Out" << " |\n";
//    cout << "\t\t\t\t\t\t\t\t*****************************\n";
//    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\033[1;95mEnter your choice:\033[0m ";
//        cin >> choice;
//        switch (choice) {
//            case 1:
//                admin.addRoute();
//                break;
//            case 2:
//                admin.deleteRoute();
//                break;
//            case 3:
//                admin.displayRoutes();
//                break;
//            case 4:
//                admin.viewUserLogins(); // Call the new function
//                break;
//            case 5:
//                cout << "\033[0;91m"<<"\n\n\t\t\t\t\t\t\t\tLogging out...\n\n\n\n";
//                pressEnterToContinue();
//                break;
//            default:
//                cerr << "\n\n\t\t\t\t\t\tInvalid choice!";
//                pressEnterToContinue();
//        }
//    } while (choice != 5);
//}
//
//int main() {
//	 system("cls");    
//    cout<<"\033[1;91m";
//    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t BUS ROUTE MANAGEMENT SYSTEM";
//    cout<<"\n\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n\n\n\n\n\n\n";
//    cout<<"\033[1;92m";
//    cout<<"\t\t\t\t\tW       W  EEEEEEE  L          CCCCC   OOOO   M     M  EEEEEEE\n";
//    cout<<"\t\t\t\t\tW       W  E        L        CC       O    O  MM   MM  E      \n";
//    cout<<"\t\t\t\t\tW   W   W  EEEEEEE  L       CC        O    O  M M M M  EEEEEEE\n";
//    cout<<"\t\t\t\t\tW W   W W  E        L        CC       O    0  M  M  M  E      \n";
//    cout<<"\t\t\t\t\tW       W  EEEEEEE  LLLLLL     CCCCC   OOOO   M     M  EEEEEEE\n";
//    cout << "\n\t\t\t\t\033[1;96m     *#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\033[0m\n\n ";
//    cout<<"\033[0m\n\n\n";
//    pressEnterToContinue();
//     
//    int choice; 
//    do {
//        system("cls");
//        cout << "\033[92m";
//        cout << "\n\n\n\n\n\t\t\t\t\t\t\t      <------------------------------>\n ";
//        cout << "\t\t\t\t\t\t\t\t*--Bus Management System--*";
//        cout << "\n\t\t\t\t\t\t\t      <------------------------------>\n\n ";
//        cout << "\n\n\n";
//        cout << "\x1b[36m";
//        cout << "\n\n\t\t\t\t\t\t\t 1. User Login";
//        cout << "\n\n\t\t\t\t\t\t\t 2. Admin Login";
//        cout << "\n\n\t\t\t\t\t\t\t 3. Register";
//        cout << "\n\n\t\t\t\t\t\t\t 4. Exit\n\n\n\n\n";
//        cout<<"\n\n\t\t\t\t\t\t\033[1;95mEnter your choice:\033[0m ";
//        cin >> choice;
//        switch (choice) {
//            case 1: {
//                User user;
//                if (user.login()) {
//                    displayUserMenu(user);
//                }
//                break;
//            }
//            case 2: {
//                Admin admin;
//                if (admin.adminLogin()) {
//                    displayAdminMenu(admin);
//                }
//                break;
//            }
//            case 3: {
//                User user;
//                if (user.registerUser()) {
//                    displayUserMenu(user);
//                }
//                
//                break;
//            }
//            case 4:
//            	system("cls");
//                cout <<"\033[0;91m"<< "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t~...Exiting...~\n\n\n\n\n\n\n";
//                pressEnterToContinue();
//                break;
//            default:
//                cerr << "\n\n\t\t\t\t\t\tInvalid choice!";
//                pressEnterToContinue();
//        }
//    } while (choice != 4);
//    return 0;
//}



#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;

class User {
protected:
    string username;
    string password;

public:
    bool login();
    bool registerUser();
    static void displayUserLogins();
};

class Admin : public User {
private:
    static const string adminUsername;
    static const string adminPassword;

public:
    bool adminLogin();
    void addRoute();
    void deleteRoute();
    void displayRoutes();
    void viewUserLogins();
};

class BusRoute {
public:
    static void displayRoutes();
    static bool isRouteExists(int routeNumber);
    static void addRoute();
    static void deleteRoute();
    static void displayRoutesByUserChoice();
    static void displayRoutesBySourceAndDestination(const string &source, const string &destination) ;
};

// Predefined admin credentials
const string Admin::adminUsername = "admin";
const string Admin::adminPassword = "adminpass";

// Helper functions for file operations
bool checkFileOpen(ifstream &file, const string &filename) {
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }
    return true;
}

bool checkFileOpen(ofstream &file, const string &filename) {
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }
    return true;
}

// Helper function to pause and wait for user input
void pressEnterToContinue() {
	cout<<"\033[1;31m";
    cout << "\n\n\t\t\t\t\tPress Enter to continue...";
    cout<<"\033[0m";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Implementation of User class methods
bool User::login() {
    system("cls"); // Use "clear" for UNIX-based systems
    cout << "\033[92m";
    cout << "\n\n\n\t\t\t\t\t\t\t\t*--LOGIN--*";
    cout << "\n\t\t\t\t\t\t\t   \033[1;96m <-------------------->\033[0m\n\n ";
    cout << "\n\n\n\n\t\t\t\t \x1b[36m Enter your login credentials\033[0m  ";
    cout << "\n\n\t\t\t\t Username: ";
    cin >> username;
    cout << "\n\t\t\t\t Password: ";
    cin >> password;

    ifstream file("user_data.txt");
    if (!checkFileOpen(file, "user_data.txt")) {
        // File does not exist or cannot be opened for reading
        cout << "\n\n\t\t\t\tNo users registered yet.\n";
        pressEnterToContinue();
        return false;
    }

    string fileUsername, filePassword;
    bool loginSuccessful = false;
    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            loginSuccessful = true;
            break;
        }
    }
    file.close();

    if (loginSuccessful) {
        cout << "\n\n\t\t\t\tLogin successful!";
    } else {
        cout << "\n\n\t\t\t\tInvalid username or password.";
    }
    pressEnterToContinue();
    return loginSuccessful;
}


bool User::registerUser() {
    system("cls"); // Use "clear" for UNIX-based systems
    cout << "\033[92m";
    cout << "\n\n\n\t\t\t\t\t\t\t\t*--REGISTRATION--*";
    cout << "\n\t\t\t\t\t\t\t   \033[1;96m <------------------------->\033[0m\n\n ";
    cout << "\n\n\n\n\t\t\t\t \x1b[36m Enter the details\033[0m  ";
    cout << "\n\n\t\t\t\t Username: ";
    cin >> username;

    // Check if username already exists
    ifstream checkFile("user_data.txt");
    bool usernameTaken = false; // Flag to check if the username is already taken
    
    if (!checkFile) {
        // File does not exist or cannot be opened for reading
        // This is not an error; we'll create the file on the next write operation
        checkFile.close();
    } else {
        // File exists, check for existing username
        string existingUsername, existingPassword;
        while (checkFile >> existingUsername >> existingPassword) {
            if (existingUsername == username) {
                usernameTaken = true;
                break;
            }
        }
        checkFile.close();
    }
    
    if (usernameTaken) {
        cout << "\n\n\n\n\t\t\t\t\033[1;96m Username already taken, please choose another:\033[0m";
        _getch(); // Wait for user input
        return registerUser(); // Recursive call to re-register
    }
    
    cout << "\n\t\t\t\tEnter password:\t";
    cin >> password;
    while (password.length() < 6) {
        cout << "\n\n\t\t\t\t\t\033[1;96m Password too short! Enter password again:\033[0m";
        cin >> password;
    }
    
    ofstream fp("user_data.txt", ios::app);
    if (!fp) {
        cerr << "\n\n\t\t\t\t\tError opening user data file for writing.\n";
        pressEnterToContinue();
        return false;
    }
    
    fp << username << " " << password << endl;
    fp.close();
    
    system("cls");
    cout << "\n\n\n\t\033[1;96mCheck user: \033[0m";
    cout << "\n\n\t\t\tUSERNAME:\t" << username;
    cout << "\n\n\t\t\tPASSWORD:\t" << password;
    
    cout << "\033[1;32m"; // Green text
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tSuccessfully registered!\n";
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t Welcome, " << username << "!";
    cout << "\033[0m"; // Reset text color to default
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t Enter any key to continue.....";
    pressEnterToContinue();
    return true;
}
// Implementation of Admin class methods
bool Admin::adminLogin() {
	system("cls");
	 printf("\033[92m");
    printf("\n\n\n\t\t\t\t\t\t\t\t*--ADMIN LOGIN--*");
    printf("\n\t\t\t\t\t\t\t\033[1;96m    <-------------------------->\033[0m\n\n ");
    cout << "\n\n\n\n\t\t\t\tEnter admin credentials:\n";
    cout << "\n\t\t\t\tUsername: ";
    cin >> username;
    cout << "\n\t\t\t\tPassword: ";
    cin >> password;

    if (username == adminUsername && password == adminPassword) {
        cout << "\n\n\t\t\t\tAdmin login successful!";
        pressEnterToContinue();
        return true;
    }
    cout << "\n\n\t\t\t\tInvalid admin credentials.";
    pressEnterToContinue();
    return false;
}

void Admin::addRoute() {
    BusRoute::addRoute();
}

void Admin::deleteRoute() {
    BusRoute::deleteRoute();
}

void Admin::displayRoutes() {
    BusRoute::displayRoutes();
}
void Admin::viewUserLogins() {
    ifstream file("user_data.txt");
    if (!checkFileOpen(file, "user_data.txt")) return;
    system("cls");
     printf("\033[1;92m");
    printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t\t        =                 USER INFO                 =");
    printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n\n");
     printf("\033[37m");
    cout << "\n\t\t\t\t\tUsername\tPassword\n";
    
    string fileUsername, filePassword;
    while (file >> fileUsername >> filePassword) {
        cout << "\n\t\t\t\t\t" << fileUsername << "\t\t" << filePassword;
    }
    file.close();
    pressEnterToContinue();
}
// Implementation of BusRoute class methods

void BusRoute::displayRoutes() {
	system("cls");
    ifstream file("bus_routes.txt");
    if (!checkFileOpen(file, "bus_routes.txt")) return;

    // Print header
    printf("\033[1;92m");
    printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t\t        =             AVAILABLE BUS ROUTES           =");
    printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n\n");
     printf("\033[37m");
    cout << "\n\t\t\t\t\t" << setw(15) << "Route Number" 
         << setw(20) << "Source" 
         << setw(20) << "Destination" 
         << setw(15) << "Regular Fare" 
         << setw(15) << "Student Fare" 
         << setw(15) << "Departure Time" 
         << setw(15) << "Arrival Time" 
         << endl;

    cout << "\t\t\t\t\t" << setfill('-') 
         << setw(105) << "-" 
         << setfill(' ') 
         << endl;

    int routeNumber;
    string source, destination, departureTime, arrivalTime;
    float regularFare, studentFare;

    // Read and display route data
    while (file >> routeNumber >> source >> destination >> regularFare >> studentFare >> departureTime >> arrivalTime) {
        cout << "\t\t\t\t\t" 
             << setw(15) << routeNumber 
             << setw(20) << source 
             << setw(20) << destination 
             << setw(15) << regularFare 
             << setw(15) << studentFare 
             << setw(15) << departureTime 
             << setw(15) << arrivalTime 
             << endl;
    }

    file.close();
    pressEnterToContinue();
}
bool BusRoute::isRouteExists(int routeNumber) {
    ifstream file("bus_routes.txt");
    if (!checkFileOpen(file, "bus_routes.txt")) return false;

    int route;
    while (file >> route) {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        if (route == routeNumber) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void BusRoute::addRoute() {
	system("cls");
	 printf("\033[1;92m");
    printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t\t        =               ADD NEW ROUTE                =");
    printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
     printf("\033[37m");
    ofstream file("bus_routes.txt", ios::app);
    if (!checkFileOpen(file, "bus_routes.txt")) return;

    int routeNumber;
    string source, destination;
    float regularFare, studentFare;
    string departureTime, arrivalTime; // New fields for time

    cout << "\n\n\n\n\t\t\t\tEnter the following details:\n";
    cout << "\n\t\t\t\tRoute Number: ";
    cin >> routeNumber;

    if (isRouteExists(routeNumber)) {
        cerr << "\n\n\t\t\t\tRoute number already exists.\n";
        file.close();
        pressEnterToContinue();
        return;
    }

    cin.ignore(); // Clear input buffer before using getline

    cout << "\n\t\t\t\tSource: ";
    getline(cin, source); // Allow spaces in source name

    cout << "\n\t\t\t\tDestination: ";
    getline(cin, destination); // Allow spaces in destination name

    cout << "\n\t\t\t\tRegular Fare: ";
    while (!(cin >> regularFare) || regularFare < 0) {
        cout << "\n\t\t\t\tInvalid input. Please enter a positive number for Regular Fare: ";
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    cout << "\n\t\t\t\tStudent Fare: ";
    while (!(cin >> studentFare) || studentFare < 0) {
        cout << "\n\t\t\t\tInvalid input. Please enter a positive number for Student Fare: ";
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    cout << "\n\t\t\t\tDeparture Time (HH:MM): ";
    cin >> departureTime;

    cout << "\n\t\t\t\tArrival Time (HH:MM): ";
    cin >> arrivalTime;

    file << routeNumber << " " << source << " " << destination << " " 
         << regularFare << " " << studentFare << " " 
         << departureTime << " " << arrivalTime << "\n";
    file.close();

    cout << "\n\n\t\t\t\t\tRoute added successfully!";
    pressEnterToContinue();
}

void BusRoute::deleteRoute() {
	system("cls");
	 printf("\033[1;92m");
    printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t\t        =             DELETE BUS ROUTE                =");
    printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n\n");
    printf("\033[37m");
    ifstream file("bus_routes.txt");
    if (!checkFileOpen(file, "bus_routes.txt")) return;

    ofstream tempFile("temp.txt");
    if (!checkFileOpen(tempFile, "temp.txt")) return;

    int routeNumber;
    cout << "\n\n\n\n\t\t\t\tEnter the Route Number to delete: ";
    cin >> routeNumber;

    int route;
    string source, destination;
    float regularFare, studentFare;
    bool found = false;
    while (file >> route >> source >> destination >> regularFare >> studentFare) {
        if (route != routeNumber) {
            tempFile << route << " " << source << " " << destination << " " << regularFare << " " << studentFare << "\n";
        } else {
            found = true;
        }
    }
    file.close();
    tempFile.close();

    if (found) {
        remove("bus_routes.txt");
        rename("temp.txt", "bus_routes.txt");
        cout << "\n\n\t\t\t\t\tRoute deleted successfully!";
    } else {
        cerr << "\n\n\t\t\t\t\tRoute not found!";
    }
    pressEnterToContinue();
}

void BusRoute::displayRoutesBySourceAndDestination(const string &source, const string &destination) {

    ifstream file("bus_routes.txt");
    if (!checkFileOpen(file, "bus_routes.txt")) return;

    bool routeFound = false;

    cout << "\n\n\n\n\t\t\t\t\tDisplaying Routes from " << source << " to " << destination << ":";
    cout << "\n\t\t\t\t   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
    cout << "\n\t\t\t\t\t" << setw(15) << "Route Number" 
         << setw(20) << "Source" 
         << setw(20) << "Destination" 
         << setw(15) << "Regular Fare" 
         << setw(15) << "Student Fare" 
         << setw(15) << "Departure Time" 
         << setw(15) << "Arrival Time" 
         << endl;

    cout << "\t\t\t\t\t" << setfill('-') 
         << setw(105) << "-" 
         << setfill(' ') 
         << endl;

    int routeNumber;
    string fileSource, fileDestination, departureTime, arrivalTime;
    float regularFare, studentFare;

    while (file >> routeNumber >> fileSource >> fileDestination >> regularFare >> studentFare >> departureTime >> arrivalTime) {
        if (fileSource == source && fileDestination == destination) {
            cout << "\t\t\t\t\t" 
                 << setw(15) << routeNumber 
                 << setw(20) << fileSource 
                 << setw(20) << fileDestination 
                 << setw(15) << regularFare 
                 << setw(15) << studentFare 
                 << setw(15) << departureTime 
                 << setw(15) << arrivalTime 
                 << endl;
            routeFound = true;
        }
    }

    if (!routeFound) {
        cout << "\n\n\n\n\t\t\t\t\tNo routes found from " << source << " to " << destination << ".\n";
    }

    file.close();
    pressEnterToContinue();
}
void displayUserMenu(User &user) {
system("cls");

int choice;
do{
	system("cls");

    printf("\033[92m");	
        printf("\n\n\n\t\t\t\t\t\t\t\t*--User Page--*");
        printf("\n\t\t\t\t\t\t\t   \033[1;96m <------------------------------>\033[0m\n\n ");
        printf("\n\n\n");
        
        printf("\x1b[36m");
        printf("\n\t\t\t\t\t\t\t*       ||     User Menu    ||      *\n\n\n");
        printf("\033[0m");
        
    cout << "\n\n\t\t\t\t\t\t\t 1. Display All Routes";
    cout << "\n\n\t\t\t\t\t\t\t 2. Search Route by Source and Destination";
    cout << "\n\n\t\t\t\t\t\t\t 3. Logout\n\n";
    cout << "\n\n\t\t\t\t\t\t\t Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Display all routes
            BusRoute::displayRoutes();
            break;

        case 2: {
        	system("cls");
            string source, destination;
           
       
         printf("\033[1;92m");
        printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t\t\t        =        DISPLAY BUS ROUTES BY CHOICE        =");
        printf("\n\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
      
          printf("\033[37m");
            cout << "\n\n\t\t\t\t Enter Source: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, source);

            cout << "\n\n\t\t\t\t Enter Destination: ";
            getline(cin, destination);

            // Display route details based on source and destination
            BusRoute::displayRoutesBySourceAndDestination(source, destination);
            break;
        }

       case 3:
                cout << "\n\n\t\t\t\t\t\tLogging out...";
                pressEnterToContinue();
                break;

        default:
            cerr << "\n\n\t\t\t\t Invalid choice!\n";
            pressEnterToContinue();
    }
}while (choice != 3);
}
void displayAdminMenu(Admin &admin) {
    int choice;
    do {
        system("cls"); // Use "clear" for UNIX-based systems
        cout << "\033[92m";
        cout << "\n\n\n\t\t\t\t\t\t\t\t*--Admin Page--*";
        cout << "\n\t\t\t\t\t\t\t   <------------------------------>\n\n ";
        cout << "\n\n\n";
        cout << "\n\t\t\t\t\t\t\t*****";
        cout << "\x1b[36m";
        cout << "\n\n\t\t\t\t\t\t\t 1. Add Route";
        cout << "\n\n\t\t\t\t\t\t\t 2. Delete Route";
        cout << "\n\n\t\t\t\t\t\t\t 3. View Routes";
        cout << "\n\n\t\t\t\t\t\t\t 4. View User Logins"; // New menu option
        cout << "\n\n\t\t\t\t\t\t\t 5. Logout";
        cout << "\n\n\t\t\t\t\t\t\t Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                admin.addRoute();
                break;
            case 2:
                admin.deleteRoute();
                break;
            case 3:
                admin.displayRoutes();
                break;
            case 4:
                admin.viewUserLogins(); // Call the new function
                break;
            case 5:
                cout << "\n\n\t\t\t\t\t\tLogging out...";
                pressEnterToContinue();
                break;
            default:
                cerr << "\n\n\t\t\t\t\t\tInvalid choice!";
                pressEnterToContinue();
        }
    } while (choice != 5);
}

int main() {
	 system("cls");    
    printf("\033[1;91m");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t BUS ROUTE MANAGEMENT SYSTEM");
    printf("\n\t\t\t\t\t\t      ------------------------------\n\n\n\n\n\n\n\n");
    printf("\033[1;92m");
    printf("\t\t\t\t\tW       W  EEEEEEE  L          CCCCC   OOOO   M     M  EEEEEEE\n");
    printf("\t\t\t\t\tW       W  E        L        CC       O    O  MM   MM  E      \n");
    printf("\t\t\t\t\tW   W   W  EEEEEEE  L       CC        O    O  M M M M  EEEEEEE\n");
    printf("\t\t\t\t\tW W   W W  E        L        CC       O    0  M  M  M  E      \n");
    printf("\t\t\t\t\tW       W  EEEEEEE  LLLLLL     CCCCC   OOOO   M     M  EEEEEEE\n");
     printf("\n\t\t\t\t\033[1;96m     ####################################################################\033[0m\n\n ");
    printf("\033[0m");
    printf("\n\n\n\n\n\n\t\t\t\t\t Enter any key to continue.....");
    getch();
    
    
    int choice; 
    do {
        system("cls");
        cout << "\033[92m";
        cout << "\n\n\n\t\t\t\t\t\t\t\t*--Bus Management System--*";
        cout << "\n\t\t\t\t\t\t\t      <------------------------------>\n\n ";
        cout << "\n\n\n";
        cout << "\x1b[36m";
        cout << "\n\n\t\t\t\t\t\t\t 1. User Login";
        cout << "\n\n\t\t\t\t\t\t\t 2. Admin Login";
        cout << "\n\n\t\t\t\t\t\t\t 3. Register";
        cout << "\n\n\t\t\t\t\t\t\t 4. Exit\n\n\n\n\n";
        cout<<"\n\n\t\t\t\t\t\t\033[1;95mEnter your choice:\033[0m ";
        cin >> choice;
        switch (choice) {
            case 1: {
                User user;
                if (user.login()) {
                    displayUserMenu(user);
                }
                break;
            }
            case 2: {
                Admin admin;
                if (admin.adminLogin()) {
                    displayAdminMenu(admin);
                }
                break;
            }
            case 3: {
                User user;
                if (user.registerUser()) {
                    displayUserMenu(user);
                }
                
                break;
            }
            case 4:
                cout << "\n\n\t\t\t\t\t\tExiting...";
                pressEnterToContinue();
                break;
            default:
                cerr << "\n\n\t\t\t\t\t\tInvalid choice!";
                pressEnterToContinue();
        }
    } while (choice != 4);
    return 0;
}



