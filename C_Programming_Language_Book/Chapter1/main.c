#include <stdio.h>
#include <stdlib.h>
void HelloWorld();
void Fahr_Cel(int convert);
void print_header(int convert);
void simple_read_write();
void character_counting();
void count_lines();
void count_lines_tabs_blanks();
void multi_to_single_blanks();
void escape_the_escaped();

int main()
{
    escape_the_escaped();
    return 0;
}

void HelloWorld()
{
    printf("hello, world");
}

//0 = fahr to cel
//1 = cel to fahr
void Fahr_Cel(int convert)
{
    print_header(convert);
    float fahr, celsius;
    float lower,upper,step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    if(!convert){
        while(fahr <= upper)
        {
            celsius = 5*(fahr-32)/9;
            printf("%f\t%.2f\n",fahr, celsius);
            fahr = fahr + step;
        }
    }

    else
    {
        while(celsius <= upper)
        {
            fahr = (celsius*9/5)+32;
            printf("%f\t%.2f\n",celsius, fahr);
            celsius += step;
        }
    }
}

void print_header(int convert)
{
    if(!convert)
        printf("Fahrenheit\tCelsius\n");

    else
        printf("Celsius\tFahrenheit\n");
}

void simple_read_write()
{
    int c;

    c = getchar();
    while(c != EOF)
    {
        putchar(c);
        c=getchar();

    }
    if(c==EOF)
            printf("the end");

}

void character_counting()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n",nc);
}

void count_lines()
{
    int c, nl;

    nl=0;
    while ((c=getchar()) != EOF)
        if (c=='\n')
            ++nl;
    printf("%d\n",nl);
}

void count_lines_tabs_blanks()
{
    int line,tab,blank = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        if(c == '\t')
            ++tab;
        if(c==' ')
            ++blank;
        if(c=='\n')
            ++line;
    }
    printf("Tab:%d\nBlank:%d\nLine:%d\n",tab,blank,line);
}

void multi_to_single_blanks()
{
    int c;

    while((c=getchar()) != EOF)
    {
        if(c==' '){
            while(c == ' ')
                c = getchar();
            putchar(' ');
        }
        putchar(c);
    }
}

void escape_the_escaped()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        putchar(c);
    }
}
