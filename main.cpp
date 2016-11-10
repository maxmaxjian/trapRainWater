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

        std::vector<int> waters;
        std::transform(cuts.begin(), cuts.end(),
                       std::inserter(waters, waters.begin()),[&](const std::vector<int> & cross){
                           // std::cout << trappedWater(cross) << std::endl;
                           return trappedWater(cross);
                       });

        return std::accumulate(waters.begin(), waters.end(), 0);
    }

  private:
    int trappedWater(const std::vector<int> & cross) {
        std::vector<size_t> idxOfOne;
        for (size_t i = 0; i < cross.size(); i++)
            if (cross[i] == 1)
                idxOfOne.push_back(i);
        // std::copy(idxOfOne.begin(), idxOfOne.end(), std::ostream_iterator<size_t>(std::cout, " "));
        // std::cout << std::endl;

        std::vector<int> diff;
        std::transform(idxOfOne.begin(), idxOfOne.end()-1, idxOfOne.begin()+1,
                       std::inserter(diff, diff.begin()), [](int first, int second){
                           return second-first-1;
                       });
        // std::copy(diff.begin(), diff.end(), std::ostream_iterator<int>(std::cout, " "));
        // std::cout << std::endl;
        return std::accumulate(diff.begin(), diff.end(), 0);
    }
};

int main() {
    std::vector<int> hgts{0,1,0,2,1,0,1,3,2,1,2,1};

    solution soln;
    int water = soln.trap(hgts);
    std::cout << "The amount of water that can be trapped is:\n"
	      << water << std::endl;
}
