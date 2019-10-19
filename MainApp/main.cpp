#include <iostream>

#include "List1.h"

using namespace std;

int main() {
    List1 list;
    List1 list2;

    list2.push_back(22);
    list2.push_back(23);
    list2.push_back(24);

    cout << "Size " << list.get_size() << endl;
    cout << "List is empty " << list.isEmpty() << endl;
    list.push_back(11);
    list.push_front(11);
    list.push_back(list2);
    list.pop_back();
    list.pop_front();

    list.insert(2, 31);
    list.remove(2);
    list.set(1, 45);
    list.print_to_console();
    cout << "Size " << list.get_size() << endl;
    cout << "List is empty " << list.isEmpty() << endl;
    cout << list.at(2) << endl;
    list.clear();
    cout << "Size " << list.get_size() << endl;
    cout << "List is empty " << list.isEmpty() << endl;
    return 0;
}