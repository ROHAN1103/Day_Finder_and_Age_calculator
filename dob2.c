#include <stdio.h>
#include <stdlib.h>
int calculateage(int y1, int m1, int d1, int y, int m, int d)
{
    int a, b, c;
    if (y1 > y)
    {
        printf("\nERROR ! information");
    }
    if (y == y1 && m1 > m)
    {
        printf("\nERROR! information");
    }
    if (y == y1 && m1 == m && d1 > d)
    {
        printf("\nERROR! information");
    }
    else
    {
         a= y - y1;
        b = m - m1;
        c = d - d1;
        if (b < 0)
        {
            a = a - 1;
            b = b + 12;
        }
        if (c < 0)
        {
            b = b - 1;
            if (b < 0)
            {
                a = a - 1;
                if (a < 0)
                {
                    printf("\nERROR! information");
                }
                b = b + 12;
            }
            if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
            {
                c = c + 31;
            }
            else if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)
            {
                c = c + 30;
            }
            else if (m1 == 2 && y1 % 4 == 0)
            {
                c = c + 29;
            }
            else if (m1 == 2 && y1 % 4 != 0)
            {
                c = c + 28;
            }

        }
        printf("\n\n#####################################################");
        printf("\n\nCalculated Age is %d years %d months and %d days", a, b, c);
        printf("\n\n#####################################################");
    }
}

int leapcheck(int d, int m, int y)
{
    if (y % 4 == 0)
    {
        if (m == 2)
        {
            if (d > 29)
            {
                printf("Feburary contains only 29 days as it is a leap year!!");
                exit(0);
            }
        }
    }
    else if (m==2 && d > 28)
    {
        printf("Feburary contains only 28 days as it is not a leap year!!");
        exit(0);
    }
    if(m==1 || m==3 || m==5 || m==7 ||m==8 || m==10 ||m==12 )
    {
           if(d>31)
           {
             printf("This month dosen't contains date more than 31 days! Invalid date.");
            exit(0);
           }
        
    }
    if(m==4 || m==6 || m==9 || m==11 )
    {
            if(d>30)
            {
                printf("This month dosen't contains date more than 30 days! Invalid date.");
            exit(0);
            }
        
    }
}
int checkday(int day, int month, int year)
{
    int x, y, z, sum;
    x = year / 4;
    if (month == 1 || month == 10)
    {
        y = 0;
    }
    else if (month == 2 || month == 3 || month == 11)
    {
        y = 3;
    }
    else if (month == 4 || month == 7)
    {
        y = 6;
    }
    else if (month == 5)
    {
        y = 1;
    }
    else if (month == 6)
    {
        y = 4;
    }
    else if (month == 8)
    {
        y = 2;
    }
    else if (month == 9 || month == 12)
    {
        y = 5;
    }
    if (year % 4 == 0 && month < 3)
    {
        sum = year + x + y + day - 1;
        z = sum % 7;
    }
    else
    {
        sum = year + x + y + day;
        z = sum % 7;
    }
    if (z == 0)
        printf(" Friday");
    else if (z == 1)
        printf(" Saturday");
    else if (z == 2)
        printf(" Sunday");
    else if (z == 3)
        printf(" Monday");
    else if (z == 4)
        printf(" Tuesday");
    else if (z == 5)
        printf(" Wednesday");
    else if (z == 6)
        printf(" Thursday");
    else
        printf("Error!!!");
}
int main()
{
    int c, y, m, d, y1, m1, d1;

    printf("\n\n####################################################");
    printf("\n      WELLCOME TO AGE CALCULATOR AND DAY FINDER      ");
    printf("\n####################################################\n");
    printf("\nEnter the date from where you need to calculate age(D.O.B).........");
    printf("\nEnter the year :");
    scanf("%d", &y1);
    printf("\nEnter the Month(*In numbers) :");
    scanf("%d", &m1);
    printf("\nEnter the date :");
    scanf("%d", &d1);
    leapcheck(d1, m1, y1);
    printf("\n\n***********************************");
    printf("\nEnterd date is %d/%d/%d and day is : ",d1,m1,y1);
    checkday(d1, m1, y1);
    printf("\n***********************************");
    printf("\n\nDo you need to calculate the age from today?");
    printf("\n1.YES\t2.NO");
    printf("\nSelect your choice :");
    scanf("%d", &c);
    if (c == 2)
    {
        printf("\n\nEnter the date you wanted to calculate the age........");
        printf("\nEnter the year :");
        scanf("%d", &y);
        printf("\nEnter the Month(*In numbers) :");
        scanf("%d", &m);
        printf("\nEnter the date :");
        scanf("%d", &d);
        leapcheck(d, m, y);
        printf("\n\n***********************************");
        printf("\nEnterd date is %d/%d/%d and day is : ",d,m,y);
        checkday(d1, m1, y1);
        printf("\n***********************************");
    }
    else if (c == 1)
    {
        printf("\nTodays date is %s, But you need to enter the same ", __DATE__);
        printf("\n\nEnter the year :");
        scanf("%d", &y);
        printf("\nEnter the Month(*In numbers) :");
        scanf("%d", &m);
        printf("\nEnter the date :");
        scanf("%d", &d);
        leapcheck(d, m, y);
        printf("\n\n***********************************");
        printf("\nEnterd date is %d/%d/%d and day is : ",d,m,y);
        checkday(d, m, y);
        printf("\n***********************************");

    }
    else 
        {
            printf("Invalid Option!!!");
            return 0;
        }
    calculateage(y1, m1, d1, y, m, d);
}
