class component{
	private:
		grid a;
		int g_score,f_score,h;
	public:
		component(){
			g_score = 0;
			f_score = 0;
			h = 0;
		}

		void setGscore(int g){
			g_score = g;
		}

		void setFscore(int f){
			f_score = f;
		}

		void setHscore(int g){
			h = g;
		}

		void setGrid(grid g){
			a = g;	
		}

		int getGscore(){
			return g_score;
		}

		int getFscore(){
			return f_score;
		}

		int getHscore(){
			return h;
		}

		grid getGrid(){
			return a;
		}


		//operator overloaing starts from here

		bool operator== (component b) const{
			if(f_score == b.getFscore())
				return true;
			else
				return false;
		}

		bool operator> (component b) const{
			if(f_score > b.getFscore())
				return true;
			else
				return false;
		}

		bool operator< (component b) const{
			if(f_score < b.getFscore())
				return true;
			else
				return false;
		}

		bool operator= (component b){
			f_score = b.getFscore();
			g_score = b.getGscore();
			h = b.getHscore();
			a = b.getGrid();
		}

		void clearer(){
			a.clearer();
			g_score = 0;
			f_score = 0;
			h = 0;
		}


};
