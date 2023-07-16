#include <stdint.h>
#include <stdio.h>
#include <cstdlib>
#include <arpa/inet.h> //for ntohl()

void add(uint8_t buf1[], uint8_t buf2[]){
	uint32_t* p1 = reinterpret_cast<uint32_t*>(buf1);
    	uint32_t n1 = ntohl(*p1);

    	uint32_t* p2 = reinterpret_cast<uint32_t*>(buf2);
    	uint32_t n2 = ntohl(*p2);

 	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1, n1, n2, n2, n1+n2, n1+n2);
}

uint8_t* read(char *file){
	FILE *file1;
	uint8_t *buffer = (uint8_t*)malloc(32 * sizeof(uint8_t));;

	file1 = fopen(file, "rb");

	fread(buffer,1,32,file1);
	fclose(file1);

	return buffer;
}

int main(int argc, char *argv[]){
	uint8_t* buf1 = read(argv[1]);
	uint8_t* buf2 = read(argv[2]);

	add(buf1,buf2);

	free(buf1);
	free(buf2);
	
	return 0;
}
