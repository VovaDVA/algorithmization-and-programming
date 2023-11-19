class Water {
	private:
    	int temperature;
        
    public:
    	Water(int temp) : temperature(temp) {}    
    	int getTemperature() {        
        	return temperature;
    	}   	 
    	void setTemperature(int temp) {        
        	temperature = temp;
   	 	}
};
class Teapot {
	private:    
    	Water& water;
	public:
    	Teapot(Water& w) : water(w) {}    
    	bool is_boiling() {   
        	return water.getTemperature() >= 100;
    	}    
    	void heat_up(int degrees) {        
        	int currentTemp = water.getTemperature();
        	water.setTemperature(currentTemp + degrees);    
        }
};
