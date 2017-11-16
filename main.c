#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char
c[10],
cmd[5]="cmnd",
ex[5]="exit",
hp[5]="help";

void error(int u);
void arrio();

int main(int argc, char *argv[])
{
    printf("\nHi there ;-)\nThis program is designed to calculate weekday using date\nLet's begin\nPlease read user manual carefully\n\nUSER MANUAL\n");
    error(6);
    error(5);
    error(6);
    if (argc!=1)
    {
        error(6); error(0); error(6);
    }
    int init=0;
    while(init==0) /*Initialization loop*/
    {
        int i, day=0, month=0, year=0, max=0, vis=0, m_code=0, y_code=0, temp=0, y_xx, y_temp=0, result;
        for (i=0;i<10;i++)
        {
            c[i]='\n';
            if (i<4)
                cmd[i]='\0';
        }
        printf("\t>>> ");
        arrio(); /*Input*/

        for (i=0;i<4;i++)
            cmd[i]=c[i];

        if ((!strcmp(cmd, hp))&&(c[4]=='\0')) /*Help handling*/
        {
            error(6); error(5); error(6);
        }

        if ((!strcmp(cmd, ex))&&(c[4]=='\0')) /*Exit handling*/
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
                y_xx=((c[6]-'0')*10)+(c[7]-'0');
                y_xx%=4;
                switch (y_xx)
                {
                    case 0:{ temp=6; break; }
                    case 1:{ temp=4; break; }
                    case 2:{ temp=2; break; }
                    case 3:{ temp=0; break; }
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
                    error(6);
                    error(2);
                    if (!(year>1582||(year==1582&&month>=10&&day>=15)))
                        error(4);
                    error(6);
                    continue;
                }
                if (day>0&&day<=max)
                {
                    if (year>1582||(year==1582&&month>=10&&day>=15))
                    {
                        result=(day+m_code+y_code)%7; /*Main formula*/
                        switch (result) /*Result to string translation*/
                        {
                            case 0:{ printf("\t it's Saturday\n"); break; }
                            case 1:{ printf("\t it's Sunday\n"); break; }
                            case 2:{ printf("\t it's Monday\n"); break; }
                            case 3:{ printf("\t it's Tuesday\n"); break; }
                            case 4:{ printf("\t it's Wednesday\n"); break; }
                            case 5:{ printf("\t it's Thursday\n"); break; }
                            case 6:{ printf("\t it's Friday\n"); break; }
                            default: break;
                        }
                    } else
                    {
                        error(6);
                        error(3);
                        if (!(year>1582||(year==1582&&month>=10&&day>=15)))
                            error(4);
                        error(6);
                    }
                } else
                {
                    error(6);
                    if (!(month>0&&month<13))
                        error(2);
                    error(4);
                    error(6);
                }
            } else
            {
                if ((c[0]=='h'&&c[1]=='e'&&c[2]=='l'&&c[3]=='p'&&c[4]=='\0'&&c[5]=='\n')||(c[0]=='\0'&&c[1]=='\n'&&c[2]=='\n'&&c[3]=='\n'&&c[4]=='\n'&&c[5]=='\n'&&c[6]=='\n'&&c[7]=='\n'&&c[8]=='\n'&&c[9]=='\n')) /*Incompatible input error handling*/
                    continue;
                else
                {
                    error(6); error(1); error(6);
                }
            }

            }

        }

    return 1;
}

void error(int u)
{
    switch (u)
    {
        case 0: { printf("NOTE\nThis program does not support command line arguments\n"); break; }
        case 1: { printf("ERROR\nInvalid input format.\nTry: DD.MM.YYYY\n"); break; }
        case 2: { printf("ERROR\nInvalid month\n"); break; }
        case 3: { printf("ERROR\nInvalid day\n"); break; }
        case 4: { printf("NOTE\nSupport only for Georgian calendar from 15.10.1582\n"); break; }
        case 5: { printf("HELP\n\nInput format:\n DD.MM.YYYY\n\nLegal commands:\n 'exit'\n 'help'\n\n"); error(4); break; }
        case 6: { printf("________\n"); break; }
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
