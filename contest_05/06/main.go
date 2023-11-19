type Cat struct {
	alive bool
}
func(c* Cat) is_alive() bool{
	return c.alive
}
type Box struct {}

func(b* Box) open()* Cat {
	rand.Seed(time.Now().UnixNano())	
    alive := rand.Intn(2) == 1
	return &Cat{ alive: alive }
}
