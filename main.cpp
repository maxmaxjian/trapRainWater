#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class solution {
public:
    int trap(const std::vector<int> & heights) {
	auto temp = std::minmax_element(heights.begin(), heights.end());
	int minhgt = *temp.first, maxhgt = *temp.second;

	std::vector<std::vector<int>> cuts;
	for (int h = maxhgt; h > minhgt; h--) {
	    std::vector<int> cross;
	    std::transform(heights.begin(), heights.end(), std::inserter(cross, cross.begin()),
			   [=](int i){
			       return i >= h ? 1 : 0;
			   });
	    cuts.push_back(cross);
	    std::copy(cross.begin(), cross.end(), std::ostream_iterator<int>(std::cout, " "));
	    std::cout << std::endl;
	}

	return 0;
    }

private:
    int trappedWater(const std::vector<int> & cross) {
	
    }
};

int main() {
    std::vector<int> hgts{0,1,0,2,1,0,1,3,2,1,2,1};

    solution soln;
    int water = soln.trap(hgts);
    std::cout << "The amount of water that can be trapped is:\n"
	      << water << std::endl;
}
