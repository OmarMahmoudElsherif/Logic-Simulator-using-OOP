# Logic Simulator

Design a simple logic simulator that provides a mechanism to run and simulate logic circuits then find the desired outputs for different designs.

Class called "Node" has name and value data members to represent each node in the circuit.

Class "Node" have the following Specifications:

1-Default and non-default Constructor.

2-Setters and getters.

3-methods called AND() / OR() / XOR() to perform the logical operation between two nodes objects.



class Called "Gate" which has two input nodes and one output node data members

Class Gate support the following methods:

1-Default and non-Default Constructors.

2-getters and setters for its nodes.

3-Implementation of gate types AND / OR / NAND / NOR / XOR / XNOR / NOT.

4-function simulateGate() returns the logic value of the gate according to its type.



Class called "Simulator" which accpets all types of gates then calculate circuits outputs, It has the following specifications:

1-array of pointers to Gate and array of pointers to Node.

2-Method postGate() accepts a pointer to a created gate to insert it into the array.

3-Method postNode() accepts a pointer to a created node to insert it into the array.

4-Method FindNode() accepts a string node's name to find it in the container and return its address.

5-Method startSimulate() start the simulation for each gate by looping over the gates container.




Class called "GateGenerator" that generates the nodes and all sepcified gates from the input then post them to the simulator.

"GateGenerator" class have the following specifications:

1-Function parseInput() reads the inputs and parses each keyword ("SIM"/"OUT",..) to the appropriate logic.

2-Function createNode() creates a node and return its address.

3-Function createGate() creates a (AND,OR,...) gates according to the input and return its address.



# Input Format

The input follows these formats:

gate type (such as AND/OR gate)

The inputs and output symbols

Write "SET" values to the inputs (either 0 or 1)

Write "SIM" to start simulation

Write "OUT" to view the output of a specific node or "OUT ALL" to view all nodes' values



# Output Format

Output format should be the node symbol: node Value.


# Sample Input :
AND A B D

OR C D E

SET A 1

SET B 0 

SET C 1

SIM 

OUT E

OUT ALL


# Sample Output:

E: 1

A: 1

B: 0

D: 0

C: 1

E: 1

