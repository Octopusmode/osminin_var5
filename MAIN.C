#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>

double getDoubleInput(const char *argName, int checkNonZero)
{
	double value;
	int result;
	char str[DBL_MAX_10_EXP + 1];

	do
	{
		printf("Input value for %s: ", argName);
		if (fgets(str, sizeof(str), stdin) != NULL)
		{
			result = sscanf(str, "%lf", &value);
		}
		else
		{
			result = 0;
		}

		if (result != 1)
		{
			printf("Invalid input. Please try again.\n");
		}
		else if (checkNonZero && value == 0)
		{
			printf("Value cannot be zero. Please try again.\n");
			result = 0;
		}
	} while (result != 1);

	return value;
}

int main()
{
	double a, b, c, d;
	double r, s, t;
	double p, q;
	double D;
	double ro, phy;
	double x1, x2, x3;
	double u, v, h, g;

	clrscr();

	printf("Cubic equation solver\n");
	// Variables input with type check
	a = getDoubleInput("a", 1);
	b = getDoubleInput("b", 0);
	c = getDoubleInput("c", 0);
	d = getDoubleInput("d", 0);

	// Cannonical equation coeffs calculation
	r = b / a; s = c / a; t= d / a;
	// Reduced equation coeffs calculation
	p = (3 * s - r * r) / 3;
	q = 2 * r * r * r / 27 - r * s / 3 + t;
	// Discriminant calculation
	D = pow(p / 3, 3) + pow(q / 2, 2);

	clrscr();
	printf("Cubic equation results\n\n");
	// Output the equation with the fitted arguments
	printf("Equation: %.6g*x^3 + %.6g*x^2 + %.6g*x + %.6g = 0\n\n", a, b, c, d);
	// Output the discriminant
	printf("Discriminant: %.6g\n\n", D);
	// Output Q, R, S coefficients
	printf("Q = %.6g\t", q);
	printf("R = %.6g\t", r);
	printf("S = %.6g\n\n", s);

	if (D < 0)
	{
		// Equation has one real root and two complex roots
		double ro = sqrt(-p * p * p / 27);
		double phy = atan2(sqrt(-D), -q / 2);
		double cos_phy_3 = cos(phy / 3);
		double sin_phy_3 = sin(phy / 3);
		x1 = 2 * pow(ro, 1.0 / 3.0) * cos_phy_3 - b / (3 * a);
		x2 = 2 * pow(ro, 1.0 / 3.0) * (cos_phy_3 * cos(M_PI * 2 / 3) - sin_phy_3 * sin(M_PI * 2 / 3)) - b / (3 * a);
		x3 = 2 * pow(ro, 1.0 / 3.0) * (cos_phy_3 * cos(M_PI * 4 / 3) - sin_phy_3 * sin(M_PI * 4 / 3)) - b / (3 * a);

		// Result output
		printf("Roots:\n");
		printf("x1 = %.6g\n", x1);
		printf("x2 = %.6g + %.6g * i\n", x2, x3);
		printf("x3 = %.6g - %.6g * i\n", x2, x3);
	}
	else if (D == 0)
	{
		// Equation has two real roots
		double u, v;
		if (q >= 0) {
			u = -pow(q, 1.0 / 3.0);
		} else {
			u = pow(-q, 1.0 / 3.0);
		}
		v = -p / (3 * u);

		x1 = u + v - b / (3 * a);
		x2 = -(u + v) / 2 - b / (3 * a);

		// Result output
		printf("Roots:\n");
		printf("x1 = %.6g\n", x1);
		printf("x2 = %.6g\n", x2);
	}
	else
	{
		// Equation has three real roots
		double u, v;
		if (q >= 0) {
			u = -pow(q, 1.0 / 3.0);
		} else {
			u = pow(-q, 1.0 / 3.0);
		}
		v = -p / (3 * u);

		x1 = u + v - b / (3 * a);
		x2 = (-u - v / 2) - b / (3 * a);
		x3 = (-u + v / 2) - b / (3 * a);

		// Result output
		printf("Roots:\n");
		printf("x1 = %.6g\n", x1);
		printf("x2 = %.6g\n", x2);
		printf("x3 = %.6g\n", x3);
	}

	// Wait for user input to exit
	printf("\n\nPress any key to exit...");
	getchar();

	return 0;
}