/*Header Files*/
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <algorithm>
/*Global Variables*/
int NoOfElements, NoOfLoops;
__int64 Time;
/*Namespace Declaration*/
using namespace std;
using namespace chrono;
/*Printing Function*/
void Print(vector<float>& Any)
{
	for (auto Printing : Any)
	{
		cout << Printing << " ";
	}
	cout << endl;
}
/*Print Time Function*/
void PrintTime()
{
	cout << "Number of Elements: " << NoOfElements << endl;
	cout << "Number of Loops: " << NoOfLoops << endl;
	cout << "Time taken: " << Time << " microseconds" << endl;
}
/*Comparison Function*/
void Comparator(vector<float>& Any, int& I, int& J, float& Point)
{
	if (isnan(Any[J]) == true)
	{
		I = I + 1;
		swap(Any[I], Any[J]);
	}
	else if (Any[J] == 0.0f && signbit(Any[J]) == 0)
	{
		if (Any[J] < Point)
		{
			I = I + 1;
			swap(Any[I], Any[J]);
		}
	}
	else if (Any[J] <= Point)
	{
		I = I + 1;
		swap(Any[I], Any[J]);
	}
}
/*Partition Function*/
int Partition(vector<float>& Any, int Left, int Right)
{
	int I = Left, J;
	float Point = Any[Left];
	/*Recursively Swap Numbers if One is Smaller Than the Other*/
	for (J = Left + 1; J < Right; J++)
	{
		NoOfLoops++;
		Comparator(Any, I, J, Point);
	}
	swap(Any[I], Any[Left]);
	return I;
}
/*QuickSort Function*/
void QuickSort(vector<float>& Any, int Left, int Right)
{
	NoOfElements = Any.size();
	int Position;
	if (Left < Right)
	{
		Position = Partition(Any, Left, Right);
		QuickSort(Any, Left, Position);
		QuickSort(Any, Position + 1, Right);
	}
}
int main()
{
    return 0;
}

