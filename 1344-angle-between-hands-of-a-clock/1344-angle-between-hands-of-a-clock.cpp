class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr_angle = hour*30*1.0 + minutes*0.5;
        if(hr_angle>=360) 360-hr_angle;
        double min_angle = (minutes*6*1.0);
        double angle = abs(hr_angle-min_angle);
        if(angle>180) return 360-angle;
        return angle;
    }
};