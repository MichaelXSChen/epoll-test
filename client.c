#include <sys/socket.h>
#include <linux/types.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


// void *serve(void * arg){
// }






// static int main_cl(int argc, char **argv)
// {
//     int sk, port, ret, val = 1, rval;
//     struct sockaddr_in addr;

//     sk = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//     if (sk < 0) {
//         perror("Can't create socket");
//         return -1;
//     }


//     port = atoi(argv[2]);
//     printf("Connecting to %s:%d\n", argv[1], port);
//     memset(&addr, 0, sizeof(addr));
//     addr.sin_family = AF_INET;
//     ret = inet_aton(argv[1], &addr.sin_addr);
//     if (ret < 0) {
//         perror("Can't convert addr");
//         return -1;
//     }
//     addr.sin_port = htons(port);

//     ret = connect(sk, (struct sockaddr *)&addr, sizeof(addr));
//     if (ret < 0) {
//         perror("Can't connect");
//         return -1;
//     }
//     int rd, wr;
//     char buf[1024];



//      while (1) {
//         rd = read(sk, buf, sizeof(buf));
//         if (!rd)
//             break;

//         if (rd < 0) {
//             perror("Can't read socket");
//             return 1;
//         }

//         wr = 0;
//         while (wr < rd) {
//             int w;

//             w = write(sk, buf + wr, rd - wr);
//             if (w <= 0) {
//                 perror("Can't write socket");
//                 return 1;
//             }

//             wr += w;
//         }
//     }
    
// }

#define NUMCLI 10

int main(int argc, char** argv){

	struct sockaddr_in addr;

	int fd[NUMCLI];
	int i;
	int port, ret;
	for (i = NUMCLI-1; i >=0; i--){
		fd[i] = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    	if (fd[i] < 0) {
        perror("Can't create socket");
        return -1;
    	}
    	port = atoi(argv[2]);
	    printf("[%d]:Connecting to %s:%d\n", i, argv[1], port);
	    memset(&addr, 0, sizeof(addr));
	    addr.sin_family = AF_INET;
	    ret = inet_aton(argv[1], &addr.sin_addr);
	    if (ret < 0) {
	        perror("Can't convert addr");
	        return -1;
	    }
	    addr.sin_port = htons(port);

	    ret = connect(fd[i], (struct sockaddr *)&addr, sizeof(addr));
	    if (ret < 0) {
	        perror("Can't connect");
	        return -1;
	    }
	}
	char input[NUMCLI];
	for( i= 0; i<NUMCLI; i++){
		input[i]= '0'+i;
	}
	while(1){
		for (i = 0; i<NUMCLI; i++){
			write(fd[i], &input[i], 1);
		}
		usleep(5000);
	}


}