/*
This is the program designed with the requirement of 6.2 Exercise, which gave the 
programmer a specific main() function and the declaration of the drawRoom() function
and ask the programmer to define 3 different functions to handle the work of the drawRoom()
function. And the drawRoom() function is required to draw a room with specific length and width
and also point out the position of given X and Y value.
*/

void drawRoom(int length, int width, int X, int Y);     // Declare tbe drawRoom() function

int main(void) {                                        // Define the main() function
    drawRoom(2,2,0,1);                                  // The given struct of the main() function in handout
    drawRoom(5,3,1,2);
    drawRoom(14,8,8,5);
    
    getchar();
    return 0;
}

void drawHorizon(int length) {                          // Define the drawHorizon() function
    putchar('+');                                       // Print the first charactor of the Horizon '+'
    for (int i=0; i<length; i++) putchar('-');          // Print the middle of the Horizon which composed with '-' until reach the end
    putchar('+');                                       // Print the last charactor of the Horizon '+'
    putchar('\n');                                      // Turn to the next line
}

void drawLine(int length) {                             // Define the drawLine() function
    putchar('|');                                       // Print the first charactor of the Line '|'
    for (int i=0; i<length; i++) putchar('.');          // Print the middle of the Horizon which composed with '.' until reach the end
    putchar('|');                                       // Print the last charactor of the Line '|'
    putchar('\n');                                      // Turn to the next line
}

void drawLineWithPlayer(int length, int X) {            // Define the drawLineWithPlayer() function
    putchar('|');                                       // Print the first charactor of the Line '|'
    for (int i=0; i<X; i++) putchar('.');               // Print the middle of the Horizon which composed with '.' until reach the player
    putchar('@');                                       // Print the player as '@'
    for (int i=X+1; i<length; i++) putchar('.');        // Print the middle of the Horizon which composed with '.' until reach the enn
    putchar('|');                                       // Print the last charactor of the Line '|'
    putchar('\n');                                      // Turn to the next line
}

void drawRoom(int length, int width, int X, int Y) {    // Define the drawRoom() function
    drawHorizon(length);                                // Draw the Up Horizon of the room
    for (int i=0; i<Y; i++) drawLine(length);           // Draw the line until reach the line the player locates in
    drawLineWithPlayer(length, X);                      // Draw the line which the player locates in
    for (int i=Y+1; i<width; i++) drawLine(length);     // Draw the line until reach the Down Horizon
    drawHorizon(length);                                // Draw the down horizon of the room
}