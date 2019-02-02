lmcrack:
	g++ -Wall -O3 -fomit-frame-pointer -funroll-loops lmcrack.cpp -olmcrack -lcrypto -lpthread
sse:
	g++ -Wall -DSSE2 -msse2 -O3 -fomit-frame-pointer -funroll-loops lmcrack.cpp -olmcrack -lcrypto -lpthread

avx:
	g++ -Wall -DAVX2 -mavx2 -O3 -fomit-frame-pointer -funroll-loops lmcrack.cpp -olmcrack -lcrypto -lpthread

clean:
	rm -rf *.o lmcrack
