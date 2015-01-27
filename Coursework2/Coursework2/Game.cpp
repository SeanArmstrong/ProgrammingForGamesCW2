#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include "Circle.h"
#include "Square.h"
#include <set>

void game();
void test();
float randomFloat(float minBound, float maxBound);

/*
* Sets the grids dimensions to be
* GRID_LENGTH by GRID_LENGTH
*/
const float GRID_LENGTH = 100.0f;
const float MAX_LENGTH_OR_RADIUS = 5.0f;

int main(void){

	//test();
	game();

	_CrtDumpMemoryLeaks();
	int x;
	std::cin >> x;
	return 0;
}

void game(){
	// Set up variables
	int const NUMBER_OF_SHAPES = 1001;
	int shapesLeft = NUMBER_OF_SHAPES;
	int round = 0;

	// Setup Shapes
	/* Storing shape pointers within an vector to allow dyanmic sizing
	* easy addition and deletion.
	*/
	std::vector<Shape*> shapes;
	for (int i = 0; i < NUMBER_OF_SHAPES; i++){
		if (i % 2 == 0){
			//Squares
			shapes.push_back(new Square(randomFloat(1.0f, MAX_LENGTH_OR_RADIUS), Vector2(randomFloat(0, GRID_LENGTH), randomFloat(0, GRID_LENGTH))));
		}
		else {
			//Circles
			shapes.push_back(new Circle(randomFloat(1.0f, MAX_LENGTH_OR_RADIUS), Vector2(randomFloat(0, GRID_LENGTH), randomFloat(0, GRID_LENGTH))));
		}
	}

	// Run game
	while (shapesLeft > 1){
		/* Set used for colliding indexes
		* This maintains that there are not duplcates and is sorted from lowest to highest.
		* This means when im reverse iterating through the set i can be sure the indexes
		* below that of the one I am deleteing will not change.
		* A list could of also been used but it is not sorted nor does it check for duplicates
		* however it can be faster for searching, insertions and deletions
		*/
		std::set<int> collidingIndexes;

		//Move all shapes
		for (int i = 0; i < shapesLeft; i++){
			float randomX = randomFloat(0, GRID_LENGTH);
			float randomY = randomFloat(0, GRID_LENGTH);

			shapes[i]->move(Vector2(randomX, randomY));
		}

		int collisionsThisRound = 0;

		for (int i = 0; i < shapesLeft; i++){
			bool overlap = false;
			for (int j = i + 1; j < shapesLeft; j++){
				if (shapes[i]->overlap((*shapes[j]))){
					std::cout << "\nCollision!\n" << *shapes[i] << "\nCollides with\n" << *shapes[j] << std::endl;
					collidingIndexes.insert(j);
					collisionsThisRound++;
					overlap = true;
				}
			}
			// If i has overlapped it needs to be added
			if (overlap == true){
				collidingIndexes.insert(i);
			}
		}

		/*
		* Revere iterate so indexs below the one you are currently looking 
		* will be maintains (and not shifted) when deleting
		*/
		std::set<int>::reverse_iterator rit;
		for (rit = collidingIndexes.rbegin(); rit != collidingIndexes.rend(); ++rit){
			delete shapes[*rit];
			shapes.erase(shapes.begin() + *rit);
			shapesLeft--;
		}

		if (collisionsThisRound > 0){
			std::cout << "\nCollisions this round: " << collisionsThisRound << std::endl;
			std::cout << "Shapes Left: " << shapesLeft << std::endl;
		}
		round++;
	}
	std::cout << "END GAME: Rounds taken = " << round << std::endl;

	/*
	* Tidy up memory if one shape remains
	*/
	if (shapes.size() > 0){
		std::cout << "Last Shape: " << *shapes[0] << std::endl;
		delete shapes[0];
	}
	else{
		std::cout << "No Shapes Left" << std::endl;
	}
}

// Random number between 0 and 100.0f
float randomFloat(float minBound, float maxBound){
	return (((maxBound-minBound)*((float)rand() / RAND_MAX)) + minBound);
}

void test(){

	// Test
	Vector2 vector = Vector2();

	Circle circle1 = Circle(4.0f, vector);
	std::cout << circle1.getRadius() << "\n";

	Circle circle2 = Circle(2.0f, Vector2(5.0f, 2.0f));

	Square square1 = Square(2, vector);
	std::cout << square1.getLength() << "\n";

	Square square2 = Square(6, vector);

	std::cout << square1.overlap(square2) << "\n";
	std::cout << circle1.overlap(circle2) << "\n";


	std::cout << "Square Circle Overlapping" << "\n";
	std::cout << square1.overlap(circle1) << "\n";
	std::cout << circle1.overlap(square1) << "\n";

	std::cout << circle2.overlap(square1) << "\n";
	std::cout << square1.overlap(circle2) << "\n";

	//Edge Cases
	Square square3 = Square(2, vector);
	Square square4 = Square(2, Vector2(2.0001f, 0));
	std::cout << square3.overlap(square4) << std::endl;

	Circle circle3 = Circle(2, vector);
	Circle circle4 = Circle(2, Vector2(4.0001f, 0));
	std::cout << circle3.overlap(circle4) << std::endl;

	
	Square square5 = Square(2, vector);
	Circle circle5 = Circle(1, Vector2(2.0f, 1.001f));
	std::cout << circle5.overlap(square5);

}