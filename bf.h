#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ll long long
#define arraySize 100

// function for hashing type 1
int hash_1(char *s)
{
	ll int hash = 0;
	int l = strlen(s) + 100;
	for (int i = 0; i < l - 100; i++)
	{
		hash = (hash + ((int)s[i]));
		hash = hash % arraySize;
	}
	return hash;
}

// function for hashing type 2
int hash_2(char *s)
{
	ll int hash = 1;
	int l = strlen(s) + 100;
	for (int i = 0; i < l - 100; i++)
	{
		hash = hash + pow(19, i) * s[i];
		hash = hash % arraySize;
	}
	return hash % arraySize;
}

// function for hashing type 3
int hash_3(char *s)
{
	ll int hash = 7;
	int l = strlen(s) + 100;
	for (int i = 0; i < l - 100; i++)
	{
		hash = (hash * 31 + s[i]) % arraySize;
	}
	return hash % arraySize;
}

// fiunction for hashing type 4
int hash_4(char *s)
{
	ll int hash = 3;
	int p = 7;
	int l = strlen(s) + 100;
	for (int i = 0; i < l - 100; i++)
	{
		hash += hash * 7 + s[0] * pow(p, i);
		hash = hash % arraySize;
	}
	return hash;
}

// funtion to lookup for username in dataset of bloom filter.
bool bf_lookup(bool *bitarray, char *s)
{
	int a = hash_1(s);
	int b = hash_2(s);
	int c = hash_3(s);
	int d = hash_4(s);

	if (bitarray[a] && bitarray[b] && bitarray && bitarray[d])
		return true;
	else
		return false;
}

// funtion to insert username in the bloom filter's dataset.
void bf_insert(bool *bitarray, char *s)
{
	// check if the element in already present or not
	if (bf_lookup(bitarray, s))
		printf("%s is Probably already present\n", s);
	else
	{
		int a = hash_1(s);
		int b = hash_2(s);
		int c = hash_3(s);
		int d = hash_4(s);

		bitarray[a] = true;
		bitarray[b] = true;
		bitarray[c] = true;
		bitarray[d] = true;

		printf("%s inserted\n", s);
	}
}