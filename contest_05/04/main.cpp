class Point {private:
    double x, y, r, a;
    public:
    	Point(double x, double y) : x(x), y(y) {        
    		r = sqrt(x * x + y * y);
        	a = atan2(y, x);    
    	}	
    	double get_x() const {
        	return x;    
    	}
    	double get_y() const {
        	return y;    
    	}
    	double get_r() const {
        	return r;    
    	}
    	double get_a() const {
        	return a;    
    	}
    	void set_x(double new_x) {
        	x = new_x;        
    		r = sqrt(x * x + y * y);
        	a = atan2(y, x);    
    	}
    	void set_y(double new_y) {
        	y = new_y;       
    		r = sqrt(x * x + y * y);
        	a = atan2(y, x);    
    	}
    	void set_r(double new_r) {
        	r = new_r;        
    		x = r * cos(a);
        	y = r * sin(a);    
    	}
    	void set_a(double new_a) {
        	a = new_a;        
    		x = r * cos(a);
        	y = r * sin(a);
    	}
};
