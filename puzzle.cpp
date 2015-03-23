#include <iostream>
#include <set>
#include "grid.h"

using namespace std;

bool isSolvable(grid inp);
int getInvCount(grid inp);
void a_star(grid inp);

int main(){
	grid inp;
	int arr[9];
	//here input the elements into the array

	inp.setGrid(*arr);

	if(!isSolvable(inp)){
		cout<<"Not Solvable\n";
		return 0;
	}
	else{
		a_star(inp);
		return 0;
	}
}

bool isSolvable(grid inp){
	// Count inversions in given 8 puzzle
    int invCount = getInvCount(inp);
 
    // return true if inversion count is even.
    return (invCount%2 == 0);

}


int getInvCount(grid inp)
{
    //yet to be corrected
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i+1; j < 9; j++)
             // Value 0 is used for empty space
             if (arr[j] && arr[i] &&  arr[i] > arr[j])
                  inv_count++;
    return inv_count;
}

void a_star(grid inp){

}