class ParkingSystem {
 int b,m,s;
public:
    ParkingSystem(int big, int medium, int small) {
        b=big; m=medium; s=small;
    }
    
    bool addCar(int carType) {
        bool result = true;
        switch(carType) {
            case 1:
                (b <= 0)? result=false:  --b;
                break;
            case 2: 
                (m <= 0)? result=false:  --m;
                break;
            case 3: 
                (s <= 0)? result=false:  --s;
                break;
            default:
                result=false;
        }
        return result;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
