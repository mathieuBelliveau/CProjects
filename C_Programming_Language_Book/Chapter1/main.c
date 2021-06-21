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
void count_words();
void word_per_line();
void count_digits_white_others();
void print_horizontal_hist(int ndigit[10] , int nwhite, int nother);
void print_vertical_hist(int ndigit[10] , int nwhite, int nother);

int main()
{
    count_digits_white_others();
    return 0;
}

void HelloWorld()
{
    printf("hello, world");
}

void Fahr_Cel(int convert)
{
    //0 = fahr to cel
    //1 = cel to fahr
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
        else if(c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else if(c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
}

void count_words()
{
    int in = 1;
    int out = 0;

    int c, nl, nw, nc, state;

    state = out;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if(c=='\n')
            ++nl;
        if(c == ' ' || c =='\n' || c=='\t')
            state = out;
        else if (state == out)
        {
            state = in;
            ++nw;
        }

    }
    printf("%d %d %d\n",nl,nw,nc);
}

void word_per_line()
{
    //I don't consider this one done 1-12
    int c;

    while((c = getchar()) != EOF)
    {
        while((c = getchar()) == '\n' || c == ' ' || c == '\t')
        {
            putchar('\n');
        }
        putchar(c);
    }
}

void count_digits_white_others()
{
    //1.6 example
    int c,i,nwhite,nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i=0; i<10; ++i)
        ndigit[i] = 0;

    while ((c=getchar()) != EOF)
        if (c>='0' && c<='9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    print_horizontal_hist(&ndigit, nwhite, nother);
    print_vertical_hist(&ndigit, nwhite, nother);

    printf("\ndigits =");
    for (i = 0; i<10; ++i)
        printf(" %d", ndigit[i]);

    printf(", white space = %d, other = %d\n", nwhite, nother);
}

void print_horizontal_hist(int ndigit[10] , int nwhite, int nother)
{
    //Exercise 1-13 with parameters

    for(int i = 0; i<10; ++i)
    {
        printf("%d          :",i);
        for (int j = 0; j<ndigit[i]; ++j)
            printf("|");
        printf("\n");
    }

    printf("WhiteSpace :");
    for (int i = 0; i<nwhite; ++i)
        printf("|");
    printf("\n");

    printf("Other      :");
    for (int i = 0; i<nother; ++i)
        printf("|");
    printf("\n");

}

void print_vertical_hist(int ndigit[10] , int nwhite, int nother)
{
    //Exercise 1-13 with parameters with a twist (90 degrees to be exact)

    //12 values
    for (int i = 0; i < 12; ++i)
    {
        if(i<10)

    }
}
