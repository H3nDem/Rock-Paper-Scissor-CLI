#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int your_choice;
int opponent_choice;
int your_score = 0;
int opponent_score = 0;
int rounds = 0;
int check_correct_move(int);
char* convert_into_move(int);
void print_round(int, int);
void print_final_result(void);
void print_choices(void);

int main() {
    srand(time(0));
    printf("\e[1;1H\e[2J");
    printf("Welcome to Rock, Paper, Scissor !\nSelect one of the following actions\n");
    while (1)
    {
        print_choices();
        if (scanf("%d", &your_choice) != 1 || !check_correct_move(your_choice)) {
            printf("\e[1;1H\e[2J");
            printf("Incorrect move entered.\nPlease enter one of the actions below.\n");
            while (getchar() != '\n'); // Clear the input buffer, if this line not here -> stuck into infinite loop upon entering char like 'a'
            continue;
        }
        else if (your_choice==0) break;
        else {
            opponent_choice = (rand() % 3) + 1;
            print_round(your_choice, opponent_choice);
            rounds++;
        }
    }
    print_final_result();
    return 0;
}

int check_correct_move(int value) {
    if (value < 0 || value > 3) {
        return 0;
    } else {
        return 1;
    }
}

char* convert_into_move(int value) {
    switch (value)
    {
    case 1:
        return "Rock";
    case 2:
        return "Paper";
    case 3:
        return "Scissor";
    default:
        printf("Unknown move: %d", value);
        break;
    }
}

void print_round(int your_choice, int opponent_choice) {
    printf("\e[1;1H\e[2J");
    printf("You  -->    %s - %s    <--  Bot\n", convert_into_move(your_choice), convert_into_move(opponent_choice));
    if (your_choice == opponent_choice) {
        printf("\t        Draw !\n");
    } else if (your_choice < opponent_choice && !(your_choice==1 && opponent_choice==3) || (your_choice==3 && opponent_choice==1)){
        printf("\t      You lost !\n");
        opponent_score++;
    } else {
        printf("\t      You won !\n");
        your_score++;
    }
}

void print_final_result(void) {
    printf("\e[1;1H\e[2J");
    printf("\n\t       --- Game results ---\n");
    printf("_________________________________________________\n|\t\t\t\t\t\t|\n");
    printf("|\tYour score :  %d - %d  : Bot score\t|\n|\t\t Total draws: %d\t\t\t|\n|\t\t Total rounds: %d\t\t|\n",your_score, opponent_score, (rounds-(your_score+opponent_score)), rounds);
    printf("|_______________________________________________|\n\n\n");
}

void print_choices(void) {
    printf("\t_____________________\n");
    printf("\t|\t\t    |\n");
    printf("\t|   1 -->  Rock\t    |\n");
    printf("\t|   2 -->  Paper    |\n");
    printf("\t|   3 -->  Scissor  |\n");
    printf("\t|\t\t    |\n");
    printf("\t|   0 -->  Quit\t    |\n");
    printf("\t|___________________|\n\n");
    printf("Choose your move: ");
}


