#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result =(char**) malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}
bool is_ip_valid(char* ip )
{
    char** tokens;
    tokens = str_split(ip, '.');
    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            printf("%d\n",atoi(*(tokens + i) ));

            if(0 >atoi(*(tokens + i) )    || atoi(*(tokens + i) )>255){
                return false;
            }
            printf("range =[%s]\n", *(tokens + i));
            free(*(tokens + i));
        }
        if (i>3)
        {
           return false;
        }
        printf("\n");
        free(tokens);
    }
    return true;
}

int main()
{

    char ip[] = "222.168.1.-1";
    printf("ip=[%s]\n\n", ip);
    printf("%d\n",is_ip_valid(ip));

}
