#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Operation {
	int x, y, z;
	long long w;
	Operation() {}
	Operation( int a, int b, int c, long long v ) {
		x = a; y = b; z = c; w = v;
	}
	bool isInside ( int x1, int y1, int z1, int x2, int y2, int z2 ) {
		return x1 <= x && x <= x2 && y1 <= y && y <= y2 && z1 <= z && z <= z2;
	}
	bool equalsTo ( int x1, int y1, int z1 ) {
		return x1 == x && y1 == y && z1 == z;
	}
	void updateW ( long long nw ) {
		w = nw;
	}
	long long getW () {
		return w;
	}
};

// Verifica si la operacion existe previamente en la misma posicion y de ser asi
// actualiza el valor en esa posicion, en caso que no se haya actualizado antes
// se crea una nueva operacion en esa posicion.
void addOperation ( vector < Operation > &O, int x, int y, int z, long long w ) {
	for ( int i = 0; i < O.size(); i ++ )
		if ( O[i].equalsTo( x, y, z ) ) {
			O[i].updateW(w);
			return;
		}
	O.push_back( Operation(x, y, z, w) );
}

// Lee los numeros de la posicion a actualizar con su respectivo valor.
void doUpdate ( vector < Operation > &O ) {
	int x, y, z;
	long long w;
	cin >> x >> y >> z >> w;
	addOperation( O, x, y, z, w );
}

// Lee los numeros que corresponden al cubo a analizar y efectua la suma
// de los valores que se encuentren dentro y finalmente imprime la suma
// total.
void doQuery ( vector < Operation > &O ) {
	int x1, y1, z1, x2, y2, z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	long long sum = 0;
	
	for ( int i = 0; i < O.size(); i ++ )
		if ( O[i].isInside( x1, y1, z1, x2, y2, z2 ) )
			sum += O[i].getW();
			
	cout << sum << '\n';
}

int main() {
    
    int testCases;
    int N, M;
    
    // Archivos de prueba locales ( descomentar para hacer pruebas )
    // freopen ( "input.txt", "r", stdin );
    // freopen ( "output.txt", "w", stdout );
    
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
