#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <cctype>
#include <algorithm>
#include <set>


using namespace std;

#pragma region Functions

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void printHelp()
{

	cout
	<<" worp <min> <max> <first word> <second word> [... <nth word>]"<<endl<<endl
	<<"\t Word Permutator generates all possible permutations of the given words."<<endl<<endl
	<<"\t Keep in mind that more words are given, more time consuming it will be."<<endl
	<<"\t Moreover, it may generate very large files (ridiculously large files!)."<<endl
	
	<<"\t\t <min> - <max> idicate how long should the outputed words be."<<endl
	<<"\t\t\t 0 values means 'no limit' (i.e. 0 0 will generate words with length 1 as well as 1000 or more)"<<endl<<endl
	<<"\t\t Usage Example:"<<endl
	<<"\t\t $ worp 0 8 this is america > output.txt"<<endl
	<<"\t\t $ cat output.txt"<<endl
	<<"\t\t this thisis is isthis"<<endl
	<<"\t\t thisis"<<endl
	<<"\t\t is"<<endl
	<<"\t\t isthis"<<endl
	<<"\t\t america"<<endl;

}

 //Check if every character in given argument is "string" value

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
