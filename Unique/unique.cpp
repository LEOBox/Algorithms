#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//use left indicator as base indicator
void unique_left_point(vector<int> &v);
//use right indicator as base indicator
void unique_right_point(vector<int> &v);

int main() {
	vector<int> v = {3,2,6,3,7,4,6,7,8,1,0,3,5};
	unique_left_point(v);
	unique_right_point(v);
	
	return 0;
}

void unique_left_point(vector<int> &v) {
    //sort the vector
    sort(v.begin(), v.end());
    
    //unique the element and cout the number of each element in vector
    for (size_t L = 0, R; L < v.size(); L = R) {
        for (R = L+1; R < v.size(); ++R) {
            if (v[L] != v[R]) {
                break;
            }
        }
        std::cout << v[L] << ":" << R-L << std::endl;
    }
}

void unique_right_point(vector<int> &v) {
    //sort the vector
    sort(v.begin(), v.end());
    //init left and right indicator	
    size_t L,R;
    
    //unique the element and cout the number of each element in vector
    for (L=0,R=0; R < v.size(); ++R) {
        if (v[L] != v[R]) {
            std::cout << v[L] << ":" << R-L << std::endl;
            L = R;
        }
    }
    //don't forget the tail!!!
    if (v.size() > 0) {
        std::cout << v[L] << ":" << R-L << std::endl;
    }
}
