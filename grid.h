class grid{
	private:
		int block[3][3],base[3][3],zero_position;
	public:
		grid(){
			block[0][0] = 1;
			block[0][1] = 2;
			block[0][2] = 3;
			block[1][0] = 8;
			block[1][1] = 0;
			block[1][2] = 4;
			block[2][0] = 7;
			block[2][1] = 6;
			block[2][2] = 5;
			//base grid for comparison
			base[0][0] = 1;
			base[0][1] = 2;
			base[0][2] = 3;
			base[1][0] = 8;
			base[1][1] = 0;
			base[1][2] = 4;
			base[2][0] = 7;
			base[2][1] = 6;
			base[2][2] = 5;

			zero_position = 11;

		}

		void setBlock(int inp[][]){
			//this is supposz
        	block[0][0] = 1;
			block[0][1] = 2;
			block[0][2] = 3;
			block[1][0] = 8;
			block[1][1] = 0;
			block[1][2] = 4;
			block[2][0] = 7;
			block[2][1] = 6;
			block[2][2] = 5;
		}

		bool left(){
 	    	int tmp1,tmp2,co_ordinate11,co_ordinate12,co_ordinate21,co_ordinate22;

 	    	if(zero_position == 0 || zero_position == 11 || zero_position == 20){
 	    		return false;
 	    	}
 	    	else{
 	    		tmp2 = zero_position - 1;
 	    		co_ordinate11 = position_to_coordinate1(zero_position);
 	    		co_ordinate12 = position_to_coordinate2(zero_position);
 	    		co_ordinate21 = position_to_coordinate1(tmp2);
 	    		co_ordinate22 = position_to_coordinate2(tmp2);
 	    		tmp1 = block[co_ordinate11][co_ordinate12];
 	    		block[co_ordinate11][co_ordinate12] = block[co_ordinate21][co_ordinate22];
 	    		block[co_ordinate21][co_ordinate22] = tmp1;
 	    		zero_position = zero_position - 1;
 	    		return true;
 	    	}
		}

		bool right(){
			int tmp1,tmp2,co_ordinate11,co_ordinate12,co_ordinate21,co_ordinate22;

 	    	if(zero_position == 2 || zero_position == 12 || zero_position == 22){
 	    		return false;
 	    	}
 	    	else{
 	    		tmp2 = zero_position + 1;
 	    		co_ordinate11 = position_to_coordinate1(zero_position);
 	    		co_ordinate12 = position_to_coordinate2(zero_position);
 	    		co_ordinate21 = position_to_coordinate1(tmp2);
 	    		co_ordinate22 = position_to_coordinate2(tmp2);
 	    		tmp1 = block[co_ordinate11][co_ordinate12];
 	    		block[co_ordinate11][co_ordinate12] = block[co_ordinate21][co_ordinate22];
 	    		block[co_ordinate21][co_ordinate22] = tmp1;
 	    		zero_position = zero_position - 1;
 	    		return true;
 	    	}
		}

		bool up(){
			int tmp1,tmp2,co_ordinate11,co_ordinate12,co_ordinate21,co_ordinate22;

 	    	if(zero_position == 0 || zero_position == 1 || zero_position == 2){
 	    		return false;
 	    	}
 	    	else{
 	    		tmp2 = zero_position - 10;
 	    		co_ordinate11 = position_to_coordinate1(zero_position);
 	    		co_ordinate12 = position_to_coordinate2(zero_position);
 	    		co_ordinate21 = position_to_coordinate1(tmp2);
 	    		co_ordinate22 = position_to_coordinate2(tmp2);
 	    		tmp1 = block[co_ordinate11][co_ordinate12];
 	    		block[co_ordinate11][co_ordinate12] = block[co_ordinate21][co_ordinate22];
 	    		block[co_ordinate21][co_ordinate22] = tmp1;
 	    		zero_position = zero_position - 1;
 	    		return true;
 	    	}
		}

		bool down(){
			int tmp1,tmp2,co_ordinate11,co_ordinate12,co_ordinate21,co_ordinate22;

 	    	if(zero_position == 20 || zero_position == 21 || zero_position == 22){
 	    		return false;
 	    	}
 	    	else{
 	    		tmp2 = zero_position + 10;
 	    		co_ordinate11 = position_to_coordinate1(zero_position);
 	    		co_ordinate12 = position_to_coordinate2(zero_position);
 	    		co_ordinate21 = position_to_coordinate1(tmp2);
 	    		co_ordinate22 = position_to_coordinate2(tmp2);
 	    		tmp1 = block[co_ordinate11][co_ordinate12];
 	    		block[co_ordinate11][co_ordinate12] = block[co_ordinate21][co_ordinate22];
 	    		block[co_ordinate21][co_ordinate22] = tmp1;
 	    		zero_position = zero_position - 1;
 	    		return true;
 	    	}
		}

		bool isRightConfig(){
			bool ret;
			int i,j;
			ret == true;
 			for(i=0;i<3;i++){
 				for(j=0;j<3;j++){
 					if(!(block[i][j] == base[i][j])){
 						ret = false;
 					}
 				}
 				if(ret == false){
 					break;
 				}
 			}

 			return ret;
		}

		int position_to_coordinate1(int zp){
			int r;
			r = zp/10;
			return r;
		}

		int position_to_coordinate2(int zp){
			int r;
			r = zp%10;
			return r;
		}

        //operator overloading

        bool operator== (ValueExpr a) const{
		
	}

        bool operator= (ValueExpr a) {
	
	}
};
