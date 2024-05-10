#include <iostream> 
#include <algorithm> 
 
int SumOfLine(int* line, int* numbers)  
{ 
	return numbers[line[0]] + numbers[line[1]] + numbers[line[2]] + numbers[line[3]]; 
} 
 
void PrintLine(int* line, int* numbers, int index)  
{ 
	std::cout << index << ": " << numbers[line[0]] << ", " << numbers[line[1]] << ", " << numbers[line[2]] << ", " << numbers[line[3]] << std::endl; 
} 
 
void PrintNumbers(int* numbers, int count) 
{ 
	std::cout << "Numbers: "; 
	for (int i = 0; i < count; ++i) 
		std::cout << numbers[i] << ", "; 
	std::cout << std::endl; 
} 
 
int main()  
{	 
	enum POINT { A, B, C, D, E, F, G, H, I, J }; 
	int no[] = { 2, 2, 2, 4, 4, 4, 4, 6, 6, 6 }; 
 
	int lines[][4] =  
	{  
		{ A, B, C, D }, 
		{ A, H, F, J }, 
		{ G, H, B, I }, 
		{ G, F, E, D }, 
		{ J, E, C, I } 
	}; 
 
	do  
	{ 
		PrintNumbers(no, 10); 
 
		bool combinationFound = true; 
		//Try the combination 
		for (int i = 0; i < 5; ++i)  
		{ 
			if (SumOfLine(lines[i], no) != 16)  
			{ 
				combinationFound = false; 
				break; 
			} 
		} 
 
		if (combinationFound)  
		{ 
			//Found combination that works, print 
			for (int i = 0; i < 5; ++i) 
				PrintLine(lines[i], no, i); 
 
			break; 
		} 
	}  
	while (std::next_permutation(no, no + 10)); 
}
