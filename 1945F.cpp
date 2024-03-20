#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
int index(ordered_multiset<int> &st,int value){
    return st.order_of_key(value);
}
int value(ordered_multiset<int> &st,int index){
    return *st.find_by_order(index);
}
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
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ordered_multiset<int> s;
        for(int i=1;i<=n;i++){
            s.insert(a[i]);
        }
        vector<int> p(n+1);
        for(int i=1;i<=n;i++){
            cin>>p[i];
        }
        long long int ans=0,k=0;
        for(int i=1;i<=n;i++){
            long long int mul=min(i,(int)s.size());
            long long int val=value(s,max(0,(int)s.size()-i));
            if(ans<mul*val){
                ans=mul*val;
                k=i;
            }
            s.erase(s.find_by_order(index(s,a[p[i]])));
        }
        cout<<ans<<" "<<k<<endl;
    }
    return 0;
}
