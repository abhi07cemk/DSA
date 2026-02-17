class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for(int hour = 0; hour < 12; ++hour)
        {
            for(int minutes = 0; minutes < 60; ++minutes)
            {
                int hourBits = __builtin_popcount(hour);
                int minuteBits = __builtin_popcount(minutes);

                 if (hourBits + minuteBits == turnedOn) 
                {
                    string timeString = to_string(hour) + ":" + 
                                       (minutes < 10 ? "0" : "") + 
                                       to_string(minutes);
                  
                    result.push_back(timeString);
                }
            }
        }
        return  result;
    }
};