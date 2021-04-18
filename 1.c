#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char ans = 0;
int ok;
int b, valid = 0;

// FUNCTION DECLARATION.

void WelcomeScreen(void); //Welcome screen function declaration.
void Title(void);         //Title function declaration
void MainMenu(void);      //MainMenu function declaration
void LoginScreen(void);   //Login_Screen function declaration
void Add_Rec(void);       //Add_Rec function declaration
void Func_List();         //Function to list the patient details
void Search_Rec(void);    //Search_Rec function declaration
void Edit_Rec(void);      //Edit_Rec function declaration
void Dlt_Rec(void);       //Dlt_Rec function declaration
void Ex_It(void);         //Exit function declaration
void Gotoxy(short x, short y)

{
    COORD pos = {x, y}; //Sets coordinates in (x,y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//List of Global Variables
struct patient
{
    int Age;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char Address[30];
    char Email[30];
    char Doctor[20];
    char Problem[20];
};

struct patient p, temp_C;
main(void)
{
    WelcomeScreen(); //Use to call WelcomeScreen function
    Title();         //Use to call Title function
    LoginScreen();   //Use to call LoginScreen function
}

//WelcomeScreen
void WelcomeScreen(void) //Function for WelcomeScreen
{
    printf("\n\n\n\n\n\n\n\t\t\t\t*##########################################*");
    printf("\n\t\t\t\t#\t\t WELCOME TO \t\t   # ");
    printf("\n\t\t\t\t#      VIT HOSPITAL MANAGEMENT SYSTEM\t   #");
    printf("\n\t\t\t\t*##########################################*");
    printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue.....\n");
    getch();
    system("cls"); //Used to clear screen
}
void Title(void) //Function for Title Screen
{
    printf("\n\n\t\t--------------------------------------------------------------");
    printf("\n\t\t\t\t\t   VIT HOSPITAL  ");
    printf("\n\n\t\t--------------------------------------------------------------");
}

//MainMenu
void MainMenu(void)
//Function declaration
{
    system("cls");
    int choose;
    Title(); //Call Title function
    printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
    printf("\n\t\t\t\t2. List Patient's Record\n");
    printf("\n\t\t\t\t3. Search Patient's Record\n");
    printf("\n\t\t\t\t4. Edit Patient's Record\n");
    printf("\n\t\t\t\t5. Delete Patient's Record\n");
    printf("\n\t\t\t\t6. Exit\n");
    printf("\n\n\n \n\t\t\t\tChoose From 1 to 6");
    scanf("%i", &choose);
    switch (choose) 
    {
    case 1:
        Add_Rec();     //Add_Rec Function is called
        break;
    case 2:
        Func_List();
        break;
    case 3:
        Search_Rec(); //Search_Rec function is called.
        break;
    case 4:
        Edit_Rec();
        break;
    case 5:
        Dlt_Rec();
        break;
    case 6:
        Ex_It();
        break;
    default:
        printf("\t\t\t Invalid Entry. Please enter the right option.");
        getch();
    }
}
void Ex_It(void)
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :) ");
    getch();
}
void LoginScreen(void)
{
    int e = 0;
    char Username[15];
    char Password[15];
    char Original_Username[25] = "Vit";
    char Original_Password[15] = "0000";
    do
    {
        printf("\n\n\n\n\t\t\t\tEnter your Username and Password :) ");
        printf("\n\n\n\t\t\t\t\tUSERNAME : ");
        scanf("%s", &Username);
        printf("\n\n\t\t\t\t\tPASSWORD : ");
        scanf("%s", &Password);
        if (strcmp(Username, Original_Username) == 0 && strcmp(Password, Original_Password) == 0)
        {
            printf("\n\n\n\t\t\t\t\t...Login Successful...");
            getch();
            MainMenu();
            break;
        }
        else
        {
            printf("\n\t\t\tPassword is Incorrect :( Try Again :) ");
            e++;
            getch();
        }

    } while (e <= 2);
    if (e > 2)
    {
        printf("You have crossed the limit. You cannot Login. :( :( ");
        getch();
        Ex_It();
    }
    system("cls");
}

void Add_Rec(void)
{
    system("cls");
    Title();
    char ans;
    FILE *ek;
    ek = fopen("Record2.dat", "a"); //Open FIle in write mode.
    printf("\n\n\t\t\t!!!!!! Add Patient's Record !!!!!!\n");
//First Name
A:
    printf("\n\t\t\tFirst Name ");
    scanf("%s", p.First_Name);
    p.First_Name[0] = toupper(p.First_Name[0]);

    if (strlen(p.First_Name) > 20 || strlen(p.First_Name) < 2)
    {
        printf("\n\n\tInvalid :( \t The max range for First Name is 20 and min range is 2");
        goto A;
    }
    else
    {
        for (b = 0; b < strlen(p.First_Name); b++)
        {
            if (isalpha(p.First_Name[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\tFirst Name contain invalid character :( Enter Again :) ");
            goto A;
        }
    }
B:
    printf("\n\t\t\tLast Name : ");
    scanf("%s", p.Last_Name);
    p.Last_Name[0] = toupper(p.Last_Name[0]);

    if (strlen(p.Last_Name) > 20 || strlen(p.Last_Name) < 2)
    {
        printf("\n\tInvalid :( \t The max range for Last Name is 20 and min range is 2");
        goto B;
    }
    else
    {
        for (b = 0; b < strlen(p.Last_Name); b++)
        {
            if (isalpha(p.Last_Name[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\tLast Name contain invalid character :( Enter Again :) ");
            goto B;
        }
    }
    do
    {
        printf("\n\t\t\tGender(F/M)");
        while (getchar() != '\n')
            ;
        scanf("%c", &p.Gender);
        if (toupper(p.Gender) == 'M' || toupper(p.Gender) == 'F')
        {
            ok = 1;
        }
        else
        {
            ok = 0;
        }
        if (!ok)
        {
            printf("\n\t\tGender contain invalid character :( Enter either F or M");
        }
    } while (!ok);
    {
        printf("\n\t\t\tAge");
        scanf("%i", &p.Age);
    }
    do
    {
    C:
        printf("\n\t\t\tAddress");
        scanf("%s", p.Address);
        p.Address[0] = toupper(p.Address[0]);
        if (strlen(p.Address) > 20 || strlen(p.Address) < 4)
        {
            printf("\n\tInvalid :( \t The max range for Address is 20 and min is 4");
            goto C;
        }
    } while (!valid);

    do
    {
    D:
        printf("\n\t\t\tContact Number");
        scanf("%s", p.Contact_no);

        if (strlen(p.Contact_no) > 10 || strlen(p.Contact_no) != 10)
        {
            printf("\n\tSorry :( Invalid. Contact Number must have ten numbers. Enter Again");
            goto D;
        }
        else
        {
            for (b = 0; b < strlen(p.Contact_no); b++)
            {
                if (!isalpha(p.Contact_no[b]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n\t\tContact Number contain invalid character :( Enter Again :) ");
                goto D;
            }
        }
    } while (!valid);
    do
    {
        printf("\n\t\t\tEmail");
        scanf("%s", p.Email);
        if (strlen(p.Email) > 30 || strlen(p.Email) < 8)
        {
            printf("\n\tInvalid :( The max range of Email is 30 and min is 8");
        }
    } while (strlen(p.Email) > 30 || strlen(p.Email) < 8);

E:
    printf("\n\t\t\tProblem:");
    scanf("%s", p.Problem);
    p.Problem[0] = toupper(p.Problem[0]);
    if (strlen(p.Problem) > 15 || strlen(p.Problem) < 3)
    {
        printf("\n\tInvalid :( \t The max range for Problem is 15 and min range is 3.");
        goto E;
    }
    else
    {
        for (b = 0; b < strlen(p.Problem); b++)
        {
            if (isalpha(p.Problem[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\n\n\tProblem contains invalid character. :( Enter Again :)");
            goto E;
        }
    }
F:
    printf("\n\t\t\tPrescribed Doctor");
    scanf("%s", p.Doctor);
    p.Doctor[0] = toupper(p.Doctor[0]);
    if (strlen(p.Doctor) > 30 || strlen(p.Doctor) < 3)
    {
        printf("\n\tInvalid :( \t The max range for Doctor is 30 and min range is 3.");
        goto F;
    }
    else
    {
        for (b = 0; b < strlen(p.Doctor); b++)
        {
            if (isalpha(p.Doctor[b]))
            {

                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\n\tDoctor Name contains invalid character :( Enter Again :)");
            goto F;
        }
    }
    fprintf(ek, "%s%s%c%i%s%s%s%s%s\n", p.First_Name, p.Last_Name, p.Gender, p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t...Information Record Successful...");
    fclose(ek);
sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more [Y / N] ?? ");
    scanf("%c", &ans);
    if (toupper(ans) == 'Y')
    {
        Add_Rec();
    }
    else if (toupper(ans) == 'N')
    {
        printf("\n\t\tThank You :):) ");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}

void Func_List()
{
    int row;
    system("cls");
    Title();
    FILE *ek;
    ek = fopen("Record2.dat", "r");
    printf("\n\n\t\t\t!!!!!! List Patient's Record !!!!!!\n");
    Gotoxy(1, 15);
    printf("Full Name");
    Gotoxy(20, 15);
    printf("Gender");
    Gotoxy(32, 15);
    printf("Age");
    Gotoxy(37, 15);
    printf("Address");
    Gotoxy(49, 15);
    printf("Contact No");
    Gotoxy(64, 15);
    printf("Email");
    Gotoxy(88, 15);
    printf("Problem");
    Gotoxy(98, 15);
    printf("Prescribed Doctor\n");
    printf("======================================================================================================================");
    row = 17;
    while (fscanf(ek, "%s%s%c%i%s%s%s%s\n", p.First_Name, p.Last_Name, &p.Gender, &p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor) != EOF)
    {
        Gotoxy(1, row);
        printf("%s%s", p.First_Name, p.Last_Name);
        Gotoxy(20, row);
        printf("%c", p.Gender);
        Gotoxy(32, row);
        printf("%i", p.Age);
        Gotoxy(37, row);
        printf("%s", p.Address);
        Gotoxy(49, row);
        printf("%s", p.Contact_no);
        Gotoxy(64, row);
        printf("%s", p.Email);
        Gotoxy(68, row);
        printf("%s", p.Problem);
        Gotoxy(98, row);
        printf("%s", p.Doctor);
        row++;
    }
    fclose(ek);
    getch();
    MainMenu();
}

void Search_Rec(void)
{
    char Name[20];
    system("cls");
    Title();
    FILE *ek;
    ek = fopen("Record2.dat", "r");
    printf("\n\n\t\t\t!!!!!! Search Patient's Record !!!!!! \n");
    Gotoxy(12, 8);
    printf("\nEnter Patient's Name to be Viewed");
    scanf("%s", Name);
    fflush(stdin);
    Name[0] = toupper(Name[0]);

    while (fscanf(ek, "%s%s%c%i%s%s%s%s%s\n", p.First_Name, p.Last_Name, &p.Gender, &p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor) != EOF)
    {
        if (strcmp(p.First_Name, Name) == 0)
        {
            Gotoxy(1, 15);
            printf("Full Name");
            Gotoxy(25, 15);
            printf("Gender");
            Gotoxy(32, 15);
            printf("Age");
            Gotoxy(37, 15);
            printf("Address");
            Gotoxy(52, 15);
            printf("Contact Number");
            Gotoxy(64, 15);
            printf("Email");
            Gotoxy(80, 15);
            printf("Problem");
            Gotoxy(95, 15);
            printf("Prescribed Doctor\n");
            printf("**********************");

            Gotoxy(1, 18);
            printf("%s%s", p.First_Name, p.Last_Name);
            Gotoxy(25, 18);
            printf("%c", p.Gender);
            Gotoxy(32, 18);
            printf("%i", p.Age);
            Gotoxy(37, 18);
            printf("%s", p.Address);
            Gotoxy(52, 18);
            printf("%s", p.Contact_no);
            Gotoxy(64, 18);
            printf("%s", p.Email);
            Gotoxy(80, 18);
            printf("%s", p.Problem);
            Gotoxy(95, 18);
            printf("%s", p.Doctor);
            printf("\n");
            break;
        }
    }
    if (strcmp(p.First_Name, Name) != 0)
    {
        Gotoxy(5, 10);
        printf("Record not Found!");
        getch();
    }
    fclose(ek);
L:
    getch();
    printf("\n\n\t\t\tDo you want to view more [Y / N] ??");
    scanf("%c", &ans);
    if (toupper(ans) == 'Y')
    {
        Search_Rec();
    }
    else if (toupper(ans) == 'N')
    {
        printf("\n\t\tThank You :):) ");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\tInvalid Input\n");
        goto L;
    }
}

void Edit_Rec(void)
{
    FILE *ek, *ft;
    int i, b, valid = 0;
    char ch;
    char Name[20];
    system("cls");
    Title();
    ft = fopen("temp2.dat", "w+");
    ek = fopen("Record2.dat", "r");
    if (ek == NULL)
    {
        printf("\n\tCannot open file!");
        getch();
        MainMenu();
    }
    printf("\n\n\t\t\t!!!!!! Edit Patient's Record !!!!!!\n");
    Gotoxy(12, 13);
    printf("Enter the First Name of Patient : ");
    scanf("%s", Name);
    fflush(stdin);
    Name[0] = toupper(Name[0]);
    Gotoxy(12, 15);
    if (ft == NULL)
    {
        printf("\nCannot open file!");
        getch();
        MainMenu();
    }
    while (fscanf(ek, "%s%s%c%i%s%s%s%s%s\n", p.First_Name, p.Last_Name, &p.Gender, &p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor) != EOF)
    {
        if (strcmp(p.First_Name, Name) == 0)
        {
            valid = 1;
            Gotoxy(25, 17);
            printf("**Existing Record**");
            Gotoxy(10, 19);
            printf("%s\t%s\t%c\t%i\t%s\t%s\t%s\t%s\t%s\t\n", p.First_Name, p.Last_Name, p.Gender, p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
            Gotoxy(12, 22);
            printf("New First Name");
            scanf("%s", p.First_Name);
            Gotoxy(12, 24);
            printf("Enter Last Name");
            scanf("%s", p.Last_Name);
            Gotoxy(12, 26);
            printf("Enter Gender");
            scanf("%c", &p.Gender);
            p.Gender = toupper(p.Gender);
            Gotoxy(12, 28);
            printf("Enter Age");
            scanf("%i", &p.Age);
            Gotoxy(12, 30);
            printf("Enter Address");
            scanf("%s", p.Address);
            p.Address[0] = toupper(p.Address[0]);
            Gotoxy(12, 32);
            printf("Enter Contact Number");
            scanf("%s", p.Contact_no);
            Gotoxy(12, 34);
            printf("Enter new Email");
            scanf("%s", p.Email);
            Gotoxy(12, 36);
            printf("Enter Problem");
            scanf("%s", p.Problem);
            p.Problem[0] = toupper(p.Problem[0]);
            Gotoxy(12, 38);
            printf("Enter Doctor");
            scanf("%s", p.Doctor);
            p.Doctor[0] = toupper(p.Doctor[0]);
            printf("\nPress U character for updating operation");
            ch = getche();
            if (ch == 'u' || ch == 'U')
            {
                fprintf(ft, "%s%s%c%i%s%s%s%s%s\n", p.First_Name, p.Last_Name, p.Gender, p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
                printf("\n\n\t\t\t Patient's Record Updated Successfully...");
            }
        }
        else
        {
            fprintf(ft, "%s%s%c%i%s%s%s%s%s\n", p.First_Name, p.Last_Name, p.Gender, p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
        }
    }
    if (!valid)
    {
        printf("\n\t\t No Record Found...");
    }
    fclose(ft);
    fclose(ek);
    remove("Record2.dat");
    rename("temp2.dat", "Record2.dat");
    getch();
    MainMenu();
}

void Dlt_Rec()
{
    char name[20];
    int found = 0;
    system("cls");
    Title();
    FILE *ek, *ft;
    ft = fopen("temp_file2.dat", "w+");
    ek = fopen("Record2.dat", "r");
    printf("\n\n\t\t\t!!!!!! Delete Patient's Record !!!!!!\n");
    Gotoxy(12, 8);
    printf("\nEnter Patient's Name to Delete");
    fflush(stdin);
    gets(name);
    name[0] = toupper(name[0]);
    while (fscanf(ek, "%s%s%c%i%s%s%s%s%s", p.First_Name, p.Last_Name, &p.Gender, &p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor) != EOF)
    {
        if (strcmp(p.First_Name, name) != 0)
        {
            fprintf(ft, "%s%s%c%i%s%s%s%s%s", p.First_Name, p.Last_Name, p.Gender, p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
        }
        else
        {
            printf("%s%s%c%i%s%s%s%s%s", p.First_Name, p.Last_Name, p.Gender, p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("\n\n\t\t\tRecord Not Found...");
        getch();
        MainMenu();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Record2.dat");
        rename("temp_file2.dat", "Record2.dat");
        printf("\n\n\t\t\t Record Deleted Successfully :) ");
        getch();
        MainMenu();
    }
}