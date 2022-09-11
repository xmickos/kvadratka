#include <stdio.h>
#include <math.h>
#include <mykvadratka.h>
#define epsilon 0.001
void inputstr(double* a, double* b, double* c){
     /*
    вывод нужного кол-ва символов через printf (не 1.00000 а 1.0)? 
    */
    int flag = 3;
    do{
        if(flag != 3) {
            printf("\nWrong input!\n");
            while(!getchar());
        }
        printf("\nInput the coefficients of quadratic equation, tap 'Enter' to end the input:\n");
        flag = scanf("%lf %lf %lf", a, b, c);
   }while(flag != 3);
   printf("a = %lf, b = %lf, c = %lf\n", *a, *b, *c);
}

double discrim(double a, double b, double c){

    return (b * b - (4.0 * a * c));
}

int compar(double a, double b){ // <=> верно ли что a отлично от b с точностью epsilon
    return(fabs(a - b) > epsilon);
}

void linear(double b, double c)
{
    if(compar(b, 0.0)){
        if(!compar(c, 0.0)){
        printf("The only one solution is x = %lf", 0);
        }
        else{
        printf("The only one solution is x = %lf", (-(c / b)));
        }
    }
    else{
        if(!compar(c, 0.0)){
            printf("Your equation has infinitely many solutions.\n");
        }
        else{
            printf("Your equation has no solution.\n");
        }
        return;
    };
}

void nonlinear(double a, double b, double c){
    double firstx = NAN, secondx = NAN, d = NAN;
        d = discrim(a, b, c);
        if(d >= 0.0){ // <=> d > 0.0
            firstx = (-b + sqrt(d))/(2 * a);  //случай b = 0.0 учтён
            secondx = (-b - sqrt(d))/(2 * a);
            if(compar(firstx, secondx)){ 
                printf("\nFirst solution is %lf, second solution is %lf", firstx, secondx);
            }
            else{        
                printf("The only one solution is x = %lf", firstx);
            }
            return;
        }
        else{
            printf("\nYour equation has no solution.\n");
            return;
        }
}

    // |0.1 - 0| > 0.001 -> 0.1 > 0.001 - true => 0.1 

void kvadratnoe(){
    double a = NAN, b = NAN, c = NAN;
    inputstr(&a, &b, &c);
    if(compar(a, 0.0)){          // <=> a != 0
        nonlinear(a, b, c);
    }
    else{
        linear(b, c);
        return;
    }
}

void outputstr(){       //? точно нужно? 
    
}
