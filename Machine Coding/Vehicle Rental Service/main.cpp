#include<bits/stdc++.h>
using namespace std;

class Vehicle{
    private:
        string name;
        int seat;
        int cost;
    public:
        Vehicle(string name,int seat,int cost){
            this->name = name;
            this->seat = seat;
            this->cost = cost;
        }
        string getName(){
            return name;
        }
        void setName(int name){
            this->name = name;
        }

        int getSeat(){
            return seat;
        }
        void setSeat(int seat){
            this->seat = seat;
        }

        int getCost(){
            return cost;
        }
        void setCost(int cost){
            this->cost = cost;
        }
};

class Branch{
    private:
        string location;
        list<Vehicle> vehicles;
        unordered_map<string,int> vehicleCount;
    public:
        Branch(string location,list<Vehicle> vehicles){
            this->location = location;
            this->vehicles = vehicles;
            for(Vehicle vehicle:vehicles)
                vehicleCount[vehicle.getName()] ++;
        }

        string getLocation(){
            return this->location;
        }
        void setLocation(string location){
            this->location = location;
        }

        list<Vehicle> getVehicles(){
            return this->vehicles;
        }
        void setVehicles(list<Vehicle> vehicles){
            this->vehicles = vehicles;
        }

        int getVehicleCount(string vehicleName){
            if(vehicleCount.find(vehicleName)==vehicleCount.end()){
                return 0;
            }
            return vehicleCount[vehicleName];
        }
};

class Company{
    list<Branch> branches;

    //location,cartype -> num of available
    map<pair<string,string>,int> availableVehicle; 

public:
    map<pair<string,string>,int> getAvailableVehicle(){
        return this->availableVehicle;
    }
    void setAvailableVehicle(map<pair<string,string>,int> availableVehicle){
        this->availableVehicle = availableVehicle ;
    }

    bool checkAvailability(string location, string vehicleName ){
        
        if(availableVehicle.find({location,vehicleName})==availableVehicle.end())
            return false;
        
        if(availableVehicle[{location,vehicleName}] == 0)
            return false;
        return true; 
    }

    bool bookVehicle(string location,int seat){
        for(Branch branch:branches){
            if(branch.getLocation()==location){
                for(Vehicle vehicle:branch.getVehicles()){
                    if(vehicle.getSeat()==seat){
                        if(checkAvailability(location,vehicle.getName())){
                            availableVehicle[{location,vehicle.getName()}]--;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool cancelBooking(string location,string vehicleName){
        int getTotalVehicleAtBranch;
        int getTotalAvalilableVehicle = availableVehicle[{location,vehicleName}];

        for(Branch branch:branches){
            if(branch.getLocation()==location){
                getTotalVehicleAtBranch = branch.getVehicleCount(vehicleName);
            }
        }

        if(getTotalVehicleAtBranch==0 or getTotalAvalilableVehicle==getTotalVehicleAtBranch)
            return false;
        
        availableVehicle[{location,vehicleName}] ++;
        return true;
    }

    bool addBranch(string location,list<Vehicle> vehicles){
        
        for(Branch branch:branches){
            if(branch.getLocation()==location)
                return false;
        }

        Branch newBranch(location,vehicles);
        branches.push_back(newBranch);

        return true;
    }

    bool removeBranch(string location)
    {
        for(Branch branch:branches){
            if(branch.getLocation()==location){
                branches.remove(branch);
                return true;
            }
        }
        return false;
    }

    bool addVehicle(string location,Vehicle vehicle){
        for(Branch branch:branches){
            if(branch.getLocation()==location){
                list<Vehicle> tempVehicles = branch.getVehicles();
                tempVehicles.push_back(vehicle);
                branch.setVehicles(tempVehicles);
            }
        }
    }
};









int main()
{

}