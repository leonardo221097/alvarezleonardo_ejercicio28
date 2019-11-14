ejercicio28.png: ejercicio28.dat 
	python ejercicio28.py

ejercicio28.dat: ejercicio28.x
	./ejercicio28.x > ejercicio28.dat
	
ejercicio28.x : ejercicio28.cpp
	c++ ejercicio28.cpp -o ejercicio28.x







