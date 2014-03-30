#include <algorithm>
#include <bitset>
#include <cctype>
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

class EmoticonsDiv2 {
public:
    int N = 2 << 10;
    vector<bool> isPrime;
    vector<int> primes;

    EmoticonsDiv2() {
        calcPrimes();
    }

    void calcPrimes() {
        isPrime.clear();
        isPrime.resize(N);
        fill(begin(isPrime), end(isPrime), true);
        isPrime[0] = isPrime[1] = false;
        primes.clear();
        primes.push_back(2);
        for (int i = 4; i < N; i+= 2) {
            isPrime[i] = false;
        }
        for (int i = 3; i + i < N; i += 2) {
            if (!isPrime[i]) {
                continue;
            }
            primes.push_back(i);
            for (int j = i + i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int printSmiles(int smiles) {
        int ret = 0;
        auto itr = begin(primes);
        while (smiles > 1 && itr != end(primes)) {
            while ((smiles % *itr) == 0) {
                smiles /= *itr;
                ret += *itr;
            }
            itr++;
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
			int smiles                = 2;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = EmoticonsDiv2().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int smiles                = 6;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = EmoticonsDiv2().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int smiles                = 11;
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = EmoticonsDiv2().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int smiles                = 16;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = EmoticonsDiv2().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int smiles                = 1000;
			int expected__            = 21;

			std::clock_t start__      = std::clock();
			int received__            = EmoticonsDiv2().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int smiles                = 101;
			int expected__            = 101;

			std::clock_t start__      = std::clock();
			int received__            = EmoticonsDiv2().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int smiles                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EmoticonsDiv2().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int smiles                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EmoticonsDiv2().printSmiles(smiles);
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
