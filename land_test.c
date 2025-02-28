#include <stdio.h>
#include <stdlib.h>

void floodfill_util(int m, int n, char **map, int i, int j)
{
    //if out of map's boundary or is water do nothing
    if (i < 0 || j < 0 || i == m || j == n || map[i][j] == '-')
        return ;
    //if it's land look for its up down left and right
    if(map[i][j] == 'x')
    {
        //change it to water too
        map[i][j] = '-';
        floodfill_util(m, n, map, i+1, j);
        floodfill_util(m, n, map, i-1, j);
        floodfill_util(m, n, map, i, j+1);
        floodfill_util(m, n, map, i, j-1);
    }
    //this will do recursive to change the founded island to water
    //so we can count all the island appear on the map
}

void floodfill(int m, int n, char **map, int i, int j)
{
    //using floodfill algorithm
    //look on the up down left and right
    floodfill_util(m, n, map, i+1, j);
    floodfill_util(m, n, map, i-1, j);
    floodfill_util(m, n, map, i, j+1);
    floodfill_util(m, n, map, i, j-1);
}
void printMap(int m, int n,char **map)
{
    //print map to check
    int i=0,j;
    while(i < m)
    {
        j=0;
        while (j<n)
        {
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}

int countIsland(int m, int n, char **map)
{
    int res = 0;
    int i,j;
    
    i=0;
    while(i < m)
    {
        j=0;
        while (j<n)
        {
            //if found x send to change the founded island to water 
            //and plus the counter by 1
            if (map[i][j] == 'x')
            {
                floodfill(m, n, map, i, j);
                //printMap(m, n,map);
                res++;
            }
            j++;
        }
        i++;
    }
    return(res);
}

int main()
{
    int m, n;
    printf("m : "); 
    scanf("%d", &m); 
    printf("n : "); 
    scanf("%d", &n);
    //after get the dimension of map, allocate the memory of map size
    //select pointer because the map can be edit through the function 
    //witout return the map argument
    char **map = (char **)malloc(sizeof(char *) * (m + 1));
    map[m] = NULL;
    int i,j;
    
    i=0;
    while(i < m)
    {
        //allocate inside array
        map[i] = (char *)malloc(sizeof(char) * (n + 1));
        map[i][n] = '\0';
        scanf("%s",map[i]);
        i++;
    }
    int ans = countIsland(m, n, map);
    printf("no. of island : %d", ans);
    i=0;
    while(i < m)
    {
        //free the memory inside
        free(map[i]);
        i++;
    }
    //and free the array
    free(map);
    return 0;
}