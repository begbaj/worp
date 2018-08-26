#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <cctype>
#include <algorithm>
#include <set>


using namespace std;

#pragma region Global

#pragma endregion

#pragma region Functions
int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void printHelp()
{

	cout
	<<"pwp <min> <max> <word1> <word2> [... <wordn>]"<<endl<<endl
	<<"\tPossible Word Permutations generates all"<<endl
	<<"\tpossible permutations from given words."<<endl<<endl
	<<"\tI raccomanded to NOT give more than 10 words"<<endl
	<<"\tas it will take too long and will generate a very oversized file!"<<endl<<endl
	
	<<"\t MIN and MAX are the minimum and the maximum"<<endl
	<<"\tgenerated word lenght to output. 0 values means 'no limit'"<<endl
	<<"\tes. pwp 0 8 this is america > output.txt"<<endl
	<<"\t---> this, thisis, is, isthis, america"<<endl;

}

 //Check if every character in given argument is "string" value
 //True if is of type "string"
 //False if is not

bool isString(char *a)
{
	int i=0;

	while(a[i])
		if(!isalpha(a[i++]))
			return false;
	return true;
}

void printError(string msg)
{
	cout<<"ERROR:"<<msg<<endl;
}

#pragma endregion

#pragma region Main

int main(int argc, char *argv[])
{
	//Checking Arguments
	if (argc<4)
	{
		printHelp();
		return -1;
	}
	
	if(isString(argv[1]) || isString(argv[2]))
	{
		printError("First and second arguments must be int values!");
		return -1;
	}

	int argnum=argc-3; //count of arguments after INT values
	string arr[argnum]; //declaration of string array
	string strtot="";
	for(int i=0; i<argnum; i++) //initialization of string array
	{
		arr[i] = argv[i+3];
		strtot += arr[i];
	}
	
	sort (arr,arr+argnum);
	unsigned int MIN = strtof(argv[1], NULL ); //MINimum lenght of the generated words
	unsigned int MAX = (strtof(argv[2], NULL ) != 0 ? strtof(argv[2], NULL ) :
	strtot.length()); //MAXimum lenght of the generated words
	
	set<string> lof;
	
	cout<<"Minimum:\t"<<MIN<<"\t Maximum:\t"<<MAX<<endl<<endl;
	
	do {
	
	string finalstr=""; // variable to store generated strings
	string prev_finalstr=""; // variable that stores previuos version of current generation of string
	
	for (int i = 0; i < argnum; i++) 
	{
		finalstr += arr[i];
		if(finalstr.length() <= MAX && finalstr.length() > MIN) lof.insert(finalstr);
	}
	
	if(lof.size() > 1000)
	{
		for (set<string>::iterator it=lof.begin(); it!=lof.end(); ++it)
			cout << *it << endl;
			
		lof.clear();
	}
	
	} while (next_permutation(arr, arr + argnum));
	
	
	 for (set<string>::iterator it=lof.begin(); it!=lof.end(); ++it)
		cout << *it << endl;
	
	return 0;
	
}

#pragma endregion
