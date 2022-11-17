# High-Level-Synthesis

Multiple-Input Multiple-Output (MIMO) increases the capacity of a radio link by exploiting multipath propagation by using multiple transmitting and receiving antennas. It is becoming increasingly common as part of wireless communications standards, including Wireless Local Area Network (WLAN), Evolved High Speed Packet Access (HSPA+),
and Long-Term Evolution (LTE). In Fifth-Generation (5G) wireless systems, the short wavelengths result in smaller antenna dimensions, and the base station equipped with hundreds of antenna elements that serve tens of user equipment simultaneously in the same frequency band leads to MIMO as massive which provides significantly higher spectral efficiency and link reliability than traditional, small-scale MIMO systems. However, the price for the enhanced spectral efficiency is increased signal processing complexity which grows exponentially with modulation alphabets and antennas in the system with optimal Maximum Likelihood (ML) algorithms. In the MIMO uplink phase, data at the base station are recovered with less complexity using near-optimal linear equalizers, such as Zero-Forcing (ZF) or Minimum Mean Square Error (MMSE). However, These equalization schemes typically rely on centralized processing which results in excessive computational complexity and interconnects bandwidth between the baseband processing unit and the Radio Frequency (RF) chains. Equalizers based on a decentralized architecture can mitigate these complexity and bandwidth bottlenecks.

Highly Configurable Decentralized Massive MIMO Detector Design using High-Level Synthesis

* The detection algorithm has been programmed in C-code. A netlist (VHDL/Verilog/SystemC) has been generated by synthesizing the C-code using High-Level Synthesis in the Vivado HLS suite.
* A testbench in C-code has been built to provide MIMO uplink received data.
* The testbench has been expanded with the C model of the massive MIMO detector based on the Gauss-Seidel binary tree structure. It has also been made self-checking. It checks if the output of the software model and the synthesized C-code are identical.
* The design has been optimized to reduce the latency using different HLS directives and arbitrary precision fixed-point data types. The systolic array architectures have beenappiled for parallel operation. The design can easily be configured in the number of antennas, the number of users, and the cluster size.
