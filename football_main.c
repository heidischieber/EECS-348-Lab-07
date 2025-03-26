#include "football.h" //includes header football.h
#include "football.c" //includes football.c code
#include <stdio.h> //includes library stdio.h that has stuff such as printf and scanf 

//find way to throw error if user inputs a wrong type in score!!!

int main(int argc, char *argv[]) {
    int score; //initializes variable score
    printf("Enter 0 or 1 to STOP\nEnter the NFL score: \n"); //asks user for input
    if (scanf("%d", &score) != 1){ //stroes user input in score and if True then wrong type inputted by user
        printf("Invalid type for score."); //display error
        return 0; //return 0 to quit program 
    }; 
    while (score >= 2){ //while loop runs while score is greater than or equal to 2
        int c = count_combinations(score); //int c is initialized and holds value returned by calling the function count_combinations() with param score
        printf("Possible combinations of scoring plays if a team's score is %d: \n\n", score); //prints an explanation
        print_combinations(score); //calls function print_combinations which will print the combinations of param score
        printf("Total count: %d\n\n", c); //prints the total count of combinations which is stored in c
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: \n"); //asks for user input on a new score
        scanf("%d", &score); //stores user score 
    }
    return 0; //returns nothing (0)
}