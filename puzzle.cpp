#include <iostream>
#include <set>
#include "grid.h"
#include "component.h"

using namespace std;

bool isSolvable(grid inp);
int getInvCount(grid inp);
void a_star(grid inp);
int heur(grid start);

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
	set<component> closed,open,came_from;
	set<component>::iterator current;
	component inserter,temp;
	grid g,g_up,g_down,g_left,g_right;
	bool isLeft,isUp,isDown,isRight,isPresent;
	int h;

	closed.clear();
	open.clear();
	came_from.clear();

    h = heur(inp);
	inserter.setGrid(inp);
	inserter.setGscore(0);
    inserter.setHscore(h);
	inserter.setFscore(h);

    open.insert(inserter);

    while(!open.empty()){
    	iter = open.begin();
    	g = iter->getGrid();
    	if(g.isRightConfig()){
        	reconstruct_path(came_from);
        	break;
    	}
    	else{
    		current = open.begin();
    		closed.insert(*current);
    		open.erase(current);

    		//now generate the children
    		g_right = g;
    		g_left = g;
    		g_up = g;
    		g_down = g;
    		isLeft = g_left.left();
    		isRight = g_right.right();
    		isUp = g_up.up();
    		isDown = g_down.down();

    		if(isDown){
    			isPresent = false;
    			for(set<component>::iterator itt = closed.begin(); itt != closed.end(); itt++){
    				temp = *itt;
    				if(){}
    			}
    		}

    		if(isRight){}

    		if(isLeft){}

    		if(isUp){}
    	}
    }


}

int heur(grid inp){

}