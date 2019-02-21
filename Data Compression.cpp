﻿// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <math.h>
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(int arr[],char Letter[], int n)// sort Array
{
	int i, key, j;
	char key2;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		key2 = Letter[i];
		j = i - 1;
		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			Letter[j + 1] = Letter[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		Letter[j + 1] = key2;
	}
}
int lenChar(char arr[]) {//len of array char
	int i = 0;
	while (arr[i] != '\0') {
	i++;
	}
	return i;
}
int len(int arr[]) {//len of ary int
	int i = 0;
	while (arr[i] != 0) {
		i++;
	}
	return i;
}

int FromFiboToNumber(char present[]) {// the functoin get the string delet the 1 at the end and do reverse, and return the real number 
	int  fibo[13] = { 144,89,55,34,21,13,8,5,3,2,1 }; 
	char ReversePre[15];
	int num = 0;
	int index = 0;
	for (int i =0; i<lenChar(present); i++) {
	}
	for (int i = lenChar(present) - 2; i >= 0; i--) {
		ReversePre[index] = present[i];
		index++;
	}
	ReversePre[index] = '\0';
	int index2 = len(fibo) - 1;
	int v = lenChar(ReversePre) - 1;
	for (int i = v; i >=0; i--) {
		if (ReversePre[i]== '1') {
			num = num + fibo[index2];
		}
		index2--;
	}
	return num;
}

int FiboPresrntCode(char present[], char reverse[20]) {// take the number and preset him at fibo number
	 // do reverse to the arry and add 1 at thr end
	int lenPresent = lenChar(present);
	int index = 0;
	for (int i =lenPresent-1; i >= 0; i--) {
		reverse[index] = present[i];
		index++;
	}
	reverse[index] = '1';
	return lenPresent;
}

int calculateFibo(int number, char fib_num[]) {// preset the number at fibo number
	int  fibo[13] = { 1,2,3,5,8,13,21,34,55,89,144 };
	char fiboPresnt[20];
	int index = 0;
	for (int i = 0; i <len(fibo) ; i++) {
		if (number < fibo[i]) {
			 index = i-1;
			 break;
		}
	}
	int indexOnChar = 0;
	fiboPresnt[indexOnChar] = '1';
	indexOnChar++;
	number = number - fibo[index];
	for (int i = index-1; i >=0;i--) {
		if (number>=fibo[i]) {
			fiboPresnt[indexOnChar] = '1';
			number = number - fibo[i];
		}
		else {
			fiboPresnt[indexOnChar] = '0';
		}
		indexOnChar++;
	}
	indexOnChar++;
	fiboPresnt[indexOnChar] = '\0';
	int leng = lenChar(fiboPresnt);
	for (int i = 0; i < leng-1; i++) {
	}	
	return FiboPresrntCode(fiboPresnt, fib_num);

}

int encoder(const char * input_path, const char * output_path) {// 
	FILE *input_file;
	FILE *output_file;
	char ch; ;
	errno_t err;
	if ((err = fopen_s(&input_file, input_path, "r")) != 0) {
		if (input_file == NULL) {
			printf("Error opening text file for reading\n");
			return 1;
		}
	}
	int overall_len = 0;
	char Letter[127];
	int Freq[127];
	int index = 0;
	int found = 0;
	for (int i = 0; i < 127; i++) {
		Freq[i] = 0;
	}
	int countOfTab = 0;
	while ((ch = fgetc(input_file)) != EOF) {
		countOfTab++;
			char  ansChar[12];
			found = 0;
			for (int i = 0; i < 127; i++) {// put all the char at the text to 1 array and count how many time  all char Appeared at the text
				if (Letter[i] == ch) {
					Freq[i]++;
					found = 1;
					break;
				}
			}
			if (found == 0) {
				Letter[index] = ch;
				Freq[index] = 1;
				index++;
			}
		}
	fclose(input_file);
	insertionSort(Freq,Letter,index);// sort array
	Letter[index] = '\0';
	int  fibo[13] = { 1,2,3,5,8,13,21,34,55,89,144 };
	int IndexFibo;
	char num_fib[20];
	if ((err = fopen_s(&input_file, input_path, "r")) != 0) {

		if (input_file == NULL) {
			printf("Error opening text file for reading\n");
			return 1;
		}
	}
	if ((err = fopen_s(&output_file, output_path, "w")) != 0) {
		if (output_file == NULL) {
			printf("Error opening text file for writing\n");
			return 1;
		}
	}
	int count = 0;
	int countLetter = lenChar(Letter) * 8;
	char lencount[15];
	int g= calculateFibo(lenChar(Letter),lencount);// print to the new file the len of the Dictionary at fibo preaent
	for (int i = 1; i <= g; i++) {
		fprintf(output_file, "%c", lencount[i]);
		count++;
	}
	for (int i = 0; i < index; i++) {// print the Dictionary to the new file 
		fprintf(output_file, "%c", Letter[i]);
	}
	while ((ch = fgetc(input_file)) != EOF) {// read the file 
		for (int i = 0; i <= len(Freq); i++) {
			if (Letter[i] == ch) {
				 IndexFibo= i+1;// get the char location at the Dictionary +1 
				
			}
		}
		int present = calculateFibo(IndexFibo,num_fib);// fibo present
		for (int i = 1; i <= present; i++) {
			fprintf(output_file, "%c", num_fib[i]);// print the char fibo preasent to the taxt
			count++;
		}
	}
	printf_s(" old len of fill  %d, ", countOfTab);
	printf_s(" new len of fill  %d, ", (count/8)+countLetter);
		fclose(input_file);
		fclose(output_file);
		return 0;
	}

int decodder(const char * input_path, const char * output_path) {
	FILE *input_file;
		FILE *output_file;
		char ch =' ';
		errno_t err;
		if ((err = fopen_s(&input_file, input_path, "r")) != 0) {
			if (input_file == NULL) {
				printf("Error opening text file for reading\n");
				return 1;
			}
		}
		if ((err = fopen_s(&output_file, output_path, "w")) != 0) {
			if (output_file == NULL) {
				printf("Error opening text file for writing\n");
				return 1;
			}
		}
		char num_dict[15];
		char  befor ;
		befor = ' ';
		int index = 0;
		while ((ch = fgetc(input_file)) != EOF) {
			num_dict[index] = ch;
			index++;

			if (befor == '1' && ch == '1') {// if 11 end of char
				num_dict[index] = '\0';
				break;
			}
			befor = ch;
		}	
		num_dict[index] = '\0';
		int lenwo = FromFiboToNumber(num_dict);// the len of the Dictionary
		char Letter[127];
		for (int i = 0; i < lenwo; i++) {
			if (ch = fgetc(input_file))
			{ 
				Letter[i] = ch;
				printf("%c  ", ch);// the Dictionary
			}
		}
		int overall_len = 0;
		index = 0;
		int found = 0;
		char GetLeter[15];
		befor=' ';
		int  fibo[13] = { 1,2,3,5,8,13,21,34,55,89,144 };
		while ((ch = fgetc(input_file)) != EOF) {
			GetLeter[index] = ch; // here the fibo preaent we want to replace to char
			index++;
			if (befor == '1' && ch == '1') {
				GetLeter[index] = '\0';
				int num = FromFiboToNumber(GetLeter);
				index = 0;
				fprintf(output_file, "%c", Letter[num-1]);
			}
			befor = ch;
			if (index == 0) {
				befor = ' ';		
			}
		}
		fclose(input_file);
		fclose(output_file);

		return 0;
	}

int main()
{
	int  fibo[13] = {1,2,3,5,8,13,21,34,55,89,144};
	int  fibo2[13] = { 144,89,55,34,21,13,8,5,3,2,1};
	const char * input_path = "C:\\Users\\Aviya\\לימודים\\שנה ד\\דחיסת נתונים\\input.txt";
	const char * output_path = "C:\\Users\\Aviya\\לימודים\\שנה ד\\דחיסת נתונים\\out1one.txt";
	decodder(input_path, output_path);
	encoder(input_path, output_path);
	return 0;
}





