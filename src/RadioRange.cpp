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

class RadioRange {
public:
    static bool dist_comp(pair<double, double> p1, pair<double, double> p2) {
        return (p1.first * p1.first + p1.second * p1.second) < (p2.first * p2.first + p2.second * p2.second);
    }

    double to_dist(pair<double, double> p) {
        return sqrt(p.first * p.first + p.second * p.second);
    }

    double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
        int n = X.size();
        vector<double> begs, ends;
        for (int i = 0; i < n; i++) {
            double y = Y[i];
            double x = X[i];
            double r = R[i];
            double theta = atan2(y, x);
            pair<double, double> p1(y + r * sin(theta), x + r * cos(theta));
            pair<double, double> p2(y - r * sin(theta), x - r * cos(theta));
            double b = to_dist(min(p1, p2, dist_comp));
            if (to_dist(make_pair(y, x)) <= r) {
                begs.push_back(0);
            } else {
                begs.push_back(b);
            }
            ends.push_back(to_dist(max(p1, p2, dist_comp)));
        }

        map<double, int> cs;
        cs[0] = 0;
        cs[Z] = 0;
        for (int i = 0; i < n; i++) {
            cs[begs[i]]++;
            cs[ends[i]]--;
        }
        double d = 0;
        for (auto& c : cs) {
            d += c.second;
            c.second = d;
        }

        double ret = 0;
        for (auto it = begin(cs); it != end(cs); it++) {
            if (it->first >= Z) {
                break;
            }
            if (it->second != 0) {
                continue;
            }

            auto jt(it);
            if (++jt == end(cs)) {
                break;
            }
            ret += (jt->first - it->first);
        }
        ret /= Z;

        return ret;
    }
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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

	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}

	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) {
		std::cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int X[]                   = {0};
			int Y[]                   = {0};
			int R[]                   = {5};
			int Z                     = 10;
			double expected__         = 0.5;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X[]                   = {0};
			int Y[]                   = {0};
			int R[]                   = {10};
			int Z                     = 10;
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X[]                   = {10};
			int Y[]                   = {10};
			int R[]                   = {10};
			int Z                     = 10;
			double expected__         = 0.4142135623730951;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X[]                   = {11, -11, 0, 0};
			int Y[]                   = {0, 0, 11, -11};
			int R[]                   = {10, 10, 10, 10};
			int Z                     = 31;
			double expected__         = 0.3548387096774194;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int X[]                   = {100};
			int Y[]                   = {100};
			int R[]                   = {1};
			int Z                     = 10;
			double expected__         = 1.0;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int X[]                   = {1000000000};
			int Y[]                   = {1000000000};
			int R[]                   = {1000000000};
			int Z                     = 1000000000;
			double expected__         = 0.41421356237309503;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int X[]                   = {20, -20, 0, 0};
			int Y[]                   = {0, 0, 20, -20};
			int R[]                   = {50, 50, 50, 50};
			int Z                     = 100;
			double expected__         = 0.3;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int X[]                   = {0, -60, -62, -60, 63, -97};
			int Y[]                   = {-72, 67, 61, -8, -32, 89};
			int R[]                   = {6, 7, 8, 7, 5, 6};
			int Z                     = 918;
			double expected__         = 0.9407071068962471;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int Z                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int Z                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int Z                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = RadioRange().RadiusProbability(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), Z);
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
