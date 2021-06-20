#include <stdio.h>
#include <stdlib.h>
void HelloWorld();
void Fahr_Cel(int convert);
void print_header(int convert);
void simple_read_write();

int main()
{

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
{    if(!convert)
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

}

