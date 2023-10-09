/*
 *  This is the program designed with the requirement of 6.2 Exercise, which gave the 
 *  programmer a specific main() function and the declaration of the drawRoom() function
 *  and ask the programmer to define 3 different functions to handle the work of the drawRoom()
 *  function. And the drawRoom() function is required to draw a room with specific length and width
 *  and also point out the position of given X and Y value.
 */

#include <stdio.h>                                          // Include the standard I/O library
#include <conio.h>                                          // Include the console I/O library

/* 
 *  This program has used conio.h (or called Console I/O library), so it may not be able to compile
 *  or run in every system.
 */

void drawRoom(int length, int height, int X, int Y);        // Declare the drawRoom() function

typedef struct {                                            // Define the struct including the data of the room
    int length;                                                 // The length of the room
    int height;                                             // The height of the room
    int X;                                                  // The X Position of the player
    int Y;                                                  // The Y Position of the player
} Room;                                                     // The name of the struct

void getKey(Room *Room_Obj) {                               // Define the function to get the input and return the input status
    switch (getch()) {                                      // Find which key was typed
    case '2':                                               // '2' represents DOWN
        if (Room_Obj->Y < Room_Obj->height-1) Room_Obj->Y++;// If it's able to move, move the position of the player
        else printf("Bump into the wall :(\n");             // If it's unable to move, print the tip on screen
        break;
    case '4':                                               // '4' represents LEFT
        if (Room_Obj->X > 0) Room_Obj->X--;                 // If it's able to move, move the position of the player
        else printf("Bump into the wall :(\n");             // If it's unable to move, print the tip on screen
        break;
    case '6':                                               // '6' represents RIGHT
        if (Room_Obj->X < Room_Obj->length-1) Room_Obj->X++;// If it's able to move, move the position of player
        else printf("Bump into the wall :(\n");             // If it's unable to move, print the tip on screen
        break;
    case '8':                                               // '8' represents UP
        if (Room_Obj->Y > 0) Room_Obj->Y--;                 // If it's able to move, move the position of the player
        else printf("Bump into the wall :(\n");             // If it's unable to move, print the tip on screen
        break;
    default:                                                // And the other inputs are invalid
        printf("Invalid Input X(\n");                       // If the input number is invalid, print the tip on screen
        break;
    }
}

int main(void) {                                            // Define the main() function
    printf("Turn on your num lock first ;)\n");             // The tip before the game

    // Part 1: Init the room and the position.
    Room room;                                              // Declare the struct Room
    printf("Type the length, height of the room, then type the X and Y of the player.\n");  // Print the line to get the data from input
    scanf("%d %d %d %d", &room.length, &room.height, &room.X, &room.Y);                     // Get the data from the input
    drawRoom(room.length, room.height, room.X, room.Y);     // Draw the origin scene of the room and the player
    
    // Part 2: Use a infinite loop to control the player
    while (1) {
        getKey(&room);                                      // Get the input from the number pad and change the position of the player
        drawRoom(room.length, room.height, room.X, room.Y); // Draw the room then
    }

    return 0;
}

/*------------------------ This part is the functions in 6-2-original ------------------------*/

void drawHorizon(int length) {                              // Define the drawHorizon() function
    putchar('+');                                           // Print the first charactor of the Horizon '+'
    for (int i=0; i<length; i++) putchar('-');              // Print the middle of the Horizon which composed with '-' until reach the end
    putchar('+');                                           // Print the last charactor of the Horizon '+'
    putchar('\n');                                          // Turn to the next line
}

void drawLine(int length) {                                 // Define the drawLine() function
    putchar('|');                                           // Print the first charactor of the Line '|'
    for (int i=0; i<length; i++) putchar('.');              // Print the middle of the Horizon which composed with '.' until reach the end
    putchar('|');                                           // Print the last charactor of the Line '|'
    putchar('\n');                                          // Turn to the next line
}

void drawLineWithPlayer(int length, int X) {                // Define the drawLineWithPlayer() function
    putchar('|');                                           // Print the first charactor of the Line '|'
    for (int i=0; i<X; i++) putchar('.');                   // Print the middle of the Horizon which composed with '.' until reach the player
    putchar('@');                                           // Print the player as '@'
    for (int i=X+1; i<length; i++) putchar('.');            // Print the middle of the Horizon which composed with '.' until reach the enn
    putchar('|');                                           // Print the last charactor of the Line '|'
    putchar('\n');                                          // Turn to the next line
}

void drawRoom(int length, int height, int X, int Y) {       // Define the drawRoom() function
    putchar('\f');                                          // Print '\f' to clear the screen
    drawHorizon(length);                                    // Draw the Up Horizon of the room
    for (int i=0; i<Y; i++) drawLine(length);               // Draw the line until reach the line the player locates in
    drawLineWithPlayer(length, X);                          // Draw the line which the player locates in
    for (int i=Y+1; i<height; i++) drawLine(length);        // Draw the line until reach the Down Horizon
    drawHorizon(length);                                    // Draw the down horizon of the room
    putchar('\n');                                          // Turn to the next line
}