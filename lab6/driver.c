/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex2
 * driver.c
 * This program calculate the possible routes given an array of gas stations available within distance.
 * <Ding Lingke>
 * <T04>
 */

#include <stdio.h>
#define MAX_STATIONS 20

void readStations(int [], int [], int *, int *);
void printStations(int [], int [], int, int);
int calcPossibleRoutes(int dist[], int fuel[], int totalDist, int numStation);
int step_recur(int , int , int , int [], int [], int, int);
int could_i_reach_dest(int , int , int);

int loop_counter = 0;
int dest_count = 0;

int main() {
	int distances[MAX_STATIONS];
	int fuels[MAX_STATIONS];
	int totalDist, numStation;
	int possibleRoute;

	readStations(distances, fuels, &totalDist, &numStation); 
	printStations(distances, fuels, totalDist, numStation); 

	possibleRoute = calcPossibleRoutes(distances, fuels, totalDist, numStation);
	printf("Possible number of routes = %d\n", possibleRoute);

	return 0;
}

// Read the gas stations' distances and available fuel 
// and return the total distance and number of gas stations read.
// Note: Do not change this function
void readStations(int distances[], int fuels[], int *totalDistPtr, int *numStationPtr) {
	int i;

	printf("Enter total distance: ");
	scanf("%d", totalDistPtr);

	printf("Enter number of gas stations: ");
	scanf("%d", numStationPtr);

	printf("Enter distance and amount of fuel for each gas station:\n");
	// gasStation Array will store in such way [dist0, fuel0, dist1, fuel1, dist2, fuel2, ...]
	for (i = 0; i < *numStationPtr; i++) {
		scanf("%d %d", &distances[i], &fuels[i]);
	}
}

// Print total distance and gas stations' distances and fuel
// Note: Do not change this function
void printStations(int distances[], int fuels[], int totalDist, int numStation) {
	int i;

	printf("Total distance = %d\n", totalDist);
	printf("Number of gas stations = %d\n", numStation);
	printf("Gas stations' distances: ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", distances[i]);
	}
	printf("\n");
	printf("Gas stations' fuel amt : ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", fuels[i]);
	}
	printf("\n");
}

// Fill in description of function and brief explanation
int calcPossibleRoutes(int dist[], int fuel[], int totalDist, int numStation){
    int counter, current_location = -1, amount_of_fuel_left = 100, next_location = 0;
    counter = step_recur(next_location, amount_of_fuel_left, current_location, dist, fuel, totalDist, numStation);
    return counter;
}

int step_recur(int next_location, int amount_of_fuel_left, int current_location, int dist[], int fuel[], int totalDist, int numStation){
    int right_now;
    //printf("loop is entered for the %d times\n", loop_counter++);
    //printf("Current location: %d\n", current_location);
    //printf("Next Location: %d\n", dist[current_location + 1]);
    //printf("Amount of fuel left right now %d\n", amount_of_fuel_left);

    if (current_location == -1){
        right_now = 0;
    }else{
        right_now = dist[current_location];
    }

    if (dist[current_location + 1] - right_now <= amount_of_fuel_left && current_location + 1 < numStation){
        //printf("Decision making 1 is entered\n");
        next_location = current_location + 1;
        amount_of_fuel_left -= dist[current_location + 1] - right_now;
        //printf("Amount of fuel left if I travelled to the next location %d\n", amount_of_fuel_left);
        if (current_location == -1){
            return step_recur(current_location + 2, amount_of_fuel_left, current_location + 1, dist, fuel, totalDist, numStation) + // this is if I do not wish to refill when I am in the next waypoint
                step_recur(current_location + 2, amount_of_fuel_left + fuel[current_location + 1], current_location + 1, dist, fuel, totalDist, numStation) + // this is I want to refill when I am in the next waypoint
                could_i_reach_dest(totalDist, 0, amount_of_fuel_left);
        }else {
            //printf("Amount of fuel that I should gain if I top up now: %d\n", fuel[current_location]);
            return step_recur(current_location + 2, amount_of_fuel_left + fuel[current_location], current_location + 1, dist, fuel, totalDist, numStation) + // this is I want to refill when I am in the next waypoint
                step_recur(current_location + 2, amount_of_fuel_left, current_location + 1, dist, fuel, totalDist, numStation) + // this is if I do not wish to refill when I am in the next waypoint
                could_i_reach_dest(totalDist, dist[current_location], amount_of_fuel_left) + 
                could_i_reach_dest(totalDist, dist[current_location], amount_of_fuel_left + fuel[current_location]);
        }
    }else{
        //printf("this is gonna end\n");
        if (current_location == -1){
            return could_i_reach_dest(totalDist, 0, amount_of_fuel_left);
        }
        else {
            return could_i_reach_dest(totalDist, dist[current_location], amount_of_fuel_left) + 
                could_i_reach_dest(totalDist, dist[current_location], amount_of_fuel_left + fuel[current_location]);
        }
    }
}

int could_i_reach_dest(int destination, int current_location, int amount_of_fuel_left){
    //printf("Dest loop is entered! for the %d times\n", dest_count++);
    if ( (destination - current_location) <= amount_of_fuel_left){
        return 1;
    }else{
        return 0;
    }
}