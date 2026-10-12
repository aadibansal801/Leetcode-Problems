class BusBooking {
public:

    vector<vector<bool>>booked;
    vector<vector<int>>bookingCost;
    int totalTime = 0;
    int bookedCount = 0;
    
    BusBooking(int n) {
        booked.assign(4, vector<bool>(n, false));
        bookingCost.assign(4, vector<int>(n, 0));
    }
    
    void toggle(string seat) {
        int col = seat[0] - 'A';
        int row = stoi(seat.substr(1)) - 1;
        if(booked[col][row]){
            booked[col][row] = false;
            bookedCount--;
            totalTime-=bookingCost[col][row];
            bookingCost[col][row] = 0;
            return;
        }
        int cost = 1;
        if(col == 0 && booked[1][row]){
            cost = 3;
        }else if(col == 3 && booked[2][row]){
            cost = 3;
        }
        booked[col][row] = true;
        bookingCost[col][row] = cost;
        totalTime+=cost;
        bookedCount++;
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return bookedCount;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */