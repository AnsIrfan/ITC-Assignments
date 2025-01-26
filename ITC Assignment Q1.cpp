#include <iostream>
using namespace std;

int main()
{
    int num,sum = 0;
    bool dupe_check = false;
    cout << "Enter the size of the array = ";
    cin >> num;
    while(num<=0) // input validation, making sure a person  does not enter a negative number or a zero
    {
        cout << "Invalid Input, array size cannot be in negative." << endl; // output for invalid input and asking to input a correct value
        cout << "Enter the size of the array = ";
        cin >> num; // loop will keep taking input as long as the input isnt valid
    }
    int arr[num] = {}; // declaring and initiazling the array with the array size that was taken as input
    for(int i = 0;i<num;i++) // this loop is used to take the same number of inputs as the size of the array
    {
        cout << "Enter the number = ";
        cin>>arr[i];
    }
    for(int i = 0; i<num;i++) // this loop is being used to check if the array contains a duplicate element
    {
        for (int j = i+1;j<num;j++)
        {
            if(arr[i]==arr[j])
            {
                dupe_check = true;
                break;
            }
        }
        if(dupe_check==true)
        {
            break;
        }
    }
    if(dupe_check==true) // outputs the following cout if there are duplicate elements
    {
        cout << "The array contains duplicate elements." << endl; 
    }
    cout << endl;
    for(int i = 0;i<num;i++) // this loop logic makes sure that not pair is repeated as its symmetric pair or a pair on itself
    {                        // e.g if (a,b) is alrd present then (b,a) will not exist until there is a duplicate element
        for(int j = i+1;j<num;j++)
        {
            cout << " ("<<arr[i] << "," << arr[j] <<") ";
            sum+= (arr[i]+arr[j]);
        }
    }
    cout << endl;
    cout << "Sum of all of the pairs = " << sum << endl;
    return 0;
}