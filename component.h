class component{
	private:
		grid a;
		int g_score,f_score,h;
	public:
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

		bool operator== (component a) const{
			if(f_score == a.getFscore())
				return true;
			else
				return false;
		}

		bool operator> (component a) const{
			if(f_score > a.getFscore())
				return true;
			else
				return false;
		}

		bool operator< (component a) const{
			if(f_score < a.getFscore())
				return true;
			else
				return false;
		}

		bool operator= (component a){
			f_score = a.getFscore();
			g_score = a.getGscore();
			h = a.getHscore();
			a = a.getGrid();
		}


};
