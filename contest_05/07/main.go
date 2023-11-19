type Water struct {
	temperature int
}

func NewWater(temp int)* Water {
	return &Water{ temperature: temp }
}

func(w* Water) getTemperature() int{
return w.temperature
}

func(w* Water) setTemperature(temp int) {
	w.temperature = temp
}

type Teapot struct {
	water* Water
}

func NewTeapot(w* Water)* Teapot {
	return &Teapot{ water: w }
}

func(t* Teapot) is_boiling() bool {
    return t.water.getTemperature() >= 100
}

func(t* Teapot) heat_up(degrees int) {
    currentTemp := t.water.getTemperature()
    t.water.setTemperature(currentTemp + degrees)
}
