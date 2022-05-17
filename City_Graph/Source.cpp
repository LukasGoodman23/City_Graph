#include <iostream>
#include <string>

using namespace std;

void getNeighbor(int);

void getGrid();

int totalDistance(int, int);

int tempEnd;

int total;

string names[15]={ "Mohave", "Coconino", "Navajo", "Apache", "Greenlee", "Cochise", "Santa Cruz", "Pima", "Pinal", "Graham", "Gila", "Yavapai", "La Paz", "Yuma", "Maricopa" };
int adj[15][15];

int main() {

    //populate the weight array
    getGrid();

    //print the array
    for (int i= 0; i < 15; i++)
    {
        for (int j= 0; j < 15; j++)
        {
            cout << adj[i][j] << "\t";
        }
        cout << endl;
    }

    //print out all the neighbors of Coconino
    getNeighbor(1);

    //print the distance of a path between Mohave and Santa Cruz and the path taken
    cout << totalDistance(0, 6);
}

void getNeighbor(int i)
{
    cout << endl;
    //loop through array at the index
    for (int j= 0; j < 15; j++)
    {
        //if the weight value is more than 0
        if (adj[i][j] > 0)
        {
            //print out name of neighbor
            cout << names[j] << "\t";
        }
    }
}

int totalDistance(int start, int destination)
{
    cout << endl << endl;
    cout << "Path Taken:" << endl;
    cout << names[start] << endl;

    tempEnd = destination;

    //check if the two are immidiate neighbors
    if (adj[start][tempEnd] > 0)
    {
        //if they are, return the weight
        return adj[start][tempEnd];
    }
    //if not enter the function loop
    while (adj[start][tempEnd] == 0)
    {
        //because we are always checking right on the grid, if m = 14 it needs to be set to -1
        if (tempEnd == 14)
        {
            tempEnd = -1;
        }
        tempEnd++;

        //if there is weight between 2 given cities, move from start city to end city and add weight to total weight
        if (adj[start][tempEnd] != 0)
        {
            total += adj[start][tempEnd];
            //set the previous end to be the new start
            start = tempEnd;
            //reset m to the end
            tempEnd = destination;
            //print the newly visted city to the path list
            cout << names[start] << endl;
        }

        if (adj[start][tempEnd] > 0)
        {
            //Check to see if last start end update resulted in the path to the destination, if so add the distance and print the name
            total += adj[start][destination];
            cout << names[destination] << endl << endl;
        }
    }
    //print the distance distance of the path taken
    cout << "Distance:" << endl;
    return total;
}

void getGrid()
{
    adj[0][1] = 14;
    adj[0][11] = 14;
    adj[0][12] = 12;

    adj[1][0] = 14;
    adj[1][2] = 9;
    adj[1][10] = 17;
    adj[1][11] = 9;

    adj[2][1] = 9;
    adj[2][3] = 5;
    adj[2][9] = 20;
    adj[2][10] = 13;

    adj[3][2] = 5;
    adj[3][4] = 17;
    adj[3][9] = 19;

    adj[4][3] = 17;
    adj[4][5] = 16;
    adj[4][9] = 4;

    adj[5][4] = 16;
    adj[5][6] = 8;
    adj[5][7] = 9;
    adj[5][9] = 12;

    adj[6][5] = 8;
    adj[6][7] = 6;

    adj[7][5] = 9;
    adj[7][6] = 6;
    adj[7][8] = 7;
    adj[7][9] = 12;
    adj[7][13] = 23;
    adj[7][14] = 10;

    adj[8][7] = 7;
    adj[8][9] = 13;
    adj[8][10] = 5;
    adj[8][14] = 6;

    adj[9][2] = 20;
    adj[9][3] = 19;
    adj[9][4] = 4;
    adj[9][5] = 12;
    adj[9][7] = 12;
    adj[9][8] = 13;
    adj[9][10] = 7;

    adj[10][1] = 17;
    adj[10][2] = 13;
    adj[10][8] = 5;
    adj[10][9] = 7;
    adj[10][11] = 18;
    adj[10][14] = 8;

    adj[11][0] = 14;
    adj[11][1] = 9;
    adj[11][10] = 18;
    adj[11][12] = 15;
    adj[11][14] = 9;

    adj[12][0] = 9;
    adj[12][11] = 15;
    adj[12][13] = 11;
    adj[12][14] = 15;

    adj[13][7] = 23;
    adj[13][12] = 11;
    adj[13][14] = 18;

    adj[14][7] = 10;
    adj[14][8] = 6;
    adj[14][10] = 8;
    adj[14][11] = 9;
    adj[14][12] = 15;
    adj[14][13] = 18;
}