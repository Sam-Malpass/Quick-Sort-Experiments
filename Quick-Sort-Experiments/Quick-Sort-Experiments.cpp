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
/*Empty List Test*/
void TestEmpty()
{
	vector<float> Testing = {};
	int Left = 0, Right = Testing.size();
	cout << "Original: ";
	Print(Testing);
	high_resolution_clock::time_point T1 = high_resolution_clock::now();
	QuickSort(Testing, Left, Right);
	high_resolution_clock::time_point T2 = high_resolution_clock::now();
	Time = duration_cast<microseconds>(T2 - T1).count();
	cout << "Sorted: ";
	Print(Testing);
	PrintTime();
}
/*List of One*/
void TestOne()
{
	vector<float> Testing = { 6.2f };
	int Left = 0, Right = Testing.size();
	cout << "Original: ";
	Print(Testing);
	high_resolution_clock::time_point T1 = high_resolution_clock::now();
	QuickSort(Testing, Left, Right);
	high_resolution_clock::time_point T2 = high_resolution_clock::now();
	Time = duration_cast<microseconds>(T2 - T1).count();
	cout << "Sorted: ";
	Print(Testing);
	PrintTime();
}
/*List of Two*/
void TestTwo()
{
	vector<float> Testing = { 6.2f, 2.3f };
	int Left = 0, Right = Testing.size();
	cout << "Original: ";
	Print(Testing);
	high_resolution_clock::time_point T1 = high_resolution_clock::now();
	QuickSort(Testing, Left, Right);
	high_resolution_clock::time_point T2 = high_resolution_clock::now();
	Time = duration_cast<microseconds>(T2 - T1).count();
	cout << "Sorted: ";
	Print(Testing);
	PrintTime();
}
/*General List*/
void TestGeneral()
{
	vector<float> Testing = { 6.2f, 10.1f, 13.4f, 5.5f, 8.9f, 3.1f, 2.2f, 25.6f, 4.1f, 11.9f };
	int Left = 0, Right = Testing.size();
	cout << "Original: ";
	Print(Testing);
	high_resolution_clock::time_point T1 = high_resolution_clock::now();
	QuickSort(Testing, Left, Right);
	high_resolution_clock::time_point T2 = high_resolution_clock::now();
	Time = duration_cast<microseconds>(T2 - T1).count();
	cout << "Sorted: ";
	Print(Testing);
	PrintTime();
}
/*Infinity and Minus Infinity*/
void TestInfinity()
{
	vector<float> Testing = { 6.2f, 10.1f, 13.4f, 5.5f, 8.9f, 3.1f, 2.2f, 25.6f, 4.1f, 11.9f };
	float Zero = 0.0f, Negative = -1.0f / Zero, Positive = 1.0f / Zero;
	Testing.push_back(Negative);
	Testing.push_back(Positive);
	int Left = 0, Right = Testing.size();
	cout << "Original: ";
	Print(Testing);
	high_resolution_clock::time_point T1 = high_resolution_clock::now();
	QuickSort(Testing, Left, Right);
	high_resolution_clock::time_point T2 = high_resolution_clock::now();
	Time = duration_cast<microseconds>(T2 - T1).count();
	cout << "Sorted: ";
	Print(Testing);
	PrintTime();
}
int main()
{
    return 0;
}

