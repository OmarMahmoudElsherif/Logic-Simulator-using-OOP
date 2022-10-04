
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



class Node{

	/*
	 * Class Node : has name and data value
	 * Setters : SetName -> sets the name , SetData -> sets the data
	 * Getters:  GetName -> gets the name , GetData -> gets the data
	 *
	 * Member function:
	 *  AND() : make bit wise AND operation between two nodes
	 *  OR() : make bit wise OR operation between two nodes
	 *  XOR() : make bit wise XOR operation between two nodes
	 */


private:
	string name;
	int data;

public:
	Node() :data() {}
	Node(string name,int data) : name(name),data(data) {}

	friend ostream& operator<<(ostream& out, const Node& ob) {
		out <<ob.name<<": "<<ob.data<<endl;
		return out;
	}

	void SetName(string setname){
		name=setname;
	}
	void SetData(int setdata){
		data=setdata;
	}
	string GetName(){
		return name;
	}
	int GetData(){
		return data;
	}
	int AND(Node in)
	{
		return data & in.data;
	}
	int OR(Node in)
	{
		return data | in.data;
	}
	int XOR(Node in)
	{
		return data ^ in.data;
	}

};








class Gate {
	/*
	 * Class Gate: has two input nodes, one output node and operation name
	 *
	 * Setters :
	 * SetInputNodeName -> sets the input name whether input1 or input2
	 * SetInputNode -> sets the  input data whether input1 or input2
	 * SetOutputNodeName -> sets the output name
	 * SetOutputNode -> sets the  output data
	 *
	 * Getters
	 * GetInputNodeName,GetInputNode -> gets the input name/data whether input1 or input2
	 * returnInput, returnOutput -> return the whole input/output node
	 * GetOutputNodeName,GetOutputNode -> gets the output name/data

	 * Member function:
	 *  Gate_AND(), Gate_OR(), Gate_XOR(), Gate_NOR(), Gate_NAND(), Gate_XNOR()
	 *  these function make bitwise operation according to their function
	 *
	 *  simulateGate() --> takes the gate as input parameter and makes the
	 *  				   required gate operation and return the value of output.
	 */

private:
	Node input1;
	Node input2;
	Node output;
	string operation;
public:
	Gate() :input1(),input2(),output(){ }
	Gate(int in1,int in2) {
		input1.SetData(in1);
		input2.SetData(in2);
		output.SetData(0);
	}
	void SetInput1Node(int in1)
	{
		input1.SetData(in1);
	}
	void SetInput1Name(string in1)
	{
		input1.SetName(in1);
	}

	void SetInput2Node(int in2)
	{
		input2.SetData(in2);
	}
	void SetInput2Name(string in2)
	{
		input2.SetName(in2);
	}
	void SetOutputNode(int out)
	{
		output.SetData(out);
	}
	void SetOutputNodeName(string out)
	{
		output.SetName(out);
	}
	void SetOperationName(string s)
	{
		operation=s;
	}
	string GetOperationName()
	{
		return operation;
	}
	Node returnInput1()
	{
		return input1;
	}
	Node returnInput2()
	{
		return input2;
	}
	Node returnOutput()
	{
		return output;
	}



	int GetInput1Node()
	{
		return input1.GetData();
	}
	string GetInputNode1Name()
	{
		return input1.GetName();
	}
	int GetInput2Node()
	{
		return input2.GetData();
	}
	string GetInputNode2Name()
	{
		return input2.GetName();
	}
	int GetOutputNodeData()
	{
		return output.GetData();
	}
	string GetOutputNodeName()
	{
		return output.GetName();
	}


	int Gate_AND(Node in1,Node in2)
	{
		return in1.AND(in2);
	}
	bool Gate_NAND(Node in1,Node in2)
	{
		return !in1.AND(in2);
	}
	int Gate_OR(Node in1,Node in2)
	{
		return in1.OR(in2);
	}
	bool Gate_NOR(Node in1,Node in2)
	{
		return !in1.OR(in2);
	}
	int Gate_XOR(Node in1,Node in2)
	{
		return in1.XOR(in2);
	}
	bool Gate_XNOR(Node in1,Node in2)
	{
		return !in1.XOR(in2);
	}
	bool Gate_NOT(Node in)
	{
		return !in.GetData();
	}

	int simulateGate(Gate &gate)
	{
		if(gate.operation=="AND")
			gate.output.SetData(gate.Gate_AND(gate.input1, gate.input2));
		else if(gate.operation=="OR")
			gate.output.SetData(gate.Gate_OR(gate.input1, gate.input2));
		else if(gate.operation=="NOR")
			gate.output.SetData(gate.Gate_NOR(gate.input1, gate.input2));
		else if(gate.operation=="XOR")
			gate.output.SetData(gate.Gate_XOR(gate.input1, gate.input2));
		else if(gate.operation=="XNOR")
			gate.output.SetData(gate.Gate_XNOR(gate.input1, gate.input2));
		else if(gate.operation=="NAND")
			gate.output.SetData(gate.Gate_NAND(gate.input1, gate.input2));
		else if(gate.operation=="NOT")
			gate.output.SetData(gate.Gate_NOT(gate.input1));
		else
		{
			cout<<"Invalid Gate\n";
		}
		return gate.output.GetData();


		{
			gate.output.GetData();
		}



	}
};


class Simulator{

	/* Class Simulator: has vector array of pointers to gates and nodes
	 *
	 *	Member Functions:
	 *	startSimulate() -> starts the simulation for all gates entered
	 *	OUTPUTSIM() -> outputs all nodes names and values
	 *	OUTPUTSPECIFIC() -> output a specific node only
	 *	postGate() -> insert and pointer to gate in vector array "gates"
	 *	postNode() -> insert and pointer to node in vector array "nodes"
	 *	FindNode() -> find a specific node in vector array nodes and return location
	 *
	 */
private:
	Simulator() {}
public:
	vector<Gate*>gates;
	vector<Node*>nodes;

	static Simulator& createSim() 	// only one object can be created from this class
	{
		static Simulator Sim;
		return Sim;
	}
	void postGate(Gate* ptrgate)
	{
		gates.push_back(ptrgate);
	}
	void postNode(Node* ptrnode)
	{
		nodes.push_back(ptrnode);
	}
	int FindNode(string nodename)
	{
		int location=0;
		for(auto i : nodes)
		{
			if((*i).GetName()==nodename)
				return location;
			location++;
		}
		return -1; 	// not found
	}

	void startSimulate(Simulator &sim)
	{
		string outputname;
		int outputvalue;
		for(auto x : gates)
		{
			outputvalue=(*x).simulateGate(*x);
			outputname=(*x).GetOutputNodeName();

			/* Update value of nodes after simulation each gate respectively*/
			for(auto i:gates)
			{
				if ( (*i).GetOutputNodeName()==outputname  )
					(*i).SetOutputNode(outputvalue);

				else if ( (*i).GetInputNode1Name()==outputname  )
					(*i).SetInput1Node(outputvalue);

				else if ( (*i).GetInputNode2Name()==outputname  )
					(*i).SetInput2Node(outputvalue);
			}
		}

	}

	void OUTPUTSIM()
	{
		string st;
		for(auto x : gates)
		{
			size_t found = st.find((*x).GetInputNode1Name());
			// if not found
			if(found == string::npos)
			{
				cout<<(*x).returnInput1();
				st+=(*x).GetInputNode1Name();
			}

			found=st.find((*x).GetInputNode2Name());
			// if not found
			if(found == string::npos)
			{
				cout<<(*x).returnInput2();
				st+=(*x).GetInputNode2Name();
			}

			found=st.find((*x).GetOutputNodeName());
			// if not found
			if(found == string::npos)
			{
				cout<<(*x).returnOutput();
				st+=(*x).GetOutputNodeName();
			}
		}
	}

	void OUTPUTSPECIFIC(string target)
	{

		for(auto x : gates)
		{
			if((*x).GetInputNode1Name()==target)
				cout<<(*x).returnInput1();
			else if((*x).GetInputNode2Name()==target)
				cout<<(*x).returnInput2();
			else if((*x).GetOutputNodeName()==target)
				cout<<(*x).returnOutput();
		}
	}



};


class GateGenerator{

	/*
	 * Function parseInput() reads the inputs and parses each keyword ("SIM"/"OUT",..) to the appropriate logic.
	 * Function createNode() creates a node and return its address.
	 * Function createGate() creates a (AND,OR,...) gates according to the input and return its address
	 * Function UpdateGateNodes() updates the gates vector after inserting value via SET operation]
	 * Function SET() sets the specific node according to given value
	 * Function createGate() creates new gate to be inserted in vector array gates
	 *
	 */

public:
	void parseInput(Simulator &sim)
	{
		string obj;
		cin>>obj;
		while(obj!= "SIM")
		{
			if(obj != "SET" && obj != "OUT")
			{
				sim.postGate(createGate(obj,sim));

			}

			if(obj =="SET")
			{
				Node *test=SET(sim);
				if (test==nullptr)
				{
					cin>>obj;
					continue;
				}
				else
				{
					sim.postNode(test);
					UpdateGateNodes(sim);		// after put new node update similar one in gate node
				}
			}

			cin>>obj;
		}

		/*   SIM is read here   */
		sim.startSimulate(sim);


		cin>>obj;		// OUT

		string obj2;
		while(obj=="OUT")
		{
			cin>>obj2;
			if(obj2=="ALL")
			{
				sim.OUTPUTSIM();
				break;
			}
			else
				sim.OUTPUTSPECIFIC(obj2);
			cin>>obj;
		}

	}

	void UpdateGateNodes(Simulator &sim)
	{
		for(auto x: sim.gates)
		{
			for(auto y: sim.nodes)
			{

				if((*y).GetName()==(*x).GetInputNode1Name())
				{
					(*x).SetInput1Node((*y).GetData());
				}
				else if((*y).GetName()==(*x).GetInputNode2Name())
				{
					(*x).SetInput2Node((*y).GetData());
				}
			}
		}
	}


	Node* SET(Simulator sim)
	{
		int location=-1;
		string input;
		cin>>input;
		int value;
		cin>> value;
		Node *n= new Node();
		location= sim.FindNode(input);
		if(location == -1)		// not found
		{
			(*n).SetData(value);
			(*n).SetName(input);
		}
		else		// found at location--> change value
		{
			sim.nodes.at(location)->SetData(value);
			delete n;
			return nullptr;
		}
		return n;
	}


	Gate* createGate(string typeofgate,Simulator &sim)
	{
		Gate *g=new Gate();
		string input,output;
		(*g).SetOperationName(typeofgate);

		bool isNot=false;
		if(typeofgate=="NOT")	// if NOT gate this it has only 1 input
			isNot=true;

		cin>>input;
		(*g).SetInput1Name(input);

		if(!isNot)		// if gate is not a NOT gate this is has 2 inputs
		{
			cin>>input;
			(*g).SetInput2Name(input);
		}
		cin>>output;
		(*g).SetOutputNodeName(output);

		return g;
	}

};



int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	Simulator& sim= Simulator::createSim();
	GateGenerator gategen;
	gategen.parseInput(sim);

	return 0;
}
