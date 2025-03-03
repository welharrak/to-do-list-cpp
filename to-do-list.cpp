#include <iostream>
#include <string>
#include <vector>

using namespace std;

void show_list(vector<string>& list){
    for (auto& el: list){
        cout << el << endl;
    }
}

int main()
{
    cout << "Welcome to your personal To-Do List!" << endl;
    char choice;
    vector<string> list;
    string input;

    while(true){
        cout << "Please, choose one of the following options:" << endl;
        cout << "1: Add a new point" << endl << "2: Remove the a point" << endl;
        cout << "3: Mark a point as done" << endl << "4: Show current list" << endl;
        cout << "5: End programm" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch(choice){
            case '1':
                cout << "Point to add:" << endl;
                cin.ignore();
                getline(cin, input);
                list.push_back(input);
                break;
            case '2':
                cout << "Point to remove:" << endl;
                break;
            case '3':
                cout << "Wich point to mark:" << endl;
                break;
            case '4':
            show_list(list);
                break;
            case '5':
                cout << "Ciao! Until next time!" << endl;
                return 0;
                break;
            default:
                cout << "Error! Wrong option, please choose again." << endl;
        }
    }
    
}