
#include "iostream"
#include "cstdlib"
#include "string.h"
#include "stdio.h"

using namespace std;

int hash_function(int key, int size){
	int hashed_val = ((key+1)*4)%size;
	return hashed_val;
}

void contains(int* data, int size){
	int key = 0, index = 0;
	cout << "Enter the key: "<<endl;
	cin >>key;
	
	index = hash_function(key, size);
	if(data[index] != 0){
	cout <<"Your value is: ";
	cout <<data[index]<<endl;
	}
	else{
		cout << "There is no value associated with that key"<<endl;
	}
}

void insert(int* data, int size){
	int value = 0, key = 0, hashed_val = 0;
	
	cout << "Insert a value: ";
	cin >>value;
	cout << "\nInsert a key: ";
	cin >> key;
	
	hashed_val = hash_function(key, size);
//	cout << hashed_val <<endl;
	if(data[hashed_val] != 0){
		cout <<"Collision detected, overwriting old value with new value"<<endl;
	}
		data[hashed_val] = value;
}

int get_user_input(int* data, int size){
	int run = 1;
	int choice = 0;
		cout <<"   1. Insert a new key/value pair"<<endl;
		cout <<"   2. Look up a value using the associated key" <<endl;
		cout <<"   3. Quit" <<endl;
		cin >> choice;
			switch(choice){
				case 1: insert(data, size);
					   break;
				case 2: contains(data, size);
					   break;
				case 3: run = 0;
					   break;
			}
		return run;
}


int main(){
	int run = 1;
	int size = 0;
		cout << "Declare desired size of array: ";
		cin >>size;
	int *data = new int[size](); 
	for(int i = 0; i<size; i++){
		data[i] = 0;
	}
	cout <<"Welcome! Please choose from the following menu options:"<<endl;
	
	while(run == 1){
/*		
	for(int i=0;i<size;i++){			//uncomment if you want to see all elements of array
		cout << data[i];
		cout << ", ";
	}
*/
	run = get_user_input(data, size);
	}
	
	delete [] data;
	
	return 0;

}
