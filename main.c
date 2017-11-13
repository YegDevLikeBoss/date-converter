#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char c[10], ex[10]="exitprogra";

void error(int u);
void arrio();

int main(int argc, char *argv[])
{
    if (argc!=1)
        error(0);
    int init=0;
    while(init==0) /*Initialization loop*/
    {
        int day=0, month=0, year=0, max=0, vis=0, m_code=0, y_code=0, temp=0, aaa=0, y_temp=0, result;

        printf(">>> ");
        arrio(); /*Input*/

        if (!strcmp(c, ex)) /*Exit handling*/
        {
            init=1;
            continue;
        } else
        {
            if(c[0]<='9'&&c[0]>='0'&&c[1]<='9'&&c[1]>='0'&&c[3]<='9'&&c[3]>='0'&&c[4]<='9'&&c[4]>='0'&&c[6]<='9'&&c[6]>='0'&&c[7]<='9'&&c[7]>='0'&&c[8]<='9'&&c[8]>='0'&&c[9]<='9'&&c[9]>='0'&&c[2]=='.'&&c[5]=='.')
            {
                day=((c[0]-'0')*10)+(c[1]-'0');
                month=((c[3]-'0')*10)+(c[4]-'0');
                year=((c[6]-'0')*1000)+((c[7]-'0')*100)+((c[8]-'0')*10)+(c[9]-'0');
                aaa=((c[6]-'0')*10)+(c[7]-'0');
                switch (aaa)
                {
                    case 15:{ temp=0; break; }
                    case 16:{ temp=6; break; }
                    case 17:{ temp=4; break; }
                    case 18:{ temp=2; break; }
                    case 19:{ temp=0; break; }
                    case 20:{ temp=6; break; }
                    case 21:{ temp=4; break; }
                    case 22:{ temp=2; break; }
                    case 23:{ temp=0; break; }
                    case 24:{ temp=6; break; }
                    case 25:{ temp=4; break; }
                    case 26:{ temp=2; break; }
                    case 27:{ temp=0; break; }
                    case 28:{ temp=6; break; }
                    case 29:{ temp=4; break; }
                    case 30:{ temp=2; break; }
                }
                if (year%4==0) /*Leap year checking*/
                {
                    vis=1;
                    if (year%4==0&&year%100==0)
                    {
                        vis=0;
                        if (year%4==0&&year%100==0&&year%400==0)
                        {
                            vis=1;
                        }
                    }
                }
                y_temp=((c[8]-'0')*10)+(c[9]-'0'); /*Temporary operation for year code*/
                y_code=(temp+y_temp+(y_temp/4))%7; /*Year code*/
                if (month>0&&month<13)
                {
                    switch (month) /*Month checking*/
                    {
                        case 1: { m_code=1; max=31; break; }
                        case 2: { m_code=4; if(vis==1) max=29; else max=28; ;break; }
                        case 3: { m_code=4; max=31; break; }
                        case 4: { m_code=0; max=30; break; }
                        case 5: { m_code=2; max=31; break; }
                        case 6: { m_code=5; max=30; break; }
                        case 7: { m_code=0; max=31; break; }
                        case 8: { m_code=3; max=31; break; }
                        case 9: { m_code=6; max=30; break; }
                        case 10: { m_code=1; max=31; break; }
                        case 11: { m_code=4; max=30; break; }
                        case 12: { m_code=6; max=31; break; }
                    }
                } else
                {
                    error(2);
                    continue;
                }
                if (day>0&&day<=max)
                {
                    if (year>1582&&day<=31&&month<=12&&year<=3099)
                    {
                        result=(day+m_code+y_code)%7; /*Main formula*/
                        switch (result) /*Result to string translation*/
                        {
                            case 0:{ printf("Saturday\n"); break; }
                            case 1:{ printf("Sunday\n"); break; }
                            case 2:{ printf("Monday\n"); break; }
                            case 3:{ printf("Tuesday\n"); break; }
                            case 4:{ printf("Wednesday\n"); break; }
                            case 5:{ printf("Thursday\n"); break; }
                            case 6:{ printf("Friday\n"); break; }
                            default: break;
                        }
                    } else
                        error(4);
                } else
                    error(3);
            } else
            {
                if (c[0]=='\n')
                    continue;
                else
                    error(1); /*Incompatible input error handling*/
            }

            }

        }

    return 1;
}

void error(int u)
{
    switch (u)
    {
        case 0: { printf("***\nNOTE This programm does not support command line arguments\n***\n"); break; }
        case 1: { printf("***\nERROR Invalid input format.\nTry: DD.MM.YYYY\n***\n"); break; }
        case 2: { printf("***\nERROR Invalid month\n***\n"); break; }
        case 3: { printf("***\nERROR Invalid day\n***\n"); break; }
        case 4: { printf("***\nNOTE Support only for Georgian calendar from 01.01.1583 to 31.12.3099\n***\n"); break; }
    }
}

void arrio()
{
    int i=0, k=0;
    while(k==0)
    {
        c[i] = getchar();
        if (c[i]=='\n')
        {
            c[i]='\0';
            k=1;
        }
        i++;
    }
}
