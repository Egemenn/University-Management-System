/*Egemen ÇAGSIRLI
 * 161044101
 * GTU 2019
 *
 * The program allow user to enter smaller than 46. Because I tried all inputs until 46 and program halted
 * for inputs which are bigger than 45. Besides program do not allow to enter an input which is smaller than 0.
 * L+1 will be 1 for 0 (zero) input, so 0 is allowed to enter.*/

#include <iostream>
using namespace std;

int FiboPyramid(int n, int m)
{
    /*---- Base Case of recursion. ----*/
    /* These are the first equality for Fibonacci Pyramid*/
    if ((n == 0 && m == 0) || (n == 1 && m == 1)||      //control if m and n is one of the numbers in base case
        (n == 1 && m == 0) || (n == 2 && m == 1))
            return 1;                                   //if yes return 1

    /*---- Recursive Part of recursion ----*/
    /*in this step our pyramid occurs. If n bigger than m,
     *program will calculate summation of (n-1, m) and (n-2, m)*/
    if (n == m)
        return FiboPyramid(n - 2, m - 2) + FiboPyramid(n - 1, m - 1);
    /*If n is equal to m program will look summation of (n-1, m-1)
     * and (n-2, m-2). Otherwise it will return 0*/
    else if (n > m)
        return FiboPyramid(n - 2, m) + FiboPyramid(n - 1, m);
    else if(n < m)
        return 0;
}

void printFibo(int n)
{
    bool even;
    int tempN=n;
    int tempJ=0, tempI=0;
    int lineNumber=0;
    int biggest=0;
    int heart1=0, heart2=0;

    /*find true inputs for FiboPyramid function and find biggest*/
    for (int i = 0; i < n; i++) {                   //from i to n. this step for number of lines
        for (int j = 0; j <= i; j++) {
            cout << FiboPyramid(i, j) << " ";       //call FiboPyramid function
                           //find the largest number in the pyramid
            tempI=i;                                //tempI will be used as value of j below. It will prevent unnecessary memory allocation
            tempJ=j;                                //tempJ will be used as value of j below
        }
        cout << endl;                               //end of each lines
    }

    /*----Calculation of largest and heart of the pyramids----*/
    //calculate FiboPyramid for last i and j in here to use least memory
    biggest=FiboPyramid(tempI,tempJ);

    /*if n (L+1) is an odd number, assign it n+1. For instance when L+1=5
    *and 5/2=2 in code, it prevents this and 5/2 will be 3 in here */
    if(tempN%2==1) {
        tempN=tempN+1;
    }
    lineNumber=tempN/2+1;
    /*if  (L+1)/2 is equal to an even number even is true. else false*/
    if (lineNumber % 2 == 0)
        even = true;
    else
        even = false;

    if(even) {
        heart1 = FiboPyramid(lineNumber-1, tempJ / 4);     //one of the heart of pyramid
        heart2 = FiboPyramid(lineNumber-1, tempJ / 4 + 1); //other of the heart of the pyramid
    }
    else{
        heart1 = FiboPyramid(lineNumber-1, tempJ / 4 + 1);
    }
    /*----Calculation of largest and heart of the pyramids----*/


    if(even) {
        cout << "Largest number of the pyramid :" << biggest << endl;
        cout << "Heart of the pyramid : " << heart1 << " " << heart2 << endl;
    }
    else{
        cout << "Largest number of the pyramid :" << biggest << endl;
        cout << "Heart of the pyramid : " << heart1 << endl<<endl;
    }
}

/* Driver code */
void driver(){

    int L=0,n;
    do {
        /*take the input from user*/
        cout<<"Enter a number for Fibonacci Pyramid :  (Enter 999 to finish the program and exit...)"<<endl;
        cin >> L;
        /* if user enter 999 program will be finished. otherwise it will go on */
        if(L==999){
            cout<<"PROGRAM FINISHED. (999 EXITS FROM LOOP AND FINISHES PROGRAM)";
            exit(1);
        }

        /*------input control------*/
        do {
            //program may be halted for number that is bigger than 45
            if (!(L >= 0 && L <46 )) {
                cout << "Wrong input! Please enter a number between 0-50 :" << endl;
                cin >> L;
                if(L==999){
                    cout<<"PROGRAM FINISHED. (999 EXITS FROM LOOP AND FINISHES PROGRAM)";
                    exit(1);//when user enter 999, program will end.
                }
            }
        }while(!(L >= 0 && L < 46));
        /*------input control------*/

        /*find input+1 and calculate for this number*/
        n=L+1;
        printFibo(n);
    /*if user do not enter 999 program will go on for other inputs of user*/
    }while (L!=999);

}

int main() {

    /*driver function*/
    driver();

    return 0;
}