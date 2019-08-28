#include <stdio.h>
#include <math.h>

int main(void){
        int hrs, mins;
        float t, T;
        printf("Enter hours and minutes since power failure: ");
        scanf("%d", &hrs);
        scanf("%d", &mins);

        t = (float) hrs + ( (float) mins / 60.0);
        T = ( (4 * pow (t, 10.0)) / ( pow (t, 9.0) + 2.0) ) - 20.0;

        printf("Temperature in freezer = %.2f\n", T);

        return 0;
}

