#include<stdio.h>
#include<stdlib.h>
#define maxheight 36
#define maxwidth 86
#define tokenheight 7
#define tokenwidth 12
#define playgroundlen 9
#define clear "clear" /* you can change this to "cls" for windows */

void display_banner(void)
{
    int c;
    FILE *file;
    file = fopen("banner.txt", "r");
    fflush(stdin);
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    return ;
}

void init_playground(char playground_arr[maxheight][maxwidth])
{
    int c, i = 0, j = 0;
    FILE *file;
    file = fopen("playground.txt", "r");
    fflush(stdin);
    if (file) {
        while( i < maxheight )
        {
            while (j < maxwidth)
            {
                c = getc(file);
                playground_arr[i][j] = c;
                
                j++;
            }
            j = 0;
            i++;
        }
        fclose(file);
        printf("\n");
    } 

    return ;
}

void init_token(char token_arr[tokenheight][tokenwidth], char filename[6])
{
    int c, i = 0, j;
    FILE *file;
    file = fopen(filename,"r");

    if (file) {
        for(i = 0; i <tokenheight; i++)
        {
            for ( j = 0; j < tokenwidth; j++)
            {
                c = getc(file);
                if (c != '\n')
                    token_arr[i][j] = c;
            }
        }
        fclose(file);
        printf("\n");
    }
    return ;
}

void display_playground(char playground_arr[maxheight][maxwidth])
{
    int i, j;
    fflush(stdout);
    for(i = 0; i < maxheight; i++)
    {
        for(j = 0; j <maxwidth; j++)
        {
            printf("%c",playground_arr[i][j]);
        }
    } 
    printf("\n\n");
    return ;
}

void display_token(char token_arr[tokenheight][tokenwidth])
{
    int i, j;
    fflush(stdout);
    for(i = 0; i < tokenheight; i++)
    {
        for(j = 0; j < tokenwidth; j++)
        {
            printf("%c",token_arr[i][j]);
        }
        printf("\n");
    } 
    printf("\n\n");
    return ;
}

int win_status(int area[])
{
    int i, j, board[3][3] = {0}, k = 0, sum;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = area[k++];
        }
    }
    /* horizontal */
    for (i = 0; i < 3; i++) {
        sum = 0;
        for (j = 0; j < 3; j++) {
            sum += board[i][j];
        }
        if (sum == 3) return 1; else if (sum == -3) return -1;
    }
    /* vertical */
    for (j = 0; j < 3; j++) {
        sum = 0;
        for (i = 0; i < 3; i++) {
            sum += board[i][j];
        }
        if (sum == 3) return 1; else if (sum == -3) return -1;
    } 
    sum = area[0] + area[4] + area[8];
    if (sum == 3) return 1; else if (sum == -3) return -1;
    sum = area[2] + area[4] + area[6];
    if (sum == 3) return 1; else if (sum == -3) return -1;
    return -2;
}

int calculate_area(int area[], int position, char token)
{
    int win_stat = 0;
    /*
    exit code 1: X token win status
    exit code 0: position occupied
    exit code -1: O token win status
    exit code -2: no win, continue
    */
    if (area[position-1] == 0)
    {
        if(token == 'X') area[position-1] = 1; else area[position-1] = -1;
        win_stat = win_status(area);
        if (win_stat == 1) return 1; else if (win_stat == -1) return -1; else return -2;
    }
    return 0;
}

void print_x_won()
{
    int c;
    FILE *file;
    file = fopen("x_won.txt", "r");
    fflush(stdin);
    printf("\n");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    return ;
}

void print_o_won()
{
    int c;
    FILE *file;
    file = fopen("o_won.txt", "r");
    fflush(stdin);
    printf("\n");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    return ;
}

void print_draw()
{
    int c;
    FILE *file;
    file = fopen("draw.txt", "r");
    fflush(stdin);
    printf("\n");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    return ;
}


void play(char playground[maxheight][maxwidth], char X[tokenheight][tokenwidth], char O[tokenheight][tokenwidth], int area[])
{
    int position, count = 0, game_status;
    char token;
    
    while (1)
    {
        display_playground(playground);
        printf(" \nPlease input position from 1-9: ");
        scanf(" %d", &position);
        if (position < 1 || position > 9) goto jp;
        printf(" \nPlease input token [ X | O ]: ");
        scanf(" %c", &token);

        if (token == 'x' || token == 'o' ) token -= 32;
    jp: if (position < 1 || position > 9 || (token != 'X' && token != 'O')) 
        { 
            char answer;
            printf("\nWould you like to quit?[Y|N]");
            scanf(" %c",&answer);
            if (answer == 'y') answer -= 32;
            if (answer == 'Y') {
                exit(0);
            } else {
                system(clear);
                continue;
            }
        }
        game_status = calculate_area(area, position, token);
        if (game_status == 0) {
            system(clear);
            printf("\nThis position is occupied please enter different position\n");
            continue;
        }

        system(clear);
        switch (position)
            {
            case 1:
                {  
                    int i, j, y = 3, x = 14;
                    fflush(stdout);
                    for (i = 0; i < tokenheight; i++ )
                    {
                        for (j = 0; j < tokenwidth-2; j++) 
                        {
                            if (token == 'X')
                                playground[y+i][x+j] = X[i][j]; 
                            else  
                                playground[y+i][x+j] = O[i][j];
                        }
                    }
                    
                    break;
                }

            case 2:
                {  
                    int i, j, y = 3, x = 40;
                    fflush(stdout);
                    for (i = 0; i < tokenheight; i++ )
                    {
                        for (j = 0; j < tokenwidth-2; j++) 
                        {
                            if (token == 'X')
                                playground[y+i][x+j] = X[i][j]; 
                            else  
                                playground[y+i][x+j] = O[i][j];
                        }
                    }
                    
                    break;
                }

            case 3:
                {  
                    int i, j, y = 3, x = 66;
                    fflush(stdout);
                    for (i = 0; i < tokenheight; i++ )
                    {
                        for (j = 0; j < tokenwidth-2; j++) 
                        {
                            if (token == 'X')
                                playground[y+i][x+j] = X[i][j]; 
                            else  
                                playground[y+i][x+j] = O[i][j];
                        }
                    }
                    
                    break;
                }

            case 4:
                {  
                    int i, j, y = 15, x = 14;
                    fflush(stdout);
                    for (i = 0; i < tokenheight; i++ )
                    {
                        for (j = 0; j < tokenwidth-2; j++) 
                        {
                            if (token == 'X')
                                playground[y+i][x+j] = X[i][j]; 
                            else  
                                playground[y+i][x+j] = O[i][j];
                        }
                    }
                    
                    break;
                }

            case 5:
                {  
                    int i, j, y = 15, x = 40;
                    fflush(stdout);
                    for (i = 0; i < tokenheight; i++ )
                    {
                        for (j = 0; j < tokenwidth-2; j++) 
                        {
                            if (token == 'X')
                                playground[y+i][x+j] = X[i][j]; 
                            else  
                                playground[y+i][x+j] = O[i][j];
                        }
                    }
                    
                    break;
                }

            case 6:
                {  
                    int i, j, y = 15, x = 66;
                    fflush(stdout);
                    for (i = 0; i < tokenheight; i++ )
                    {
                        for (j = 0; j < tokenwidth-2; j++) 
                        {
                            if (token == 'X')
                                playground[y+i][x+j] = X[i][j]; 
                            else  
                                playground[y+i][x+j] = O[i][j];
                        }
                    }
                    
                    break;
                }

            case 7:
                {  
                    int i, j, y = 27, x = 14;
                    fflush(stdout);
                    for (i = 0; i < tokenheight; i++ )
                    {
                        for (j = 0; j < tokenwidth-2; j++) 
                        {
                            if (token == 'X')
                                playground[y+i][x+j] = X[i][j]; 
                            else  
                                playground[y+i][x+j] = O[i][j];
                        }
                    }
                    
                    break;
                }

            case 8:
                {  
                    int i, j, y = 27, x = 40;
                    fflush(stdout);
                    for (i = 0; i < tokenheight; i++ )
                    {
                        for (j = 0; j < tokenwidth-2; j++) 
                        {
                            if (token == 'X')
                                playground[y+i][x+j] = X[i][j]; 
                            else  
                                playground[y+i][x+j] = O[i][j];
                        }
                    }
                    
                    break;
                }

            case 9:
                {  
                    int i, j, y = 27, x = 66;
                    fflush(stdout);
                    for (i = 0; i < tokenheight; i++ )
                    {
                        for (j = 0; j < tokenwidth-2; j++) 
                        {
                            if (token == 'X')
                                playground[y+i][x+j] = X[i][j]; 
                            else  
                                playground[y+i][x+j] = O[i][j];
                        }
                    }
                    
                    break;
                }
            default:
                printf("\nSomething went wrong :/\n");
                break;
            }
        count++;
        if (game_status == 1) {
            system(clear);
            display_playground(playground);
            print_x_won();
            return ;
        } else if (game_status == -1){
            system(clear);
            display_playground(playground);
            print_o_won();
            return ;
        } else if (count == 9) {
            system(clear);
            display_playground(playground);
            print_draw();
            return ;
        } 
    }
    return ;
}

int main(void)
{
    char playground[maxheight][maxwidth] = {0};
    char X[tokenheight][tokenwidth] = {0}, O[tokenheight][tokenwidth] = {0};
    char x_file[6] = "X.txt", o_file[6] = "O.txt";
    

    display_banner();
    printf("\n This tic-tac-toe game is little different than the usual ones. There is no order for the x and o choices. O player\n may choose to play 2 times but then x player will play 2 adjacent rounds.\n Have fun !");


    

    
    init_token(X, x_file);
    init_token(O, o_file);

    while (1)
    {
        int area[9] = {0};
        char ans;
        printf("\nPress any key to start...\n");

        if (getchar()) {
            system(clear);
        }
        init_playground(playground);
        play(playground, X, O, area);
        printf("\n\nWanna play again? [y|n]:\n");
        scanf(" %c", &ans);
        if (ans == 'Y' || ans == 'N' ) ans += 32;
        if (ans == 'y') {
            continue;
        } else break;
    }
     

    return 0;
}