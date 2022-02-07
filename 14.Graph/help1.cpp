#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    int empId;
    char name[20];
    int salary;
    struct employee *next;
};

// function for adding new employee
void addEmployee(struct employee **Head, int employeeCount)
{
    struct employee *Emps=(struct employee*)malloc(sizeof(struct employee));
    
    if(Emps!=NULL){
        printf("Enter Employee ID->");
        scanf("%d", &Emps->empId);

        printf("Enter Employee Name->");
        fflush(stdin);
        gets(Emps->name);

        printf("Enter Employee Salary->");
        scanf("%d", &Emps->salary);

        printf("Successfully Inserted!!");
        Emps->next = *Head;
        *Head = Emps;
        employeeCount++;
    }else{
        printf("NO MEMORY IS ALLOCATE");
    }
}

// function for display all the employees
void displayAllEmployees(struct employee *Emps, int employeeCount)
{

    printf("\n-----------------------------------------------------------------------");
    if (Emps!= NULL)
        while(Emps)
        {
            printf("\nEmployee-Id: %d", Emps->empId);
            printf("\nName of Employee: %s", Emps->name);
            printf("\nSalary - %d", Emps->salary);
            Emps=Emps->next;
            printf("\n-----------------------------------------------------------------------");
        }
    else
        printf("No Employees Exist!!!");
}

// function for search employ by id
void searchEmployeeById(int searchID, struct employee *Emps, int employeeCount)
{

    int found = 0;

  while(Emps!=NULL)
    {

        if (searchID == Emps->empId)
        {
            printf("\n-----------------------------------------------------------------------");

            printf("\nEmployee-Id: %d", Emps->empId);
            printf("\nName of Employee: %s", Emps->name);
            printf("\nSalary - %d", Emps->salary);

            printf("\n-----------------------------------------------------------------------");
            found = 1;
            break;
        }
        Emps=Emps->next;
    }

    if (found == 0)
        printf("\nNo Employee Exist of this ID");
}

// function for search employ by name
void searchEmployeeByName(char searchName[20], struct employee *Emps, int employeeCount)
{

    int found = 0;

    printf("\n-----------------------------------------------------------------------");

    while(Emps!=NULL)
    {
        if (strcmp(searchName, Emps->name) == 0)
        {
            printf("\nEmployee-Id: %d", Emps->empId);
            printf("\nName of Employee: %s", Emps->name);
            printf("\nSalary - %d", Emps->salary);
            found = 1;
            Emps=Emps->next;
            printf("\n-----------------------------------------------------------------------");
        }
    }

    if (found == 0)
        printf("\nNo Employee Exist of this Name");
}

// function for display employ with the highest salary
void HighestSalary(struct employee *Emps, int employeeCount)
{

    int salary = 0;
    char name[20];

    if (employeeCount != 0)
    {

        while(Emps!=NULL)
        {
            if (salary < Emps->salary)
            {
                salary = Emps->salary;
                strcpy(name, Emps->name);
            }
            Emps=Emps->next;
        }

        printf("Highest Salary Employee");
        searchEmployeeByName(name, Emps, employeeCount);
    }
    else
        printf("No Employees Exist");
}

int main()
{
    struct employee *Emps = NULL;
    int searchID;
    char searchName[20];

    int choice = 0;
    int employeeCount = 0;

    // loop continue until exit condition is met
    while (choice != 6)
    {
        printf("\n\nEnter Your Choice->");
        printf("\n1 - for Add an Employee");
        printf("\n2 - Display all the Employees");
        printf("\n3 - Search Employee by empId");
        printf("\n4 - Search Employee by name");
        printf("\n5 - Employee having Highest Salary ");
        printf("\n6 - Exit ");
        printf("\nChoice->");

        scanf(" %d ", &choice);

        switch (choice)
        {
            // add employee
        case 1:
            addEmployee(&Emps, employeeCount);
            break;

            // display all the employees
        case 2:
            displayAllEmployees(Emps, employeeCount);
            break;

            // search by ID
        case 3:
            printf("Enter Id to be searched->");
            scanf("%d", &searchID);

            searchEmployeeById(searchID, Emps, employeeCount);
            break;

            // search by Name
        case 4:
            printf("Enter Name to be searched->");
            gets(searchName);

            searchEmployeeByName(searchName, Emps, employeeCount);
            break;

            // display employee with the highest salary
        case 5:
            HighestSalary(Emps, employeeCount);
            break;

            // exit case
        case 6:
            printf("Exited...");
            break;

            // Invalid Case
        default:
            printf("Invalid Choice");
        }
    }

    return 0;
}