#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//use left point as base point
void unique_left_point(vector<int> &v);
//use right point as base point
void unique_right_point(vector<int> &v);

int main() {
	// your code goes here
	vector<int> v = {3,2,6,3,7,4,6,7,8,1,0,3,5};
	//unique_left_point(v);
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
    sort(v.begin(), v.end());
    size_t L,R;
    
    for (L=0,R=0; R < v.size(); ++R) {
        if (v[L] != v[R]) {
            std::cout << v[L] << ":" << R-L << std::endl;
            L = R;
        }
    }
    
    if (v.size() > 0) {
        std::cout << v[L] << ":" << R-L << std::endl;
    }
}
