// https://leetcode.com/problems/design-parking-system

class ParkingSystem {

   public ParkingSystem(int big, int medium, int small) {
            sizes = new int[3];
            sizes[0] = big;
            sizes[1] = medium;
            sizes[2] = small;
            hm = new HashMap<>();
            for(int i = 1; i <= 3; i++) {
                hm.put(i, new ArrayList<Integer>());
            }
        }
        public boolean addCar(int carType) {
            ArrayList<Integer> parking = hm.get(carType);
            if(parking.size() < sizes[carType - 1])
            {
                parking.add(carType);
                return true;
            }
            return false;
        }
        private final int[] sizes;
        private final HashMap<Integer, ArrayList<Integer>> hm;
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */