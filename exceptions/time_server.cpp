#include <iostream>
#include <exception>
#include <string>
using namespace std;

class TimeServer {
	public:
		string GetCurrentTime() {
			string res;
			try {
				try {
					res = AskTimeServer();
				} catch(system_error) {
					return last_fetched_time;
				}
			} catch(exception& ex) {
				throw;
			}
			last_fetched_time = res;
			return last_fetched_time;
		}
	private:
		string last_fetched_time = "00:00:00";
};
