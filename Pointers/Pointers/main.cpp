#include <iostream>

void basicPointers() {
	std::cout << "Learn basic pointers in c++ with a+3" << std::endl;
	std::cout << "************************ \n" << std::endl;
	/***********************/

	std::cout << "Example 1" << std::endl;

	// With * we are going to get the value and with & we get the memory where the value is stored
	int myvar = 25;
	int* foo = &myvar;
	std::cout << "My value is " << myvar << " and its stored in the mem " << foo << std::endl;

	std::cout << "\n" << std::endl;
	/*******************/

	std::cout << "Example 2" << std::endl;

	// We declare two integers and a int pointer, both int will be 4byte each and the pointer 
	// will be the same size as the type where he is pointing (in this case 4 byte too)
	int ex2_A, ex2_B;
	int * mypointer = nullptr;

	// We are stroring the address of first value in mypointer which is a int pointer (this means, 
	// the OS knows that his value has 4 byte size and the next value is starting in the 5th mem position)
	mypointer = &ex2_A;
	// Storing the value into the memory where the pointer is pointing (:p), we had the mem position  of firstvalue
	// and we are storing in it the value 10
	*mypointer = 10;
	// Same with second value, but re-using mypointer variable
	mypointer = &ex2_B;
	*mypointer = 20;

	// As we can see, we are storing stuff inside values A and B, not in the pointers. 
	// Pointers are numbers refering to memory locations
	std::cout << "ex2_A is " << ex2_A << std::endl;
	std::cout << "ex2_B is " << ex2_B << std::endl;

	std::cout << "\n" << std::endl;
	/************************/

	std::cout << "Example 3" << std::endl;

	// Declared two integers with values and two int pointers (16 bytes in mem = 4 bytes * each int value)
	int ex3_A = 5, ex3_B = 15;
	int * p1 = nullptr, *p2 = nullptr;

	p1 = &ex3_A;		// p1 = address of ex3_A
	p2 = &ex3_B;		// p2 = address of ex3_B
	*p1 = 10;			// value pointed to by p1 = 10
	*p2 = *p1;			// value pointed to by p2 = value pointed to by p1
	p1 = p2;			// p1 = p2 (value of pointer is copied)
	*p1 = 20;			// value pointed to by p1 = 20

	std::cout << "ex3_A is " << ex3_A << std::endl;
	std::cout << "ex3_B is " << ex3_B << std::endl;

	std::cout << "\n" << std::endl;
	/************************/

	std::cout << "Example 4" << std::endl;

	// Declared an array of int with size of 5 (5 * 4 bytes = 20 bytes) and a int pointer ( 4bytes because its an int pointer)
	int numbers[5];
	int * p = nullptr;

	// Arrays are memory positions where we have stored multiple elements (they assure you that they are stored together, before each one)
	// so we dont need to use the & to get  the address because an array its already an address.
	p = numbers;

	// the actual address is pointing to the first direction from the array, so setting a 10 into his value will replace whatever that contains with a 10
	*p = 10;

	// We are increasing the pointer value, this will check the size of the pointer (int pointer = 4 byte) and move it to the next mem int value
	p++;

	// storing in the next mem section of the int pointer a 20
	*p = 20;

	// This is showing that we can substract the address from an specific array element, if we use numbers[2] we will get the content
	// but we are requesting the address where the [2] element is pointing (this element is something we dont know or null)
	p = &numbers[2];

	// store 30 in there
	*p = 30;

	// This is showing another way of dealing with arrays, we can easily increase 3 positions of the first position address of our array
	// this means that: number is the first address of our int array ( f.e: 100 ) and we are jumping 3 values ahead of that position
	// and because we are using an int array, this means that we will check the 4 * 3 mem next to the first, the 112 mem position to get the address
	p = numbers + 3;

	// store a 40 there
	*p = 40;

	// We are setting the pointer to the first element in the array
	p = numbers;

	// we are increasing the array mem location by 16 (4 times a int(remember 4 bytes)) and asking to put a 50 in the value
	*(p + 4) = 50;

	// print this magic
	for (int n = 0; n < 5; n++) {
		std::cout << numbers[n] << std::endl;
	}
}

void advancedPointers() {
	char mycharE = 'a';
	short myshortE = 1;
	long mylongE = 10;

	// As we already know, char have 1 byte of memory, short 2 bytes and long 4
	char *mychar = &mycharE;
	short *myshort = &myshortE;
	long *mylong = &mylongE;

	// If we request the next element in memory for those elements we will search into the next mem address for char, the 2nd mem address for short and 4th for long
	// And we also can say that this
	++mychar;
	++myshort;
	++mylong;
	// Is exaclty the same as this
	mychar = mychar + 1;
	myshort = myshort + 1;
	mylong = mylong + 1;
	// Because both are trying to access the next mem address next to our type refered (1byte char, 2byte short, 4byte long)

	// Also, we can get the pointer address and then request to ponint to the next mem value (using the increment operator ++ post numbers (asking for increasing the address mem for the type of pointer))
	mychar++;
	myshort++;
	mylong++;
	// or we can increase the mem address and then get that doing first the incremental operator and then the variable)
	++mychar;
	++myshort;
	++mylong;

	/***********************/

	std::cout << "Example 1 Advanced" << std::endl;

	// operator precedence rules

	// For this example we will deal with an array of chars (remember, each char 1 byte)
	char strE_1[] = "hello";
	char* ptrE_1 = strE_1;

	// As we can see here, the ptr is pointing to the first address mem where the h is located and accesing the value
	std::cout << *ptrE_1 << std::endl;

	std::cout << "\n" << std::endl;
	/*******************/

	std::cout << "Example 2 Advanced" << std::endl;
	char strE_2[] = "hello";
	char* ptrE_2 = strE_2;

	// We can see that if we use the increment operator as a suffix, we will move the pointer to the next char location (1 byte to the right)
	// but we wont see that until we ask for its content
	std::cout << *ptrE_2++ << std::endl;
	std::cout << *ptrE_2 << std::endl;

	// The incremental and decremental operators could be a prefix or a suffix, being a prefix will use the next value in the current operation
	// meanwhile in the suffix will prepare the next value in memory for the next operation

	std::cout << std::endl;

	// reset the pointer to the first address because in the previous example we incremented it
	ptrE_2 = strE_2;

	// As you can see, now we are using the incremental as a suffix, and it have priority over the dereference to the pointer
	// so it will increase the address to the next char value and then acces its memory
	std::cout << *++ptrE_2 << std::endl;
	// Now we will get the same result because the incremental is a prefix
	std::cout << *ptrE_2 << std::endl;

	std::cout << "\n" << std::endl;
	/*******************/

	std::cout << "Example 3 Advanced" << std::endl;
	char strE_3[] = "hello";
	char* ptrE_3 = strE_3;
	// Operator priorities

	// Try and guess what this examples do
	// A
	std::cout << *ptrE_3++ << std::endl;
	ptrE_3 = strE_3;
	// B
	std::cout << *++ptrE_3 << std::endl;
	ptrE_3 = strE_3;
	// C
	std::cout << ++*ptrE_3 << std::endl;
	ptrE_3 = strE_3;
	// D
	std::cout << (*ptrE_3)++ << std::endl;
	   
	// SOLUTION
	// A - Will access to ptrE address and access de value, then increase the pointer address to the next one. Value is h
	// B - Will increase the ptrE address and get the value. Value is e
	// C - Will get the value of ptrE and then increase its value (its a char, so it will print the 4th next ascii element after the e, that is i letter)
	// D - Same as C

	std::cout << "\n" << std::endl;

}

// Template example
template <class T>
class Vector3 {
	T x, y, z;
	public:
		Vector3() {};
		Vector3(T a, T b, T c) {
			x = a;
			y = b;
			z = c;
		};
		Vector3(const Vector3<T>& a) { 
			x = a.x;
			y = a.y;
			z = a.z;
		};
		Vector3<float> normalize();
		float distance_to(const Vector3<T>& a);
		void printVector();
		Vector3<T> operator+(const Vector3<T>& a);
};

template <class T>
Vector3<float> Vector3<T>::normalize() {
	float vecLen = sqrt((x * x) + (y * y) + (z * z));
	return Vector3<float>(x / vecLen, y / vecLen, z / vecLen);
}

template <class T>
inline float Vector3<T>::distance_to(const Vector3<T>& toVec3) {
	return sqrt(pow(x - toVec3.x, 2) + pow(y - toVec3.y, 2) + pow(z - toVec3.z, 2));
}

template <class T>
void Vector3<T>::printVector() {
	std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
}

template <class T>
inline Vector3<T> Vector3<T>::operator+(const Vector3<T>& a) {
	return Vector3<T>(x + a.x, y + a.y, z + a.z);
}


void vector3Exercise() {
	// a()
	Vector3<int> vecA();
	// b(1,0,1)
	Vector3<int> vecB(1,0,1);
	// c(b)
	Vector3<int> vecC(vecB);
	// d = b + c
	Vector3<int> vecD = vecB + vecC;
	// d.normalize()
	Vector3<float> normVecD = vecD.normalize();
	// d.distance_to(b)
	float distToVecB = vecD.distance_to(vecB);

	std::cout << "Vec B" << std::endl;
	vecB.printVector();
	std::cout << "Vec C" << std::endl;
	vecC.printVector();
	std::cout << "Vec D" << std::endl;
	vecD.printVector();
	
	std::cout << "Distance between vectors is " << distToVecB << std::endl;
	std::cout << "Vector A normalized is " << std::endl;
	normVecD.printVector();

}

int main() {

	// basicPointers();
	// advancedPointers();
	vector3Exercise();

	std::cout << "Press Enter to exit" << std::endl;
	getchar();
	return 0;
}