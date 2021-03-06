// main.cpp : Triangle main.
//

#include "stdafx.h"
#include "iostream"

int main()
{
	int triangleType{};

	// Prompt the user for the configuration type of a triangle to solve: AAA, AAS, ASA, SAS, SSA, SSS.
	std::cout << "Select a type of triangle to solve\n";
	std::cout << "1) AAA\n";
	std::cout << "2) AAS\n";
	std::cout << "3) ASA\n";
	std::cout << "4) SAS\n";
	std::cout << "5) SSA\n";
	std::cout << "6) SSS" << std::endl;
	std::cin >> triangleType;
	std::cout << std::endl;

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
			// Three Angles
			std::cout << "Selected AAA\n";
			std::cout << "Enter angles A and B in degrees:" << std::endl;
			std::cin >> angleA >> angleB;
			angleC = 180 - angleA - angleB;
			break;
		case 2:
			// Two Angles and a Side not between
			std::cout << "Selected AAS\n";
			std::cout << "Enter angleA, angleC and non-adjacent sideC" << std::endl;
			std::cin >> angleA >> angleC >> sideC;
			angleB = 180.0 - angleA - angleC;
			sideA = (sideC * sin(angleA * pi / 180.0)) / sin(angleC * pi / 180.0);
			sideB = (sideC * sin(angleB * pi / 180.0)) / sin(angleC * pi / 180.0);
			break;
		case 3:
			// Two Angles and a Side between
			std::cout << "Selected ASA\n";
			std::cout << "Enter angleA, angleB, and sideC (side between angles A and B)" << std::endl;
			std::cin >> angleA >> angleB >> sideC;
			angleC = 180.0 - angleA - angleB;
			sideA = (sideC / sin(angleC * pi / 180.0)) * sin(angleA * pi / 180.0);
			sideB = (sideC / sin(angleC * pi / 180.0)) * sin(angleB * pi / 180.0);
			break;
		case 4:
			// Two Sides and an Angle between
			std::cout << "Selected SAS\n";
			std::cout << "Enter sideB, sideC, and angleA (angle between sides B and C)" << std::endl;
			std::cin >> sideB >> sideC >> angleA;
			sideA = sqrt((sideB * sideB) + (sideC * sideC) - 2 * sideB * sideC * cos(angleA * pi / 180.0));
			// chose the smaller side, and therefore the smaller angle
			if (sideB < sideC)
			{
				angleB = asin((sin(angleA * pi / 180.0) * sideB) / sideA) * 180.0 / pi;
				angleC = 180.0 - angleA - angleB;
			}
			else
			{
				angleC = asin((sin(angleA * pi / 180.0) * sideC) / sideA) * 180.0 / pi;
				angleB = 180.0 - angleA - angleC;
			}
			break;
		case 5:
			// Two Sides and an Angle not between
			std::cout << "Selected SSA\n";
			std::cout << "Enter sideB, sideC, and angleB (angle not between sides B and C)" << std::endl;
			std::cin >> sideB >> sideC >> angleB;
			angleC = asin((sideC * sin(angleB * pi / 180.0)) / sideB) * 180.0 / pi;
			angleA = 180.0 - angleB - angleC;
			sideA = (sin(angleA * pi / 180.0) * sideB) / sin(angleB * pi / 180.0);
			break;
		case 6:
			// Three Sides
			std::cout << "Selected SSS\n";
			std::cout << "Enter sideA, sideB, and sideC" << std::endl;
			std::cin >> sideA >> sideB >> sideC;
			angleA = acos(((sideB * sideB) + (sideC * sideC) - (sideA * sideA)) / (2 * sideB * sideC)) * 180.0 / pi;
			angleB = acos(((sideC * sideC) + (sideA * sideA) - (sideB * sideB)) / (2 * sideC * sideA)) * 180.0 / pi;
			angleC = 180.0 - angleA - angleB;
			break;
		default:
			std::cout << "Invalid Selection" << std::endl;
			return 1;
	}

	std::cout << "\n";
	std::cout << "Angle A = " << angleA << "\n";
	std::cout << "Angle B = " << angleB << "\n";
	std::cout << "Angle C = " << angleC << "\n";
	std::cout << " Side A = " << sideA << "\n";
	std::cout << " Side B = " << sideB << "\n";
	std::cout << " Side C = " << sideC << "\n" << std::endl;

	// if any of the angles are less than or equal to 0, or if the angles do not add up to 180, say that it is unsolvable
	if (angleA <= 0 || angleB <= 0 || angleC <= 0 || sideA <= 0 || sideB <= 0 || sideC <= 0 || (angleA + angleB + angleC) != 180.0)
	{
		std::cout << "Unsolvable" << std::endl;
	}

    return 0;
}

