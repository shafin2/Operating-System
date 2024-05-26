// Shafin-uz-zaman
// sp22-bcs-063

#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
// include cstdlib for rand() and srand(), ctime for time()

using namespace std;

int guessNumber(int user) {
    // can find randome no betwee 1 to 10 by following line of code
    // Reference: https://www.javatpoint.com/how-to-generate-random-number-between-1-to-10-in-cpp
    srand(time(0));  
    double randomNumber = (rand() % 10) + 1;


    double userGuess;
    int turnCount = 0;
    do {
        cout << "User " << user << "; Enter your guess: ";
        cin >> userGuess;
        turnCount++;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << turnCount << " turns." << endl;
        }

    } while (userGuess != randomNumber);

    return turnCount;
}


int main()
{
    int pipe1[2], pipe2[2], pipe3[2];
    if (pipe(pipe1) == -1)
    {
        cout << "Pipe Failed" << endl;
        return 1;
    }
    if (pipe(pipe2) == -1)
    {
        cout << "Pipe Failed" << endl;
        return 1;
    }
    if (pipe(pipe3) == -1)
    {
        cout << "Pipe Failed" << endl;
        return 1;
    }

    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);
    pid_t process;
    int results[3];

    process = fork();
    if (process == 0)
    {
        cout << "Child process 1: " << getpid() << " ppid: " << getppid() << endl;
        int turn = guessNumber(1);
        write(pipe1[1], &turn, 4);
        exit(EXIT_SUCCESS);
    }
    else if (process > 0)
    {   
        wait(NULL);
        process = fork();
        if (process == 0)
        {
            cout << "Child process 2: " << getpid() << " ppid: " << getppid() << endl;
            int turn = guessNumber(2);
            write(pipe2[1], &turn, 4);
            exit(EXIT_SUCCESS);
        }
        else if (process > 0)
        {
            process = fork();
            if (process == 0)
            {
                cout << "Child process 3: " << getpid() << " ppid: " << getppid() << endl;
                int turn = guessNumber(3);
                write(pipe3[1], &turn, 4);
                exit(EXIT_SUCCESS);
            }
            else if (process > 0)
            {
                wait(NULL);
                wait(NULL);

                int results[3];
                read(pipe1[0], &results[0], 4);
                read(pipe2[0], &results[1], 4);
                read(pipe3[0], &results[2], 4);

                int min = results[0];
                int j = 0;
                for (int i = 0; i < 3; i++)
                {
                    if (results[i] < min)
                    {
                        min = results[i];
                        j = i;
                    }
                }
                cout << "User " << j + 1 << " wins, the minimum number of turns was " << min << endl;
            }
            else
            {
                cout << "Fork failed" << endl;
            }
        }
        else
        {
            cout << "Fork failed" << endl;
        }
    }
    else
    {
        cout << "Fork failed" << endl;
    }

    return 0;
}

// By using wait(), the parent process ensures that it doesn't proceed further until all child processes it spawned have finished executing. This helps synchronize the execution of parent and child processes and prevents the parent process from completing before its children.
