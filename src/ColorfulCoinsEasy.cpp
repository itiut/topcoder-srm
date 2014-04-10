#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class ColorfulCoinsEasy {
public:
    bool canDistinguish(vector<int> values, int n) {
        vector<int> nums(values.size(), 0);
        for (int i = values.size() - 1; i >= 0; i--) {
            if (n >= values[i]) {
                nums[i] = n / values[i];
                n %= values[i];
            } else {
                return false;
            }
        }
        set<int> num_set;
        for (auto num : nums) {
            if (num_set.find(num) != end(num_set)) {
                return false;
            }
            num_set.insert(num);
        }
        return true;
    }

    string isPossible(vector <int> values) {
        for (int i = 1; i < 1e6; i++) {
            if (canDistinguish(values, i)) {
                return "Possible";
            }
        }
        return "Impossible";
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}

	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) {
		std::cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;

		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl;
			std::cerr << "    Received: \"" << received << "\"" << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int values[]              = {1};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int values[]              = {1, 3};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int values[]              = {1, 2, 4};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int values[]              = {1, 5, 15, 90};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int values[]              = {1, 4, 20, 60, 180, 1440, 5760};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int values[]              = {1, 7, 21, 105, 630, 3150, 18900};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int values[]              = {1, 10, 30, 300, 900, 9000, 18000};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int values[]              = {1, 2, 10, 40, 200, 1000, 4000, 20000};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int values[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int values[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int values[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ColorfulCoinsEasy().isPossible(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
