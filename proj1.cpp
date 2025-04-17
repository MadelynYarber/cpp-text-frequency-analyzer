#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
int main()
{	

//unordered maps
unordered_map <char, int> map;
unordered_map <string, int> map1;
unordered_map <string, int> map2;

//vectors
vector<string> wordOrder;
vector<string> numOrder;

//counts and ints
int newLine = 0;
int numPrinted = 0;
int wordPrinted = 0;
int charPrinted = 0;

//strings
string line;
string word;
string number;

//bools
bool inNumber = false;

while(getline(cin, line))
{
	
	for(char& c : line)
	{	
		//going through each character and adds to character map
		map[c]++;
		//charCount++;
			//checks if character is a number and adds to number map
			if (isdigit(c))
			{
				number += c;
				inNumber = true;
			} else { 
			if (inNumber) 
			{
				if (map1[number] == 0)
				{
				numOrder.push_back(number);	
				}			
			map1[number]++;
			number.clear();
			inNumber = false;
			}	
		}
	}
	//counts every new line in the while loop
	newLine++;	

	//Seperate for loop for words
	for(char& c : line)
	{
		//checks if character is a letter, makes lowercase, develops word, clears after word
		if (isalpha(c))
		{	
		word += tolower(c);
		}
		else
		{
			if (!word.empty())
			{ 
				if (map2[word] == 0)
				{
				wordOrder.push_back(word);
				}
			map2[word]++;
			word.clear();
			}
		}
	}
	
	//if statement for if there is a word at the end
	if (!word.empty())	
	{
		if (map2[word] == 0) 
		{
		wordOrder.push_back(word);
		}
	map2[word]++;
	word.clear();
	}
}
	//if statement for if there are numbers at the end
	if (inNumber)	
	{
		if (map1[number] == 0)
		{
		numOrder.push_back(number);
		}
	map1[number]++;
	}

//puts the newline character in the charcter map
map['\n'] = newLine;

//vectors
vector<pair<char, int>> sortedCharacters(map.begin(), map.end());
vector<pair<string, int>> sortedNumbers(map1.begin(), map1.end());
vector<pair<string, int>> sortedWords(map2.begin(), map2.end());	

//Sort vectors
//Sort Characters
sort(sortedCharacters.begin(), sortedCharacters.end(), [](const pair<char, int>& a, const pair<char, int>& b)
{
	if (a.second == b.second)	
	{
	return a.first < b.first;
	}
return a.second > b.second; 
});

//Sort Words
sort(sortedWords.begin(), sortedWords.end(), [&wordOrder](const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second == b.second)
	{
	return find(wordOrder.begin(), wordOrder.end(), a.first) < find(wordOrder.begin(), wordOrder.end(), b.first);
	}
return a.second > b.second;
});

//Sort numbers
sort(sortedNumbers.begin(), sortedNumbers.end(), [&numOrder](const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second == b.second)
	{
	return find(numOrder.begin(), numOrder.end(), a.first) < find(numOrder.begin(), numOrder.end(), b.first);
	}
return a.second > b.second;
});

//Print top 10 characters
cout << "Total " << map.size() << " different characters, ";
for (int i = 0; i < min(10, (int)sortedCharacters.size()); ++i)
{
charPrinted++;
}
cout << charPrinted << " most used characters: " << endl;
for (int i = 0; i < min(10, (int)sortedCharacters.size()); ++i)
{
	//checks if new like is in top 10 and prints
	if (sortedCharacters[i].first  == '\n')
	{
	cout << "No. " << i << ": ";
        cout << left << setw(15) << "\\n"  << right << setw(8) << sortedCharacters[i].second << endl; 	
	}
	else
	{
	cout << "No. " << i << ": ";
	cout << left << setw(15) << sortedCharacters[i].first << right << setw(8)  << sortedCharacters[i].second << endl;
	}
}	

//Spacing between outputs
cout << endl;

//Print top 10 words
cout << "Total " << map2.size() << " different words, ";
for (int i = 0; i < min(10, (int)sortedWords.size()); ++i)
{
	wordPrinted++;
}
cout << wordPrinted << " most used words: " << endl;
for (int i = 0; i < min(10, (int)sortedWords.size()); ++i)
{
	cout << "No. " << i << ": ";
	cout << left << setw(15) << sortedWords[i].first << right << setw(8) << sortedWords[i].second << endl;
}
	
//Spacing between outputs
cout << endl;

//Print top 10 numbers
cout << "Total " << map1.size()  << " different numbers, ";
for (int i = 0; i < min(10, (int)sortedNumbers.size()); ++i)
{
	numPrinted++;
}
cout << numPrinted << " most used numbers: " << endl;
for (int i = 0; i < min(10, (int)sortedNumbers.size()); ++i)
{
 	cout << "No. " << i << ": ";
 	cout << left << setw(15) << sortedNumbers[i].first << right << setw(8) << sortedNumbers[i].second << endl;
}


return 0;
}	
