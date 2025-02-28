#include <stdio.h>
#include <stdlib.h>

void floodfill_util(int m, int n, char **map, int i, int j)
{
    if (i < 0 || j < 0 || i == m || j == n || map[i][j] == '-')
        return ;
    if(map[i][j] == 'x')
    {
        map[i][j] = '-';
        floodfill_util(m, n, map, i+1, j);
        floodfill_util(m, n, map, i-1, j);
        floodfill_util(m, n, map, i, j+1);
        floodfill_util(m, n, map, i, j-1);
    }
    
}

void floodfill(int m, int n, char **map, int i, int j)
{
    floodfill_util(m, n, map, i+1, j);
    floodfill_util(m, n, map, i-1, j);
    floodfill_util(m, n, map, i, j+1);
    floodfill_util(m, n, map, i, j-1);
}
void printMap(int m, int n,char **map)
{
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
    char **map = (char **)malloc(sizeof(char *) * (m + 1));
    map[m] = NULL;
    int i,j;
    
    i=0;
    while(i < m)
    {
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
        free(map[i]);
        i++;
    }
    free(map);
    return 0;
}