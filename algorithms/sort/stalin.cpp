#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv){
	std::vector<int> vec={
		1, 2, 5, 4, 3, 10, 6, 3, 50, 9
	};
	if (vec.empty()){
		return -1;
	}
	int last=vec[0];
	vec.erase(std::remove_if(vec.begin(), vec.end(),
			[&last](int x){
				bool ret=x<last;
				if (!ret){
					last=x;
				}
				return ret;
			}
		),
		vec.end()
	);
	for (int it: vec){
		std::cout << it << "\n";
	}
	return 0;
}
