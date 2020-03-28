#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
    {
        printf("Tell me the dir you fucker!\n");
        exit(1);
    }
    if ((dp = opendir(argv[1])) == NULL)
    {
        printf("cannot open directory that you  wish to open! - %s\n", strerror(errno));
        exit(1);
    }

    while ((dirp = readdir(dp)) != NULL)
        printf("%s \n", dirp->d_name);

        closedir(dp);
    return 0;
}