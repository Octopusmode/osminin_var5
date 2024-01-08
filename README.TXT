/*

Program for solving cubic equations of the form

	a*x^3 + b*x^2 + c*x + d = 0

1.	Bring the equation into canonical form after dividing by 3:

	x^3 + r*x^2 + s*x + t = 0

	where:
	r = a / b, s = c / a, t = d / a

2.	Substitute x = y - r/3 in the equation to get the reduced equation:

	y3 + py + q = 0

	where:
	p = ( 3*s - r^2 ) / 3, q = ( (2*r^3) / 27 ) - ( (r*s) / 3 ) + t

3.	The number of real roots of the given equation depends on the sign of the discriminant

	D = ( p / 3 )^3 + ( q / 2 )^2

	Discr 	| Num of real roots | Num if complex roots
	D >= 0	| 1					| 2
	D < 0	| 3					| -

4.	If D >= 0, the roots of the above equation can be calculated
	using Cardano's formulas:
	y1 = u + v
	y2 = ( (-u + v) / 2 ) + ( ((u - v) / 2) * i * sqrt(3) )
	y3 = ( (-u + v) / 2 ) - ( ((u - v) / 2) * i * sqrt(3) )

	u = ( -q / 2 + sqrt(D) ) ** 1/3
	v = ( -q / 2 - sqrt(D) ) ** 1/3

	If D < 0, the equation has three real roots,
	but they will be calculated through auxiliary complex quantities.
	To get rid of this use the formulas:

	y1 = 2 * ( (p * cos(phy/3)) ** 1/3 )
	y2 = 2 * ( (p * cos(phy/3 + (2*pi/3))) ** 1/3 )
	y3 = 2 * ( (p * cos(phy/3 + (4*pi/3))) ** 1/3 )

	where:
	p = sqrt( -p^3/27 ), cos(phy) = -q / 2*pi

5.	After calculating the roots of the above equation, we need to use the formulas:

	xk = yk - ( r / 3), k = 1, 2, 3, ...

*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */