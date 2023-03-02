#include <stdio.h>

int main() {
    int x, y;
    int x1, y1;
    int k;
    scanf("%d", &  k);
    while (k != 0) {
        scanf("%d %d",&x1 , &y1);
        int i = 0;
        while (i < k) {
            scanf("%d %d", &x, &y);
            if (x == x1 && y != 0) {
                printf("divisa \n");
            } else if (x != 0 && y == y1) {
                printf("divisa \n");
            } else if (x < x1 && y > y1) {
                printf("NO \n");
            } else if (x < x1 && y < y1) {
                printf("SO \n");
            } else if (x > x1 && y > y1) {
                printf("NE \n");
            } else if (x > x1 && y < y1) {
                printf("SE \n");
            }
            i++;
        }
        scanf("%d", &k);

    }
}