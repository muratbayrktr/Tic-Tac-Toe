#include<stdio.h>
#include<stdlib.h>
#define maxheight 36
#define maxwidth 86
#define tokenheight 7
#define tokenwidth 12


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
}

void play(char playground[maxheight][maxwidth], char X[tokenheight][tokenwidth], char O[tokenheight][tokenwidth], int filled_area[])
{
    int position, count = 0;
    char token;
    
    while (count++ < 9)
    {
        display_playground(playground);
        printf(" \nPlease input position from 1-9: ");
        scanf(" %d", &position);
        printf(" \nPlease input token [ X | O ]: ");
        scanf(" %c", &token);

        if (token == 'x' || token == 'o' ) token -= 32;
        if (position < 1 || position > 9 || (token != 'X' && token != 'O')) 
        { 
            char answer;
            printf("Would you like to quit?[Y|N]");
            scanf(" %c",&answer);
            if (answer == 'y') answer -= 32;
            if (answer == 'Y') {
                exit(0);
            } else {
                continue;
            }
        }
        system("clear");
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
                printf("default\n");
                break;
            } 
        if (count == 9)
        {
            scanf(" %c",token);
        }
        
    }

}

int main(void)
{
    char playground[maxheight][maxwidth] = {0};
    char X[tokenheight][tokenwidth] = {0}, O[tokenheight][tokenwidth] = {0};
    char x_file[6] = "X.txt", o_file[6] = "O.txt";
    int filled_area[9] = {0};

    display_banner();

    printf("\nPress any key to start...\n");

    if (getchar()) {
        system("clear");
    }

    init_playground(playground);

    
    init_token(X, x_file);
    init_token(O, o_file);

    play(playground, X, O, filled_area); 

    return 0;
}