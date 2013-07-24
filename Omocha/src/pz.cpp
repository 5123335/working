/*
 * pz.cpp
 *
 *  Created on: 2013/07/24
 *      Author: yumikoy
//
//void printl(int l[4]){
//	for(int i = 0; i < 4; i++){
//		printf("%d", l[i]);
//	}
//	printf("\n");
//}
//
//void print12(int l[4], int fromto[2]){
//	for(int i = 0; i<12; i++){
//		swap(l, fromto);
//		printl(l);
//	}
//}
//
//int factorial(int n){
//	int result = 1;
//	for(int i = 1; i <= n; i++){
//		result *= i;
//	}
//	return result;
//}
//
//int main(){
////	int fromto12[2] = {1,2};
////	int fromto13[2] = {1,3};
////	int fromto24[2] = {2,4};
////	int fromto34[2] = {3,4};
//
////	int fromtos[4][2] = {{1,2}, {3,1}, {2,4}, {4,3}};
//////	printl(l);
////	for(int i = 0; i < 4; i++){
////		int l[4] = {1,2,3,4};
////		print12(l, fromtos[i]);
////	}
//
//	printf("%d\n", factorial(6));
//
//	printf("end");
//}
 */


#include <set>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

set<int> nums;  // 空のset

int mypow(int x, int n){
	int result = 1;
	for(int i=0; i<n; i++){
		result *= x;
	}
	return result;
}
int p10(int n){
	return mypow(10, n);
}
int nonp(int l, int p){
	return fmod(l / p10(9-p) , 10);
}

int swap(int l, int from, int to) {
	int f = nonp(l, from), t = nonp(l, to);
	printf("swap (p%d(%d), p%d(%d))  ", from, f, to, t);
	int hd,ld,hn,ln;
	if(from < to){
		hd = from; ld = to; hn = f; ln = t;
	} else {
		hd = to; ld = from; hn = t; ln = f;
	}
	return l + (p10(9-hd)-p10(9-ld))*(ln-hn);
}

int con[][4] = {{2,4,-1,-1},{1,3,5,-1},{2,6,-1,-1},
		{1,5,7,-1},{2,4,6,8},{3,5,9,-1},
		{4,8,-1,-1},{5,7,9,-1},{6,8,-1,-1}};

static int count = 0;
static int lv = 0;
void enumer(int l, int have, int p){
	printf("enumer(%d, %d, %d)\n", l, have, p);
	lv++;
	int* nextps = con[p-1];
	for(int i=0; i<4; i++){
		int nextp = nextps[i];
		if(nextp==-1)
			break;
		int swapped = swap(l, p, nextp);
		printf("%d : %d->%d  %d\n", lv, p, nextp, swapped);
//		pair<set<int>::iterator, bool> result = nums.insert(swapped);
		count++;
		if(count==50000)
			exit(0);
		if(!nums.insert(swapped).second){
//			printf("!\n");
			continue;
		}
		printf("%d\n",(unsigned int) nums.size());
		enumer(swapped, have, nextp);
	}
	lv--;
}
void enumerStart(int l, int start){

	int* cons = con[start-1];
	int have = nonp(l, start);
	for(int i=0; i<4; i++){
		if(cons[i]==-1)
			break;
		int swapped = swap(l, start, cons[i]);
		printf("s%d->%d %d\n", start, cons[i], swapped);
//		pair<set<int>::iterator, bool> result = nums.insert(swapped);
//		printf("%d", result.second);
		if(!nums.insert(swapped).second){
//			printf("!\n");
			break;
		}
		enumer(swapped, have, cons[i]);
	}
}

int main() {


	int l = 123456789;
	// 要素を追加する
	nums.insert(l);
	nums.insert(l);
	printf(nums.find(987654321) == nums.end() ? "nai" : "aru");
	printf(nums.find(123456789) == nums.end() ? "nai" : "aru");
	printf("\n");

	enumerStart(l,1);
//	int fromto[2];
//	int fromto[] = { 1, 3 };

//	printf("%d\n", swap(l, fromto));
//	nums.insert(swap(l,fromto));
//	enumer(l,1);

	// 要素を出力する
//	set<int>::iterator it = nums.begin();
//	while (it != nums.end()) {
//		cout << *it << endl;
//		++it;
//	}

	cout << "要素数：" << (unsigned int) nums.size() << endl;
//	nums.clear();

	return 0;
}
