lmcrack:
	g++ -Wall -O3 -fomit-frame-pointer -funroll-loops lmcrack.cpp -olmcrack -lcrypto -lpthread
sse:
	g++ -Wall -DSSE2 -msse2 -O3 -fomit-frame-pointer -funroll-loops lmcrack.cpp -olmcrack -lcrypto -lpthread

avx:
	g++ -Wall -DAVX2 -mavx2 -O3 -fomit-frame-pointer -funroll-loops lmcrack.cpp -olmcrack -lcrypto -lpthread

asm:
	yasm -felf64 crack_lm5.asm -osetkey2.o
	g++ -no-pie -Wall -DAVX2 -mavx2 -O3 -fomit-frame-pointer -funroll-loops lmcrack.cpp -olmcrack -lcrypto -lpthread setkey2.o
clean:
	rm -rf *.o lmcrack
