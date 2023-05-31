/**
 * Design Underground System
 * 
 * An underground railway system is keeping track of customer travel times between different stations. They are using this data to calculate the average time it takes to travel from one station to another.
 * 
 * Implement the UndergroundSystem class:
 *  void checkIn(int id, string stationName, int t)
 *      A customer with a card ID equal to id, checks in at the station stationName at time t.
 *      A customer can only be checked into one place at a time.
 *  void checkOut(int id, string stationName, int t)
 *      A customer with a card ID equal to id, checks out from the station stationName at time t.
 *  double getAverageTime(string startStation, string endStation)
 *      Returns the average time it takes to travel from startStation to endStation.
 *      The average time is computed from all the previous traveling times from startStation to endStation that happened directly, meaning a check in at startStation followed by a check out from endStation.
 *      The time it takes to travel from startStation to endStation may be different from the time it takes to travel from endStation to startStation.
 *      There will be at least one customer that has traveled from startStation to endStation before getAverageTime is called.
 */

#include "iostream"
#include "map"
#include "string"
using namespace std;

class UndergroundSystem {
private:
    map<int, pair<string, int>> checkInMap;
    map<pair<string, string>, pair<int, double>> cost;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = pair<string, int>(stationName, t);
        return ;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto in = checkInMap[id];
        checkInMap.erase(checkInMap.find(id));

        auto key = pair<string, string>(in.first, stationName);
        if (cost.find(key) != cost.end()) {
            cost[key] = pair<int, double>(1 + cost[key].first, t - in.second + cost[key].second);
        } else {
            cost[key] = pair<int, double>(1, t - in.second);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto key = pair<string, string>(startStation, endStation);
        return cost[key].second / cost[key].first;
    }

    void printCost() {
        for (auto p: cost) {
            printf("%s -> %s, id: %d, cost: %f", p.first.first.c_str(), p.first.second.c_str(), p.second.first, p.second.second);
        }
    }
};

int main() {
    UndergroundSystem *undergroundSystem = new UndergroundSystem();
    undergroundSystem->checkIn(45, "Leyton", 3);
    undergroundSystem->checkIn(32, "Paradise", 8);
    undergroundSystem->checkIn(27, "Leyton", 10);
    undergroundSystem->checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
    undergroundSystem->printCost();
    undergroundSystem->checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
    undergroundSystem->checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
    undergroundSystem->getAverageTime("Paradise", "Cambridge"); // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
    undergroundSystem->getAverageTime("Leyton", "Waterloo");    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
    undergroundSystem->checkIn(10, "Leyton", 24);
    undergroundSystem->getAverageTime("Leyton", "Waterloo");    // return 11.00000
    undergroundSystem->checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
    undergroundSystem->getAverageTime("Leyton", "Waterloo");    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
}