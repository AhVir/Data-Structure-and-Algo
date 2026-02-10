class RideSharingSystem {
public:
    queue<int> drivers;
    queue<int> riders;

    vector<pair<int, int>> matches;
    
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(drivers.empty() || riders.empty()) return vector<int>{-1, -1};

        int r = riders.front();
        riders.pop();

        int d = drivers.front();
        drivers.pop();

        matches.push_back({d, r});

        return vector<int>{d, r};
    }
    
    void cancelRider(int riderId) {
        queue<int> tempQ;
        bool removed = false;

        while(riders.empty() == false){
            int temp = riders.front();
            riders.pop();

            if(temp == riderId && removed == false) removed = true;
            else{
                tempQ.push(temp);
            }
        }

        riders = tempQ;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
