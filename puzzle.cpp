#include <iostream>
#include <string>
#include <set>
#include "grid.h"
#include "component.h"

using namespace std;

bool isSolvable(grid inp);
int getInvCount(grid inp);
void a_star(grid inp);
int heur(grid start);
void reconstruct_path(set<component> came_from);
int tile_reversal(grid g);

int main(){
	grid inp;
	int arr[3][3];
	
	//here input the elements into the array
	cout<<"Enter 9 integers representing the elements\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	inp.setBlock(arr);

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
    // int inv_count = 0;
    // for (int i = 0; i < 8; i++)
    //     for (int j = i+1; j < 9; j++)
    //          if (arr[j] && arr[i] &&  arr[i] > arr[j])
    //               inv_count++;
    return 2;
}

void a_star(grid inp){
	set<component> closed,open,came_from,all;
	set<component>::iterator current,iter;
	component inserter,temp,temp1;
	grid g,g_up,g_down,g_left,g_right;
	bool isLeft,isUp,isDown,isRight,isPresent,isPresent_open;
	int h,tentative_g_score,g_child;

	closed.clear();
	open.clear();
	came_from.clear();
	all.clear();

    h = heur(inp);
	inserter.setGrid(inp);
	inserter.setGscore(0);
    inserter.setHscore(h);
	inserter.setFscore(h);

    open.insert(inserter);
    all.insert(inserter);

    while(!open.empty()){
    	iter = open.begin();
    	temp1 = *iter;
    	g = temp1.getGrid();
    	if(g.isRightConfig()){
        	// reconstruct_path(came_from);
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
            
            //start of the insertion of then compnents into the all set.......................................
    		inserter.clearer();
    		//set inserter grid as g_down;.............
    		inserter.setGrid(g_down);
    		isPresent = false;
    		for(set<component>::iterator itt = all.begin(); itt != all.end(); itt++){
    			temp = *itt;
				if(temp.getGrid() == g_down){
					isPresent = true;
					break;
				}
    		}
    		if(!isPresent){
    			all.insert(inserter);
    		}

			inserter.clearer();
    		//set inserter grid as g_up;.............
    		inserter.setGrid(g_up);
    		isPresent = false;
    		for(set<component>::iterator itt = all.begin(); itt != all.end(); itt++){
    			temp = *itt;
				if(temp.getGrid() == g_up){
					isPresent = true;
					break;
				}
    		}
    		if(!isPresent){
    			all.insert(inserter);
    		}

    		inserter.clearer();
    		//set inserter grid as g_left;.............
    		inserter.setGrid(g_left);
    		isPresent = false;
    		for(set<component>::iterator itt = all.begin(); itt != all.end(); itt++){
    			temp = *itt;
				if(temp.getGrid() == g_left){
					isPresent = true;
					break;
				}
    		}
    		if(!isPresent){
    			all.insert(inserter);
    		}

    		inserter.clearer();
    		//set inserter grid as g_right;.............
    		inserter.setGrid(g_right);
    		isPresent = false;
    		for(set<component>::iterator itt = all.begin(); itt != all.end(); itt++){
    			temp = *itt;
				if(temp.getGrid() == g_right){
					isPresent = true;
					break;
				}
    		}
    		if(!isPresent){
    			all.insert(inserter);
    		}    		

    		//end of the insertion of then components into the all set.........................................

    		if(isDown){
    			g_child = 0;
    			for(set<component>::iterator itt = all.begin(); itt != all.end(); itt++){
	    			temp = *itt;
					if(temp.getGrid() == g_down){
						g_child = temp.getGscore();
						break;
					}
	    		}

    			isPresent = false;
    			for(set<component>::iterator itt = closed.begin(); itt != closed.end(); itt++){
    				temp = *itt;
    				if(temp.getGrid() == g_down){
    					isPresent = true;
    					break;
    				}
    			}

    			if(!isPresent){
    				temp1 = *iter;
    				tentative_g_score = temp1.getGscore() + 1;
    				isPresent_open = false;

    				for(set<component>::iterator itt = open.begin(); itt != open.end(); itt++){
	    				temp = *itt;
	    				if(temp.getGrid() == g_down){
	    					isPresent_open = true;
	    					break;
	    				}
	    			}
    				if(!isPresent_open || tentative_g_score < g_child){
    					inserter.clearer();
    					inserter.setGscore(tentative_g_score);
    					h = heur(g_down);
    					inserter.setHscore(h);
    					inserter.setFscore(h + tentative_g_score);
    					inserter.setGrid(g_down);
    					came_from.insert(inserter);
    					isPresent_open = false;

	    				for(set<component>::iterator itt = open.begin(); itt != open.end(); itt++){
		    				temp = *itt;
		    				if(temp.getGrid() == g_down){
		    					isPresent_open = true;
		    					break;
		    				}
		    			}

		    			if(!isPresent_open){
		    				open.insert(inserter);
		    			}
    				}
    			}
    		}

    		if(isRight){
    			g_child = 0;
    			for(set<component>::iterator itt = all.begin(); itt != all.end(); itt++){
	    			temp = *itt;
					if(temp.getGrid() == g_right){
						g_child = temp.getGscore();
						break;
					}
	    		}

    			isPresent = false;
    			for(set<component>::iterator itt = closed.begin(); itt != closed.end(); itt++){
    				temp = *itt;
    				if(temp.getGrid() == g_right){
    					isPresent = true;
    					break;
    				}
    			}

    			if(!isPresent){
    				temp1 = *iter;
    				tentative_g_score = temp1.getGscore() + 1;
    				isPresent_open = false;

    				for(set<component>::iterator itt = open.begin(); itt != open.end(); itt++){
	    				temp = *itt;
	    				if(temp.getGrid() == g_right){
	    					isPresent_open = true;
	    					break;
	    				}
	    			}
    				if(!isPresent_open || tentative_g_score < g_child){
    					inserter.clearer();
    					inserter.setGscore(tentative_g_score);
    					h = heur(g_right);
    					inserter.setHscore(h);
    					inserter.setFscore(h + tentative_g_score);
    					inserter.setGrid(g_right);
    					came_from.insert(inserter);
    					isPresent_open = false;

	    				for(set<component>::iterator itt = open.begin(); itt != open.end(); itt++){
		    				temp = *itt;
		    				if(temp.getGrid() == g_right){
		    					isPresent_open = true;
		    					break;
		    				}
		    			}

		    			if(!isPresent_open){
		    				open.insert(inserter);
		    			}
    				}
    			}
    		}

    		if(isLeft){
    			g_child = 0;
    			for(set<component>::iterator itt = all.begin(); itt != all.end(); itt++){
	    			temp = *itt;
					if(temp.getGrid() == g_left){
						g_child = temp.getGscore();
						break;
					}
	    		}

    			isPresent = false;
    			for(set<component>::iterator itt = closed.begin(); itt != closed.end(); itt++){
    				temp = *itt;
    				if(temp.getGrid() == g_left){
    					isPresent = true;
    					break;
    				}
    			}

    			if(!isPresent){
    				temp1 = *iter;
    				tentative_g_score = temp1.getGscore() + 1;
    				isPresent_open = false;

    				for(set<component>::iterator itt = open.begin(); itt != open.end(); itt++){
	    				temp = *itt;
	    				if(temp.getGrid() == g_left){
	    					isPresent_open = true;
	    					break;
	    				}
	    			}
    				if(!isPresent_open || tentative_g_score < g_child){
    					inserter.clearer();
    					inserter.setGscore(tentative_g_score);
    					h = heur(g_left);
    					inserter.setHscore(h);
    					inserter.setFscore(h + tentative_g_score);
    					inserter.setGrid(g_left);
    					came_from.insert(inserter);
    					isPresent_open = false;

	    				for(set<component>::iterator itt = open.begin(); itt != open.end(); itt++){
		    				temp = *itt;
		    				if(temp.getGrid() == g_left){
		    					isPresent_open = true;
		    					break;
		    				}
		    			}

		    			if(!isPresent_open){
		    				open.insert(inserter);
		    			}
    				}
    			}
    		}

    		if(isUp){
    			g_child = 0;
    			for(set<component>::iterator itt = all.begin(); itt != all.end(); itt++){
	    			temp = *itt;
					if(temp.getGrid() == g_up){
						g_child = temp.getGscore();
						break;
					}
	    		}

    			isPresent = false;
    			for(set<component>::iterator itt = closed.begin(); itt != closed.end(); itt++){
    				temp = *itt;
    				if(temp.getGrid() == g_up){
    					isPresent = true;
    					break;
    				}
    			}

    			if(!isPresent){
    				temp1 = *iter;
    				tentative_g_score = temp1.getGscore() + 1;
    				isPresent_open = false;

    				for(set<component>::iterator itt = open.begin(); itt != open.end(); itt++){
	    				temp = *itt;
	    				if(temp.getGrid() == g_up){
	    					isPresent_open = true;
	    					break;
	    				}
	    			}
    				if(!isPresent_open || tentative_g_score < g_child){
    					inserter.clearer();
    					inserter.setGscore(tentative_g_score);
    					h = heur(g_up);
    					inserter.setHscore(h);
    					inserter.setFscore(h + tentative_g_score);
    					inserter.setGrid(g_up);
    					came_from.insert(inserter);
    					isPresent_open = false;

	    				for(set<component>::iterator itt = open.begin(); itt != open.end(); itt++){
		    				temp = *itt;
		    				if(temp.getGrid() == g_up){
		    					isPresent_open = true;
		    					break;
		    				}
		    			}

		    			if(!isPresent_open){
		    				open.insert(inserter);
		    			}
    				}
    			}
    		}
    	}
    }


}

int heur(grid inp){
    return 1;
}

void reconstruct_path(set<component> came_from){
	component current;
	grid g;
    
    while(!came_from.empty()){
    	current = *came_from.begin();
		g = current.getGrid();
		cout<<g.printfn()<<"\n";
		came_from.erase(current);
    }
	
}

int manhattan_distance(grid g){

}

int tile_reversal(grid g){
	int count,a,b,c,d;
	count = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			a=i-1;
			b=j;
			if(a<3 && a>0 && b<3 && b>0 && g.getBlock(i,j) != 0){
				c = g.getBlock(i,j);
				d = g.getBase(a,b);
				if(c==d){
					c = g.getBase(i,j);
					d = g.getBlock(a,b);
					if(c==d){
						count++;
					}
				}
			}

			a = i+1;
			b = j;
			if(a<3 && a>0 && b<3 && b>0 && g.getBlock(i,j) != 0){
				c = g.getBlock(i,j);
				d = g.getBase(a,b);
				if(c==d){
					c = g.getBase(i,j);
					d = g.getBlock(a,b);
					if(c==d){
						count++;
					}
				}
			}

			a = i;
			b = j-1;
			if(a<3 && a>0 && b<3 && b>0 && g.getBlock(i,j) != 0){
				c = g.getBlock(i,j);
				d = g.getBase(a,b);
				if(c==d){
					c = g.getBase(i,j);
					d = g.getBlock(a,b);
					if(c==d){
						count++;
					}
				}
			}

			a = i;
			b = j+1;
			if(a<3 && a>0 && b<3 && b>0 && g.getBlock(i,j) != 0){
				c = g.getBlock(i,j);
				d = g.getBase(a,b);
				if(c==d){
					c = g.getBase(i,j);
					d = g.getBlock(a,b);
					if(c==d){
						count++;
					}
				}
			}
		}
	}

	return count/2;
}

int heur(grid g){
	int m;
	m = tile_reversal(g) + manhattan_distance(g);
	return m;
}