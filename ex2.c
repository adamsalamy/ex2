/******************
Name:Adam Salamy
ID:322726068
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
    int choice;
    while (1) {
        printf("Choose an option:\n"
               "\t1. Happy Face\n"
               "\t2. Balanced Number\n"
               "\t3. Generous Number\n"
               "\t4. Circle Of Joy\n"
               "\t5. Happy Numbers\n"
               "\t6. Festival Of Laughter\n"
               "\t7. Exit\n");
        scanf("%d", &choice);

    //    while (choice != 7) {
            if (choice == 1) {
                char s1, s2, s3;// s _ symbol
                int FaceSize = 0;
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &s1, &s2, &s3);
                printf("Enter face size:\n");
                scanf("%d", &FaceSize);
                while (FaceSize % 2 == 0 || FaceSize <= 0) {
                    printf("The face's size must be an odd and positive number, please try again:\n");
                    scanf("%d", &FaceSize);
                }
                printf("%c", s1);
                for (int i = 0; i < FaceSize; ++i) {
                    printf(" ");
                }
                printf("%c\n", s1);
                for (int i = 0; i < FaceSize; ++i) {

                    printf(" ");
                    if (FaceSize == 1) {
                        break;
                    }
                    if (i == (FaceSize / 2)) {
                        break;
                    }
                }
                printf("%c\n", s2);
                printf("\\");
                for (int i = 0; i < FaceSize; ++i) {
                    printf("%c", s3);
                }
                printf("/\n");

            } else if (choice == 2) {
                int number;
                printf("Enter a number:\n");
                scanf("%d", &number);
                while (number < 1) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &number);
                }
                int temp = number;
                int length = 0;

                while (temp > 0)//finding the length of the number
                {
                    ++length;
                    temp /= 10;
                }
                if (length == 1)  // Single-digit numbers are balanced
                {
                    printf("This number is balanced and brings harmony!\n");
                }
                if (length != 1) {
                    temp = number;
                    int RightSide = 0;
                    int LeftSide = 0;
                    int HalfLength = length / 2;

                    // Skip the middle digit if the length is odd
                    if (length % 2 != 0) {
                        for (int i = 0; i < HalfLength; ++i) {
                            RightSide += temp % 10;
                            temp /= 10;
                        }
                        temp /= 10; // Skip the middle digit
                    } else {
                        for (int i = 0; i < HalfLength; ++i) {
                            RightSide += temp % 10;
                            temp /= 10;
                        }
                    }

                    // Calculate the left side
                    while (temp > 0) {
                        LeftSide += temp % 10;
                        temp /= 10;
                    }

                    if (LeftSide == RightSide) // Compare sums of both sides
                    {
                        printf("This number is balanced and brings harmony!\n");
                    } else {
                        printf("This number isn't balanced and destroys harmony.\n");
                    }
                }
            } else if (choice == 3) {

                int number = 0;
                printf("Enter a number:\n");
                scanf("%d", &number);
                while (number < 1) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &number);
                }

                int sum = 0;
                int flag = 1;
                for (int i = 2; i < ((number / 2) + 1); ++i) {
                    if (number % i == 0) {
                        sum += (number / i);
                    }
                    if (sum > number) {
                        flag = 0;
                        printf("This number is generous!\n");
                        break;
                    }
                }
                if (flag) {
                    printf("This number does not share.\n");
                }

            } else if (choice == 4) {
                int number = 0;
                int power = 1;
                printf("Enter a number:\n");
                scanf("%d", &number);
                // printf("df%d\n", number % 10);
                while (number < 1) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &number);
                }
                int temp = number;
                int temp2 = number;
                int length = 0;
                while (temp != 0)//finding the length of the number
                {
                    ++length;
                    temp = (temp / 10);
                    power = (power * 10);
                }

                int ReversedNumber = 0;
                power = power / 10;
                if (length > 1)// reversing the number
                {
                    for (int i = 0; i < length; ++i) {
                        ReversedNumber += (power * (temp2 % 10));
                        power = power / 10;
                        temp2 = (temp2 / 10);
                    }

                    int flag = 0;
                    for (int i = 2; i < (number / 2) + 1; ++i) {
                        if (number % i == 0)// if true then number is not prime
                        {
                            flag = 1;
                        }
                    }
                    int flag2 = 0;
                    for (int i = 2; i < (ReversedNumber / 2) + 1; ++i) {
                        if (ReversedNumber % i == 0)// if true then ReversedNumber is not prime
                        {
                            flag2 = 1;
                        }
                    }
                    if (flag || flag2) {
                        printf("The circle remains incomplete.\n");
                    } else {
                        printf("This number completes the circle of joy!\n");
                    }
                }
                if (length == 1 && number != 1) {
                    int flag = 0;
                    for (int i = 2; i < (number / 2) + 1; ++i) {
                        if (number % i == 0)// if true then number is not prime
                        {
                            flag = 1;
                        }
                    }
                    if (flag) {
                        printf("The circle remains incomplete.\n");
                    } else {
                        printf("This number completes the circle of joy!\n");
                    }
                }
                if (length == 1 && number == 1) {
                    printf("The circle remains incomplete.\n");
                }
            } else if (choice == 5) {

                int number;
                printf("Enter a number:\n");
                scanf("%d", &number);

                while (number < 1) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &number);
                }

                printf("Between 1 and %d only these numbers bring happiness: ", number);

                for (int i = 1; i <= number; ++i)// Loop through all numbers from 1 to the given number
                {
                    int current = i;
                    int flag = 0; // Flag to check if a cycle is found


                    while (current != 1)// Check if the number is happy
                    {
                        int sum = 0;


                        while (current > 0)    // Calculate the sum of the squares of digits
                        {
                            int digit = current % 10;
                            sum += digit * digit;
                            current /= 10;
                        }
                        current = sum;
                        if (current == 4)  // Stop if we reach a known unhappy number
                        {
                            flag = 1;
                            break;
                        }
                    }


                    if (!flag)// Print the number if it's happy
                    {
                        printf("%d ", i);
                    }
                }

                printf("\n");
            }
            else if (choice == 6) {
                int smile = 0;
                int cheer = 0;
                int MaxNumber = 0;
                int flag = 1;
                printf("Enter a smile and cheer number:\n");

                while (flag) {
                    int valid = scanf("smile: %d, cheer: %d", &smile, &cheer);
                    while (valid != 2 || smile < 1 || cheer < 1 || smile == cheer) {
                        printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                        scanf("%*[^\n]%*c");// cleaning input buffer
                        valid = scanf("smile: %d, cheer: %d", &smile, &cheer);
                    }
                    flag = 0;
                }
                printf("Enter maximum number for the festival:\n");

                while (1) {
                    int valid = scanf("%d", &MaxNumber);

                    if (valid != 1 || MaxNumber < 1) {
                        printf("Only positive maximum number is allowed, please try again:\n");

                        // Clear invalid input
                        scanf("%*[^\n]%*c");
                    } else {
                        break; // Valid input, exit the loop
                    }
                }

                for (int i = 1; i < MaxNumber + 1; ++i) {
                    if(i % smile == 0 && i % cheer == 0){
                        printf("Festival!\n");
                        continue;
                    }
                    if(i % smile == 0){
                        printf("Smile!\n");
                        continue;
                    }
                    if(i % cheer == 0){
                        printf("Cheer!\n");
                        continue;
                    }
                    printf("%d\n",i);
                }

            } else if (choice == 7) {
                printf("Thank you for your journey through Numeria!");
                break;
            } else {
                printf("wrong choice please choose again.\n");
            }
    }
    return 0;
}
	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
	*/
    

	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/

	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine weather a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
	//return 0;

