#include <stdio.h>
#include <stdlib.h>
int g=0;
int On=1;
char Task[100][100];
int Mark[100]={0};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EndTaskManager(){
printf("Exiting Minions Task Manager. Have a great day!");
On=0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AddTask(){
printf("\nEnter task description:");
scanf("%s",&Task[g]);
printf("\n");
g++;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ViewTask(){
int Option;
printf("\nChoose which tasks to view:\n\n1. All\n2. Uncompleted\n3. Completed\n\nChoose an option:");
scanf("%d",&Option);
switch(Option){
case 1:
    printf("\nCurrent Tasks:\n\n");
    for(int i=0; i<g; i++){
        printf("Task ID: %d\nDescription: %s\nStatus: %s\n\n",i+1,Task[i],Mark[i]==1?"Completed":"Uncompleted");
    }
    break;
case 2:
    printf("\nCurrent Uncompleted Tasks:\n\n");
    for(int i=0; i<g; i++){
        if(Mark[i]==0)
        printf("Task ID: %d\nDescription: %s\nStatus: Uncompleted\n\n",i+1,Task[i]);
    }
    break;
case 3:
    printf("\nCurrent Completed Tasks:\n\n");
    for(int i=0; i<g; i++){
        if(Mark[i]==1)
        printf("Task ID: %d\nDescription: %s\nStatus: Completed\n\n",i+1,Task[i]);
    }
    break;
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RemoveTask(){
int Id;
printf("\nEnter task ID to remove:");

scanf("%d",&Id);Id--;
for (int i = Id; i < g; i++) {
    Mark[i]=Mark[i+1];
    for(int j=0;j<100;j++){
           Task[i][j] = Task[i + 1][j];
           }
    }
g--;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MarkTask(){
int Id;
printf("\nChoose an ID to mark a task as completed:");
scanf("%d",&Id);Id--;
Mark[Id]=1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void StartTaskManager(){
int Option;
printf("Minions Task Manager\n1. Add Task\n2. View Tasks\n3. Remove Task\n4. Mark Task\n5. Exit\n\nSelect an option:");
scanf("%d",&Option);// problem when taking in a char
switch(Option){
case 1:
    AddTask();
    break;
case 2:
    ViewTask();
    break;
case 3:
    RemoveTask();
    break;
case 4:
    MarkTask();
    break;
case 5:
    EndTaskManager();
    break;
default:
    printf("\nInput a valid option\n\n");
    break;
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    while(On)
    StartTaskManager();
    return 0;
}

