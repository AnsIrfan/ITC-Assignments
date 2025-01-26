#include <iostream>
using namespace std;

int main() 
{
    int num;
    cout << "Enter the number of employees: ";
    cin >> num;

    while(num <= 0 || num > 100) 
    {
        cout << "Invalid input, please select a number between 1-100" << endl;
        cout << "Enter the number of employees: ";
        cin >> num;
    }

    int employee_id[num];
    float employee_salary[num];
    char employee_name[1000]; // single array to store all names
    int employee_xp[num];
    int name_end_index[num]; // Keep track of where each name ends

    // Data Input
    for(int i = 0; i < num; i++) 
    {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> employee_id[i];

        cout << "Name: ";
        cin.ignore(); // to ignore any lingering newline character from previous input
        
        int name_start_index;
        if (i == 0) 
        {
            name_start_index = 0;
        } 
        else 
        {
            name_start_index = name_end_index[i - 1] + 1;
        }

        cin.getline(&employee_name[name_start_index], 200); // Storing employee name in one big character array

        name_end_index[i] = name_start_index + 199; // Update end index for this name

        cout << "Salary: ";
        cin >> employee_salary[i];
        while(employee_salary[i] < 30000 || employee_salary[i] > 200000) 
        {
            cout << "Invalid input, please select a value between 30000-200000" << endl;
            cout << "Salary: ";
            cin >> employee_salary[i];
        }

        cout << "Years of Experience: ";
        cin >> employee_xp[i];
    }

    // Output Employee Records in Original Order
    cout << "Employee Records (Original Order):" << endl;
    for(int i = 0; i < num; i++) 
    {
        int name_start_index;
        if (i == 0) 
        {
            name_start_index = 0;
        } 
        else 
        {
            name_start_index = name_end_index[i - 1] + 1;
        }

        cout << "ID: " << employee_id[i] << ", Name: " << &employee_name[name_start_index] << ", Salary: " << employee_salary[i] << ", Experience: " << employee_xp[i] << " years" << endl;
    }

    // Calculate Total Salary, High Salary Count, and Highest Salary
    float total_salary = 0;
    int count_high_salary = 0;
    int highest_salary = 0;
    int highest_salary_index = 0;

    for(int i = 0; i < num; i++) 
    {
        total_salary += employee_salary[i];
        if(employee_salary[i] > 100000) 
        {
            count_high_salary++;
        }
        if(employee_salary[i] > highest_salary) 
        {
            highest_salary = employee_salary[i];
            highest_salary_index = i;
        }
    }

    cout << "Total salary of all employees: " << total_salary << endl;
    cout << "Number of employees earning more than 100,000: " << count_high_salary << endl;

    int highest_name_start_index;
    if (highest_salary_index == 0) 
    {
        highest_name_start_index = 0;
    } 
    else 
    {
        highest_name_start_index = name_end_index[highest_salary_index - 1] + 1;
    }

    cout << "Employee with the highest salary: " << &employee_name[highest_name_start_index] << " (" << highest_salary << ")" << endl;

    // Sorting IDs using Bubble Sort
    for(int i = 0; i < num - 1; i++) 
    {
        for(int j = i + 1; j < num; j++) 
        {
            if(employee_id[i] > employee_id[j]) 
            {
                // Swap IDs
                int temp_id = employee_id[i];
                employee_id[i] = employee_id[j];
                employee_id[j] = temp_id;

                // Swap Salaries
                float temp_salary = employee_salary[i];
                employee_salary[i] = employee_salary[j];
                employee_salary[j] = temp_salary;

                // Swap Experience
                int temp_xp = employee_xp[i];
                employee_xp[i] = employee_xp[j];
                employee_xp[j] = temp_xp;
            }
        }
    }

    cout << "Sorted Employee Records:" << endl;
    for(int i = 0; i < num; i++) 
    {
        int name_start_index;
        if (i == 0) 
        {
            name_start_index = 0;
        } 
        else 
        {
            name_start_index = name_end_index[i - 1] + 1;
        }
        cout << "ID: " << employee_id[i] << ", Name: " << &employee_name[name_start_index] << ", Salary: " << employee_salary[i] << ", Experience: " << employee_xp[i] << " years" << endl;
    }

    // Linear Search for an Employee ID
    int search_id;
    cout << "Enter an Employee ID to search (linear search): ";
    cin >> search_id;
    bool found = false;
    for(int i = 0; i < num; i++) 
    {
        if(employee_id[i] == search_id) 
        {
            int name_start_index;
            if (i == 0) 
            {
                name_start_index = 0;
            } 
            else 
            {
                name_start_index = name_end_index[i - 1] + 1;
            }
            cout << "Result: Name: " << &employee_name[name_start_index] << ", Salary: " << employee_salary[i] << ", Experience: " << employee_xp[i] << " years" << endl;
            found = true;
            break;
        }
    }
    if(!found) 
    {
        cout << "Employee not found" << endl;
    }

    // String Manipulation for Names: Count Vowels & Convert to Uppercase
    cout << "String Manipulation (Name Analysis):" << endl;
    for(int i = 0; i < num; i++) 
    {
        int vowels = 0;
        int name_start_index;
        if (i == 0) 
        {
            name_start_index = 0;
        } 
        else 
        {
            name_start_index = name_end_index[i - 1] + 1;
        }

        for(int j = name_start_index; employee_name[j] != '\0'; j++) 
        {
            char ch = employee_name[j];
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            }
            // Convert to Uppercase
            if(ch >= 'a' && ch <= 'z') {
                employee_name[j] = employee_name[j] - 32;
            }
        }
        cout << "Name: " << &employee_name[name_start_index] << ", Vowels: " << vowels << ", Uppercase: " << &employee_name[name_start_index] << endl;
    }

    return 0;

}