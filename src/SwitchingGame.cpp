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
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class SwitchingGame {
public:
    void next_state(vector<string>& states, int y, int x, vector<pair<int, int>>& to_on_ranges, vector<pair<int, int>>& to_off_ranges) {
        for (int yy = y + 1; yy < states.size(); yy++) {
            if (states[yy][x] == '?') {
                continue;
            }
            if (states[y][x] == '-' && states[yy][x] == '+') {
                to_on_ranges.push_back(make_pair(y + 1, yy));
            }
            if (states[y][x] == '+' && states[yy][x] == '-') {
                to_off_ranges.push_back(make_pair(y + 1, yy));
            }
            return;
        }
    }

    int timeToWin(vector <string> states) {
        states.insert(begin(states), string(states[0].size(), '-'));

        set<int> to_ons;
        set<int> to_offs;
        vector<pair<int, int>> to_on_ranges;
        vector<pair<int, int>> to_off_ranges;

        for (int x = 0; x < states[0].size(); x++) {
            for (int y = 0; y < states.size() - 1; y++) {
                if (states[y][x] == '+' && states[y+1][x] == '-') {
                    to_offs.insert(y + 1);
                } else if (states[y][x] == '-' && states[y+1][x] == '+') {
                    to_ons.insert(y + 1);
                } else if (states[y][x] != '?' && states[y+1][x] == '?') {
                    next_state(states, y, x, to_on_ranges, to_off_ranges);
                }
            }
        }

        while (!to_on_ranges.empty()) {
            int b = to_on_ranges.back().first;
            int e = to_on_ranges.back().second;
            to_on_ranges.pop_back();

            bool inserted = false;
            for (int i = b; i <= e; i++) {
                if (to_ons.count(i) > 0) {
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                to_ons.insert(b);
            }
        }

        while (!to_off_ranges.empty()) {
            int b = to_off_ranges.back().first;
            int e = to_off_ranges.back().second;
            to_off_ranges.pop_back();

            bool inserted = false;
            for (int i = b; i <= e; i++) {
                if (to_offs.count(i) > 0) {
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                to_offs.insert(b);
            }
        }
        return states.size() - 1 + to_ons.size() + to_offs.size();
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

	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) {
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
			std::cerr << "    Expected: " << expected << std::endl;
			std::cerr << "    Received: " << received << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string states[]           = {"++--",
 "--++"};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = SwitchingGame().timeToWin(vector <string>(states, states + (sizeof states / sizeof states[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string states[]           = {"+-++",
 "+-++"};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = SwitchingGame().timeToWin(vector <string>(states, states + (sizeof states / sizeof states[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string states[]           = {"++",
 "+?",
 "?+",
 "++"};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = SwitchingGame().timeToWin(vector <string>(states, states + (sizeof states / sizeof states[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string states[]           = {"+",
 "?",
 "?",
 "?",
 "-"};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = SwitchingGame().timeToWin(vector <string>(states, states + (sizeof states / sizeof states[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string states[]           = {"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-?\?-?+"}
;
			int expected__            = 20;

			std::clock_t start__      = std::clock();
			int received__            = SwitchingGame().timeToWin(vector <string>(states, states + (sizeof states / sizeof states[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string states[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SwitchingGame().timeToWin(vector <string>(states, states + (sizeof states / sizeof states[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string states[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SwitchingGame().timeToWin(vector <string>(states, states + (sizeof states / sizeof states[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string states[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SwitchingGame().timeToWin(vector <string>(states, states + (sizeof states / sizeof states[0])));
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
