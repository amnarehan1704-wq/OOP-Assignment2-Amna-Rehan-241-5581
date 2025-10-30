#include <iostream>
using namespace std;
void ChangeLocation(char *Array, int b1, int b2)
 {

    if (b1 >= b2)
        return;

    
    char temp = Array[b1];   
    Array[b1] = Array[b2];
    Array[b2] = temp;

    
    ChangeLocation(Array, b1 + 1, b2 - 1);
}

int main() {
    char arr[11] = {'P', 'R', 'O', 'G', 'R', 'A', 'M', 'M','I','N','G'};

    cout << "Original Array: ";
    for (int i = 0; i < 11; i++) 
	cout << arr[i] << " ";
    cout << endl;

    ChangeLocation(arr, 3, 7);  

    cout << "After ChangeLocation: ";
    for (int i = 0; i < 11; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
