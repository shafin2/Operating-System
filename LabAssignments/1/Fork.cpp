// Shafin zaman
// sp22-bcs-063
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void primeNumber(int num)
{
    if (num <= 0)
    {
        cout << "Negative or 0 number" << endl;
        return;
    };

    if (num >= 1)
    {
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                cout << "Not a prime number" << endl;
                return;
            };
        }
    }

    cout << "Prime number" << endl;
}

void factorial(int num)
{
    int product = 1;
    for (int i = 1; i <= num; i++)
    {
        product = product * i;
    }
    cout << "Factorial of " << num << " is: " << product << endl;
}

void thirdLargest(int array[], int size)
{
    if (size < 3)
    {
        cout << "array size is less than 3, how can I find thirdLasrgest" << endl;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    cout << "Third largest number in the array is: " << array[2] << endl;
}

int main()
{
    cout << "Creating array for third largest....\n";
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++)
    {
        int value;
        cout << "Enter value: ";
        cin >> value;
        array[i] = value;
    }

    thirdLargest(array, size);
    int pid = fork();

    if (pid == 0)
    {
        cout << "Child pid: " << getpid() << endl;
        int num;
        cout << "Prime number testing....\n";
        cout << "Enter a number: ";
        cin >> num;
        primeNumber(num);
    }
    else if (pid > 0)
    {
        cout << "Parent pid: " << getppid() << endl;
        cout << "Waiting for child process...\n";
        sleep(7);
        wait(NULL);
        cout << "Factorial Calculation....\n";
        cout << "Enter a number: ";
        int num2;
        cin >> num2;
        factorial(num2);
    }
    else
    {
        cout << "Fork ma msla ha" << endl;
    }

    return 0;
}
