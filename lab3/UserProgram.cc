#include <iostream>
#include "libs/UserTable.h"

using std::endl;
using std::cout;

int main(){
    UserTable table{"users.txt"};
    
    cout << table.find(21330) << endl;
    cout << table.find(21331) << endl;
    cout << table.find("Jens Holmgren") << endl; 

    table.addUser(User{1234, "Jon Von Bonvi"});
    table.addUser(User{1235, "Golgoth, Shadow of Nightmares and The Voidkiller of Slayer Destruction, Smiter of Heavens"});


    cout << table.find(1235) << endl; 
    cout << testFindNbr(table) << endl;

    return 0;
}
