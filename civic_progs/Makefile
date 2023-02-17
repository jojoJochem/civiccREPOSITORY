output: test_main.o core.o coreio.o array.o
	./civrun test_main.o -o output

test_main.o: test_main.cvc
	./civrun test_main.cvc

core.o: core.cvc core.h
	 ./civrun core.cvc

coreio.o: coreio.cvc coreio.h
	 ./civrun coreio.cvc

array.o: array.cvc array.h
	./cuvrun array.cvc

clean:
	rm *.o output