#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char ts_name[64];
    char ts_description[128];
    char ts_data[32];
} Task;

// declare functions
int ask_from_user(int user_choice, int i);
void fill_arr_with_task(Task info[], int len);
void print_tasks(Task info[], int len);

int main()
{
    system("cls");

    FILE *file;

    // declaring variables
    Task info[10];
    int number = 0, number_of_task = 0;
    int i = 0;
    char file_with_extension[35];

    printf(" _____________\n"
           "|             |\n"
           "| Hello there |\n"
           "|_____________|\n");

    printf("\nPress '1' if you would like to know more about Task manager\n"
           "Press '0' to skip and start usind this awesome app: ");

    int user_know;

    // getting number from user, till enters correct number
    while (i <= 10)
    {
        scanf("%d", &user_know);

        if (user_know == 1 || user_know == 0)
        {
            break;
        }
        printf("Please, enter a valid option: ");
    }

    // giving information about program
    if (user_know == 1)
    {
        system("cls");
        printf("This is an app which you can organize your tasks easily :)\n"
               "Without further ado let's start program!\n");
    }

    number = ask_from_user(number, i);

check_user_again:

    /*______________________________________________________________________________________________________________*/

    // writing tasks
    if (number == 1)
    {
        system("cls");
        int view_task, write_task_file;
        printf("How many tasks would you like to write?: ");

        // taking number from user
        while (i <= 10)
        {
            scanf("%d", &number_of_task);
            if (number_of_task <= 10)
            {
                break;
            }
            printf("Sorry, but you can write maximum 10 tasks :(\n");
            printf("Plese, enter again: ");
        }

        // declarinf variable called Task
        Task info[number_of_task];

        // calling function which writes information
        fill_arr_with_task(info, number_of_task);
        system("cls");

        // printing
        printf(" ________________________________________\n"
               "|                                        |\n"
               "| Tasks has been written succesfully. :) |\n"
               "|________________________________________|\n\n");
        printf("Press '1' if you would like to see your tasks\n"
               "Press '0' to skip: ");

        // asking user if wants to see what he/she wrote
        while (i <= 10)
        {
            scanf("%d", &view_task);
            if (view_task == 1 || view_task == 0)
            {
                break;
            }
            printf("Please, enter valid option: ");
            i++;
        }
        i = 0;
        system("cls");

        // printing user tasks
        if (view_task == 1)
        {
            print_tasks(info, number_of_task);
        }
        printf("\n\nPress '1' if you would like to write tasks into file\n"
               "Press '0' to skip: ");

        // getting number from user
        while (i <= 10)
        {
            scanf("%d", &write_task_file);
            if (write_task_file == 1 || write_task_file == 0)
            {
                break;
            }
            printf("Please, enter valid option: ");
            i++;
        }
        i = 0;

        // printing users tasks into file
        system("cls");
        if (write_task_file == 1)
        {
            char file_name[32];
            printf("Enter a name for your file: ");
            scanf(" %s", file_name);

            file_with_extension[35];
            snprintf(file_with_extension, sizeof(file_with_extension), "%s.txt", file_name);

            file = fopen(file_with_extension, "w");

            // couldn't create file
            if (file == NULL)
            {
                printf(" _____________________________\n"
                       "|                             |\n"
                       "|            Error:           |\n"
                       "| Couldn't connect to file :/ |\n"
                       "|_____________________________|\n\n");
                return 0;
            }

            // printing all users task into file
            for (int i = 0; i < number_of_task; i++)
            {
                fprintf(file, " ____________________________\n"
                              "|                            |\n"
                              "| Information about task %d.  |\n"
                              "|____________________________|\n",
                        i + 1);
                fprintf(file, "%d. %s\n", i + 1, info[i].ts_name);
                fprintf(file, "%d. %s\n", i + 2, info[i].ts_description);
                fprintf(file, "%d. %s\n", i + 3, info[i].ts_data);
            }
            fclose(file);
            system("cls");

            // printing
            printf("\n ______________________________\n"
                   "|                              |\n"
                   "| Your tasks have been written |\n"
                   "|   into file succesfully!     |\n"
                   "|______________________________|\n\n");
        }

        number = ask_from_user(number, i);
        goto check_user_again;
    }

    /*______________________________________________________________________________________________________________*/
    system("cls");

    // changing user's tasks
    if (number == 2)
    {
        system("cls");
        int change_task;
        printf("You have %d tasks written into file!\n", number_of_task);
        printf("Enter number of task that you would like to change from a file: ");
        i = 0;
        while (i <= 10)
        {
            scanf("%d", &change_task);

            // checking whether task is written or not
            if (number_of_task == 0)
            {
                printf("You haven't written any tasks :/\n");
                break;
            }

            if (change_task <= number_of_task)
            {
                break;
            }
            printf("Please, enter valid option: ");
        }

        // changing user's task
        system("cls");
        if (change_task <= number_of_task)
        {
            fclose(file);

            printf("\n __________________________________\n"
                   "|                                  |\n"
                   "| Enter your new task for %d task.  |\n"
                   "|__________________________________|\n\n",
                   change_task);

            for (int i = 0; i < 1; i++)
            {
                printf("%d. Enter name of task: ", i + 1);
                scanf(" %[^\n]s", info[change_task - 1].ts_name);

                printf("%d. Enter task's description: ", i + 2);
                scanf(" %[^\n]s", info[change_task - 1].ts_description);

                printf("%d. Enter data of task: ", i + 3);
                scanf(" %[^\n]s", info[change_task - 1].ts_data);
            }

            // and printing to file again new, changed tasks
            FILE *test = fopen(file_with_extension, "w");

            for (int i = 0; i < number_of_task; i++)
            {
                int count = 0;
                fprintf(test, " ____________________________\n"
                              "|                            |\n"
                              "| Information about task %d.  |\n"
                              "|____________________________|\n",
                        i + 1);
                fprintf(test, "%d. %s\n", count + 1, info[i].ts_name);
                fprintf(test, "%d. %s\n", count + 2, info[i].ts_description);
                fprintf(test, "%d. %s\n", count + 3, info[i].ts_data);
            }
            fclose(test);
            i++;
        }
        number = ask_from_user(number, i);
        goto check_user_again;
    }

    /*______________________________________________________________________________________________________________*/

    // printing users tasks
    else if (number == 3)
    {
        if (number_of_task != 0)
        {
            print_tasks(info, number_of_task);
        }
        else
        {
            printf("You haven't written any tasks, please write tasks!\n");
        }
        number = ask_from_user(number, i);
        goto check_user_again;
    }

    /*______________________________________________________________________________________________________________*/

    // deleting user's task
    else if (number == 4)
    {
        system("cls");
        int delete_task;
        printf("Enter a number of task, that you want to delete: ");
        i = 0;

        while (i <= 10)
        {
            scanf("%d", &delete_task);

            if (number_of_task == 0)
            {
                printf("You haven't written any tasks :/\n");
                break;
            }

            if (number_of_task >= delete_task)
            {
                break;
            }

            printf("Please, enter valid option: ");
            i++;
        }

        int press;

        // writing user's new, deleted tasks into file
        if (number_of_task >= delete_task)
        {
            Task new_arr[number_of_task - 1];

            for (int i = 0; i < number_of_task - 1; i++)
            {
                if (number_of_task != delete_task)
                {
                    new_arr[i] = info[i];
                }
            }
            system("cls");
            printf("\n ________________________________________\n"
                   "|                                        |\n"
                   "| %d task have been removed succesfully!  |\n"
                   "|________________________________________|\n\n",
                   delete_task);

            printf("Press '1' if you would like to write you tasks into file\n"
                   "Press '0' to skip: ");

            i = 0;
            while (i <= 10)
            {
                scanf("%d", &press);
                if (press == 0 || press == 1)
                {
                    break;
                }

                printf("Please, enter a valid option: ");
            }
        }

        if (press == 1)
        {
            FILE *test = fopen(file_with_extension, "w");

            for (int i = 0; i < number_of_task; i++)
            {
                int count = 0;
                fprintf(test, " ____________________________\n"
                              "|                            |\n"
                              "| Information about task %d.  |\n"
                              "|____________________________|\n",
                        i + 1);
                fprintf(test, "%d. %s\n", count + 1, info[i].ts_name);
                fprintf(test, "%d. %s\n", count + 2, info[i].ts_description);
                fprintf(test, "%d. %s\n", count + 3, info[i].ts_data);
            }
            fclose(test);
        }

        number = ask_from_user(number, i);
        goto check_user_again;
    }

    /*______________________________________________________________________________________________________________*/

    // finishing program
    else if (number == 5)
    {
        system("cls");
        printf(" __________________________________________\n"
               "|                                          |\n"
               "| Thank you for using Task_Manager app :)  |\n"
               "|__________________________________________|\n\n");

        return 0;
    }
    printf(" __________________________________________\n"
           "|                                          |\n"
           "| Thank you for using Task_Manager app :)  |\n"
           "|__________________________________________|\n\n");

    return 0;
}

// funtion which asks user's desire
int ask_from_user(int user_choice, int i)
{
    printf("\nTo  add   tasks 1: "
           "\nTo change tasks 2: "
           "\nTo  see   tasks 3: "
           "\nTo remove tasks 4: "
           "\nTo stop program 5: \n"
           "\nEnter number below : ");

    while (i <= 10)
    {
        scanf("%d", &user_choice);
        if (user_choice == 1 || user_choice == 2 || user_choice == 3 ||
            user_choice == 4 || user_choice == 5)
        {
            break;
        }
        printf("Please, enter valid option: ");
        i++;
    }
    i = 0;
    return user_choice;
}
// function to fill structure
void fill_arr_with_task(Task info[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int count = 0;
        printf("\n ____________________________\n"
               "|                            |\n"
               "| Information about task %d.  |\n"
               "|____________________________|\n\n",
               i + 1);

        printf("%d. Enter name of task: ", count + 1);
        scanf(" %[^\n]s", info[i].ts_name);

        printf("%d. Enter task's description: ", count + 2);
        scanf(" %[^\n]s", info[i].ts_description);

        printf("%d. Enter data of task: ", count + 3);
        scanf(" %[^\n]s", info[i].ts_data);
    }
}

// function to print information which is in Task structure
void print_tasks(Task info[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int count = 0;

        printf("\n ___________________________\n"
               "|                           |\n"
               "| Information about task %d  |\n"
               "|___________________________|\n\n",
               i + 1);

        printf("  %d. Task name: %s \n", count + 1, info[i].ts_name);
        printf("  %d. Task description: %s \n", count + 2, info[i].ts_description);
        printf("  %d. Task data: %s \n", count + 3, info[i].ts_data);

        printf(" ___________________________\n"
               "|___________________________|\n\n");
    }
}
