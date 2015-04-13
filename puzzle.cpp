#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include "grid.h"
#include "component.h"

using namespace std;

bool isSolvable(grid inp);
int getInvCount(grid inp);
void a_star(grid inp);
int heur(grid start);
void reconstruct_path(set<component> current);
int tile_reversal(grid g);
int manhattan_distance(grid g);

int main(){
	grid inp;
	int arr[3][3],test;
	
	//here input the elements into the array
	cout<<"Enter 9 integers representing the elements\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	inp.setBlock(arr);

	// test = heur(inp);
	// cout<<test<<"\n";

	if(!isSolvable(inp)){
		cout<<"Not Solvable\n";
		return 0;
	}
	else{
		cout<<"solvable\n";
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
   int inv_count = 0,arr[9],one_d;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            one_d = i*3 + j;
            arr[one_d] = inp.getBlock(i,j);
        }
    }


    for (int i = 0; i < 8; i++){
       for (int j = i+1; j < 9; j++){
          if(1<=arr[i] && arr[i]<=3){
              if(arr[j] && arr[i] > arr[j]){
                inv_count++;
              }
          }

          if(arr[i] == 8){
              if(arr[j] && arr[j] < 4){
                inv_count++;
              }
          }

          if(arr[i] == 4){
              if(arr[j] && arr[j] != 5 && arr[j] != 6 && arr[j] != 7){
                inv_count++;
              }
          }

          if(arr[i] == 7){
              if(arr[j] && arr[j] != 5 && arr[j] != 6){
                inv_count++;
              }
          }

          if(arr[i] == 6){
              if(arr[j] && arr[j]!=5){
                inv_count++;
              }
          }
          if(arr[i] == 5){
              if(arr[j]){
                inv_count++;
              }
          }

       }
    }
             
    return inv_count;
}

void a_star(grid inp){
    set<component> closed,open,child_set,came_from;
    component inserter,current,current_child,temp;
    grid g,g_right,g_left,g_up,g_down;
    bool isRight,isLeft,isUp,isDown,isPresent;
    int h,tentative_g_score,g_score_child,came_from_count;

    came_from_count = 0;
    closed.clear();
    open.clear();

    inserter.setGscore(0);
    h = heur(inp);
    inserter.setHscore(h);
    inserter.setFscore(h);
    inserter.setGrid(inp);
    
    open.insert(inserter);
    
    

    while(!(open.empty())){
        current = *open.begin();
        g = current.getGrid();
        
        inserter = current;
                inserter.setFscore(came_from_count);
                came_from.insert(inserter);
                came_from_count++;
                
        if(g.isRightConfig()){
            //g.printfn();
            reconstruct_path(came_from);
            return;
        }
        
        open.erase(open.begin());
        
        closed.insert(current);

        g_right = g;
        g_left = g;
        g_up = g;
        g_down = g;
        isLeft = g_left.left();
        isRight = g_right.right();
        isUp = g_up.up();
        isDown = g_down.down();

        
        if(isLeft){
            // cout<<"hil\n";
            inserter.clearer();
            inserter.setGrid(g_left);
            child_set.insert(inserter);
        }

        if(isRight){
            // cout<<"hir\n";
            inserter.clearer();
            inserter.setGrid(g_right);
            inserter.setFscore(1);
            child_set.insert(inserter);
        }
        if(isUp){
            // cout<<"hiu\n";
            inserter.clearer();
            inserter.setGrid(g_up);
            inserter.setFscore(2);
            child_set.insert(inserter);
        }

        if(isDown){
            //cout<<"hid\n";
            inserter.clearer();
            inserter.setGrid(g_down);
            inserter.setFscore(3);
            child_set.insert(inserter);
        }
        
        for(set<component>::iterator itt = child_set.begin(); itt != child_set.end(); itt++){
            temp = *itt;
            // temp.getGrid().printfn();
            // cout<<"\n";
        }
        
        while(!(child_set.empty())){
            current_child = *child_set.begin();
            child_set.erase(child_set.begin());

            isPresent = false;
            for(set<component>::iterator itt = closed.begin(); itt != closed.end(); itt++){
                temp = *itt;
                if(current_child.getGrid() == temp.getGrid()){
                    isPresent = true;
                    break;
                }
            }

            if(isPresent){
                continue;
            }

            tentative_g_score = current.getGscore() + 1;

            isPresent = false;
            for(set<component>::iterator itt = open.begin(); itt != open.end(); itt++){
                temp = *itt;
                if(current_child.getGrid() == temp.getGrid()){
                    isPresent = true;
                    g_score_child = temp.getGscore();
                    current_child = temp;
                    open.erase(itt);
                    break;
                }
            }
            

            if(tentative_g_score > g_score_child){
                open.insert(current_child);
            }

            if(!isPresent || tentative_g_score < g_score_child){
                //cout<<&current;
                current_child.setGscore(tentative_g_score);
                h = heur(current_child.getGrid());
                current_child.setFscore(h+tentative_g_score);
                current_child.setHscore(h);
                open.insert(current_child);
            }

        }


    }

}


void reconstruct_path(set<component> current){
    component temp;
    for(set<component>::iterator itt = current.begin(); itt != current.end(); itt++){
        temp = *itt;
        temp.getGrid().printfn();
        cout<<"\n";
    }
}

int manhattan_distance(grid g){
	int num,x_block,y_block,x_goal,y_goal,mdistance;
	mdistance = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			num = g.getBlock(i,j);
			

			x_block = i;
			y_block = j;
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					if(num == g.getBase(k,l)){
						x_goal = k;
						y_goal = l;
						break;
					}
				}
			}
			if(num !=0)
			mdistance += abs(x_goal - x_block) + abs(y_goal - y_block);
		}
	}

	return mdistance;
}

int tile_reversal(grid g){
	int count,a,b,c,d;
	count = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			a=i-1;
			b=j;
			if(a<3 && a>=0 && b<3 && b>=0 && g.getBlock(i,j) != 0){
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
			if(a<3 && a>=0 && b<3 && b>=0 && g.getBlock(i,j) != 0){
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
			if(a<3 && a>=0 && b<3 && b>=0 && g.getBlock(i,j) != 0){
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
			if(a<3 && a>=0 && b<3 && b>=0 && g.getBlock(i,j) != 0){
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