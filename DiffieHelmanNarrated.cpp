// ===============================================================
// Programmer: Alejandro Sanchez
// Course: CPSC353
// Instructor: Kung
// Assignment: Project 2 - Diffie-Hellman Key Exchange
// Desc: This program demostrates the Diffie-Hellman Key Exchange 
//		Algorithm in a simplified, and narrated form. It will use 
//		values of 0 < p < 100; and values of 0 < x < 10 and 
//		0 < y < 10.  
// ============================================================== 

#include <iostream>
#include <math.h> // pow()

using namespace std;
int main()
{
	int p, g, x, y, X, Y, k1, k2;
	unsigned long long int Yx, Xy, gx, gy;

	p = 19; // prime modulus
	g = 3; // generator
	x = 9; // Alice's secret number
	y = 6; // Bob's secret number

	gx = static_cast<int>(pow(static_cast<double>(g), x)); //Alice's g^x
	X = gx % p; // Alice's First computation 
	
	gy = static_cast<int>(pow(static_cast<double>(g), y)); //Bob's g^y
	Y = gy % p;// Bob's first computation

	Yx = static_cast<int>(pow(static_cast<double>(Y), x)); // Alice's Y^x
	k1 = Yx % p; // Alice's secret key

	Xy = static_cast<int>(pow(static_cast<double>(X), y)); // Bob's X^y
	k2 = Xy % p; // Bob's secret key

	cout << "**DIFFIE-HELLMAN KEY GENERATION**\n\n";
	cout << "FOR BOTH ALICE AND BOB:\n";
	cout << "They select the same prime number, p, and generator, g.\n";
	cout << "They decide: p = "<< p<<" and g = " << g<<".\n";

	cout << "\nAlice selects her private number, x = " << x << "\n";
	
	cout << "Alice caluclates X which is g^x mod p\n";
	cout << "In this case: " << g << "^" << x << ", mod " << p << endl;
	cout << "g^x = " << gx << endl;
	cout << "Alice's X value is: " << X << endl;
	cout << "Alice sends X to Bob.\n";

	cout << "\nMeanwhile, on the other side of the office building. . . \n\n";
	
	cout << "Bob selects his private number, y = " << y<<"\n";
	
	cout << "Bob caluclates Y which is g^y mod p\n";
	cout << "In this case: "<< g << "^"<<  y << " mod " <<p<<"\n";

	cout << "g^y = " << gy << endl;

	cout << "Bob's Y value is: " << Y << endl;
	cout << "Bob sends Y back to Alice.\n";

	cout << "\nNow Alice and Bob compute their respective secret keys. . .";

	cout << "\n\nALICE'S COMPUTATION\n";
	cout << "Alice computes her secret key as K1 = Y ^ x mod p\n";
	cout << "Or in this case, " << Y << " ^ "<<x <<" mod "<<p << "\n";

	cout << "Alice's secret key is " << k1 << endl << endl;

	cout << "\n\BOB'S COMPUTATION\n";
	cout << "Bob computes his secret key as K2 = X ^ y mod p\n";
	cout << "Or in this case, " << X << " ^ " << y << " mod " << p << "\n";
	
	cout << "Bob's secret key is " << k2 << endl<<endl;

	if (k1 == k2)
		cout << "Alice and Bob's keys match!\n\n";
	else
	cout << "Alice and Bob's keys do not match.\n\n";
} // end of main()
/* OUTPUT

**DIFFIE-HELLMAN KEY GENERATION**

FOR BOTH ALICE AND BOB:
They select the same prime number, p, and generator, g.
They decide: p = 19 and g = 3.

Alice selects her private number, x = 9
Alice caluclates X which is g^x mod p
In this case: 3^9, mod 19
g^x = 19683
Alice's X value is: 18
Alice sends X to Bob.

Meanwhile, on the other side of the office building. . .

Bob selects his private number, y = 6
Bob caluclates Y which is g^y mod p
In this case: 3^6 mod 19
g^y = 729
Bob's Y value is: 7
Bob sends Y back to Alice.

Now Alice and Bob compute their respective secret keys. . .

ALICE'S COMPUTATION
Alice computes her secret key as K1 = Y ^ x mod p
Or in this case, 7 ^ 9 mod 19
Alice's secret key is 1


BOB'S COMPUTATION
Bob computes his secret key as K2 = X ^ y mod p
Or in this case, 18 ^ 6 mod 19
Bob's secret key is 1

Alice and Bob's keys match!

Press any key to continue . . .

*/
// ======================== END OF PROJECT 2 ===================== //