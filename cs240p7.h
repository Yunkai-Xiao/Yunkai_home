#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Team{
    int wins;
    int losses;
    string name;
    int maxIndex;
    int minIndex;
    public:
    Team(int wins, int losses, string name, int maxIndex);
    int getWins();
    int getLosses();
    string getName();
    int getMaxIndex();
    int getMinIndex();
    void setMaxIndex(int a);
    void setMinIndex(int a);
};

class TeamPQ{
    vector<Team> winHeap;
    vector<Team> lossHeap;
    void swap(int index, int parent, bool max);
    int getParent(int index);
    
    public:
    TeamPQ();
    ~TeamPQ();
    bool isEmpty();
    int getSize();
    void insert(const Team &t);         // O(log n) time
    const Team &findMaxWins() const;    // O(1) time
    const Team &findMinLosses() const;  // O(1) time

    void removeMaxWins();     // O(log n)
    void removeMinLosses();   // O(log n)
};