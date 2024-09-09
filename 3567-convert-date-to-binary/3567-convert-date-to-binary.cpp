
class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        string binaryYear = bitset<12>(year).to_string();
        string binaryMonth = bitset<4>(month).to_string();
        string binaryDay = bitset<5>(day).to_string();

        binaryYear.erase(0, binaryYear.find_first_not_of('0'));
        binaryMonth.erase(0, binaryMonth.find_first_not_of('0'));
        binaryDay.erase(0, binaryDay.find_first_not_of('0'));
        return binaryYear + "-" + binaryMonth + "-" + binaryDay;
    }
};
