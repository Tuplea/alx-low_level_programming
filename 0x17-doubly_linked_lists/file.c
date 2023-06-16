#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *reversed(char *str)
{
    int i = 0, j = (strlen(str) - 1);
    while (i < j)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++; j--;
    }
    return (str);
}
int main(void)
{
    int i, j, result, highest = 0;
    char num1[10], num2[10];
    for (i = 100; i < 1000; i++)
    {
        for (j = 100; j < 1000; j++)
        {
            result = j * i;
            sprintf(num1, "%d", result);
            sprintf(num2, "%d", result);
            if (strcmp(num1, reversed(num2)) == 0)
            {
                if (result > highest)
                    highest = result;
            }
        }
    }
    FILE *fp = fopen("102-result", "w");
    fprintf(fp, "%d", highest);
    fclose(fp);
}
