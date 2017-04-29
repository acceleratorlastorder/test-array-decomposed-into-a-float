#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tmp;
char test[40] ="";
char yolo[37] ="";
float testultime = 0.8415616717171971;
char trash;
int i = 0;
int lel;
float arf = 0;
int s=0;
int j=0;
int *pointer = NULL;
char buffer[8]= "";
float roll, pitch, yaw, throttle;
//[0.51374,0.498054,0.501976,0.000015]\0  the array to parse
int main()
{

    pointer = &yolo;
    while(1)
    {
        printf("Hello world!\n");
        scanf("%s", yolo);
        if(yolo == "fin\\0")
        {
            printf("you entered fin bye then :)\n");
            return 0;
        }
        else
        {
            printf("you entered %s and the length is %d\n", yolo,(unsigned)strlen(yolo));
            rxmanager(yolo);
        }
    }


    return 0;
}

void rxmanager(const char* essai)
{
    j=0;
    s=0;
    for (i=0; i<(unsigned)strlen(essai); i++)
    {
        printf("into the function\n");
        tmp = essai[i];
        printf("tmp = %c iteration number %d\n",tmp, i);
        if(tmp == ']' || tmp == '[' || tmp == '\0')
        {
            printf("] or [ or \\0 found\n");
            trash = essai[i];
            printf("trash = %c\n", trash);
        }
        else
        {
            printf("essai at index %d = %c\n", i, essai[i]);
            if(tmp==',')
            {
                printf(", found \n");
                printf("j before reset = %d\n", j);
                j=0;
                printf("j after reset= %d\n", j);
                if (s == 0)
                {
                    printf("asign the value %s to roll \n", buffer);
                    roll = atof(buffer);
                    printf("roll is now %f\n", roll);
                }
                else if  (s == 1)
                {
                    printf("asign the value %s to pitch \n", buffer);
                    pitch = atof(buffer);
                    printf("pitch is now %f\n", pitch);
                }
                else if  (s == 2)
                {
                    printf("asign the value %s to yaw \n", buffer);
                    yaw = atof(buffer);
                    printf("yaw is now %f\n", yaw);

                }
                printf("buffer before clean = %s\n", buffer);
                for(int k=0; k<8; k++)
                {
                    buffer[k]=0;
                }
                printf("buffer after clean = %s\n", buffer);
                s++;
            }
            else
            {
                buffer[j] = tmp;
                printf("buffer = %s\n", buffer);

                printf("increment before next loop i = %d\n", i);
                j++;
                if (s==3)
                {
                    printf("asign the value %s to throttle \n", buffer);
                    throttle = atof(buffer);
                    printf("throttle is now %f\n", throttle);

                }
            }
        }
        printf("s after reset= %d\n", s);
    }
    printf("end of the function the array we've got was %s and here's what we got from: \n roll= %f ,pitch= %f , yaw= %f, throttle= %f \n",essai,roll, pitch, yaw, throttle);
    return;
}
