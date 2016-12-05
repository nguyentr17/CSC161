
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contain_newline (char * text);
void block_encrypt (int width, int height, char * message_block);

int main ()
{
    /* Declaring input variables */
    char * input;
    int height, width;
    /* Asking for height and width of the encrypting box */
    printf("Enter your encrypting rectangular size (height and width respectively and separated by space): ");
    scanf("%d %d", &height, &width);
    printf("\n");
    while(getchar()!= '\n'); // clearing out the old line and reading the next input from the next line
    
    printf("Enter text: ");
    int block_length = height*width;
    /* The program will read and process each box at one time 
     * and continue until a block contains a newline character */
    do
    {
        fgets(input, (block_length + 1) , stdin); // plus 1 for NULL character
        block_encrypt(width, height, input);
    } while (contain_newline(input) == 0);
    
    /* Closing the program */
    printf("\nThe program ended \n");
    return 0;
}

/* This function checks whether a text contains a newline character. 
 * This will serve as a condition to stop reading input on the terminal */
int contain_newline (char * text)
{
    int i = 0;
    int yes = 0;
    do
    {
        if (text[i] == '\n')
            yes = 1;
        i++;
    } while (i < strlen(text) && yes == 0);
    return yes;
}

/* This function processes a message block read from the terminal and
 * prints out the encrypted message.
 * Method: Putting the message block in a 2D array and reads it vertically */
void block_encrypt (int width, int height, char * message_block)
{
    
    // If the message-block contains a newline character, the program will not take that character into account
    int real_length;
    if (contain_newline(message_block))
        real_length = (int) strlen(message_block)-1;
    else
        real_length = (int) strlen(message_block);
    
    if (real_length > 0) // if the message block starts with newline, this procedure will do nothing
    {
        // Putting the message_block into a rectangular of specified size
        char rec [height][width];
        for (int row = 0; row < height; row++)
            for (int col = 0; col < width; col++)
            {
                if ((row*width+col) < real_length)
                    rec[row][col] = message_block[(row*width+col)];
                else
                    rec[row][col] = 'a' + row*width + col - real_length;
            }
        // Printing the encrypted message block
        for (int i = 0; i < width; i++)
            for (int j = 0; j < height; j++)
                printf("%c",rec[j][i]);
    }
}





