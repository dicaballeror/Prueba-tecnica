#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Operation {
	int x, y, z;
	long long w;
	bool isInside ( int x1, int y1, int z1, int x2, int y2, int z2 ) {
		return x1 <= x && x <= x2 && y1 <= y && y <= y2 && z1 <= z && z <= z2;
	}
};

void doUpdate ( vector < Operation > &O ) {
	// to do
}

void doQuery ( vector < Operation > &O ) {
	// to do
}

int main() {
    
    int testCases;
    int N, M;
    
    cin >> testCases;
    
    while ( testCases -- ) {
    	
    	vector < Operation > operations;
    	string type;
    	
    	cin >> N >> M;
    	
    	for ( int i = 0; i < M; i ++ ) {
    		cin >> type;
    		if ( type == "UPDATE" ) doUpdate(operations);
    		else doQuery(operations);
			}
		}
    
    return 0;
}
