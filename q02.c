#include <stdio.h>
#define MAX_FLOORS 10


void floor_move(int *current_floor, int floor, char floors[MAX_FLOORS][15]) {
    if (floor >= 0 && floor < MAX_FLOORS) {
        printf("You requested to go to the %s\n", floors[floor]);
        if (*current_floor < floor) {
            while (*current_floor < floor) {
                (*current_floor)++;
                printf("Passing Floor %d\n", *current_floor);
            }
            printf("Arrived at Floor %d\n", *current_floor);
        } else {
            while (*current_floor > floor) {
                (*current_floor)--;
                printf("Passing Floor %d\n", *current_floor);
            }
            printf("Arrived at Floor %d\n", *current_floor);
        }
    }
    else{

        printf("You requested to go to the Number is out of range.\n"
               "Invalid floor number.\n");
        }
}


int main() {
    char floors[MAX_FLOORS][15]= {"Zeroth floor", "First floor", "Second floor", "Third floor",
                                  "Fourth floor", "Fifth floor", "Sixth floor", "Seventh floor",
                                  "Eighth floor", "Ninth floor"};
    int current_floor =0;
    int floor;
    printf("Elevator is currently at floor: %d\n", current_floor);
    int isint;
    while (1) {
        printf("Enter the floor number you wish to go to (-1 to exit): \n");
        isint= scanf(" %d", &floor);
        if (floor==-1){
            printf("You requested to go to the Number is out of range.\n");
            printf("Elevator simulation ended.\n");
            break;
        }
        if (isint==0) {
            printf("MyERROR: An illegal operation was performed, so I have to stop the program.\n");
            break;
        }
        int check_buffer = getchar();
        if (check_buffer  != '\n' && check_buffer != EOF){
            printf("MyERROR: An illegal operation was performed, so I have to stop the program.\n");
            break;
        }

        floor_move(&current_floor, floor, floors);

    }

    return 0;
}