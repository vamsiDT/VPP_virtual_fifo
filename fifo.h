#include <vlib/vlib.h>
#include <vnet/ip/ip.h>
#include <vnet/vnet.h>
#include <stdlib.h>
#include <math.h>
#ifndef FIFO_H
#define FIFO_H
#define ALPHA 0.1 //The link is 10Gpbs. To limit traffic upto 1Gbps Alpha will be 0.1
extern int old_t;
extern int t;
extern int threshold;
extern u32 fifoqueue;

always_inline u8 fifo(u16 pktlen){
	u8 drop;
	if(fifoqueue<=threshold){
		fifoqueue+=pktlen;
        drop=0;
    }
	else
		drop=1;
return drop;
}

#endif /*FIFO_H*/
