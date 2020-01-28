#include "cs240p7.h"

Team::Team(int _wins, int _losses, string _name, int _maxIndex){
    wins = _wins;
    losses = _losses;
    name = _name;
    maxIndex = _maxIndex;
    minIndex = _maxIndex;
}
int Team::getWins(){
    return wins;
}

int Team::getLosses(){
    return losses;
}

string Team::getName(){
    return name;
}
int Team::getMaxIndex(){
    return maxIndex;
}
int Team::getMinIndex(){
    return minIndex;
}
void Team::setMaxIndex(int a){
    maxIndex = a;
}
void Team::setMinIndex(int a){
    minIndex = a;
}
void TeamPQ::swap(int index, int parent, bool max){
    if (max){
        if (index > winHeap.size() - 1){return; }
        Team t = winHeap.at(index);
        if (t.getMinIndex() > lossHeap.size() - 1 || winHeap.at(parent).getMinIndex() > lossHeap.size() - 1){
            
        }else{
            lossHeap.at(t.getMinIndex()).setMaxIndex(parent);
            
        }
        lossHeap.at(winHeap.at(parent).getMinIndex()).setMaxIndex(index);
        
        winHeap.at(index) = winHeap.at(parent);
        winHeap.at(parent) = t;
    }else{
        
        if (index > lossHeap.size() - 1){return; }
        Team t = lossHeap.at(index);
        if (t.getMaxIndex() > winHeap.size() - 1 || lossHeap.at(parent).getMaxIndex() > winHeap.size() - 1){
            
        }else{
            winHeap.at(t.getMaxIndex()).setMinIndex(parent);
            
        }
        winHeap.at(lossHeap.at(parent).getMaxIndex()).setMinIndex(index);
        lossHeap.at(index) = lossHeap.at(parent);
        lossHeap.at(parent) = t;
    }
    
}

int TeamPQ::getParent(int index){
    if (index <= 0) {return -1;}
    return (index-1) / 2;
}

TeamPQ::TeamPQ(){
    winHeap = vector<Team>();
    lossHeap = vector<Team>();
}

TeamPQ::~TeamPQ(){
}

int TeamPQ::getSize(){
    return winHeap.size();
}

bool TeamPQ::isEmpty(){
    if (winHeap.size() == 0 && lossHeap.size() == 0){return true;}
    return false;
}
void TeamPQ::insert(const Team &t){
    winHeap.push_back(t);
    int k = winHeap.size()-1;
    while (getParent(k) != -1 && winHeap[getParent(k)].getWins() < winHeap[k].getWins()){
        swap(k, getParent(k), true);
        k = getParent(k);
    }
    lossHeap.push_back(t);
    k = lossHeap.size() - 1;
    while (getParent(k) != -1 && lossHeap[getParent(k)].getLosses() > lossHeap[k].getLosses()){
        swap(k, getParent(k), false);
        k = getParent(k);
    }
}

const Team& TeamPQ::findMaxWins() const{
    return winHeap.at(0);
}
const Team& TeamPQ::findMinLosses() const{
    return lossHeap.at(0);
}

void TeamPQ::removeMaxWins(){

    if (lossHeap.size() == 1){
        lossHeap.clear();
        winHeap.clear();
        return;
    }
    
    int minIndex = winHeap.at(0).getMinIndex();
    swap(minIndex, lossHeap.size() - 1, false);
    
    if (lossHeap.size() == 1){
        lossHeap.clear();
    }else{
        lossHeap.pop_back();
    }
    int losssize = lossHeap.size();
    while (((minIndex * 2 + 1) < losssize - 1) || ((minIndex * 2 + 2) < losssize - 1)){
        int tempj = minIndex * 2 + 1;
        if (tempj < lossHeap.size() - 1 && lossHeap[tempj + 1].getLosses() < lossHeap[tempj].getLosses()){
            tempj = tempj + 1;
        }
        if (lossHeap[minIndex].getLosses() <= lossHeap[tempj].getLosses()){
            break;
        }
        swap(minIndex, tempj, false);
        minIndex = tempj;
    }
    
    
    int maxIndex = 0;
    swap(maxIndex, winHeap.size() - 1, true);
    if (winHeap.size() == 1){
        winHeap.clear();
    }else{
        winHeap.pop_back();
    }
    while ((maxIndex * 2 + 1 < winHeap.size() - 1) || (maxIndex * 2 + 2 < winHeap.size() - 1)){
        int tempj = maxIndex * 2 + 1;
        if (tempj < winHeap.size() - 1 && winHeap[tempj + 1].getWins() > winHeap[tempj].getWins()){
            tempj = tempj + 1;
        }
        if (winHeap[maxIndex].getWins() >= winHeap[tempj].getWins()){
            break;
        }
        swap(maxIndex, tempj, true);
        maxIndex = tempj;
    }

}

void TeamPQ::removeMinLosses(){
    if (lossHeap.size() == 1){
        lossHeap.clear();
        winHeap.clear();
        return;
    }
    int maxIndex = lossHeap.at(0).getMaxIndex();
    swap(maxIndex, winHeap.size() - 1, true);
    if (winHeap.size() == 1){
        winHeap.clear();
    }else{
        winHeap.pop_back();
    }
    while ((maxIndex * 2 + 1 < winHeap.size() - 1) || (maxIndex * 2 + 2 < winHeap.size() - 1)){
        int tempj = maxIndex * 2 + 1;
        if (tempj < winHeap.size() - 1 && winHeap[tempj + 1].getWins() > winHeap[tempj].getWins()){
            tempj = tempj + 1;
        }
        if (winHeap[maxIndex].getWins() >= winHeap[tempj].getWins()){
            break;
        }
        swap(maxIndex, tempj, true);
        maxIndex = tempj;
    }
    
    int minIndex = 0;
    swap(minIndex, lossHeap.size() - 1, false);
    if (lossHeap.size() == 1){
        lossHeap.clear();
    }else{
        lossHeap.pop_back();
    }
    while ((minIndex * 2 + 1 < lossHeap.size() - 1) || (minIndex * 2 + 2 < lossHeap.size() - 1)){
        int tempj = minIndex * 2 + 1;
        if (tempj < lossHeap.size() - 1 && lossHeap[tempj + 1].getLosses() < lossHeap[tempj].getLosses()){
            tempj = tempj + 1;
        }
        if (lossHeap[minIndex].getLosses() <= lossHeap[tempj].getLosses()){
            break;
        }
        swap(minIndex, tempj, false);
        minIndex = tempj;
    }
}