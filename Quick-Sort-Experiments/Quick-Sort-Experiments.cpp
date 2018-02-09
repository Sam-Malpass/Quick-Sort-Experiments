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
/*Minus Zero*/
void TestMinusZero()
{
	vector<float> Testing = { 6.2f, 10.1f, 13.4f, 5.5f, 8.9f, 3.1f, 2.2f, 25.6f, 4.1f, 11.9f, -0.2f, -0.0f, -0.0f, 0.0f, 0.0f, 0.0f, -5.4f };
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
/*Testing NaN*/
void TestNaN()
{
	float Zero = 0.0f, NegInf = -1.0 / Zero;
	vector<float> Testing = { 6.2f, nanf("3"), 10.1f, nanf("5"), 13.4f, NegInf, 5.5f, nanf("1"), 8.9f, 3.1f, nanf("2"), 2.2f, 25.6f, nanf("10"), 4.1f, 11.9f };
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
/*Accepting User Inputted Values*/
void Inputting()
{
	bool Continue = true;
	float Number;
	vector<float> Input;
	char Choice;
	system("cls");
	while (Continue == true)
	{
		cout << "Enter Number: ";
		cin >> Number;
		Input.push_back(Number);
		cout << "Continue? (Y / N): ";
		cin >> Choice;
		if (Choice == 'N' || Choice == 'n')
		{
			Continue = false;
		}
	}
	int Left = 0, Right = Input.size();
	system("cls");
	cout << "Original: ";
	Print(Input);
	high_resolution_clock::time_point T1 = high_resolution_clock::now();
	QuickSort(Input, Left, Right);
	high_resolution_clock::time_point T2 = high_resolution_clock::now();
	Time = duration_cast<microseconds>(T2 - T1).count();
	cout << "Sorted: ";
	Print(Input);
	PrintTime();
}
/*Read from File*/
void ReadFile()
{
	vector<float> Read;
	float Input;
	ifstream Data("Data.txt");
	while (Data.good())
	{
		Data >> Input;
		Read.push_back(Input);
	}
	int Left = 0, Right = Read.size();
	cout << "Original: ";
	Print(Read);
	high_resolution_clock::time_point T1 = high_resolution_clock::now();
	QuickSort(Read, Left, Right);
	high_resolution_clock::time_point T2 = high_resolution_clock::now();
	Time = duration_cast<microseconds>(T2 - T1).count();
	cout << "Sorted: ";
	Print(Read);
	PrintTime();
	Data.close();
}
int main()
{
    return 0;
}

