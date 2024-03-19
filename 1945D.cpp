#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isNumber(const std::string& s) {
    std::istringstream iss(s);
    double num;
    iss >> std::noskipws >> num; // Try to extract a number from the string
    
    // Check if extraction was successful and if there are no remaining characters
    if (!iss.eof() || iss.fail()) {
        return false; // If there are remaining characters or extraction failed, return false
    }

    // Check if the extracted number matches the entire input string, including leading zeros
    return std::to_string(static_cast<int>(num)) == s;
}
std::vector<int> findCommonElements(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> result;
    int i = 0, j = 0;

    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) {
            i++;  // Move pointer for vec1
        } else if (vec1[i] > vec2[j]) {
            j++;  // Move pointer for vec2
        } else {
            // Found a common element
            result.push_back(vec1[i]);
            i++;
            j++;
        }
    }

    return result;
}
int firstNonZeroNotInSet(const std::set<int>& s) {
    int num = 0; // Start from 1

    // Iterate until we find a number not present in the set
    while (s.count(num) > 0) {
        num++;
    }

    return num;
}
int closestValue(const std::vector<int>& vec, int target) {
    if (vec.empty())
        return 0; // Return default value if the vector is empty

    int closest = vec[0]; // Initialize closest to the first element
    int min_diff = std::abs(target - closest); // Initialize minimum difference

    // Iterate through the vector to find the closest value
    for (int num : vec) {
        int diff = std::abs(target - num);
        if (diff < min_diff) {
            min_diff = diff;
            closest = num;
        }
    }

    return closest;
}
signed main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<int>arr(n),brr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>brr[i];
        }
        int ans=0;
        int reqdi = m--;
        for(int i=n-1;i>=reqdi;i--){
            ans+=min(arr[i],brr[i]);
        }
        // cout<<ans<<" ";
        vector<int>left;int s=0;
        for(int i=reqdi-1;i>=0;i--){
            if(i==reqdi-1){
                left.push_back(arr[i]);
            }
            else{
                left.push_back(arr[i]+s);
            }
            s+=brr[i];
        }
        sort(left.begin(),left.end());
        cout<<ans+left[0]<<endl;
        
    }
    return 0;
}
