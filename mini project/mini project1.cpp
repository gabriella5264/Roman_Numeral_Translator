// mini project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <control.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>

//prototype to convert roman number to decimal number//
int convert(char roman[10000], int i);

int main()
{
	char roman[10000];
	int i, sum = 0;

	printf("Enter roman number:");

	gets_s(roman);

	
		for (i = 0; roman[i] > 0; i++)//loop//
		{
			sum += convert(roman, i);//sum=sum+(roman[i] value)//
			
			//if the same roman number repeats 4 times(except M), print "Invalid Number"//
			if (convert(roman, i) == convert(roman, i + 1) && convert(roman, i + 1) == convert(roman, i + 2) && convert(roman, i + 2) == convert(roman, i + 3)&&convert(roman,i) != 1000)
			{
				printf("Invalid Number");
				return 1;
			}

			//if roman[i] is less than roman[i+1], -2*(roman[i] value) from sum//
			if (convert(roman, i) < convert(roman, i + 1))
			{
				sum -= (2 * convert(roman, i));
			}

			//if roman[i] value becomes \0, break//
			else if (roman[i] = '\0')
				break;
		}

		printf("\The decimal number is %d \t \n ",sum); //print sum//

		system("pause");
		return 0;
	}


//function to convert roman number to decimal number//
int convert(char roman[10000], int i)
{
	switch (roman[i])
	{
	case 'M': return 1000;
		break;
	case 'D': return 500;
		break;
	case 'C': return 100;
		break;
	case 'L': return 50;
		break;
	case 'X': return 10;
		break;
	case 'V': return 5;
		break;
	case 'I': return 1;
		break;
	case '\0': return 0;

	default: return '0';
		break;
	}
	return 0;
}