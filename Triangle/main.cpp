// main.cpp : Triangle main.
//

#include "stdafx.h"
#include "iostream"

int main()
{
	int triangleType{};

	// Prompt the user for the configuration type of a triangle to solve: AAA, AAS, ASA, SAS, SSA, SSS.
	std::cout << "Select a type of triangle to solve" << std::endl;
	std::cout << "1) AAA\n";
	std::cout << "2) AAS\n";
	std::cout << "3) ASA\n";
	std::cout << "4) SAS\n";
	std::cout << "5) SSA\n";
	std::cout << "6) SSS\n";
	std::cin >> triangleType;

	const double pi{3.14159};
	double angleA{};
	double angleB{};
	double angleC{};
	double sideA{};
	double sideB{};
	double sideC{};

	switch (triangleType)
	{
		case 1:
			std::cout << "Selected AAA\n";
			std::cout << "Enter angles A and B in degrees:" << std::endl;
			std::cin >> angleA >> angleB;
			angleC = 180 - angleA - angleB;
			break;
		case 2:
			std::cout << "Selected AAS\n";
			std::cout << "Enter angleA, angleC and non-adjacent sideC" << std::endl;
			std::cin >> angleA >> angleC >> sideC;
			angleB = 180.0 - angleA - angleC;
			sideA = (sideC * sin(angleA * pi / 180.0)) / sin(angleC * pi / 180.0);
			sideB = (sideC * sin(angleB * pi / 180.0)) / sin(angleC * pi / 180.0);
			break;
		case 3:
			std::cout << "Selected ASA" << std::endl;
			break;
		case 4:
			std::cout << "Selected SAS" << std::endl;
			break;
		case 5:
			std::cout << "Selected SSA" << std::endl;
			break;
		case 6:
			std::cout << "Selected SSS" << std::endl;
			break;
		default:
			std::cout << "Invalid Selection" << std::endl;
			return 1;
	}
	std::cout << "\n";
	std::cout << "angleA = " << angleA << "\n";
	std::cout << "angleB = " << angleB << "\n";
	std::cout << "angleC = " << angleC << "\n";
	std::cout << " sideA = " << sideA << "\n";
	std::cout << " sideB = " << sideB << "\n";
	std::cout << " sideC = " << sideC << "\n" << std::endl;

	if (angleA <= 0 || angleB <= 0 || angleC <= 0 || sideA <= 0 || sideB <= 0 || sideC <= 0 || (angleA + angleB + angleC) != 180.0)
	{
		std::cout << "Unsolvable" << std::endl;
	}

	// Prompt the user to enter the values they know based upon their selection of triangle configuration.

	// Display all possible values for the triangle sides and angles.If the sides are only proportional(case AAA), note that in the answer.

	// All angles are to be in degrees(not radians).

	// If a solution is not possible, output "Unsolvable".

	// For AAA, you only need to prompt for 2 angles.Calculate the 3rd.

    return 0;
}

