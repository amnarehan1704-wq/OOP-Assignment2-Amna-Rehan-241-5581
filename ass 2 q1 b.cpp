#include <iostream>
using namespace std;
void printPartition(int arr[],int size)
 {
    for (int i=0;i<size;i++) 
	{
        cout<<arr[i];
        if(i!=size-1)
            cout<<"  ";
    }
    cout<<endl;
}
void partitionNumber(int n,int maxVal,int arr[],int index)
 {
    if(n == 0) 
	{
        printPartition(arr,index);
        return;
    }

    for(int i=min(n,maxVal);i>=1;i--) 
	{
        arr[index]=i;                  
        partitionNumber(n-i,i,arr,index+1); 
    }
}

int main() 
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int arr[n]; 
    cout<<"All possible partitions of "<<n<<" are:"<<endl;
    partitionNumber(n,n,arr,0);
    return 0;
}
