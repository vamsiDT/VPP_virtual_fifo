# VPP_virtual_fifo
This is a Virtual fifo implementation before the transmit node of VPP to limit the bandwidth utilization of the transmit interface. This is just for experimental purposes to simulate for example 1Gbps interface when you have 10Gbps interfaces.

# How to use

1) Since ip4_rewrite is the last node in VPP processing before packets are sent to transmit node, fifo is implemented in this node.

2) Check for the comment "start of extra code" , "end of extra code" to find the changed to be made in default vpp git code.

3) Parameter ALPHA in fifo.h defines the percentage of bandwidth to be utilized. For example if you want to use only upto 1Gbps bandwidth in a 10Gbps link, ALPHA will be 0.1 .

4) ip4_forward.c in vpp/src/vnet/ip directory should be modified according to the changes mentioned in step 2, fifo.h,fifo_var.h should be copied to this directory and included in ip4_forward.c
