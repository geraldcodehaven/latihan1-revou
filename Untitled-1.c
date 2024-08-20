#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 256

// Structure to store a task
typedef struct {
    char description[MAX_TASK_LENGTH];
} Task;

// Function declarations
void addTask(Task tasks[], int *taskCount);
void viewTasks(const Task tasks[], int taskCount);
void deleteTask(Task tasks[], int *taskCount);

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("\nTodo List Manager\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left in buffer

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, &taskCount);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full. Cannot add more tasks.\n");
        return;
    }

    printf("Enter task description: ");
    fgets(tasks[*taskCount].description, MAX_TASK_LENGTH, stdin);

    // Remove newline character from the end of the description
    size_t len = strlen(tasks[*taskCount].description);
    if (len > 0 && tasks[*taskCount].description[len - 1] == '\n') {
        tasks[*taskCount].description[len - 1] = '\0';
    }

    (*taskCount)++;
    printf("Task added successfully.\n");
}

void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("\nTodo List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i].description);
    }
}

void deleteTask(Task tasks[], int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int index;
    printf("Enter task number to delete: ");
    scanf("%d", &index);
    getchar(); // Consume newline character left in buffer

    if (index < 1 || index > *taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = index - 1; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*taskCount)--;
    printf("Task deleted successfully.\n");
}
