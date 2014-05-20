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

class CandidatesSelectionEasy {
public:
    vector <int> sort(vector <string> score, int x) {
        vector<pair<string, int>> maids;
        for (int i = 0; i < score.size(); i++) {
            maids.push_back(make_pair(score[i], i));
        }
        stable_sort(begin(maids), end(maids), [x](pair<string, int> p1, pair<string, int> p2) { return p1.first[x] < p2.first[x]; });

        vector<int> ret;
        for (auto p : maids) {
            ret.push_back(p.second);
        }
        return ret;
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

	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) {
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
			string score[]            = {"ACB", "BAC", "CBA"};
			int x                     = 1;
			int expected__[]          = {1, 2, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CandidatesSelectionEasy().sort(vector <string>(score, score + (sizeof score / sizeof score[0])), x);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string score[]            = {"A", "C", "B", "C", "A"};
			int x                     = 0;
			int expected__[]          = {0, 4, 2, 1, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CandidatesSelectionEasy().sort(vector <string>(score, score + (sizeof score / sizeof score[0])), x);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string score[]            = {"LAX","BUR","ONT","LGB","SAN","SNA","SFO","OAK","SJC"};
			int x                     = 2;
			int expected__[]          = {5, 3, 8, 7, 4, 6, 1, 2, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CandidatesSelectionEasy().sort(vector <string>(score, score + (sizeof score / sizeof score[0])), x);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string score[]            = {"BBCBABAC","BCBACABA","CCCBAACB","CACABABB","AABBBBCC"};
			int x                     = 6;
			int expected__[]          = {0, 1, 3, 2, 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CandidatesSelectionEasy().sort(vector <string>(score, score + (sizeof score / sizeof score[0])), x);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string score[]            = {"XXYWZWWYXZ","YZZZYWYZYW","ZYZZWZYYWW","ZWZWZWZXYW","ZYXWZXWYXY","YXXXZWXWXW","XWWYZWXYXY","XYYXYWYXWY","ZZYXZYZXYY","WXZXWYZWYY"};
			int x                     = 3;
			int expected__[]          = {0, 3, 4, 5, 7, 8, 9, 6, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CandidatesSelectionEasy().sort(vector <string>(score, score + (sizeof score / sizeof score[0])), x);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			string score[]            = {"X"};
			int x                     = 0;
			int expected__[]          = {0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CandidatesSelectionEasy().sort(vector <string>(score, score + (sizeof score / sizeof score[0])), x);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string score[]            = ;
			int x                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = CandidatesSelectionEasy().sort(vector <string>(score, score + (sizeof score / sizeof score[0])), x);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string score[]            = ;
			int x                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = CandidatesSelectionEasy().sort(vector <string>(score, score + (sizeof score / sizeof score[0])), x);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			string score[]            = ;
			int x                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = CandidatesSelectionEasy().sort(vector <string>(score, score + (sizeof score / sizeof score[0])), x);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
