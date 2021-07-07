#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019
*/

int main() {
    printf("pow(2, 10) = %f\n", pow(2, 10));
    printf("pow(2, 0.5) = %f\n", pow(2, 0.5));
    printf("pow(-2, -3) = %f\n", pow(-2, -3));

    printf("pow(-1, NAN) = %f\n", pow(-1, NAN));
    printf("pow(+1, NAN) = %f\n", pow(+1, NAN));
    printf("pow(INFINITY, 2) = %f\n", pow(INFINITY, 2));
    printf("pow(INFINITY, -1) = %f\n", pow(INFINITY, -1));
    // penanganan error
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("pow(-1, 1/3) = %f\n", pow(-1, 1.0 / 3));
    if (errno == EDOM) {
        perror("    errno == EDOM");
    }

    if (fetestexcept(FE_INVALID)) {
        puts("    FE_INVALID raised");
    }

    feclearexcept(FE_ALL_EXCEPT);
    printf("pow(-0, -3) = %f\n", pow(-0.0, -3));

    if (fetestexcept(FE_DIVBYZERO)) {
        puts("    FE_DIVBYZERO raised");
    }

    _getch();
    return 0;
}