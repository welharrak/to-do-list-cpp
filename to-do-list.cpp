#include <iostream>
#include <string>
#include <vector>

using namespace std;

void show_list(vector<string>& list, int count){
    cout << "------------------------------Your To-Do-List-------------------------------------" << endl;
    for (int i = 0; i < count;i++){
        cout << i + 1 << ". " + list[i] << endl;
    }
    cout << "----------------------------------------------------------------------------------" << endl;
}

void print_help(){
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Please, choose one of the following options:" << endl;
    cout << "1: Add a new point" << endl << "2: Remove a point" << endl;
    cout << "3: Mark a point as done" << endl << "4: Show current list" << endl;
    cout << "q: To quit programm" << endl;
    cout << "------------------------------------------------------------------------" << endl;
}

int main()
{
    cout << "Welcome to your personal To-Do List!" << endl;
    print_help();
    char choice;
    vector<string> list;
    string input;
    int count = 0;
    int index = 0;

    while(true){
        cout << "Please enter your choice: " << endl << "If you need help, write h!" << endl << ">> ";
        cin >> choice;
        switch(choice){
            // Add point to list
            case '1':
                cout << "Point to add: ";
                cin.ignore();
                getline(cin, input);
                list.push_back(input);
                count++;
                break;
            // Remove point from list
            case '2':
                show_list(list, count);
                cout << "Wich point to remove?: ";
                cin >> input;
                try{
                    index = stoi(input);
                    if (index >= count){
                        cout << "Invalid input, your list has just " << count << " points." << endl;
                        break;
                    }
                    list.erase(list.begin() + index - 1);
                    count--;
                } catch (const invalid_argument& e){
                    cout << "Invalid input, you have to give a number! Please try again." << endl;
                }
                break;
            // Mark point as done
            case '3':
                show_list(list, count);
                cout << "Wich point to mark: ";
                cin >> input;
                try{
                    index = stoi(input);
                    if (index >= count){
                        cout << "Invalid input, your list has just " << count << " points." << endl;
                        break;
                    }
                    list[index-1] = string("✔ ") + list[index-1];
                } catch (const invalid_argument& e){
                    cout << "Invalid input, you have to give a number! Please try again." << endl;
                }
                break;
            case '4':
                show_list(list, count);
                break;
            case 'q':
                cout << "Ciao! Until next time!" << endl;
                return 0;
                break;
            case 'h':
                print_help();
                break;
            default:
                cout << "Error! Wrong option, please choose again." << endl;
        }
    }
    
}