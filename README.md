# CS2600 - Project 2
Travel Expenses - Group project

**How to complile multiple files together:**

Compile both files individually first:

gcc -Wall -c .\main.c

gcc -Wall -c .\travelTime.c

Then compile both together into an executable:

gcc -o program travelTime.o main.o

Then run executable with .\program.exe


**How to run unit tests with Unity:**

After writing unit test, compile both together:

gcc .\test_travelTime.c .\travelTime.c unity/src/unity.c -o test.exe

Then run executable with .\test.exe
