// Working

#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void current_dir()
{
    cout << "Current directory is: " << system("pwd") << endl;
    return;
}

void dir_content()
{
    cout << " directory content are: " << system("ls -l") << endl;
    return;
}

void print_date()
{
    cout << "Current date is: " << system("date") << endl;
    return;
}

void save_file()
{
    // thnx abdullah
    // system("echo 'Name: Abdullah Ahmad' | cat >> hello.txt");
    // system("echo 'Roll No: SP22-BCS-045' | cat >> hello.txt");
    // system("echo 'Skills:' | cat >> hello.txt");
    // system("echo '1. Python programming' | cat >> hello.txt");
    // system("echo '2. Data analysis' | cat >> hello.txt");
    // system("echo '3. Machine learning' | cat >> hello.txt");
    // system("echo '4. Web development' | cat >> hello.txt");
    // system("echo '5. Problem solving' | cat >> hello.txt");
    // system("echo '6. Communication' | cat >> hello.txt");
    // system("echo '7. Leadership' | cat >> hello.txt");
    // system("echo '8. Time management' | cat >> hello.txt");
    // system("echo '9. Teamwork' | cat >> hello.txt");
    // system("echo '10. Critical thinking' | cat >> hello.txt");

    string skills = "cat > skills.txt <<EOF\n"
                    "Name: Abdullah Ahmad\n"
                    "Roll No: SP22-BCS-045\n"
                    "Skills:\n"
                    "1. Python programming\n"
                    "2. Data analysis\n"
                    "3. Machine learning\n"
                    "4. Web development\n"
                    "5. Problem solving\n"
                    "6. Communication\n"
                    "7. Leadership\n"
                    "8. Time management\n"
                    "9. Teamwork\n"
                    "10. Critical thinking\n"
                    "EOF";

    const char *cmd = skills.c_str();
    system(cmd);

    string instruction = "cat skills.txt";
    const char *command = instruction.c_str();
    system(command);

    return;
}

void search_file_with_extension()
{
    cout << "Enter extension you want to search: ";
    string extension;
    cin >> extension;
    string command = "ls *." + extension;
    cout << "Files with extension " << extension << " are: " << system(command.c_str()) << endl;
}

int main()
{
    current_dir();
    dir_content();
    print_date();
    save_file();

    return 0;
}
