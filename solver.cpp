#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>

#include "Cube.h"

using namespace std;

string iv = "Invalid cube -- no solutions possible. Make sure you have entered your cube's state correctly.";

int readChar() {
	while (true) {
		char c = getchar();
		if (cin.fail()) { cerr << "Input error."; exit(0); }
		c = tolower(c);
		switch (c) {
		case 'w': return 0;
		case 'r': return 1;
		case 'b': return 2;
		case 'o': return 3;
		case 'g': return 4;
		case 'y': return 5;
		}
		cout << "Input invalid. Please enter the first letter of the color: " << endl;
	}
}

void firstLayer(Cube &c) {
	/* Reference: 0 = up, 1 = right, 2 = left, 3 = front, 4 = back, 5 = down */
	if (c.getSide(0).same() && c.getSide(0).color == 0) {
		cout << "Side is already solved.";
		return;
	}

	/* Color notation:
	* 0: white
	* 1: red
	* 2: blue
	* 3: orange
	* 4: green
	* 5: yellow
	*/

	/* We want the top face to be all white */
	/* Find and place top left cubie */
	Side u = c.getSide(0);
	Side b = c.getSide(4);
	Side l = c.getSide(2);
	Side r = c.getSide(1);
	Side f = c.getSide(3);
	Side d = c.getSide(5);
	if (!u.getupper().getleft() &&
		b.getupper().getright() == 3 &&
		l.getupper().getleft() == 4) {
		// already in correct position
	}
	// check for cubie in top left of another face
	else if (!l.getupper().getleft() && u.getupper().getleft() == 3) {
		c.Up();
		c.Lp();
	}
	else if (!f.getupper().getleft() && u.getlower().getleft() == 3) {
		c.Lp();
	}
	else if (!r.getupper().getleft() && u.getlower().getright() == 3) {
		c.U();
		c.Lp();
	}
	else if (!b.getupper().getleft() && u.getupper().getright() == 3) {
		c.U2();
		c.Lp();
	}
	else if (!d.getupper().getleft() && f.getlower().getleft() == 3) {
		c.L2();
	}
	// check for cubie in top right
	else if (!l.getupper().getright() && f.getupper().getleft() == 3) {
		c.Up();
		c.Fp();
		c.Lp();
	}
	else if (!f.getupper().getright() && r.getupper().getleft() == 3) {
		c.Fp();
		c.Lp();
	}
	else if (!r.getupper().getright() && b.getupper().getleft() == 3) {
		c.U();
		c.Fp();
		c.Lp();
	}
	else if (!b.getupper().getright() && l.getupper().getleft() == 3) {
		c.U2();
		c.Fp();
		c.Lp();
	}
	else if (!d.getupper().getright() && f.getlower().getright() == 4) {
		c.R();
		c.Fp();
		c.Lp();
	}
	// check for cubie in bottom left
	else if (!l.getlower().getleft() && b.getlower().getright() == 3) {
		c.D();
		c.F();
		c.Lp();
	}
	else if (!f.getlower().getleft() && l.getlower().getright() == 3) {
		c.F();
		c.Lp();
	}
	else if (!r.getlower().getleft() && f.getlower().getright() == 3) {
		c.Dp();
		c.F();
		c.Lp();
	}
	else if (!b.getlower().getleft() && r.getlower().getright() == 3) {
		c.D2();
		c.F();
		c.Lp();
	}
	else if (!d.getlower().getleft() && b.getlower().getright() == 4) {
		c.L2();
		c.U();
	}
	// check for cubie in bottom right
	else if (!l.getlower().getright() && f.getlower().getleft() == 4) {
		c.D();
		c.F2();
		c.Lp();
	}
	else if (!f.getlower().getright() && r.getlower().getleft() == 4) {
		c.F2();
		c.Lp();
	}
	else if (!r.getlower().getright() && b.getlower().getleft() == 4) {
		c.Dp();
		c.F2();
		c.Lp();
	}
	else if (!b.getlower().getright() && l.getlower().getleft() == 4) {
		c.D2();
		c.F2();
		c.Lp();
	}
	else if (!d.getlower().getright() && u.getupper().getright() == 3) {
		c.D2();
		c.L2();
	}
	else {
		throw iv;
	}
	// check that cube was properly placed
	u = c.getSide(0);
	b = c.getSide(4);
	l = c.getSide(2);
	r = c.getSide(1);
	f = c.getSide(3);
	d = c.getSide(5);
	if (!(!u.getupper().getleft() &&
		b.getupper().getright() == 3 &&
		l.getupper().getleft() == 4)) {
		cout << endl;
		c.displayCube();
		throw "Invalid cube or logic error -- cube cannot be solved.";
	}

	/* The top left cubie is placed correctly */
	/* Find and place the top right cubie */
}

void orientFinal(Cube &c) {

}

void solveFinal(Cube &c) {

}

void beginnersMethod(Cube &c) {
	/* Solve cube using beginner's method */
	cout << endl << "To solve the first layer:" << endl;
	firstLayer(c);
	cout << endl << endl << "Your cube should now look like this:" << endl;
	c.displayCube();
	cout << endl << "To orient the final layer:" << endl;
	orientFinal(c);
	cout << endl << endl << "Your cube should now look like this:" << endl;
	c.displayCube();
	cout << endl << "To solve the final layer:" << endl;
	solveFinal(c);
	cout << endl << endl << "Your cube is solved." << endl << endl;
}

void inputTestCube(Cube &c) {
	/* for testing purposes */
	c.set(0, 4, 2, 1, 3); // up
	c.set(3, 4, 4, 2, 5); // front
	c.set(1, 0, 0, 2, 5); // right
	c.set(4, 1, 5, 3, 1); // back
	c.set(2, 1, 0, 2, 3); // left
	c.set(5, 0, 3, 5, 4); // down
}

void inputSolvedCube(Cube &c) {
	c.set(0, 0, 0, 0, 0); // up
	c.set(3, 1, 1, 1, 1); // front
	c.set(1, 2, 2, 2, 2); // right
	c.set(4, 3, 3, 3, 3); // back
	c.set(2, 4, 4, 4, 4); // left
	c.set(5, 5, 5, 5, 5); // down
}

void inputCube(Cube &c) {
	/* Inputs cube from user */

	/* Color notation:
	* 0: white
	* 1: red
	* 2: blue
	* 3: orange
	* 4: green
	* 5: yellow
	*/
	cout << "Please enter your cube's arrangement in the following format:" << endl << endl;
	cout << "    U U" << endl;
	cout << "    U U" << endl;
	cout << "L L F F R R B B" << endl;
	cout << "L L F F R R B B" << endl;
	cout << "    D D" << endl;
	cout << "    D D" << endl;
	cout << "\t\tHere, U represents the 'up' face," << endl
		<< "\t\tL represents the 'left' face," << endl
		<< "\t\tF represents the 'front' face which you're currently looking at," << endl
		<< "\t\tR represents the 'right' face," << endl
		<< "\t\tB represents the 'back' face opposite to you," << endl
		<< "\t\tand D represents the 'down' face." << endl;
	cout << endl << "Enter a letter corresponding to the color on each square." << endl
		<< "(w for white, r for red, b for blue, o for orange, g for green, or y for yellow)" << endl;
	cout << endl << "Please enter colors for the following:" << endl << endl;

	string input;
	int w, x, y, z;
	while (true) {
		cout << "Top-left on L face: ";
		w = readChar();
		cout << "Top-right on L face: ";
		cin.ignore();
		x = readChar();
		cout << "Bottom-left on L face: ";
		cin.ignore();
		y = readChar();
		cout << "Bottom-right on L face: ";
		cin.ignore();
		z = readChar();
		c.set(2, w, x, y, z);
		cout << "Top-left on U face: ";
		cin.ignore();
		w = readChar();
		cout << "Top-right on U face: ";
		cin.ignore();
		x = readChar();
		cout << "Bottom-left on U face: ";
		cin.ignore();
		y = readChar();
		cout << "Bottom-right on U face: ";
		cin.ignore();
		z = readChar();
		c.set(0, w, x, y, z);
		cout << "Top-left on F face: ";
		cin.ignore();
		w = readChar();
		cout << "Top-right on F face: ";
		cin.ignore();
		x = readChar();
		cout << "Bottom-left on F face: ";
		cin.ignore();
		y = readChar();
		cout << "Bottom-right on F face: ";
		cin.ignore();
		z = readChar();
		c.set(3, w, x, y, z);
		cout << "Top-left on R face: ";
		cin.ignore();
		w = readChar();
		cout << "Top-right on R face: ";
		cin.ignore();
		x = readChar();
		cout << "Bottom-left on R face: ";
		cin.ignore();
		y = readChar();
		cout << "Bottom-right on R face: ";
		cin.ignore();
		z = readChar();
		c.set(1, w, x, y, z);
		cout << "Top-left on B face: ";
		cin.ignore();
		w = readChar();
		cout << "Top-right on B face: ";
		cin.ignore();
		x = readChar();
		cout << "Bottom-left on B face: ";
		cin.ignore();
		y = readChar();
		cout << "Bottom-right on B face: ";
		cin.ignore();
		z = readChar();
		c.set(4, w, x, y, z);
		cout << "Top-left on D face: ";
		cin.ignore();
		w = readChar();
		cout << "Top-right on D face: ";
		cin.ignore();
		x = readChar();
		cout << "Bottom-left on D face: ";
		cin.ignore();
		y = readChar();
		cout << "Bottom-right on D face: ";
		cin.ignore();
		z = readChar();
		c.set(5, w, x, y, z);

		c.displayCube();
		if (!c.isValid()) {
			cout << "Cube is invalid. Please enter a valid cube." << endl;
			cin.ignore();
			cin.clear();
			continue;
		}
		if (c.isSolved()) {
			cout << "Cube is already solved." << endl;
			break;
		}
		cout << "Is this correct? (y/n) ";
		cin.ignore();
		getline(cin, input);
		if (cin.fail()) { cerr << "Input error."; exit(0); }
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		if (input == "y" || input == "yes" || input == "ye" || input == " y" || input == "y " || input == " y ") {
			return;
		}
	}
}

int main() {
	cout << "Welcome to the 2x2 Rubik's Cube Solver!" << endl << endl;
	string input;

	/* Initialize cube */
	Cube c;

	/* Enter loop */
	while (true) {
		/* Input cube data */
		inputTestCube(c);
		c.displayCube();
		//inputCube(c);

		/* Solve cube */
		try {
			beginnersMethod(c);
		}
		catch (string error) {
			cout << endl << error << endl;
		}
		catch (char* error) {
			cout << endl << error << endl;
		}
		catch (...) {
			cout << "Unknown error. Aborting program..." << endl;
			system("pause");
			exit(9);
		}

		cout << "Would you like to solve another cube? (y/n) ";
		getline(cin, input);
		if (cin.fail()) { cerr << "Input error."; exit(0); }
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		if (input == "y" || input == "yes" || input == "ye" || input == " y" || input == "y " || input == " y ") {
			continue;
		}
		else {
			break;
		}
	}
	return 0;
}